int leds[11] = {3,4,5,6,7,8,9,10,11,12,13};
void setup() {
  for(int i = 0; i<12; i++){
    pinMode(leds[i],OUTPUT);
  }
}
void loop() {
  for(int i =-1;i<12;i++){
    digitalWrite(leds[i+1], HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
  }
}