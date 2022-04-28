
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

void setup() {
  
  Serial.begin(9600); 
  pinMode(mEsquerda1, OUTPUT);
  pinMode(mEsquerda2, OUTPUT);
  pinMode(mDireita1, OUTPUT);
  pinMode(mDireita2, OUTPUT);
  pinMode(vME, OUTPUT);
  pinMode(vMD, OUTPUT);

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

  analogWrite(vME, 120);
  analogWrite(vMD, 120);
  valorE = analogRead(sensorE);
  valorD = analogRead(sensorD);
  
   valorE = analogRead(sensorE);
   valorD = analogRead(sensorD);

   if(analogRead(sensorE)>150){
    direita();
  
   }
  
   else if(analogRead(sensorD)>150){
   esquerda();
 
   }
  
   else{
   andarFrente(); 
   }
 
}
