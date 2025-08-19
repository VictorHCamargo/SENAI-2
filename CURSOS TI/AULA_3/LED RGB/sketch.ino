int cores[3] = {6,10,11};
void setup() {
  for(int i = 0; i<3; i++) {
    pinMode(cores[i],OUTPUT);
  }
}
void loop(){
  for(int i = 0 ; i<=255;i++){
    analogWrite(cores[0],i);
    analogWrite(cores[1],(i-100));
    analogWrite(cores[2],(i-200));
    delay(10);
  }
  for(int i = 255 ; i>=0;i--){
    analogWrite(cores[0],i);
    analogWrite(cores[1],(i-100));
    analogWrite(cores[2],(i-200));
    delay(10);
  }
}