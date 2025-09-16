#include <DHT.h>
#include <DHT_U.h>

int led[3] = {11,12,13};
DHT dht(3,DHT11);
float temperatura;
void setup() {
  for(int i = 0;i<3;i++) {
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000);
  temperatura = dht.readTemperature();
  if(isnan(temperatura)) {
    Serial.println("Erro  no sensor");
  } else {
    Serial.println(temperatura);
    if(temperatura >= 25) {
      Serial.println("Está calor");
      for(int i = 0;i<3;i++){
        digitalWrite(led[i],LOW);
      }
      digitalWrite(led[2],HIGH);
    } else if (temperatura < 25 && temperatura >= 23) {
      Serial.println("Está agrádavel");
      for(int i = 0;i<3;i++){
        digitalWrite(led[i],LOW);
      }
      digitalWrite(led[1],HIGH);
    } else if(temperatura <23) {
      Serial.println("Está frio");
      for(int i = 0;i<3;i++){
        digitalWrite(led[i],LOW);
      }
      digitalWrite(led[0],HIGH);
    }
  }
}