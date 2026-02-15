#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define button 8
int button_state = 0;
int buzzerPin = 5; //Define buzzerPin
int relePin = 12;
int fanPin = 2;
LiquidCrystal_I2C lcd(0x27, 16, 2); // адреса, колонки, рядки


void beep(unsigned char delayms) { //creating function
  analogWrite(buzzerPin, 20); //Setting pin to high
  delay(delayms); //Delaying
  analogWrite(buzzerPin, 100); //Setting pin to HIGH
  delay(delayms); //Delaying
  
}


void setup()
{

  pinMode(button, INPUT);
  Serial.begin(9600); // open the serial port at 9600 bps:

  pinMode(relePin, OUTPUT); //Set rele as output
  pinMode(fanPin, OUTPUT); //Set fan as output

  // PWM setup
    pinMode(buzzerPin, OUTPUT); //Set buzzerPin as output
  // beep(100); //Beep
  // beep(30); //Beep

  // setupLCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);       // колонка 0, рядок 0
  lcd.print("display test"); // новий текст
  delay(2000);
}

void loop()
{
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button); // read the input pin
  Serial.print("button state: ");     // prints a label
  Serial.print(button_state);         // prints a label
  Serial.print("\n");                 // prints a label
  delay(100);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(5, 0);
  if (button_state == 0)
  {
    lcd.print("ON"); // новий текст
    Serial.print("ON\n"); 
    // beep(100); //Beep
    digitalWrite(relePin, HIGH);       // Turn ON rele
    digitalWrite(fanPin, HIGH);       // Turn ON fan
  }
  else
  {
    lcd.print("OFF"); // новий текст
    Serial.print("OFF\n"); 
    digitalWrite(relePin, LOW);       // Turn OFF rele
    digitalWrite(fanPin, LOW);       // Turn OFF fan
  }
}
