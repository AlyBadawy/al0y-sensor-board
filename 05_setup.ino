// THIS IS THE ACTUAL CODE OF THE FIRMWARE. 
// PLEASE DO NOT CHANGE THIS FILE UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!





void setup() {
  if(hardwareRevision == 2) {
    dht1Pin  = rev2Dht1DataPin;
    dht2Pin  = rev2Dht2DataPin;
    waterPin = rev2WaterProbePin;
    r1 = rev2R1;
    r2 = rev2R2;  
    pinMode(rev2V1LedPin , OUTPUT); 
    pinMode(rev2V2LedPin , OUTPUT); 
    pinMode(rev2V3LedPin , OUTPUT); 
    pinMode(rev2WaterLedPin , OUTPUT); 
    pinMode(rev2Dht1TempLedPin, OUTPUT); 
    pinMode(rev2Dht1HumidLedPin, OUTPUT); 
    pinMode(rev2Dht2TempLedPin, OUTPUT); 
    pinMode(rev2Dht2HumidLedPin, OUTPUT); 
  } else if(hardwareRevision == 1) {
    dht1Pin  = rev1Dht1DataPin;
    dht2Pin  = rev1Dht2DataPin;
    waterPin = rev1WaterProbePin;
    r1 = rev1R1;
    r2 = rev1R2;
  } else {
    while(1); // do nothing.
  }
  pinMode(dht1Pin, INPUT);
  pinMode(dht2Pin, INPUT);
  pinMode(waterPin, INPUT);

  Serial.begin(9600);
  delay(2000);
  
  Serial.println("AL0Y's sensor board.");
  Serial.println("Initialized....");
  Serial.println("");

  
}
