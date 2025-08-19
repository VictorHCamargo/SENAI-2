int leds[4] = {3,4,5,6};
void setup() {
  Serial.begin(9600);
  for(int i = 0;i<9;i++) {
    pinMode(leds[i],OUTPUT);
    digitalWrite(leds[i],LOW);
  }
}

void loop() {
  for(int i =0;i<16;i++) {
    delay(1000);
    switch(i){
      case 1:
        digitalWrite(leds[0], HIGH);
        break;
      case 2:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        break;
      case 3:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        break;
      case 4:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        break;
      case 5:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        break;
      case 6:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        break;
      case 7:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        break;
      case 8:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        break;
      case 9:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        break;
      case 10:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        break;
      case 11:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        break;
      case 12:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
        break;
      case 13:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
        break;
      case 14:
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
        break;
      case 15:
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
        break;
      default:
        for(int l =0;l<9;l++){
          digitalWrite(leds[l],LOW);
        }
        break;
    }
  }
}
