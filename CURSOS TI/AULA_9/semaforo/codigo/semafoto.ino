int leds[3] = {2,3,4};
void setup(){
  Serial.begin(9600);
  for(int i =0;i<3;i++){
    pinMode(leds[i],OUTPUT);
  }
}
void loop(){
  if (Serial.available()) {
    char escolha = Serial.read();
    if (escolha == 'H') {
        for(int i =0;i<3;i++){
          digitalWrite(leds[i],LOW);
        }
        digitalWrite(leds[0],HIGH);
        delay(4000);
        digitalWrite(leds[0],LOW);
        digitalWrite(leds[1],HIGH);
        delay(2000);
        for(int i =0;i<3;i++){
          digitalWrite(leds[i],LOW);
        }
        digitalWrite(leds[2],HIGH);
        delay(3000);
    } else {
        for(int i =0;i<3;i++){
            digitalWrite(leds[i],LOW);
        }
    }
  }
}
