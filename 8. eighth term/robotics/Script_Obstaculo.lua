-- Funcao chamada no inicio da simula??o
function sysCall_init()
    -- Importa componentes necessarios
    sim = require('sim')
    simUI = require('simUI')
    
    -- Obtem o identificador da base do robo
    bubbleRobBase = sim.getObject('..')
    
    -- Obtem os identificadores dos motores esquerdo e direito
    leftMotor = sim.getObject("../leftMotor")
    rightMotor = sim.getObject("../rightMotor")
    
    -- Obtem o identificador do sensor, usado para detectar obstaculos na frente
    noseSensor = sim.getObject("../sensingNose")
    
    -- Define a velocidade minima e maxima dos motores (em radianos por segundo)
    minMaxSpeed = {50 * math.pi / 180, 300 * math.pi / 180}
    
    -- Variavel para controlar se o robo esta avancando ou recuando
    backUntilTime = -1
    
    -- Inicializa os sensores de linha (esquerdo, central e direito)
    floorSensorHandles = {-1, -1, -1}
    floorSensorHandles[1] = sim.getObject("../leftSensor")
    floorSensorHandles[2] = sim.getObject("../middleSensor")
    floorSensorHandles[3] = sim.getObject("../rightSensor")
    
    -- Cria uma linha para tra?ar o caminho do rob? (linha amarela)
    robotTrace = sim.addDrawingObject(sim.drawing_linestrip + sim.drawing_cyclic, 2, 0, -1, 200, {1, 1, 0}, nil, nil, {1, 1, 0})
    
    -- Cria uma interface gr?fica customizada para controlar a velocidade do rob?
    xml = '<ui title="'..sim.getObjectAlias(bubbleRobBase,1)..' speed" closeable="false" resizeable="false" activate="false">'..[[
                <hslider minimum="0" maximum="100" on-change="speedChange_callback" id="1"/>
            <label text="" style="* {margin-left: 300px;}"/>
        </ui>
        ]]
    -- Cria a interface de controle e define a velocidade inicial
    ui = simUI.create(xml)
    speed = (minMaxSpeed[1] + minMaxSpeed[2]) * 0.5
    simUI.setSliderValue(ui, 1, 100 * (speed - minMaxSpeed[1]) / (minMaxSpeed[2] - minMaxSpeed[1]))
end

-- Fun??o chamada em cada ciclo de leitura dos sensores
function sysCall_sensing()
    -- Obt?m a posi??o atual do rob? e adiciona no tra?o do caminho
    local p = sim.getObjectPosition(bubbleRobBase)
    sim.addDrawingObjectItem(robotTrace, p)
end 

-- Fun??o chamada quando o controle deslizante da interface gr?fica ? ajustado
function speedChange_callback(ui, id, newVal)
    -- Atualiza a velocidade com base no valor selecionado
    speed = minMaxSpeed[1] + (minMaxSpeed[2] - minMaxSpeed[1]) * newVal / 100
end

-- Fun??o chamada em cada ciclo de atua??o dos motores


--//////////////////////////////////////OBSTACULOS///////////////////////////////////
function sysCall_actuation() 
 -- Verifica se o sensor de proximidade detectou um obst?culo ? frente
    local result = sim.readProximitySensor(noseSensor)
    
    if result > 0 then
        -- Se um obst?culo ? detectado, inicia a contagem para recuar
        backUntilTime = sim.getSimulationTime() + 2 -- Recuar por 2 segundos para evitar colis?o
        if sensorReading[1] and not sensorReading[3] then
            -- Se apenas o sensor esquerdo detecta a linha, reduz a velocidade do motor direito para curva ? esquerda
            rightV = 0.1 * speed
            leftV = -0.2 * speed  -- Recuo inclinado ? direita para contornar obst?culo
        elseif sensorReading[3] and not sensorReading[1] then
            -- Se apenas o sensor direito detecta a linha, reduz a velocidade do motor esquerdo para curva ? direita
            leftV = 0.1 * speed
            rightV = -0.2 * speed  -- Recuo inclinado ? esquerda para contornar obst?culo
        else
            -- Se ambos ou nenhum sensor detectam a linha, faz meia-volta lenta
            leftV = 0.1 * speed
            rightV = -0.1 * speed
        end
    end
    --Novamente, tentei aplicar uma l?gica de desvios aqui, mas sem muito sucesso
--//////////////////////////////////////OBSTACULOS///////////////////////////////////


    -- L? os sensores de linha (esquerdo, central e direito)
    sensorReading = {false, false, false}
    for i = 1, 3, 1 do
        local result, data = sim.readVisionSensor(floorSensorHandles[i])
        if result >= 0 then
            -- Se a intensidade da linha for baixa (inferior a 0.5), o sensor detecta a linha
            sensorReading[i] = (data[11] < 0.5)
        end
    end
    
    -- Define a velocidade dos motores para seguir a linha detectada
    rightV = speed
    leftV = speed
    if sensorReading[1] then
        -- Se o sensor esquerdo detecta a linha, reduz a velocidade do motor esquerdo
        leftV = 0.03 * speed
    end
    if sensorReading[3] then
        -- Se o sensor direito detecta a linha, reduz a velocidade do motor direito
        rightV = 0.03 * speed
    end
    if sensorReading[1] and sensorReading[3] then
        -- Se os sensores esquerdo e direito detectam a linha, o rob? ir? recuar por 2 segundos
        backUntilTime = sim.getSimulationTime() + 2
    end
    
    -- Controla o movimento do rob? com base no estado (avan?ando ou recuando)
    if backUntilTime < sim.getSimulationTime() then
        -- Modo de avan?o: move para frente na velocidade definida
        sim.setJointTargetVelocity(leftMotor, leftV)
        sim.setJointTargetVelocity(rightMotor, rightV)
    else
        -- Modo de recuo: move para tr?s em curva com velocidade reduzida
        sim.setJointTargetVelocity(leftMotor, -speed / 2)
        sim.setJointTargetVelocity(rightMotor, -speed / 10)
    end
end 

-- Fun??o chamada no final da simula??o para limpeza
function sysCall_cleanup() 
    -- Destr?i a interface gr?fica criada
    simUI.destroy(ui)
end
