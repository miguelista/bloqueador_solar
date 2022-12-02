#include <Servo.h>

/*-------------------------|
|---VALORES E DEFINIÇÕES---|
|-------------------------*/

const int pino_fotosensor = A0; //define o pino do sensor de luz
const int triggerdeluz = 500; //nivel onde o fotosensor ativa
const int pino_ledvermelho = 3; //pino led vermelho
const int pino_ledverde = 2; //pino led verde

Servo motor; //instancia o servo

int valoranalogico; //le os niveis de luz

/*------------------------|
|----------SETUP----------|
|------------------------*/
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  //definindo os LEDs
  pinMode(pino_ledvermelho, OUTPUT); 
  pinMode(pino_ledverde, OUTPUT);
  
  //servo
   motor.attach(4, 500, 2500); //conecta o servo
   motor.write(0); //define seu valor base como 0
}





/*-------------------------|
|----------CODIGO----------|
|-------------------------*/
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  
  valoranalogico = analogRead(pino_fotosensor); //instancia a leitura de luz
  
  if(valoranalogico > triggerdeluz) {
    digitalWrite(pino_ledverde, HIGH); // liga o vermelho
    digitalWrite(pino_ledvermelho, LOW); //desliga o vermelho
    motor.write(90); //abre a tranca
    
  }
  else {
    digitalWrite(pino_ledvermelho, HIGH); //deixa o vemelho ligado
    digitalWrite(pino_ledverde, LOW); //desliga o verde se estiver ligado
    motor.write(0); //fecha a tranca
  }
 
}