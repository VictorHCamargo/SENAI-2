int led[3] = {13,12,11};

void setup() {
    for(int i = 0; i<2; i++) {
        pinMode(led[i],OUTPUT);
    }
}
void loop() {
    for(int i = 0; i<=2; i++) {
        digitalWrite(led[i],LOW);
        digitalWrite(led[0], HIGH);
    }
    delay(5000);
    for(int i = 0; i<=2; i++) {
        digitalWrite(led[i],LOW);
        digitalWrite(led[1], HIGH);
    }
    delay(1000);
    for(int i = 0; i<=2; i++) {
        digitalWrite(led[i],LOW);
        digitalWrite(led[2], HIGH);
    }
    delay(5000);
}