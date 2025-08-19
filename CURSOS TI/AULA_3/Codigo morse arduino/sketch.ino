int led = 13;
String frase = "FALAGALERA";
String alfabeto[27] = {
  ".-",    // A
  "-...",  // B
  "-.-.",  // C
  "-..",   // D
  ".",     // E
  "..-.",  // F
  "--.",   // G
  "....",  // H
  "..",    // I
  ".---",  // J
  "-.-",   // K
  ".-..",  // L
  "--",    // M
  "-.",    // N
  "---",   // O
  ".--.",  // P
  "--.-",  // Q
  ".-.",   // R
  "...",   // S
  "-",     // T
  "..-",   // U
  "...-",  // V
  ".--",   // W
  "-..-",  // X
  "-.--",  // Y
  "--..",  // Z
};
String letras= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  for(int i=0;i<frase.length();i++){
    char letra = frase[i];
    int letra_musical = letras.indexOf(letra);
    String frase_musical = alfabeto[letra_musical];

    for(int i = 0;i<frase_musical.length();i++){
      char letra_morse = frase_musical[i];
      if(letra_morse == '.') {
        digitalWrite(led, HIGH);
        delay(250);
        digitalWrite(led, LOW);
        delay(250);
      } else if(letra_morse == '-'){
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      }
    }
    delay(500);
  }
}