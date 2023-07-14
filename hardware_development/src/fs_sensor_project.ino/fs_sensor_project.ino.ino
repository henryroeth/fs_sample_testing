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


void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  dht.begin();     // initialize the sensor
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight 
}

void loop()
{
  delay(2000); // wait a few seconds between measurements

  float humi  = dht.readHumidity();    // read humidity
  float tempC = dht.readTemperature(); // read temperature
  float tempF = dht.readTemperature(true);
  lcd.clear();
  // check if any reads failed
  if ((!pms.read(data)) || (isnan(humi) || isnan(tempC) || isnan(tempF))) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Failure...");
    lcd.setCursor(0,2);
    if(!pms.read(data)) {
      lcd.print("PMS Malfunction");
    }
    if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
      lcd.print("THS Malfunction");
    }
    if ((!pms.read(data)) && (isnan(humi) || isnan(tempC) || isnan(tempF))) {
      lcd.print("Total Malfunction");
    }
  } else {
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
    lcd.print("Temperature: ");
    lcd.print(tempF);
    lcd.print((char)223);
    lcd.print("F");

    lcd.setCursor(0, 3);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("PM2.5: " + String(data.PM_AE_UG_2_5) + "(ug/m3)");
  }
}
