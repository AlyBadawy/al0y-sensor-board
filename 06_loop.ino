// THIS IS THE ACTUAL CODE OF THE FIRMWARE. 
// PLEASE DO NOT CHANGE THIS FILE UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!

void loop() {
  
  currentMillis = millis();

  getAnalogMeters();
  getDhtInformation(true);
  buildSensorBits();
  updateLEDs();
  outputToSerial();

}
