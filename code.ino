const int motorPin = 9;
int speed;
int delayTime = 20;
#include <Wire.h>
#include "SFE_ISL29125.h"

// Declare sensor object
SFE_ISL29125 RGB_sensor;


void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.println("Sensor Initialization Successful\n\r");
  }
  // Set up the motor pin to be an output:

   pinMode(motorPin, OUTPUT);


}


void loop()
{

  // Read sensor values (16 bit integers)
  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();
  
  // Print out readings, change HEX to DEC if you prefer decimal output
  Serial.print("Red: "); Serial.println(red,DEC);
  Serial.print("Green: "); Serial.println(green,DEC);
  Serial.print("Blue: "); Serial.println(blue,DEC);
  Serial.println();

if (red > 2000)
{
  digitalWrite(motorPin,LOW);
}

 else
 {
  digitalWrite(motorPin,HIGH);
 }

  // Here we've used comments to disable some of the examples.
  // To try different things, uncomment one of the following lines
  // and comment the other ones. See the functions below to learn
  // what they do and how they work.

  // motorOnThenOff();
  // motorOnThenOffWithSpeed();
  //  motorAcceleration();
  // serialSpeed();

}


// This function turns the motor on and off like the blinking LED.
// Try different values to affect the timing.

void motorOnThenOff()
{
  int onTime = 3000;  // milliseconds to turn the motor on
  int offTime = 3000; // milliseconds to turn the motor off
  
  digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
  delay(onTime);                // delay for onTime milliseconds
  digitalWrite(motorPin, LOW);  // turn the motor off
  delay(offTime);               // delay for offTime milliseconds
}


// This function alternates between two speeds.
// Try different values to affect the timing and speed.

void motorOnThenOffWithSpeed()
{
  int Speed1 = 200;  // between 0 (stopped) and 255 (full speed)
  int Time1 = 3000;  // milliseconds for speed 1
  
  int Speed2 = 50;   // between 0 (stopped) and 255 (full speed)
  int Time2 = 3000;  // milliseconds to turn the motor off
  
  analogWrite(motorPin, Speed1);  // turns the motor On
  delay(Time1);                   // delay for onTime milliseconds
  analogWrite(motorPin, Speed2);  // turns the motor Off
  delay(Time2);                   // delay for offTime milliseconds
}


// This function slowly accelerates the motor to full speed,
// then back down to zero.

void motorAcceleration()
{
  
 // milliseconds between each speed step
  
  // accelerate the motor

  for(speed = 0; speed <= 255; speed++)
  {
    analogWrite(motorPin,speed);  // set the new speed
    delay(delayTime);             // delay between speed steps
  }
  
  // decelerate the motor

 
}








