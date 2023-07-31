#include "SoftwareSerial.h"
#include <SPI.h>
#include <SD.h> 
#include "MQ131.h"
 
SoftwareSerial pmsSerial(2, 3); // RX, TX
File dataFile;  
const float S_analog = 1023.0;
 
int co, nh3; 
float no2;
 
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
  delay(2000);   
  pmsSerial.begin(9600);
  dataFile = SD.open("AQI_data.csv", FILE_WRITE); 
  dataFile.println("Seconds,PM2.5(ug/m3),PM10(ug/m3),NO2(ppm),CO(ppm)");
  dataFile.close(); 
}
 
struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
 
struct pms5003data data;
uint16_t line = 1; 

void loop() {
  dataFile = SD.open("AQI_data.csv", FILE_WRITE);
  co = map (analogRead(A0), 0, S_analog, 1, 1000);
  nh3 = map (analogRead(A1), 0, S_analog, 1, 500); 
  no2 = (map (analogRead(A2), 0, S_analog, 5, 1000)) / 100.0 ;
  if (readPMSdata(&pmsSerial)) {
    delay(1000);
    Serial.print("PM1.0: "); Serial.print(data.pm10_standard); Serial.println("(ug/m3)");
    Serial.print("PM2.5: "); Serial.print(data.pm25_standard); Serial.println("(ug/m3)");
    Serial.print("PM10: "); Serial.print(data.pm100_standard); Serial.println("(ug/m3");
    Serial.print("NO2: "); Serial.print(no2); Serial.println("(ppm)");
    Serial.print("CO: "); Serial.print(co); Serial.println("(ppm)");

    dataFile.print(line++);
    dataFile.print(",");
    dataFile.print(data.pm25_standard);
    dataFile.print(",");
    dataFile.print(data.pm100_standard);
    dataFile.print(",");
    dataFile.print(no2);
    dataFile.print(",");
    dataFile.println(co);
  }
  dataFile.close();
}

boolean readPMSdata(Stream *s) {
  if (! s->available()) {
    return false;
  }
  
  // Read a byte at a time until we get to the special '0x42' start-byte
  if (s->peek() != 0x42) {
    s->read();
    return false;
  }
 
  // Now read all 32 bytes
  if (s->available() < 32) {
    return false;
  }
    
  uint8_t buffer[32];    
  uint16_t sum = 0;
  s->readBytes(buffer, 32);
 
  // get checksum ready
  for (uint8_t i=0; i<30; i++) {
    sum += buffer[i];
  }
 
  /* debugging
  for (uint8_t i=2; i<32; i++) {
    Serial.print("0x"); Serial.print(buffer[i], HEX); Serial.print(", ");
  }
  Serial.println();
  */
  
  // The data comes in endian'd, this solves it so it works on all platforms
  uint16_t buffer_u16[15];
  for (uint8_t i=0; i<15; i++) {
    buffer_u16[i] = buffer[2 + i*2 + 1];
    buffer_u16[i] += (buffer[2 + i*2] << 8);
  }
 
  // put it into a nice struct :)
  memcpy((void *)&data, (void *)buffer_u16, 30);
 
  if (sum != data.checksum) {
    Serial.println("Checksum failure");
    return false;
  }
  // success!
  return true;
}
