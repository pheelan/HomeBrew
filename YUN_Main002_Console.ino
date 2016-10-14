// DHT Temperature & Humidity Sensor

#include <Process.h>
#include <Console.h>
#include <FileIO.h>
#include "ThingSpeak.h"
#include "BridgeClient.h"
#include <SPI.h>
#include <String.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"

BridgeClient client;


// Use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long shortMillis = 0;
unsigned long longMillis = 0;
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#define DHTTYPE DHT11   // DHT 11
#define ONE_WIRE_BUS 5  //Connect Temp sensor to pin 5

const int DHTPIN = 2;     // Internal temperature/humidity digital pin

// Loop times in milli-seconds
 long shortInterval = 60000;         // 60 seconds, fast loop to SD Card
 long longInterval = 600000;          // 10 minute, logging data loop

//const long shortInterval = 1000;            // 1 second, fast loop
//const long longInterval = 30000;            // 10 seconds, ethernet logging data loop

DHT dht(DHTPIN, DHTTYPE);

boolean       isRunning = 0;
const int     debugPin = 13;                // Pin13 on Arduino has LED attached, this is toggled in "loop", should blink on board if everything running in loop
const int     ethanol = A0;
const int     cO2 = A1;
const int     analogTemp = A2;
const int EthState = 7;                   // Pin 7 Starts or Stops the Ethenol Sensor, Hign is ON (Default)
const int CO2State = 8;                   // Pin 8 Starts or Stops the CO2 Sensor, High is ON (Default)

int           ethanolValue = 0;
int           cO2Value = 0;
float         analogTempValue = 0;
float         intTH[] = {0, 0};           // Array to store digital T&H, Temp = [0], Hum = [1]
float         DSTemp = 0;

char          SerialRead = 'a';           // Initial state 'a' activates all sensors (These are set by default later anyway

unsigned long myChannelNumber = 165003;
const char * myWriteAPIKey = "C2YAZ85A7AL3ZK2X";

void setup() {
  Bridge.begin();
  Console.begin();
  FileSystem.begin();
  dht.begin();

  pinMode(EthState, OUTPUT);
  digitalWrite(EthState, HIGH);
  pinMode(CO2State, OUTPUT);
  digitalWrite(CO2State, HIGH);
  // Initial state is to start both sensors

  ThingSpeak.begin(client);
}

void loop() {

  SensorState();

  unsigned long currentMillis = millis();

  // SHORT loop
  // Place SD logging here
  if (currentMillis - shortMillis >= shortInterval) {
    shortMillis = currentMillis;
    DHTSensorAcquire();
    DSSesnorAcquire();
    aquireDataForLogging();
    debug();
  }
  // End of SHORT loop


  // LONG loop
  // Place WIFI logging here
  if (currentMillis - longMillis >= longInterval) {
    longMillis = currentMillis;

    writeToExternal();

  }
  // End of LONG loop
}
