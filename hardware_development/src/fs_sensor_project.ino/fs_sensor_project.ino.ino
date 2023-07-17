#include <PMS.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "SoftwareSerial.h"
#define DHTPIN 2
#define DHTTYPE DHT22

SoftwareSerial Serial1(3, 4); // RX, TX
 
PMS pms(Serial1);
PMS::DATA data;

LiquidCrystal_I2C lcd(0x27, 20, 4);  
DHT dht(DHTPIN, DHTTYPE); 

int green = 13;
int yellow = 12;
int orange = 11;
int red = 10;
int purple = 9;

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  dht.begin();    
  lcd.init();      
  lcd.backlight(); 
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(purple, OUTPUT); 
}

void loop()
{
  delay(2000); 

  float humi  = dht.readHumidity();    
  float tempC = dht.readTemperature(); 
  float tempF = dht.readTemperature(true);
  int pm25 = data.PM_AE_UG_2_5;
  //green light on
  if(pm25 <= 12) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(red, LOW);
    digitalWrite(purple, LOW);
  }
  //yellow light on
  if(pm25 > 12 && pm25 <= 35) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(orange, LOW);
    digitalWrite(red, LOW);
    digitalWrite(purple, LOW);
  }
  //orange light on
  if(pm25 > 35 && pm25 <= 55) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(purple, LOW);
  }
  //red light on
  if(pm25 > 55 && pm25 <= 150) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(purple, LOW);
  }
  //purple light on
  if(pm25 > 150 && pm25 <= 250) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(red, LOW);
    digitalWrite(purple, HIGH);
  }
  //all lights on
  if(pm25 > 250 && pm25 <= 500) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(orange, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(purple, HIGH);
  }
  lcd.clear();
  // check if any reads failed
  if ((!pms.read(data)) && (!isnan(humi) || !isnan(tempC) || !isnan(tempF))) {  
    lcd.setCursor(0, 0);
    lcd.print("Sensor failure...");
    lcd.setCursor(0,1);
    lcd.print("PMS malfunction!");
    lcd.setCursor(0,2);
    lcd.print("For maintenance call");
    lcd.setCursor(0,3);
    lcd.print("5407509530.");
  }
  if ((isnan(humi) || isnan(tempC) || isnan(tempF)) && (pms.read(data))) {  
    lcd.setCursor(0, 0);
    lcd.print("Sensor failure...");
    lcd.setCursor(0,1);
    lcd.print("THS malfunction!");
    lcd.setCursor(0,2);
    lcd.print("For maintenance call");
    lcd.setCursor(0,3);
    lcd.print("5407509530.");
  }
  if ((!pms.read(data)) && (isnan(humi) || isnan(tempC) || isnan(tempF))) {  
    lcd.setCursor(0, 0);
    lcd.print("Sensor failure...");
    lcd.setCursor(0,1);
    lcd.print("All sensors!");
    lcd.setCursor(0,2);
    lcd.print("For maintenance call");
    lcd.setCursor(0,3);
    lcd.print("5407509530.");
  }
  if ((pms.read(data)) && (!isnan(humi) && !isnan(tempC) && !isnan(tempF))) {
    //serial monitor data
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.println("%");
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
    //LCD data
    lcd.setCursor(0, 0);
    lcd.print("Indoor Environment");
    lcd.setCursor(0, 1);
    
    lcd.setCursor(0, 2);
    lcd.print("Temp: ");
    lcd.print(round(10 * tempC) / 10);
    lcd.print((char)223);
    lcd.print("C  ");
    lcd.print(round(10 * tempF) / 10);
    lcd.print((char)223);
    lcd.print("F");

    lcd.setCursor(0, 3);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("PM2.5: " + String(pm25) + "(ug/m3)");
  }
}
