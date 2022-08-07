/*
 * Name: Jack Bergin
 * Date: 7/26/19
 * Project: Making a smart thermostat for the cabin
 * Suggestions for hardware and software: by adding a 100uF capacitor 
 * between 5V and GND, the capacitor will help calm the 
 * sudden rush you might get when the servo first starts to turn. 
 * --------------------------------------------------------------
 * Currently this program justs allows for you to control the 
 * thermostat remotcontrolly via bluetooth. We could also impement 
 * infred to ensure workability of the program but it would be 
 * more of a pain in the ass to update.
 * --------------------------------------------------------------
 * I am going to make a seperate program to opperate the tempsensor 
 * and then act accordingly.
 */

 //We can add an if inside of the selected temps that use the temp sensor 
 //as an auto adjust to keep the tewmpatjre constant. This can be done 
 //with small adjustments of 5 degrees clockwise or 5 degrees clockwise every 5 minutes

#include <SoftwareSerial.h>
//include the servo library
#include <Servo.h>  

volatile int state = LOW;
char getstr;

//create a servo object called servo1
Servo servo1;  

void setup() 
{
   servo1.attach(9);
   Serial.begin(9600); 
}
void loop() 
{
   getstr = Serial.read(); 
   
   if(getstr=='1')//Sets up for 60 degrees
   {
      low();
   }
   else if(getstr=='2')//Sets up for 65 degrees
   {
      medLow();
   }
   else if(getstr=='3')//Sets up for 70 degrees
   {
      medium();
   }
   else if(getstr=='4')//Sets up for 75 degrees
   {
      mediumMed();
   }
   else if(getstr=='5')//Sets up for 80 degrees
   {
      mediumHigh();
   }
   else if(getstr== '6')
   {
       high();
   }
}
void low()
{
  servo1.write(0);
  delay(1000);
}
void medLow() 
{ 
  servo1.write(0);
  delay(1000);
  // Tell servo to go to 36 degrees
  servo1.write(36); 
  delay(1000);  
}
void medium()
{
  servo1.write(0);
  delay(1000);
  // Tell servo to go to 72 degrees
  servo1.write(72); 
  delay(1000); 
}
void mediumMed()
{
  servo1.write(0);
  delay(1000);
  // Tell servo to go to 108 degrees
  servo1.write(108); 
  delay(1000); 
}
void mediumHigh()
{
  servo1.write(0);
  delay(1000);
  // Tell servo to go to 144 degrees
  servo1.write(144); 
  delay(1000); 
}
void high()
{
  servo1.write(0);
  delay(1000);
  // Tell servo to go to 180 degrees
  servo1.write(180); 
  delay(1000); 
}


/* Pretty sure this acts like a pilot 
 *  program for the HC-08 and isn't required 
 *  for the program to run smoothly...
void stateChange()
{
   state = !state;
   digitalWrite(LED, state);
}
*/
