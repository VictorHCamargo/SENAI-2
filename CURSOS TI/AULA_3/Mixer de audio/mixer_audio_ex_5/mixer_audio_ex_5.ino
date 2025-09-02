int leds[4] = {10,11,12,13};
int pot = 0;
int valor;
float mapeado;
void setup(){
  for(int i=0;i<4;i++){
    pinMode(leds[i], OUTPUT);
  }
}
void loop(){
  valor = analogRead(pot);
  mapeado = map(float(valor),1024,0,255,0);
  if(mapeado <= 0){
    for(int i=0;i<4;i++){
      digitalWrite(leds[i], LOW);
    }
  } else if(mapeado <= 50 && mapeado > 0) {
    for(int i=0;i<4;i++){
      digitalWrite(leds[i], LOW);
      digitalWrite(leds[0], HIGH);
    }
  } else if(mapeado <= 125 && mapeado > 50) {
    for(int i=0;i<2;i++){
      digitalWrite(leds[i], HIGH);
    }
    for(int i=2;i<4;i++){
      digitalWrite(leds[i], LOW);
    }
  } else if(mapeado <= 200 && mapeado > 125) {
    for(int i=0;i<4;i++){
      digitalWrite(leds[i], HIGH);
    }
    digitalWrite(leds[3],LOW);
  } else if(mapeado <= 255 && mapeado > 200) {
    for(int i=0;i<4;i++){
      digitalWrite(leds[i], HIGH);
    }
  }
}