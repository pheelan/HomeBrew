
void debug() {
  // This is a debug thing
  // If LED on uC is flashing
  // the device is running
  isRunning = !isRunning;
  digitalWrite(debugPin, isRunning);
  Serial.print("Toggle PIN13");
}
