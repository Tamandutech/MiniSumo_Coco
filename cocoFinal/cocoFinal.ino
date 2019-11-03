#include <Ultrasonic.h>

const int m1 = 5;
const int m2 = 6;
const int dirA = 7;
const int dirB = 8;
const int PWM = 140;
int valorSensor1 = 0;
int valorSensor2 = 0;
int distancia;
int cont =0;
unsigned long tempo = 0;
unsigned long delta = 0;

Ultrasonic ultrasonic(12, 13);

void setup() {
 pinMode(m1, OUTPUT);
 pinMode(m2, OUTPUT);
 pinMode(dirA, OUTPUT);
 pinMode(dirB, OUTPUT);
 Serial.begin(9600);
 delay(3300);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorSensor1 = analogRead(A0);
  valorSensor2 = analogRead(A1); 
  distancia = ultrasonic.read();
  
  delta = millis() + 1000;
  
  while(millis() < delta ){
    if(distancia < 25){
    break;
      }
      giro();
    }
    
   if(distancia < 25){
    atacar();
    }
    else{
      frente();
     }

  if(valorSensor1 > 700 || valorSensor2 > 700) {
    direcao();
    }      

}


void tras(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(m1, 40);
  analogWrite(m2, 40);
  delay(1000);
}

void frente(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(m1, 40);
  analogWrite(m2, 40);
}

void viradireita(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW); 
  analogWrite(m1, 60);
  analogWrite(m2, 0);
  delay(500);
}

void viraesquerda(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH); 
  analogWrite(m1, 0);
  analogWrite(m2, 60);
  delay(500);
}

void atacar(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(m1, 100);
  analogWrite(m2, 100);
}

void direcao(){
    if(valorSensor1 > valorSensor2){
      tras();
      viradireita();
      }
      else if (valorSensor1 < valorSensor2){
        tras();
        viraesquerda();
        }
        else{
          tras();
          viradireita();
        }       
  }
  
  void giro(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW); 
  analogWrite(m1, 60);
  analogWrite(m2, 0);
    }
    
