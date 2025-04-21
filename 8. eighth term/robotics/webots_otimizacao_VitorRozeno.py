"""
Este algoritmo reativo implementa um controle de navegação para um robô 
utilizando sensores de proximidade. 
O robô é programado para se mover para frente, desviar para a esquerda ou direita 
com base nas leituras dos sensores, que detectam a distância a objetos próximos. 

A lógica do algoritmo é baseada em uma máquina de estados.
Os dados dos sensores são processados para calcular o peso aplicado em cada roda, 
permitindo que o robô tome decisões adequadas para evitar colisões.

As constantes e variáveis são definidas para controlar a velocidade do robô 
e o comportamento dos sensores.
"""

from controller import Robot

# Constantes
V_MAX = 5.24                  # Velocidade máxima
N_SENSORES = 16               # Número máximo de sensores
V_MAX_SENSOR = 1024           # Valor máximo do sensor
D_MIN = 1.0                   # Distância mínima
L_IMPULSO = 100               # Limite de peso nas rodas

# Classe para armazenar dados de cada sensor
class DadoSensor:
    def __init__(self, tag_dispositivo, peso_roda):
        self.tag_dispositivo = tag_dispositivo
        self.peso_roda = peso_roda

# Estados do robô
FRENTE, ESQUERDA, DIREITA = 0, 1, 2

# Configura os sensores com pesos
sensores = [
    DadoSensor(None, [150, 0]), DadoSensor(None, [200, 0]), DadoSensor(None, [300, 0]), DadoSensor(None, [600, 0]),
    DadoSensor(None, [0, 600]), DadoSensor(None, [0, 300]), DadoSensor(None, [0, 200]), DadoSensor(None, [0, 150]),
    DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0]),
    DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0]), DadoSensor(None, [0, 0])
]

# Função principal
def main():
    robo = Robot()

    t_step = int(robo.getBasicTimeStep())

    # Identifica as rodas
    roda_esquerda = robo.getDevice("left wheel")
    roda_direita = robo.getDevice("right wheel")

    # Configura os sensores
    for i in range(N_SENSORES):
        nome_sensor = f"so{i}"
        sensores[i].tag_dispositivo = robo.getDevice(nome_sensor)
        sensores[i].tag_dispositivo.enable(t_step)

    # Configura as rodas
    roda_esquerda.setPosition(float('inf'))
    roda_direita.setPosition(float('inf'))
    roda_esquerda.setVelocity(0.0)
    roda_direita.setVelocity(0.0)

    estado = FRENTE
    peso_total_rodas = [0.0, 0.0]

    # Loop de simulação
    while robo.step(t_step) != -1:
        velocidade = [0.0, 0.0]
        peso_total_rodas = [0.0, 0.0]

        # Lê os valores dos sensores e calcula o peso total das rodas
        for sensor in sensores:
            valor_sensor = sensor.tag_dispositivo.getValue()

            # Calcula o modificador de velocidade com base na distância
            if valor_sensor == 0.0:
                mod_velocidade = 0.0
            else:
                distancia = 5.0 * (1.0 - (valor_sensor / V_MAX_SENSOR))
                mod_velocidade = 1 - (distancia / D_MIN) if distancia < D_MIN else 0.0

            # Atualiza o peso total das rodas
            for j in range(2):
                peso_total_rodas[j] += sensor.peso_roda[j] * mod_velocidade

        # Máquina de estados para controle de direção
        if estado == FRENTE:
            if peso_total_rodas[0] > L_IMPULSO:
                velocidade = [0.7 * V_MAX, -0.7 * V_MAX]
                estado = ESQUERDA
            elif peso_total_rodas[1] > L_IMPULSO:
                velocidade = [-0.7 * V_MAX, 0.7 * V_MAX]
                estado = DIREITA
            else:
                velocidade = [V_MAX, V_MAX]
        elif estado == ESQUERDA:
            if peso_total_rodas[0] > L_IMPULSO or peso_total_rodas[1] > L_IMPULSO:
                velocidade = [0.7 * V_MAX, -0.7 * V_MAX]
            else:
                velocidade = [V_MAX, V_MAX]
                estado = FRENTE
        elif estado == DIREITA:
            if peso_total_rodas[0] > L_IMPULSO or peso_total_rodas[1] > L_IMPULSO:
                velocidade = [-0.7 * V_MAX, 0.7 * V_MAX]
            else:
                velocidade = [V_MAX, V_MAX]
                estado = FRENTE

        # Define a velocidade dos motores
        roda_esquerda.setVelocity(velocidade[0])
        roda_direita.setVelocity(velocidade[1])

    robo.cleanup()

if __name__ == "__main__":
    main()
