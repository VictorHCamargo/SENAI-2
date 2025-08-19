int leds[8] = {6,7,8,9,10,11,12,13};
void setup(){
  for(int i=0;i<9;i++){
    pinMode(leds[i], OUTPUT);
  }
}
void loop(){
  for(int i = 0;i<9;i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
  }
  for(int i = 0;i<9;i++) {
    digitalWrite(leds[i],LOW);
  }
}