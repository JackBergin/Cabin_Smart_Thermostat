#include <SoftwareSerial.h>

volatile int state = LOW;
char getstr;

void setup() 
{
   
   Serial.begin(9600); 
}
void loop() 
{
   getstr = Serial.read(); 
   
   if(getstr=='1')//Sets up for 60 degrees
   {
      sixty();
   }
   else if(getstr=='2')//Sets up for 65 degrees
   {
      sixtyfive();
   }
   else if(getstr=='3')//Sets up for 70 degrees
   {
      seventy();
   }
   else if(getstr=='r')//Sets up for 75 degrees
   {
      seventyfive();
   }
   else if(getstr=='s')//Sets up for 80 degrees
   {
      eighty();
   }
}
void sixty() 
{ 
   //Put in the degrees to turn the servo. Have it reset to 0 degrees and then turn accordingly.
}
void sixtyfive()
{
   //Put in the degrees to turn the servo. Have it reset to 0 degrees and then turn accordingly.
}
void seventy()
{
   //Put in the degrees to turn the servo. Have it reset to 0 degrees and then turn accordingly.
}
void seventyfive()
{
   //Put in the degrees to turn the servo. Have it reset to 0 degrees and then turn accordingly.
}
void eighty()
{
   //Put in the degrees to turn the servo. Have it reset to 0 degrees and then turn accordingly.
}


/*
void stateChange()
{
   state = !state;
   digitalWrite(LED, state);
}
*/
