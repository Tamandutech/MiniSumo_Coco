#include <Ultrasonic.h>

#define pino_trigger 3
#define pino_echo 4

const int motorA = 5;
const int motorB = 6;
const int dirA = 7;
const int dirB = 8;
const int PWM = 140;
//eu
int valorSensor1 = 0;
int valorSensor2 = 0;

 float cmMsec;
 long microsec;
 int teste = 1;
 int distancia; 
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  // put your setup code here, to run once:
  
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

  delay(3300);

}

void loop() {
  // put your main code here, to run repeatedly:

 /*microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  */ 
   
  valorSensor1 = analogRead(A1);
  valorSensor2 = analogRead(A2);
  distancia = ultrasonic.read();
  
  if(distancia < 15){
    if(teste%2 == 0){
      viraaesquerda();
     }
     
     teste = 1; 
     frente();
  }
  else{
  teste = 2;
  viraadireita();
//viraaesquerda();
  }
  //refletância
  if(valorSensor1 < 500 && valorSensor2 < 500){
    tras();
    viraadireita();
    }
}

void frente(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 120);
  analogWrite(motorB, 60);
  delay(500);
}

void tras(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, PWM);
  analogWrite(motorB, PWM);
  delay(1000);
}

void viraadireita(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW); 
  analogWrite(motorA, 60);
  analogWrite(motorB, 60);
}

void viraaesquerda(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH); 
  analogWrite(motorA, 0);
  analogWrite(motorB, 40);
  delay(50);
}
