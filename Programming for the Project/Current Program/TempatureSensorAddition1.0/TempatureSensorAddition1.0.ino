/*
   Name: Jack Bergin
   Date: 7/26/19 - REVISED - 10/23/19
   Project: Making a smart thermostat for the cabin

   NOTES:
   --------------------------------------------------------------
   Suggestions for hardware and software: by adding a 100uF capacitor
   between 5V and GND, the capacitor will help calm the
   sudden rush you might get when the servo first starts to turn.
   --------------------------------------------------------------
   Currently this program justs allows for you to control the
   thermostat remotcontrolly via bluetooth. We could also impement
   infred to ensure workability of the program but it would be
   more of a pain in the ass to update.
   --------------------------------------------------------------
   I am going to make a seperate program to opperate the tempsensor
   and then act accordingly.
   --------------------------------------------------------------
   NEW IDEA FOR THE TEMPSENSOR:
   We can add an if inside of the selected temps that use the temp sensor
   as an auto adjust to keep the tewmpatjre constant. This can be done
   with small adjustments of 5 degrees clockwise or 5 degrees clockwise every 5 minutes
   --------------------------------------------------------------
   Querstion:
   Where should the tempsensor be put? Should it be in the room and measure room temp, 
   adjusting the baseboard based off of room temp changes or should we have two temps sensors.
   --------------------------------------------------------------
   Testing setup: ***Solution, use one and use the temp settings specified by the dial on the baseboard
   Have two temp sensors. One on the heater and one for the room temperature. 
   Measure the degree of the dial turned, record the temperature change of 
   the baseboard as well as the temperature change of the room.
*/
//Include the HC-08 library
#include <SoftwareSerial.h>

//include the servo library
#include <Servo.h>

volatile int state = LOW;
char getstr;

//create a servo object called servo1
Servo servo1;

//analog input pin constant
const int tempPin = 0;

//raw reading variable
int tempVal;

//voltage variable
float volts;

//final temperature variables
float tempC;
float tempF;

//Constant pin for the SPDT switch
const int switchPin = 3;

void setup()
{
  //Initializes the switch pins to be an input
  pinMode(switchPin, INPUT);
  //Sets up the servo to pin 9
  servo1.attach(9);
  // start the serial port at 9600 baud
  Serial.begin(9600);
}
void loop()
{

  //////////////////////////////////////////////////////////////////If the switch is pulled to the right it will choose the automation for the thermostat
  //read the temp sensor and store it in tempVal
  tempVal = analogRead(tempPin);

  //converting that reading to voltage by multiplying the reading by 3.3V (voltage of     //the 101 board)
  volts = tempVal * 3.3;
  volts /= 1023.0;

  //Converts the volts to celcius
  tempC = (volts - 0.5) * 100 ;

  //Converts from celcius to fahrenheit
  tempF = (tempC * 9.0 / 5.0) + 32.0;

  //print the fahrenheit temperature over the serial port. This acts as the debugger for the program
  Serial.print(" degrees F: ");
  Serial.println(tempF);

  //delcaring the variable for the input temp from the ble app.
  int desiredTemp = 0;


  if (getstr == 'a') //Sets up for 60 degrees
  {
    low();

    desiredTemp = 60;
    if (desiredTemp <= tempF || desiredTemp >= tempF)
    {
      low();
    }
  }
  else if (getstr == 'b') //Sets up for 65 degrees
  {
    medLow();

    desiredTemp = 65;
    if (desiredTemp <= tempF || desiredTemp >= tempF)
    {
      medLow();
    }
  }
  else if (getstr == 'c') //Sets up for 70 degrees
  {
    medium();

    desiredTemp = 70;
    if (desiredTemp <= tempF || desiredTemp >= tempF)
    {
      medium();
    }
  }
  else if (getstr == 'd') //Sets up for 75 degrees
  {
    mediumMed();

    desiredTemp = 75;
    if (desiredTemp <= tempF || desiredTemp >= tempF)
    {
      mediumMed();
    }
  }
  else if (getstr == 'e') //Sets up for 80 degrees
  {
    mediumHigh();

    desiredTemp = 80;
    if (desiredTemp <= tempF || desiredTemp >= tempF)
    {
      mediumHigh();
    }
  }
  else if (getstr == 'f')
  {
    high();
  }
  //wait a bit before taking another reading
  delay(1000);
}
//These methods are accessible to both states of the spdt switch
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
