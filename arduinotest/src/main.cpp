#include <Arduino.h>
#include <Wire.h>

int RELE = 10;
int BUTTON = 8; // Вказує до якої ноги підключені кнопка...
int button_state = 0; // Містить стан кнопки...


void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(RELE, OUTPUT);
}

void loop()
{
  button_state = digitalRead(BUTTON); // отримуєм стан піна...
  delay(50);
  if (button_state == 0)
  {
    /* code */
    
        digitalWrite(RELE, LOW);
  }
  else 
  {
    digitalWrite(RELE, HIGH);
  }


}
