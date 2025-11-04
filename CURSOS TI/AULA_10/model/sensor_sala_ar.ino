#include <Servo.h>

#include <DHT.h>
#include <DHT_U.h>

#define sensorPir1 8
#define sensorPir2 7
DHT dht1(4,DHT11);
DHT dht2(5,DHT11);
Servo motorAr;
void setup() {
  motorAr.attach(6);
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
}

void loop() {
  if(Serial.available()){
    char command = Serial.read();
    switch (command) {
      case '1':
        Serial.print(leituraTemp(dht1));
        Serial.print(";");
        Serial.println(leituraSensor(sensorPir1));
        break;
      case '2':
        Serial.print(leituraTemp(dht2));
        Serial.print(";");
        Serial.println(leituraSensor(sensorPir2));
        break;
      case 'l':
      case 'L':
        motorAr.write(180);
        delay(200);
        motorAr.write(-180);
        break;
      case 'd':
      case 'D':
        motorAr.write(180);
        delay(200);
        motorAr.write(-180);
        break;
    }
  }
}
float leituraTemp(DHT dht) {
  if(isnan(dht.readTemperature()) == 1){
    return -1;
  }
  return dht.readTemperature();
}
int leituraSensor(int pino){
  return digitalRead(pino);
}
