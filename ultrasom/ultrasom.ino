#define trigger 5
#define echo 4
void trigPulse();
float pulse;
float distCM;
void setup() {
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
 digitalWrite(trigger, LOW); 
 Serial.begin(9600);
}
void loop() {
  trigPulse();
  pulse = pulseIn(echo, HIGH);
  //distCM = pulse/58.82;
  Serial.println(pulse);
  delay(500);
}
void trigPulse(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  }
