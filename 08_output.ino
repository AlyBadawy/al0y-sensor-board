// THIS IS THE ACTUAL CODE OF THE FIRMWARE. 
// PLEASE DO NOT CHANGE THIS FILE UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!

/*
Output data:
  ---------------------
  The output of this firmware is on the streamed on the Serial port every 2000ms
  In the format:

  **Rev**FW**$V1:xxx~V2:xxx~V3:xxx$**$DHT1Temp:yyy~DHT1Humid:yyy~DHT1Heat:yyy~DHT2Temp:yyy~DHT2Humid:yyy~DHT2Heat:yyy$**Water:zzz**Bits:b1b2b3b4b5b6b7b8**
  Where:
    - Rev will be replaced by the board hardware revision number (ie: 1.0, 2.0, etc)
    - FW will be replaced by the firware version (ie: 1.0.3)
    - xxx are a float value for the voltage read at V1, V2, and V3 (Rev1: Solar, Battery, and PS respectively)
    - yyy are the readings of the tow DHT11 sensrors referred to as (DHT1 and DHT2) where the DHT1T refers
      to the temprature of the sensor 1, DHT1H refers to the humidity of sensor 1, and DHT1I referes to the heat index
      for sensor 1.. 
      DHT2T, DHT2H, and DHT2I refere to the temprature, humidity, and heat index (respectively) of sensor 2
    - zzz is value between (0-1023) that refers to the resistance between the two probes of the water
      sensor. (the less resistance means the more water on the probes)
    - b1..b8 are binary value of for the customizable conditions (refer to 03_customization) as:
      b2: A binary value for the water probe
      b3: A binary value for the V1 probe
      b4: A binary value for the V2 probe
      b5: A binary value for the V3 probe
      b6: A binary value for the DHT1T probe
      b7: A binary value for the DHT1H probe
      b7: A binary value for the DHT2T probe
      b8: A binary value for the DHTtH probe
*/

void outputToSerial() {
  if(hardwareRevision >= 2 && (currentMillis - serialPreviousMillis >= serialInterval)) {
    serialPreviousMillis = currentMillis;
    Serial.print("**REV");
    Serial.print(hardwareRevision);
    Serial.print("**FW");
    Serial.print(fwVersion);
    Serial.print("**$");
    Serial.print("V1:");
    Serial.print(v1);
    Serial.print("~");
    Serial.print("V2:");
    Serial.print(v2);
    Serial.print("~");
    Serial.print("V3:");
    Serial.print(v3);
    Serial.print("$**$DHT1Temp:");
    Serial.print(dht1Temp);
    Serial.print("~DHT1Humid:");
    Serial.print(dht1Humid);
    Serial.print("~DHT1Heat:");
    Serial.print(dht1Heat);
    Serial.print("~$DHT2Temp:");
    Serial.print(dht2Temp);
    Serial.print("~DHT2Humid:");
    Serial.print(dht2Humid);
    Serial.print("~DHT2Heat:");
    Serial.print(dht2Heat);
    Serial.print("$**$Water:");
    Serial.print(water);
    Serial.print("$**Bits:");
    for(int i = 0; i <8; i++) { Serial.print(b[i]); }
    Serial.println("**");
  }
}
