#include <Servo.h>

#define motorEsteira 6
#define sensor 5

//Instanciando os servo motores
Servo servoBase;
Servo servoGarra;
Servo servoTronco;
Servo servoPonta;

int i, j; //variáveis globais para controle dos laços de repetição

//Funções de movimentação
void inicializaServos(int iniBase, int iniGarra, int iniTronco, int iniPonta);
void movimento3();

void setup()
{
  //Definindo as portas nas quais os servo motores serão conectados
  servoBase.attach(12);
  servoGarra.attach(11);
  servoTronco.attach(9);
  servoPonta.attach(10);
  //Chamada da função para setar a posição inicial de cada motor
  inicializaServos(0, 0, 50, 30); //posição inicial

  Serial.begin(9600);
}

void loop() {
  //Meramente para leitura do sensor via monitor serial 
  Serial.println(sensor);
  Serial.println("#####################");
  
  Serial.println("Motor: ");
  for(i=60; i<=130; i+=5){
    analogWrite(motorEsteira, i);
    Serial.println(motorEsteira);
  }

  if(digitalRead(sensor)==0){
    //delay(200);
    analogWrite(motorEsteira, 0);
    movimento3();
    delay(1000);
  }

}

//Inicialização das posições dos servo motores
void inicializaServos(int iniBase, int iniGarra, int iniTronco, int iniPonta){
  int posAtual; 
  Serial.println("Posicionando Servos...");
  posAtual = servoBase.read(); //guardando na variavel posAtual a posição do motor da base
  //verifica se a posição atual é maior que a posição que se deseja setar
  //Se verdadeiro, o laço for se encarrega de ajustar a posição do motor de forma decrescente
  //Caso contrário, se menor, o laço ajusta a posição de forma crescente
  if(posAtual > iniBase){
    for(i=posAtual; i>=iniBase; i--){
      servoBase.write(i);
      delay(30);
    }
  }
  if(posAtual < iniBase){
    for(i=posAtual; i<=iniBase; i++){
      servoBase.write(i);
      delay(30);
    }
  }
  delay(100);

  //reatribui posAtual com a posição do novo motor e verifica se a posição atual é maior que a posição que se deseja setar
  //Se verdadeiro, o laço for se encarrega de ajustar a posição do motor de forma decrescente
  //Caso contrário, se menor, o laço ajusta a posição de forma crescente
  posAtual = servoGarra.read();
  if(posAtual > iniGarra){
    for(i=posAtual; i>=iniGarra; i--){
      servoGarra.write(i);
      delay(30);
    }
  }
  if(posAtual < iniGarra){
    for(i=posAtual; i<=iniGarra; i++){
      servoGarra.write(i);
      delay(30);
    }
  }
  delay(100);

  //reatribui posAtual com a posição do novo motor e verifica se a posição atual é maior que a posição que se deseja setar
  //Se verdadeiro, o laço for se encarrega de ajustar a posição do motor de forma decrescente
  //Caso contrário, se menor, o laço ajusta a posição de forma crescente
  posAtual = servoTronco.read();
  if(posAtual > iniTronco){
    for(i=posAtual; i>=iniTronco; i--){
      servoTronco.write(i);
      delay(30);
    }
  }
  if(posAtual < iniTronco){
    for(i=posAtual; i<=iniTronco; i++){
      servoTronco.write(i);
      delay(30);
    }
  }
  delay(100);
  
  //reatribui posAtual com a posição do novo motor e verifica se a posição atual é maior que a posição que se deseja setar
  //Se verdadeiro, o laço for se encarrega de ajustar a posição do motor de forma decrescente
  //Caso contrário, se menor, o laço ajusta a posição de forma crescente
  posAtual = servoPonta.read();
  if(posAtual > iniPonta){
    for(i=posAtual; i>=iniPonta; i--){
      servoPonta.write(i);
      delay(30);
    }
  }
  if(posAtual < iniPonta){
    for(i=posAtual; i<=iniPonta; i++){
      servoPonta.write(i);
      delay(30);
    }
  }
  delay(100);
}

//Movimentação
void movimento3(){
  Serial.println("Realizando movimento 3...");
  inicializaServos(0, 25, 0, 0); 
  inicializaServos(0, 0, 0, 0); 
  inicializaServos(45, 0, 55, 30);
  inicializaServos(90, 0, 0, 10); 
  inicializaServos(90, 25, 50, 10); 
  inicializaServos(90, 0, 50, 10); 
  inicializaServos(90, 0, 50, 10); 
  inicializaServos(45, 0, 55, 30);
  inicializaServos(0, 0, 50, 30); 
  
}