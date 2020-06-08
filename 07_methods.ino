// THIS IS THE ACTUAL CODE OF THE FIRMWARE. 
// PLEASE DO NOT CHANGE THIS FILE UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!

float getVoltage(int v) {
    delay(100);
    float voltage = ((analogRead(v) * 4.90) / 1024.0) / (r2 / (r1 + r2)); 
    if (voltage < 0.09) { voltage = 0.0; }
    return voltage;
}

int getWater() {
    delay(100);
    return (1023 - analogRead(waterPin)); 
}

void getAnalogMeters() {
  if (currentMillis - analogPreviousMillis >= analogInterval) {
    v1 = getVoltage(v1Pin);
    v2 = getVoltage(v2Pin);
    v3 = getVoltage(v3Pin);
    water = getWater();
    analogPreviousMillis = currentMillis;
  }
}


void getDhtInformation(boolean isFahrenheit) {
  if (currentMillis - dhtPreviousMillis >= dhtInterval) {
    dht1Temp  = dht1.readHumidity();
    dht1Humid = dht1.readTemperature(isFahrenheit);
    dht2Temp  = dht1.readHumidity();
    dht2Humid = dht1.readTemperature(isFahrenheit);
    if (isnan(dht1Temp))    { dht1Temp  = 0; }
    if (isnan(dht1Humid))   { dht1Humid = 0; }
    if (isnan(dht2Temp))    { dht2Temp  = 0; }
    if (isnan(dht2Humid))   { dht2Humid = 0; }
    dht1Heat  = dht1.computeHeatIndex(dht1Temp, dht1Humid, isFahrenheit);
    dht2Heat  = dht2.computeHeatIndex(dht2Temp, dht2Humid, isFahrenheit);
    dhtPreviousMillis = currentMillis;
  }
}


void buildSensorBits() {
//  if(water >= waterMax)                                       { b[0] = true; } else { b[0] = false; }
  if(v1 >= v1Min && v1 <= v1Max)                              { b[1] = true; } else { b[1] = false; }
  if(v1 >= v1Min && v1 <= v1Max)                              { b[1] = true; } else { b[1] = false; }
  if(v1 >= v2Min && v2 <= v2Max)                              { b[2] = true; } else { b[2] = false; }
  if(v3 >= v3Min && v3 <= v3Max)                              { b[3] = true; } else { b[3] = false; }
  if(dht1Temp  >= dht1TempMin  && dht1Temp  <= dht1TempMax)   { b[4] = true; } else { b[4] = false; }
  if(dht1Humid >= dht1HumidMin && dht1Humid <= dht1HumidMax)  { b[5] = true; } else { b[5] = false; }
  if(dht2Temp  >= dht2TempMin  && dht1Temp  <= dht2TempMax)   { b[6] = true; } else { b[6] = false; }
  if(dht2Humid >= dht2HumidMin && dht1Humid <= dht2HumidMax)  { b[7] = true; } else { b[7] = false; }
  if(v1Within == false)                                       { b[1] = !(b[1]); }
  if(v2Within == false)                                       { b[2] = !(b[2]); }
  if(v3Within == false)                                       { b[3] = !(b[3]); }
  if(dht1TempWithin == false)                                 { b[4] = !(b[4]); }
  if(dht1HumidWithin == false)                                { b[5] = !(b[5]); }
  if(dht2TempWithin == false)                                 { b[6] = !(b[6]); }
  if(dht2HumidWithin == false)                                { b[7] = !(b[7]); }
}


void updateLEDs() {
  if(hardwareRevision >= 2 && (currentMillis - LedPreviousMillis >= LedInterval)) {
    LedPreviousMillis = currentMillis;
//    if (b[0] == true) { digitalWrite(rev2WaterLedPin, HIGH);}       else { digitalWrite(rev2WaterLedPin,      !digitalRead(rev2WaterLedPin)); }
    if (b[1] == true) { digitalWrite(rev2V1LedPin, HIGH); }         else { digitalWrite(rev2V1LedPin,         !digitalRead(rev2V1LedPin)); }
    if (b[2] == true) { digitalWrite(rev2V2LedPin, HIGH); }         else { digitalWrite(rev2V2LedPin,         !digitalRead(rev2V2LedPin)); }
    if (b[3] == true) { digitalWrite(rev2V3LedPin, HIGH); }         else { digitalWrite(rev2V3LedPin,         !digitalRead(rev2V3LedPin)); }
    if (b[4] == true) { digitalWrite(rev2Dht1TempLedPin, HIGH); }   else { digitalWrite(rev2Dht1TempLedPin,   !digitalRead(rev2Dht1TempLedPin)); }
    if (b[5] == true) { digitalWrite(rev2Dht1HumidLedPin, HIGH); }  else { digitalWrite(rev2Dht1HumidLedPin,  !digitalRead(rev2Dht1HumidLedPin)); }
    if (b[6] == true) { digitalWrite(rev2Dht2TempLedPin, HIGH); }   else { digitalWrite(rev2Dht2TempLedPin,   !digitalRead(rev2Dht2TempLedPin)); }
    if (b[7] == true) { digitalWrite(rev2Dht2HumidLedPin, HIGH); }  else { digitalWrite(rev2Dht2HumidLedPin,  !digitalRead(rev2Dht2HumidLedPin)); }
  }
}
