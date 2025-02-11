const int pinoSinal = 18; //PINO DIGITAL UTILIZADO PELO SENSOR

void setup(){
  pinMode(pinoSinal, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(pinoSinal) == LOW)
  { //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
  Serial.println("DETECTADO");
  }else
  { //SENÃO, FAZ
  Serial.println("Objeto nao detectado");
  }
}