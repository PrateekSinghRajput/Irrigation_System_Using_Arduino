//Prateek
//www,prateeks.in

#include <Wire.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int m;
int percentage;
int Greenled = 6;
int Redled = 5;
int Relay = 4;
int map_low = 1023;
int map_high = 280;
void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(Greenled, OUTPUT);
  pinMode(Redled, OUTPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite (Relay, HIGH);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("JustDoElectronic");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Irrigation Systm");
  lcd.setCursor(0, 1);
  lcd.print("Pump=");
  lcd.setCursor(10, 1);
  lcd.print("M= ");

}

void loop() {
  int m = analogRead(A0);
  Serial.println(m);
  percentage = map(m, map_low, map_high, 0, 100);
  lcd.setCursor(10, 1);
  lcd.print("M= ");
  if (percentage > 100)
  {
    percentage = 100;
  }
  lcd.setCursor(12, 1);
  lcd.print(percentage);
  lcd.print ("%");
  lcd.print ("  ");
  delay(200);
  if (m >= 780)
  {
    digitalWrite(Greenled, HIGH);
    lcd.setCursor(6, 1); // column, row
    lcd.print("ON ");
    digitalWrite (Relay, HIGH);
    digitalWrite (Redled, LOW);

  }

  else if (m <= 770)

  {
    digitalWrite(Greenled, LOW);
    lcd.setCursor(6, 1);
    lcd.print("OFF");
    digitalWrite (Relay, LOW);
    digitalWrite (Redled, HIGH);
  }
}
