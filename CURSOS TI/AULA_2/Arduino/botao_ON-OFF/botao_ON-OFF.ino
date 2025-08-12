int botao = 7;
int led = 8;
bool estadobotao;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}
void loop() {
  if(digitalRead(botao) || estadobotao == true) {
    estadobotao = !digitalRead(botao);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led,LOW);
  }
}