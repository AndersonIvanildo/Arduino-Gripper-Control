#include <Arduino.h>
#include <Servo.h>

//Instanciando os servo motores
Servo servoBase;
Servo servoGarra;
Servo servoTronco;
Servo servoPonta;

int i, j; //variáveis globais para controle dos laços de repetição

//Funções de movimentação
void inicializaServos(int iniBase, int iniGarra, int iniTronco, int iniPonta);
void movimento1();
void movimento2();
void movimento3();

void setup()
{
  //Definindo as portas nas quais os servo motores serão conectados
  servoBase.attach(12);
  servoGarra.attach(11);
  servoTronco.attach(9);
  servoPonta.attach(10);

  //Chamada da função para setar a posição inicial de cada motor
  inicializaServos(0, 0, 70, 0); //posição inicial

  Serial.begin(9600);
}

void loop() {

  //Meramente para leitura das posições via monitor serial 
  Serial.println(servoBase.read());
  Serial.println(servoGarra.read());
  Serial.println(servoTronco.read());
  Serial.println(servoPonta.read());
  Serial.println("#####################");

  //Chamada das funções de movimentação
  movimento1();
  delay(300);
  movimento2();
  delay(300);
  movimento3();
  delay(300);
  
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
  }else if(posAtual < iniBase){
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
  }else if(posAtual < iniGarra){
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
  }else if(posAtual < iniTronco){
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
  }else if(posAtual < iniPonta){
    for(i=posAtual; i<=iniPonta; i++){
      servoPonta.write(i);
      delay(30);
    }
  }
  delay(100);
}

//Movimentação 1
void movimento1(){
  Serial.println("Realizando movimento 1...");
  for(j = 0; j<90; j++){ //Gira a base em 90 graus
    servoBase.write(j);
    delay(30);
  }
  delay(100);
  for(j = 0; j<80; j++){ //desce a ponta do braço em 80 graus
    servoPonta.write(j);
    delay(30);
  }
  delay(100);
  for(j = 0; j<35; j++){ //Abre a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 70; j>30; j--){ //desloca o braço para frente
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 35; j>0; j--){ //Fecha a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 80; j>0; j--){ //sobe a ponta do braço 
    servoPonta.write(j);
    delay(30);
  }
  delay(100);
  for(j = 30; j<70; j++){ //desloca o braço pra trás
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 90; j>0; j--){ //rotaciona a base de volta a posição original
    servoBase.write(j);
    delay(30);
  }
  delay(100);
  for(j = 70; j>30; j--){ //leva o braço pra frente
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 0; j<35; j++){//abre a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 35; j>0; j--){//fecha a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 30; j<70; j++){//trás o braço de volta
    servoTronco.write(j);
    delay(30);
  }
}

//Definição do movimento 2
void movimento2(){
  Serial.println("Realizando movimento 2...");
  inicializaServos(0, 0, 70, 0); //Seta a posição inicial do braço
  delay(100);
  for(j = 0; j<80; j++){ //desce a ponta do braço
    servoPonta.write(j);
    delay(30);
  }
  delay(100);
  for(j = 0; j<35; j++){ //abre a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 70; j>30; j--){ //leva o braço pra frente
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 35; j>0; j--){ //fecha a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 80; j>0; j--){ //sobe a ponta do braço
    servoPonta.write(j);
    delay(30);
  }
  delay(100);
  for(j = 30; j<70; j++){ //trás de volta o braço
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 90; j>0; j--){ //rotaciona a base em direção ao local de descarte
    servoBase.write(j);
    delay(30);
  }
  delay(100);
  for(j = 70; j>30; j--){ //leva o braço pra frente
    servoTronco.write(j);
    delay(30);
  }
  delay(100);
  for(j = 0; j<35; j++){ //abre a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 35; j>0; j--){ //fecha a garra
    servoGarra.write(j);
    delay(30);
  }
  delay(100);
  for(j = 30; j<70; j++){ //trás de volta o braço
    servoTronco.write(j);
    delay(30);
  }
}

//Função de movimentação simplificada (sugestão pra ser a oficial)
void movimento3(){
  Serial.println("Realizando movimento 3...");
  inicializaServos(0, 0, 70, 0); //Seta a posição inicial do braço

  inicializaServos(90, 0, 70, 80); //gira a base, e desce a ponta do braço
  inicializaServos(90, 35, 20, 80); //abre a garra, leva o braço pra frente
  inicializaServos(90, 0, 20, 0); //fecha a garra, sobe a ponta do braço
  inicializaServos(90, 0, 70, 0); //leva o braço pra trás
  inicializaServos(0, 0, 20, 0); //gira a base pra posição inicial, leva o braço pra frente
  inicializaServos(0, 35, 20, 0); //abre a garra
  inicializaServos(0, 0, 70, 0); //fecha a garra, leva o braço pra trás
}
