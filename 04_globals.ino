// THIS IS THE ACTUAL CODE OF THE FIRMWARE. 
// PLEASE DO NOT CHANGE THIS FILE UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!


#include "DHT.h"


int           dht1Pin;
int           dht2Pin;
int           waterPin;

float         r1;
float         r2;

float         v1;
float         v2;
float         v3;
int           water;

float         dht1Temp;
float         dht1Humid;
float         dht1Heat;
float         dht2Temp;
float         dht2Humid;
float         dht2Heat;

boolean       b[8];

unsigned long currentMillis;
unsigned long LedPreviousMillis       = 0;
unsigned long analogPreviousMillis    = 0;
unsigned long serialPreviousMillis    = 0;
unsigned long dhtPreviousMillis       = 0;
const long    analogInterval          = 1000; 
const long    LedInterval             = 500; 
const long    serialInterval          = 2500; 
const long    dhtInterval             = 2500; 


DHT dht1(dht1Pin, dht1Type);
DHT dht2(dht2Pin, dht2Type);
