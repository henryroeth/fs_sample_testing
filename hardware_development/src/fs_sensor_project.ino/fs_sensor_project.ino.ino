#include <LiquidCrystal_I2C.h>
#include <PMS.h>
#include <SoftwareSerial.h>

//SDA = A4;
//SCL = A5;
LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial pmSerial(2,3); // RX, TX

PMS pms(pmSerial);
PMS::DATA data;

int green = 13;
int yellow = 12;
int orange = 11;
int red = 10;
int purple = 9;

void setup() 
{
  pmSerial.begin(9600);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(purple, OUTPUT);
  lcd.print("Initializing");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing...");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing...");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing...");
  delay(500);
  lcd.clear();
  lcd.print("Initializing..");
  delay(500);
  lcd.clear();
  lcd.print("Initializing.");
  delay(500);
  lcd.clear();
  lcd.print("Initializing");
  delay(500);
  lcd.clear();
}

void loop() {
  if (pms.readUntil(data)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Particulate Matter");
    Serial.println("Particulate Matter");
    lcd.setCursor(0, 1);
    lcd.print("PM1.0 : " + String(data.PM_AE_UG_1_0) + "(ug/m3)");
    Serial.println("PM1.0 : " + String(data.PM_AE_UG_1_0) + "(ug/m3)");
    lcd.setCursor(0, 2);
    lcd.print("PM2.5 : " + String(data.PM_AE_UG_2_5) + "(ug/m3)");
    Serial.println("PM2.5 : " + String(data.PM_AE_UG_2_5) + "(ug/m3)");
    lcd.setCursor(0, 3);
    lcd.print("PM10  : " + String(data.PM_AE_UG_10_0) + "(ug/m3)");
    Serial.println("PM10  : " + String(data.PM_AE_UG_10_0) + "(ug/m3)");
      //green light on
    if(data.PM_AE_UG_2_5 <= 12) {
      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(red, LOW);
      digitalWrite(purple, LOW);
    }
    //yellow light on
    if(data.PM_AE_UG_2_5 > 12 && data.PM_AE_UG_2_5 <= 35) {
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(orange, LOW);
      digitalWrite(red, LOW);
      digitalWrite(purple, LOW);
    }
    //orange light on
    if(data.PM_AE_UG_2_5 > 35 && data.PM_AE_UG_2_5 <= 55) {
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(orange, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(purple, LOW);
    }
    //red light on
    if(data.PM_AE_UG_2_5 > 55 && data.PM_AE_UG_2_5 <= 150) {
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(purple, LOW);
    }
    //purple light on
    if(data.PM_AE_UG_2_5 > 150 && data.PM_AE_UG_2_5 <= 250) {
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(red, LOW);
      digitalWrite(purple, HIGH);
    }
    //all lights on
    if(data.PM_AE_UG_2_5 > 250 && data.PM_AE_UG_2_5 <= 500) {
      digitalWrite(green, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(orange, HIGH);
      digitalWrite(red, HIGH);
      digitalWrite(purple, HIGH);
    }
    delay(3000);
  } 
}
