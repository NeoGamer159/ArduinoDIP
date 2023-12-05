#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int myDipPins[] = {13,12,11,10,9,8,7,6};

byte readDIP(int* dipPins, int numPins)
{
  byte j = 0;
  for(int i = 0; i < numPins; i++)
  {
    if(!digitalRead(dipPins[i]))
    {
      j += 1<<(numPins-1-i);
    }
  }
  return j;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i = 0; i <= 7; i++)
  {
    pinMode(myDipPins[i], INPUT);
    digitalWrite(myDipPins[i], HIGH);
  }
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte DIPValue = readDIP(myDipPins, 8);

  switch(DIPValue)
  {
    case B00000000:
      //lcd.print("HAHA");
      break;
    case B00000001:
      //delay(60000);
      break;
    case B00000010:
      break;
    case B00000011:
    case B00000100:
      break;
    case B00000101:
      break;
    case B00000110:
      break;
    case B00000111:
      break;
    case B00001000:
      break;
    case B00001001:
      break;
    case B00001010:
  }
  delay(250);
}


