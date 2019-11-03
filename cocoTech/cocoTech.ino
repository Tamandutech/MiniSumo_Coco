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
  }

void loop(){
   

  if(digitalRead(cod1)==1&&digitalRead(cod2)==0){
  while(true){
  retao();
  } 
 }
  else if(digitalRead(cod1)==0&&digitalRead(cod2)==1){
  while(true){
  gira();
  }
  }
  else{
    while(true){
    retao();
  }
  }

}


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



void direcao(){
 if(valorSensor1 > valorSensor2){
  tras(a, b);
  delay(200);
  viradireita(a, 0);
  delay(500);
 }
      
 else if (valorSensor1 < valorSensor2){
  tras(a, b);
  viraesquerda(0, b);
 }
    
 else{
  tras(a, b);
  viradireita(a, 0);
 }       
}

void retao(){
   recarrega();
   Serial.println(distancia);
   if(distancia < 25){   
     frente(100, 100);
     if(distancia < 14){
      frente(200, 200);
      }
  }
  //refletancia - quando for colocar no tatame, inverter sinais
  if(valorSensor1 < 500 || valorSensor2 < 500){
  tras(100, 100); 
  viradireita(100,100);
  }
  frente(100, 100);
  }

  void gira(){
  recarrega();
  if(distancia < 25){   
     frente(100, 100);
    Serial.print("Frente");
  }else if(distancia < 14){
    frente(200, 200);
    }else{
  viradireita(100, 100);
  }
  //refletancia - quando for colocar no tatame, inverter sinais
  if(valorSensor1 < 500 || valorSensor2 < 500){
  tras(100, 100); 
  delay(500);
  viradireita(100,100);
  delay(500);
  }
  }

  void recarrega(){
  distancia = ultrasonic.read();
  valorSensor1 = analogRead(A0);
  valorSensor2 = analogRead(A1); 
  frente(100, 100); 
    }
  
