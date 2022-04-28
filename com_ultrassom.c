
int mEsquerda1 = 7;
int mEsquerda2 = 6;
int mDireita1 = 5;
int mDireita2 = 4;
int sensorE = A1;
int sensorD = A0; 
int valorE = 0;
int valorD = 0;
const int resposta = A5;
const int pulso = 8;

void setup() {
  
  Serial.begin(9600); 
  pinMode(mEsquerda1, OUTPUT);
  pinMode(mEsquerda2, OUTPUT);
  pinMode(mDireita1, OUTPUT);
  pinMode(mDireita2, OUTPUT);
  pinMode(pulso, OUTPUT);
  pinMode(resposta, INPUT);

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
    digitalWrite(mDireita2, LOW);  
}

void esquerda(){
    digitalWrite(mEsquerda1, LOW);
    digitalWrite(mEsquerda2, HIGH);
    digitalWrite(mDireita1, LOW);
    digitalWrite(mDireita2, HIGH); 
}


void loop() {
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

  delay(100);
  
    analogWrite(9,90);
    analogWrite(10,90);
      
    valorE = analogRead(sensorE);
    valorD = analogRead(sensorD);


   if(analogRead(sensorE)>150){
    direita();
  
   }
  
   else if(analogRead(sensorD)>150){
   esquerda();
 
   }
   
   else if (distancia<15){
   parar();
   delay(3000);
    
   }
  
   else{
   andarFrente(); 
   }
 
}

long calculoDistancia(long microsseconds){
  return microsseconds / 29 / 2;
}
