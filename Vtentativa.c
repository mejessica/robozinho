
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
int pinoSensorD = 11;
int pinoSensorE = 3;
int NvoltasD=0;
int NvoltasE=0;


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
  pinMode(pinoSensorE, INPUT);
  pinMode(pinoSensorD, INPUT);
  
 
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

void velocE(){
    NvoltasE++;
    Serial.print(NvoltasE); 
    delay(500);
    
}
void velocD(){
   NvoltasD++;
   Serial.print(NvoltasD);
   Serial.print("");
   delay(500);
    
}

long calculoDistancia(long microsseconds){
  return microsseconds / 29 / 2;
}

void loop() {
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

   if(digitalRead(3)==1){
   velocD();
    
   }
   
   if(digitalRead(11)==1){
    velocE();
   }
   
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
