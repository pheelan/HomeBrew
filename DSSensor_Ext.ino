void  DSSesnorAcquire()
{

 OneWire oneWire(5); 
  // Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

 
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  //Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  delay(7500);
  //Serial.print("Temperature for Device 1 is: ");
  //Serial.println(sensors.getTempCByIndex(0)); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
    DSTemp = float(sensors.getTempCByIndex(0));
  
  }
