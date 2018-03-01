// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"
#include <DS1302.h>

/* initialize global TM1637 Display object
   The constructor takes two arguments, the number of the clock pin and the digital output pin:
  SevenSegmentTM1637(byte pinCLK, byte pinDIO);
*/
const byte PIN_CLK = 13;   // define CLK pin (any digital pin)
const byte PIN_DIO = 12;   // define DIO pin (any digital pin)
SevenSegmentExtended      display(PIN_CLK, PIN_DIO);


const int kCePin   = 2;  // Chip Enable
const int kIoPin   = 3;  // Input/Output
const int kSclkPin = 4;  // Serial Clock

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);


// run setup code
void setup() {
// uncomment below lines and compile - then comment and compile again
 // rtc.writeProtect(false);
//  rtc.halt(false);

 // Time t(2018, 14, 2, 19, 28, 00, Time::kWednesday);

 // rtc.time(t);

  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  delay(1000);                // wait 1000 ms
};



// run loop (forever)
void loop() {
  Time t = rtc.time();
  
  display.printTime(t.hr, t.min, false);  // display time
  delay(10000);
};
