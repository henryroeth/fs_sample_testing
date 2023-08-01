#include <MHZ19.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define RX_PIN 2
#define TX_PIN 3
#define BAUDRATE 9600
MHZ19 myMHZ19;
SoftwareSerial mySerial(RX_PIN, TX_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  mySerial.begin(BAUDRATE);
  myMHZ19.begin(mySerial);
  myMHZ19.autoCalibration();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Detonation: 10");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 9");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 8");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 7");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 6");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 5");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 4");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 3");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 2");
  delay(1000);
  lcd.clear();
  lcd.print("Detonation: 1");
  delay(1000);
  lcd.clear();
  lcd.print("BOOM!");
  delay(1000);
  lcd.clear();
  lcd.print("Hah! Gotcha!");
  delay(1000);
  lcd.clear();
  
  

}

void loop() {
  int CO2;
  CO2 = myMHZ19.getCO2();
  lcd.clear();
  lcd.print("CO2(NDIR):");
  lcd.setCursor(0,1);
  lcd.print(CO2);
  lcd.print(" ppm");
  Serial.print("CO2(NDIR): ");
  Serial.print(CO2);
  Serial.println(" ppm");
  delay(2000);

}
