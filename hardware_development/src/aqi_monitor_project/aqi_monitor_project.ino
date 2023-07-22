#include <Arduino.h>
#include "MHZ19.h"                                         // include main library
#include <SoftwareSerial.h>                                // Remove if using HardwareSerial or non-uno library compatable device

#define RX_PIN 2                                          // Rx pin which the MHZ19 Tx pin is attached to
#define TX_PIN 3                                          // Tx pin which the MHZ19 Rx pin is attached to
#define BAUDRATE 9600                                      // Native to the sensor (do not change)

MHZ19 myMHZ19;                                             // Constructor for MH-Z19 class
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   // Uno example
//HardwareSerial mySerial(1);                              // ESP32 Example

unsigned long getDataTimer = 0;                             // Variable to store timer interval

void setup()
{
    Serial.begin(9600);                                     // For ESP32 baudarte is 115200 etc.
    mySerial.begin(BAUDRATE);                               // Uno example: Begin Stream with MHZ19 baudrate
    //mySerial.begin(BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN); // ESP32 Example
    myMHZ19.begin(mySerial);                                // *Important, Pass your Stream reference 
    myMHZ19.autoCalibration();                              // Turn auto calibration ON (disable with autoCalibration(false))
}

void loop(){
    if (millis() - getDataTimer >= 2000)                    // Check if interval has elapsed (non-blocking delay() equivilant)
    {
        int CO2;                                            // Buffer for CO2

        /* note: getCO2() default is command "CO2 Unlimited". This returns the correct CO2 reading even 
        if below background CO2 levels or above range (useful to validate sensor). You can use the 
        usual documented command with getCO2(false) */

        CO2 = myMHZ19.getCO2();                             // Request CO2 (as ppm)
        Serial.print("CO2: ");                      
        Serial.print(CO2);   
        Serial.println(" ppm");                                                          

        getDataTimer = millis();                            // Update interval
    }
}
