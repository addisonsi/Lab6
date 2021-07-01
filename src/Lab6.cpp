/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/addisonsimon/Lab6/src/Lab6.ino"
#include "oled-wing-adafruit.h"
/*
 * Project Lab_6
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 8 "/Users/addisonsimon/Lab6/src/Lab6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
OledWingAdafruit display;
void setup() {
  // Put initialization like pinMode and begin functions here.
  display.setup();
  display.clearDisplay();
  display.display();  // cause the display to be updated
  pinMode(A4, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  display.clearDisplay();
  display.loop();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  double voltage = (analogRead(A4) * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;

  display.print("Temperature:");
  display.print((int)(temperature+0.5));
  display.println(" degrees Celsius");
  display.print("Temperature: ");
  display.print((int)(temperature*9/5 + 32 + 0.5));
  display.println(" degrees Farenheit");
  display.display();
  delay(1000);
}