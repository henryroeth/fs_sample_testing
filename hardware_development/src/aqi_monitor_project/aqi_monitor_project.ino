#include <Arduino.h>
#include "MHZ19.h"                                         // include main library
#include <SoftwareSerial.h> 
#include <SPI.h>
#include <SD.h>   
#include <MQ131.h>  
// #include <C401_Steam_Air_MQ131_O3.h>                      // Remove if using HardwareSerial or non-uno library compatable device

#define RX_PIN 2                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 3                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600                                      // Native to the sensor (do not change)

File dataFile;
MHZ19 myMHZ19;                                             // Constructor for MH-Z19 class
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   // Uno example
//HardwareSerial mySerial(1);                              // ESP32 Example

                            // Variable to store timer interval

void setup()
{
  Serial.begin(115200);
  pmsSerial.begin(9600);
  while (!Serial)
  ; // wait for serial port to connect. Needed for native USB port only
  Serial.print("Initializing SD card...");
  if (!SD.begin()) 
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);                                  // For ESP32 baudarte is 115200 etc. 
    dataFile = SD.open("AQI_data.csv", FILE_WRITE); 
    dataFile.println("Elapsed Time(minutes),PM2.5(ug/m3),PM10(ug/m3)");
    dataFile.close();                            // Turn auto calibration ON (disable with autoCalibration(false))
}

uint16_t line = 1;
void loop(){

  dataFile = SD.open("AQI_data.csv", FILE_WRITE);                                          

  if(dataFile) {
    delay(60000);
    byte CO2 = myMHZ19.getCO2();                             
    Serial.print("CO2: ");                      
    Serial.print(CO2);   
    Serial.println(" ppm"); 
    Serial.print("O3: ");
    Serial.print(MQ131.getO3(PPM));
    Serial.println(" ppm");
    
    dataFile.print(line++);
    dataFile.print(",");
    dataFile.print(CO2);
    dataFile.print(",");
    dataFile.println(MQ131.getO3(PPM));
    dataFile.close();
 
  } else {
    Serial.println("error opening AQI_data.csv");
  }                         
}
