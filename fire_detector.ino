int pirSensor = 12;
int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pirSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = digitalRead(pirSensor);
  Serial.println("While");
  if (sensorValue == 0)
  {
    Serial.println("Fire");
    tone(buzzer, 1000);
    delay(5000);
    noTone(buzzer);

  }
  else
  {
    Serial.println("No fire");
  }

}
