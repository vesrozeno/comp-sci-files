//TRABALHO 1 - MICRO E MICRO
//VINICIUS BELTRAMI E VITOR ROZENO

const int botaoPulo = 0; // Pino do Botão de Pulo - Pino 0
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definições dos sprites personalizadas para o LCD
byte pernaTras[] = {
  B00000,
  B00000,
  B00000,
  B00010,
  B10011,
  B01110,
  B11110,
  B00010
};
byte pernaFrente[] = {
  B00000,
  B00000,
  B00000,
  B00010,
  B10011,
  B01110,
  B01111,
  B01000
};
byte cerca[] = {
  B00000,
  B00000,
  B10001,
  B11111,
  B10001,
  B11111,
  B10001,
  B10001
};
byte morto[] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11011,
  B01110,
  B01110,
  B00000
};

bool spriteAtual = false; // Variável para alternar entre os sprites das pernas do personagem
float pulo = 0; // Variável para controlar o pulo do personagem
int dist = 20; // Distância entre as cercas
int cercas[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Array para armazenar a posição das cercas
int pontuacao = 0; // Pontuação atual do jogo
int maximo = 0; // maximo de pontuação
bool menu = true; //Variável para saber se é menu
bool fim = false; // Flag para controlar a exibição fim de jogo
int cercaEspecial = 0; // Contador para o cerca especial
int velocidade = 300;
int spriteObstaculo;

void Pressione()
{
  lcd.setCursor(1, 0);
  lcd.print("PRESSIONE PARA");
  lcd.setCursor(4, 1);
  lcd.print("INICIAR");
}

void setup() {
  Serial.begin(9600);
  pinMode(botaoPulo, INPUT_PULLUP); // Configura o botão de pulo como entrada com pull-up

  // Configuração inicial do LCD
  lcd.init();
  lcd.createChar(0, pernaFrente);
  lcd.createChar(1, pernaTras);
  lcd.createChar(2, cerca);
  lcd.createChar(4, morto);
  lcd.backlight();

  lcd.setCursor(2, 0);
  lcd.print("JUMPING REX");
  lcd.setCursor(3, 1);
  lcd.print("SIMULATOR");
  delay(1000);
  lcd.clear();

}
void loop() {
  if (menu) {
    //AÇÕES PÓS-JOGO
    if (fim == true)//Variavel para mostrar resultados e finalizar
    {
      lcd.clear();

      lcd.setCursor(4, 0);
      lcd.print("REX FOI");

      lcd.setCursor(3, 1);
      lcd.print("DE VASCO :(");

      delay(1150);
      lcd.clear();

      lcd.print("pts: " + String(pontuacao));
      if (pontuacao > maximo) { //Descobrir se pontuacção obtida é a maxima
        maximo = pontuacao;
      }

      lcd.setCursor(0, 1);
      lcd.print("(max: " + String(maximo)+")");

      delay(1324);
      lcd.clear();

      Pressione();

      fim = false;
    }
    else
    {
      Pressione();/*Se o jogo acabou de começar, 
      ele pula da introdução para o pressione para continuar*/
    }
    
    //REINÍCIO
    if (digitalRead(botaoPulo) == LOW)//Apertou o botão e recomeça
    { 
      menu = false;
      pontuacao = 0;//Zera pontuação

      for (int i = 0; i < 15; i++) {
        cercas[i] = 0;
      }

      dist = 20;//Seta a distancia entre cercas como 20 de novo
      lcd.clear();//Limpa tela
    }
  }
  //AÇÕES EM JOGO
  else
  {
    //DEFINIÇÃO DA VELOCIDADE DO JOGO
    if(pontuacao > 20 && velocidade > 50)
      velocidade = velocidade - 0.01;

    delay(velocidade);

    //CASO QUERIA ACOMPANHAR A VELOCIDADE (que é inversamente proporcional)
    /*
    Serial.print(velocidade);
    Serial.print("\n");*/

    // CONDIÇÕES PARA SABER "VALOR" ATUAL DO PULO
    if (digitalRead(botaoPulo) == LOW && pulo <= 0) {//se botao está pressionado e pulo menor ou igual a zero
      pulo = 3; // Inicia o pulo quando o botão é pressionado
    }
    if (pulo > 0) {// se pulo é maior que zero
      pulo -= 0.75; // Reduz gradualmente a altura do pulo
    }

    if (pulo > 0) { //se cachorro está no ar

      lcd.setCursor(1, 1); //seta cursor embaixo

      if (cercas[1] == 0) {
        lcd.print(" ");// printa vazio (pois ele pulou)
      }

      lcd.setCursor(1, 0);// seta cursor em cima

    } else {//se cachorro já saiu do ar e está em baixo

      lcd.setCursor(1, 0);// seta cursor em cima
      lcd.print(" ");// printa vazio (para tirar a imagem do cachorro pulando)
      lcd.setCursor(1, 1);// seta cursor em baixo

    }

    //CONDIÇÕES PARA MUDANÇA DE SPRITE DO CACHORRO
    if (spriteAtual == true) {//Se está na perna de tras no momento
      lcd.write(0); // Exibe a perna da frente do personagem
      spriteAtual = false;// Seta sprite atual como 0 (perna da frente)
    } else {//Se está na perna da frente no momento
      lcd.write(1); // Exibe a perna de trás do personagem
      spriteAtual = true;// Seta sprite atual como 1 (perna de tras)
    }


    //DEFINIÇÃO DA DISTANCIA ENTRE CERCAS
    dist -= 4;

    if (dist <= 0) {//Se distancia chegou em 0
      cercas[15] = 1;//Seta cerca 15 para aparecer
      dist = random(14,25);//Reseta distancia
    }

    //FOR PARA MOVIENTAÇÃO DAS CERCAS
    for (int i = 0; i < 15; i++) {
      cercas[i] = cercas[i + 1];
      cercas[i + 1] = 0;
    }

    //PRINT DAS CERCAS
    for (int i = 0; i < 15; i++) {
      lcd.setCursor(i, 1);
      if (cercas[i] == 1) {//Se cerca está setada para aparecer
        lcd.write(2); // Exibe o cerca no LCD
        //lcd.write(3);
      } else {//Se cerca está setada como 0 (para nao aparecer)
        if (!(pulo == 0 && i == 1)) {
          lcd.print(" "); // Limpa o espaço
        }
      }
    }
    
    //CONDIÇÕES PARA DEFINIR SE MORRREU OU NÃO
    if (pulo == 0 && cercas[1] == 1) {//Se cerca apareceu embaixo e não pulou
      lcd.setCursor(1, 1);//Cursor embaixo
      lcd.write(4); // Exibe a caveira tenebrosa

      delay(1000);//Espera até ir para a próxima tela
      menu = true;
      fim = true;
      lcd.clear();//Limpa tela
    }
    else//Se pulou e não morreu (ou nao tinha cerca embaixo)
    {
      pontuacao += 5; // Aumenta a pontuação
      lcd.setCursor(6, 0);//Local onde a pontuacao sera printada
      lcd.print(pontuacao);
    }
  }
}
