#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address 0x3F, 16 column and 2 rows
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
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
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.println("%");
    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");

    lcd.setCursor(0, 2);  // start to print at the first row
    lcd.print("Temperature: ");
    lcd.print(tempF);     // print the temperature
    lcd.print((char)223); // print ° character
    lcd.print("F");

    lcd.setCursor(0, 3);  // start to print at the second row
    lcd.print("Humidity: ");
    lcd.print(humi);      // print the humidity
    lcd.print("%");
  }
}
