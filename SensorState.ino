void SensorState()
{

  // Character String to Start/Stop the Ethanol or CO2 sensors
  // Char a Starts all Sensors
  // Char e Start Eth Sensor
  // Char c Start CO2 Sensor
  // Char y Stop Eth Sensor
  // Char z Stop CO2 Sensor
  // Char x Stops all Sensors
  // Char 1 runs fast loop 
  // Char 2 runs slow loop
  

  SerialRead = Console.read();


  if (SerialRead == 'e') {
    digitalWrite(EthState, HIGH);
    Console.println("Key Pressed 'e' : EthState is ON");
  }
  else if (SerialRead == 'c') {
    digitalWrite(CO2State, HIGH);
    Console.println("Key Pressed 'c' : CO2State is ON");
  }
  else if (SerialRead  == 'y') {
    digitalWrite(EthState, LOW);
    Console.println("Key Pressed 'y' : EthState is OFF");
  }
  else if (SerialRead == 'z') {
    digitalWrite(CO2State, LOW);
    Console.println("Key Pressed 'z' : CO2State is ON");
  }
  else if (SerialRead == 'a') {
    digitalWrite(EthState, HIGH);
    digitalWrite(CO2State, HIGH);
    Console.println("Key Pressed 'a' : CO2State & EthState are ON");
  }
  else if (SerialRead == 'x') {
    digitalWrite(EthState, LOW);
    digitalWrite(CO2State, LOW);
    Console.println("Key Pressed 'x' : CO2State & EthState are OFF");
  }
  else if (SerialRead == '1') {
    shortInterval = 10000;
    longInterval = 60000;
    Console.println("Key Pressed '1' : Short loop set to 10sec, long loop set to 1min");
  }
  else if (SerialRead == '2') {
    shortInterval = 60000;
    longInterval = 600000;
    Console.println("Key Pressed '2' : Short loop set to 60sec, long loop set to 10min");
  }


}

