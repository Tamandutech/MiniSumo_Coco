#include <Ultrasonic.h>
/*#define pino_trigger 12
#define pino_echo 13*/
const int motorA = 5;
const int motorB = 6;
const int dirA = 7;
const int dirB = 8;
const int PWM = 140;
int valorSensor1 = 0;
int valorSensor2 = 0;
int distancia;
Ultrasonic ultrasonic(13, 9);

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);
  delay(3300);

}

void loop() {   
  distancia = ultrasonic.read();
  valorSensor1 = analogRead(A0);
  valorSensor2 = analogRead(A1); 
  frente();   
  
  Serial.print("Distancia: ");
  Serial.println(distancia);
  if(distancia < 14){   
     atacar();
  }
  //refletancia - quando for colocar no tatame, inverter sinais
  if(valorSensor1 > 500 || valorSensor2 > 500){
  tras(); 
  viraadireita();
  }
}
void tras(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 60);
  analogWrite(motorB, 60);
  delay(1000);
}

void frente(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 60);
  analogWrite(motorB, 60);
  delay(10);
}

void viraadireita(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW); 
  analogWrite(motorA, 60);
  analogWrite(motorB, 60);
  delay(250);
}

void viraaesquerda(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH); 
  analogWrite(motorA, 0);
  analogWrite(motorB, 60);
  delay(50);
}
void atacar(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 160);
  analogWrite(motorB, 160);
  delay(10);
}
