void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  valorlido = analogRead(ldr);
  conversao= map(valorlido,0,1023,0,100);
  Serial.print("Leitura do Sensor:");
  Serial.println(conversao);
  delay(100);
}