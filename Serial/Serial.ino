#include <SoftwareSerial.h>
SoftwareSerial BT(4,5);//TX y RX

int bomba=10;
int ledV=9;
int ledA=8;
int ledR=7;
int hum_suelo;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(bomba, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  
}

void loop() {
  
  if(Serial.available())
    BT.write(Serial.read());  
  
  hum_suelo = analogRead(A0);
  BT.print("Porcentaje de humedad: ");
  hum_suelo = map(hum_suelo,1023,0,0,100);
  BT.print(hum_suelo);
  BT.println("%");
  delay(4000);

  if(hum_suelo < 30){
    BT.println("Nivel de Humedad: BAJO");
    digitalWrite(ledR, HIGH);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    digitalWrite(bomba, HIGH);
    delay(6000);
  }
  else if((hum_suelo >= 30) && (hum_suelo < 60)){
    BT.println("Nivel de humedad: MEDIO");
    digitalWrite(ledR, LOW);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledV, LOW);
    digitalWrite(bomba, HIGH);
    delay(3000);
  }
  else if (hum_suelo >= 60){
    BT.println("Nivel de Humedad: OPTIMO");
    digitalWrite(ledR, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, HIGH);
    digitalWrite(bomba, LOW);
  }
  
}
