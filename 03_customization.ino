/*
Use this file to customize the minimum and maximum readings to turn on and off the binary sensor bits.
In hardware revesion2.0, this also lights up the corrosponding LED lights.

 the xxxxx_within variables are used to define whether a sensor bit (and corrosponding LED) should be on
 if the value is within thge specified range (set to true) or outside of the range (set to false)
*/

// shows values in Fahrenheit. fasle for celcius. 
   boolean isFahrenheit = true;  
// boolean isFahrenheit = false;  

// Uncomment whatever type you're using!
   #define dht1Type DHT11   // DHT 11
   #define dht2Type DHT11   // DHT 11
// #define dht1Type DHT21   // DHT 21
// #define dht2Type DHT21   // DHT 21
// #define dht1Type DHT22   // DHT 22
// #define dht2Type DHT22   // DHT 22




const float   v1Min           = 12.0;
const float   v1Max           = 15.0;
const boolean v1Within        = true; // Define if you want the sensor bits (and LED) on if value is within defined range (true) or out of range (false)

const float   v2Min           = 11.0;
const float   v2Max           = 15.0;
const boolean v2Within        = true;

const float   v3Min           = 18.0;
const float   v3Max           = 24.0;
const boolean v3Within        = true;


const float   dht1TempMin     = 40.0;
const float   dht1TempMax     = 75.0;
const boolean dht1TempWithin  = true;  

const float   dht1HumidMin    = 0.0;
const float   dht1HumidMax    = 40.0;
const boolean dht1HumidWithin = true; 

const float   dht2TempMin     = 10.0;
const float   dht2TempMax     = 40.0;
const boolean dht2TempWithin  = true;

const float   dht2HumidMin    = 0.0;
const float   dht2HumidMax   = 40.0;
const boolean dht2HumidWithin = true;

const int     waterMax        = 900; // the maximum value of resistance below which consider that water is present.
