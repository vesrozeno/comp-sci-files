#include <Servo.h>
#define nao_apertado 70//angulo nao apertado
#define apertado 36//angulo apertado
#define valor_luz 250 //valor para saber se tem que apertar ou nao

Servo motozin;// servo motor
//bool trig=true;

void setup()
{          
  motozin.attach(0);//servo no pin 0
  motozin.write(nao_apertado);//começa no angulo nao apertado
}

void loop() 
{
 motozin.write(nao_apertado);//não apertado
 delay(1);
 if(analogRead(A0)< valor_luz)//se valor da luz for menor
 {
    motozin.write(apertado);//coloca angulo apertado
    delay(100);//espera para que ele chegue na posição                   
 }                     
}