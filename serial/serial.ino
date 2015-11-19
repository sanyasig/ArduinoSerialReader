void setup(){
    Serial.begin(115200);
    Serial0.begin(115200);

    pinMode(13, OUTPUT);
}

void loop(){
    Serial.print("Hello");
    Serial.print(" ");
    Serial.println("A9!");

    digitalWrite(13, HIGH);
    delay(1000);

    Serial0.print("Hello");
    Serial0.print(" ");
    Serial0.println("world!");

    digitalWrite(13, LOW);
    delay(1000);
}
