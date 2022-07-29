#include <Servo.h>
#include<Keypad.h>
Servo ServoMotor;

char* password = "189";
//You can change the Passowr
int position = 0;
int flag=0;
int sensorValue;
int pirSensor = 12;
int buzzer = 13;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Create two variables for LED Lights
void setup()
{

  ServoMotor.attach(11);
  LockedPosition(true);
  pinMode(pirSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.println("give key");
  char key = keypad.getKey();
  if (key == '7')
  {
    Serial.println(key);
    position = 0;
    LockedPosition(true);
  }
  if (key == password[position])
  {
    Serial.println(key);
    position ++;
  }
  if (position == 3)
  {
    LockedPosition(false);
  }
  while (flag) {
    Serial.println("While");
    int sensorValue = digitalRead(pirSensor);
    if (sensorValue == 0)
    {
      Serial.println("Motion1");
      tone(buzzer, 1000);
      delay(5000);
      noTone(buzzer);
      flag = 0;
    }
    else
    {
      Serial.println(" no Motion2");
    }
  }
  flag =0;

  delay(100);
}
void LockedPosition(int locked)
{
  if (locked)
  {
    flag = 1;
    ServoMotor.write(30);
    Serial.println(flag);
  }
  else
  {
    int i,j;
    
    //flag = 0;
    for (i=30;i<=130;i++)
    {
      ServoMotor.write(i);
      delay(5);
    }
    delay(500);
    position = 0;
    for (j=i;j>=30;j--)
    {
      ServoMotor.write(j);
      delay(5);
    }
    
  }
}
