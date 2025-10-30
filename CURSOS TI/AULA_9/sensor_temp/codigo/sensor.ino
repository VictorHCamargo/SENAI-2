#include <DHT.h>
#include <DHT_U.h>

float temperatura,umidade;

DHT dht(3, DHT11);

void setup() {
  Serial.begin(9600);// inicializando o monitor serial
  dht.begin();// Inicializando o sensor
}
void loop() {
  if(Serial.available()){
    char escolha = Serial.read();
    if(escolha == 'P'){
      float valor1 = lerTemperatura();
      float valor2 = lerUmidade();
      if (isnan(valor1)||isnan(valor2)) {
        Serial.print("ERRO");
      }
      Serial.print(valor1);
      Serial.print(";");
      Serial.println(valor2);
    }
  }
}
float lerTemperatura() {
  temperatura = dht.readTemperature();
  return temperatura;
}
float lerUmidade() {
  umidade = dht.readHumidity();
  return umidade;
}