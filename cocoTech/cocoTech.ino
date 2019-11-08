#include <Ultrasonic.h>

const int m1 = 5;
const int m2 = 6;
const int dir1 = 7;
const int dir2 = 8;
const int PWM = 140;
int a = 100;
int b = 100;
const int cod1 = 3;
const int cod2 = 4;
int valorSensor1 = 0;
int valorSensor2 = 0;
int distancia;
Ultrasonic ultrasonic(13, 12);

void setup() {
 pinMode(m1, OUTPUT);
 pinMode(m2, OUTPUT);
 pinMode(dir1, OUTPUT);
 pinMode(dir2, OUTPUT);
 Serial.begin(9600);
 delay(3300);
 
 //define qual estretégia será usada
 if(digitalRead(cod1) == HIGH){
  frentao();
  }else{
    drift();   
  }
  }

void loop(){
  distancia = ultrasonic.read();
  valorSensor1 = analogRead(A0);
  valorSensor2 = analogRead(A1); 
  Serial.println(distancia);
   if(distancia < 35){   
     frente(100, 100);
   if(distancia < 25){
      frente(250, 250);
      } 
  }else{
  viradireita(80, 80);
    }
  if(valorSensor1 < 700 || valorSensor2 < 700){
  tras(100, 100); 
  delay(200);
  viradireita(100,100);
  delay(200);
  }

}

//Funções de direção
void tras(int pa, int pb){
 digitalWrite(dir1, LOW);
 digitalWrite(dir2, LOW);
 analogWrite(m1, pa);
 analogWrite(pa, pb);
}
void frente(int pa, int pb){
 digitalWrite(dir1, HIGH);
 digitalWrite(dir2, HIGH);
 analogWrite(m1, pa);
 analogWrite(m2, pb);
}
void viradireita(int pa, int pb){
 digitalWrite(dir1, HIGH);
 digitalWrite(dir2, LOW); 
 analogWrite(m1, pa);
 analogWrite(m2, pb);
}
void viraesquerda(int pa, int pb){
 digitalWrite(dir1, LOW);
 digitalWrite(dir2, HIGH); 
 analogWrite(m1, pa);
 analogWrite(m2, pb);
}
//Funções de estratégia
void drift(){
  viraesquerda(250,250);
  delay(80);
  frente(250, 110);
  delay(300);
}
void frentao(){
