#include <analogWrite.h>
#include <SharpDistSensor.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu(Wire);
const byte sensorPin = 27;
const byte medianFilterWindowSize = 5;
SharpDistSensor sensor(sensorPin, medianFilterWindowSize);

  
float valorInicial = mpu.getAngleY();
  #define pwmB 23
  #define b1 25
  #define b2 1
  #define stby 3
  #define a1 26
  #define a2 19
  #define pwmA 18

void setup() {
  pinMode(pwmB, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(pwmA, OUTPUT);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true);
  digitalWrite(stby,1);
}
 
void loop() {
  
  mpu.update();
  unsigned int distance = sensor.getDist();
  Serial.println(distance);
  delay(50);
  
  /*Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());*/
}

void frente(){
  digitalWrite(b1,1);
  digitalWrite(b2,0);
  digitalWrite(a1,1);
  digitalWrite(a2,0);
  analogWrite(pwmB, 100);
  analogWrite(pwmA, 100);
}
void tras(){
  digitalWrite(b1,0);
  digitalWrite(b2,1);
  digitalWrite(a1,0);
  digitalWrite(a2,1);
  analogWrite(pwmB, 100);
  analogWrite(pwmA, 100);
}
void direita(){
  digitalWrite(b1,0);
  digitalWrite(b2,1);
  digitalWrite(a1,1);
  digitalWrite(a2,0);
  analogWrite(pwmB, 100);
  analogWrite(pwmA, 100);
  }
 void esquerda(){
  digitalWrite(b1,1);
  digitalWrite(b2,0);
  digitalWrite(a1,0);
  digitalWrite(a2,1);
  analogWrite(pwmB, 100);
  analogWrite(pwmA, 100);
  }
  
