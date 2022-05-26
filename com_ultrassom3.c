
int mEsquerda1 = 7;
int mEsquerda2 = 6;
int mDireita1 = 5;
int mDireita2 = 4;
int sensorE = A1;
int sensorD = A2; 

int valorE = 0;
int valorD = 0;

int vME = 9;
int vMD = 10;

const int resposta = A5;
const int pulso = 8;


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


}

void andarFrente(){
  
    digitalWrite(mEsquerda1, LOW);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, LOW);   
}

void parar(){
    digitalWrite(mEsquerda1, HIGH);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, HIGH);   
}

void direita(){
    digitalWrite(mEsquerda1, LOW);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, LOW);
    analogWrite(vME, 30);
    analogWrite(vMD, 160);
      
}

void esquerda(){
    digitalWrite(mEsquerda1, LOW);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, HIGH);
    digitalWrite(mDireita2, LOW);
    analogWrite(vMD, 30);
    analogWrite(vME, 160); 
}
long calculoDistancia(long microsseconds){
  return microsseconds / 29 / 2;
}

void loop() {
  analogWrite(vME, 100);
  analogWrite(vMD, 100);
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

  valorE = analogRead(sensorE);
  valorD = analogRead(sensorD);
 
  
   if(analogRead(sensorE<100) && analogRead(sensorD<100)){
    analogWrite(vME, 50);
    analogWrite(vMD, 50);
    andarFrente();
   } 

   if(analogRead(sensorE)>100){ 
    esquerda();
   }
   
   if(analogRead(sensorD)>100){ 
   direita();
   }

   else if(distancia<15){
   andarFrente();
   }
   
}
