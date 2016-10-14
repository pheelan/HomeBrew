/*Logs raw data....
   Uses time stamp raw data only
   Logs A0 to A3
   May be easily expanded
*/

void aquireDataForLogging() {

  // A0 Ethanol
  // A1 C02
  // A2 Analog Temp

  // make a string that start with a timestamp for assembling the data to log:
  String dataString;


  dataString = dataString + getTimeStamp();
  dataString = dataString + " = ";

  // read three sensors and append to the string:

ethanolValue = analogRead(ethanol);
cO2Value = analogRead(cO2);
analogTempValue = analogRead(analogTemp);
analogTempValue = analogTempValue * 500; // Convert to Celsius
analogTempValue = analogTempValue / 1023; // Convert to Celsius
analogTempValue = analogTempValue * .738;  // "Calibration Factor"

//Serial.println(ethanolValue);
//Serial.println(cO2Value);
//Serial.println(analogTempValue);

dataString += String(ethanolValue);
dataString += "; ";
dataString += String(cO2Value);
dataString += "; ";
dataString += String(analogTempValue);
dataString += "; ";
dataString += String(intTH[0]); //Internal Temperature
dataString += "; ";
dataString += String(intTH[1]); // Internal Humidity
dataString += "; ";
dataString += String(DSTemp);   // External Temperature

Console.println(dataString);




  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  // The FileSystem card is mounted at the following "/mnt/FileSystema1"
  //File dataFile = FileSystem.open("/mnt/sd/datalog.txt", FILE_APPEND);
  File dataFile = FileSystem.open("/mnt/sd/EMLog.txt", FILE_APPEND);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Console.println("SD Card Logging : ");
    Console.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Console.println("error opening datalog.txt");
  }

}


// This function return a string with the time stamp
String getTimeStamp() {
  String result;
  Process time;
  // date is a command line utility to get the date and the time
  // in different formats depending on the additional parameter
  time.begin("date");
  time.addParameter("+%D-%T");  // parameters: D for the complete date mm/dd/yy
  //             T for the time hh:mm:ss
  time.run();  // run the command

  // read the output of the command
  while (time.available() > 0) {
    char c = time.read();
    if (c != '\n') {
      result += c;
    }
  }

  return result;

}

