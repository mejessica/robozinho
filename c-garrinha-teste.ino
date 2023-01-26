
#include <Servo.h>

int mEsquerda1 = 7;
int mEsquerda2 = 6;
int mDireita1 = 5;
int mDireita2 = 4;
int sensorE = A1;
int sensorD = A0; 
int valorE = 0;
int valorD = 0;
int vME = 9;
int vMD = 10;
const int resposta = A5;
const int pulso = 8;
const int pinoServo = 3;

Servo s;
int pos;

void setup() {
  
  Serial.begin(9600); 
  pinMode(mEsquerda1, OUTPUT);
  pinMode(mEsquerda2, OUTPUT);
  pinMode(mDireita1, OUTPUT);
  pinMode(mDireita2, OUTPUT);
  pinMode(vME, OUTPUT);
  pinMode(vMD, OUTPUT);
  pinMode(pulso, OUTPUT);
  pinMode(resposta, INPUT);

  s.attach(pinoServo);
  s.write(0);

}

void andarFrente(){
  
    digitalWrite(mEsquerda1, HIGH);
    digitalWrite(mEsquerda2, LOW);
    digitalWrite(mDireita1, LOW);
    digitalWrite(mDireita2, HIGH);   
}

void parar(){
    digitalWrite(mEsquerda1, HIGH);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, HIGH);   
}

void direita(){
    digitalWrite(mEsquerda1, HIGH);
    digitalWrite(mEsquerda2, LOW);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, HIGH);  
}

void esquerda(){
    digitalWrite(mEsquerda1, HIGH);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, LOW);
    digitalWrite(mDireita2, HIGH); 
}

long calculoDistancia(long microsseconds){
  return microsseconds / 29 / 2;
}

void loop() {
  
  for(pos=0; pos<180; pos++){
  s.write(pos);
  delay(15);  
  }
  delay(1000);
  for(pos=180;pos>=0;pos--){
    s.write(pos);
    delay(15);  
  }

  analogWrite(vME, 120);
  analogWrite(vMD, 120);
  valorE = analogRead(sensorE);
  valorD = analogRead(sensorD);
  
  long duracao,distancia;

  digitalWrite(pulso, LOW);
  delayMicroseconds(2);
  digitalWrite(pulso, HIGH);
  delayMicroseconds(5);
  digitalWrite(pulso, LOW);

  duracao = pulseIn(resposta, HIGH);
  distancia = calculoDistancia(duracao);

  Serial.print(distancia);
  Serial.println("cm");
  Serial.println();

   if(analogRead(sensorE)<150 && analogRead(sensorD)<150){
    andarFrente();
   }

   if(analogRead(sensorE)>150){
    direita();
   } 
   
   if(distancia<15){
   parar(); 
   }
  
   else if(analogRead(sensorD)>150){
   esquerda();
   }
   
 
}
