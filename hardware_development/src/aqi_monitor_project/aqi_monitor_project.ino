#include <Arduino.h>
#include "MHZ19.h"                                         // include main library
#include <SoftwareSerial.h> 
#include <SPI.h>
#include <SD.h>                               // Remove if using HardwareSerial or non-uno library compatable device

#define RX_PIN 2                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 3                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600                                      // Native to the sensor (do not change)

File dataFile;
MHZ19 myMHZ19;                                             // Constructor for MH-Z19 class
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   // Uno example
//HardwareSerial mySerial(1);                              // ESP32 Example

unsigned long getDataTimer = 0;                             // Variable to store timer interval

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  ; // wait for serial port to connect. Needed for native USB port only
  Serial.print("Initializing SD card...");
  if (!SD.begin()) 
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  delay(2000);                                     // For ESP32 baudarte is 115200 etc.
    mySerial.begin(BAUDRATE);                               // Uno example: Begin Stream with MHZ19 baudrate
    myMHZ19.begin(mySerial);                                // *Important, Pass your Stream reference 
    myMHZ19.autoCalibration(); 
    dataFile = SD.open("AQI_data.txt", FILE_WRITE); 
    dataFile.println("Elapsed Time(seconds),CO2(ppm)");
    dataFile.close();                            // Turn auto calibration ON (disable with autoCalibration(false))
}

uint16_t line = 1;
void loop(){
  int CO2; 
  dataFile = SD.open("AQI_data.txt", FILE_WRITE);                                          

  if(dataFile) {
    byte CO2 = myMHZ19.getCO2();                             
    Serial.print("CO2: ");                      
    Serial.print(CO2);   
    Serial.println(" ppm"); 
    
    dataFile.print(line++);
    dataFile.print(",");
    dataFile.println(CO2);
    dataFile.close();

    delay(1000);   
  } else {
    Serial.println("error opening AQI_data.txt");
  }                         
}
