
#include <analogWrite.h>
  #define ivD 4
  #define ivE 2
  #define ivT 15
  int valorSensor1 = 0;
  int valorSensor2 = 0;
  int valorSensor3 = 0;  
  
void setup() {
  Serial.begin(9600);
}

void loop() {   
  valorSensor1 = analogRead(ivD);
  valorSensor2 = analogRead(ivE);
  valorSensor3 = analogRead(ivT);
  
  Serial.print("1: ");
  Serial.println(valorSensor1);
  Serial.print("2: ");
  Serial.println(valorSensor2);
  Serial.print("3: ");
  Serial.println(valorSensor3);*/

  
  delay(2000);

}
/*
void tras(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 40);
  analogWrite(motorB, 40);
  delay(500);
}

void frente(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 40);
  analogWrite(motorB, 40);
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
  analogWrite(motorB, 40);
  delay(50);
}
void atacar(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 160);
  analogWrite(motorB, 160);
  delay(10);
}
*/
