#include <LiquidCrystal.h>
int leds[3] = {10,9,8};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char valor;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  for(int i = 0;i<=2;i++){
    pinMode(leds[i],OUTPUT);
  }
}
void escrever(String mensagem1,String mensagem2) {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(mensagem1);
  lcd.setCursor(3, 1);
  lcd.print(mensagem2);
}
void loop() {
  if(Serial.available()>0){
    char valor = Serial.read();
    switch (tolower(valor)){
      case 'r':
        escrever("LED VERMELHO","ON");
        for(int i = 0;i<=2;i++){
          digitalWrite(leds[i],LOW);
        }
        digitalWrite(leds[0],HIGH);
        break;
      case 'y':
        escrever("LED AMARELO","ON");
        for(int i = 0;i<=2;i++){
          digitalWrite(leds[i],LOW);
        }
        digitalWrite(leds[1],HIGH);
        break;
      case 'g':
        escrever("LED VERDE","ON");
        digitalWrite(leds[0],LOW);
        digitalWrite(leds[1],LOW);
        digitalWrite(leds[2],HIGH);
        break;
      default:
        break;
    }
  }
  
}
