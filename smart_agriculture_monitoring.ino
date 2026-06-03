```cpp
#include <LiquidCrystal.h>

#define pumpPin1 6
#define pumpPin2 5

int temppin = A0;
const int soilmoisturePin = A1;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    lcd.begin(16, 2);

    pinMode(soilmoisturePin, INPUT);
    pinMode(pumpPin1, OUTPUT);
    pinMode(pumpPin2, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int potStatus = analogRead(soilmoisturePin);

    int val = analogRead(temppin);
    float mv = (val / 1024.0) * 5000;
    float t = mv / 10;

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Water:");
    lcd.print(potStatus);

    Serial.print("Temp: ");
    Serial.print(t);
    Serial.println(" C");

    if (potStatus <= 200)
    {
        digitalWrite(pumpPin1, LOW);
        digitalWrite(pumpPin2, HIGH);

        Serial.print("Water level LOW, Pump ON: ");
        Serial.println(potStatus);
    }
    else
    {
        digitalWrite(pumpPin1, LOW);
        digitalWrite(pumpPin2, LOW);

        Serial.print("Water level GOOD, Pump OFF: ");
        Serial.println(potStatus);
    }

    delay(5000);
}
```
