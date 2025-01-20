
/* This example demonstrates how to take a standard 3-wire pressure transducer
and read the analog signal, then convert the signal to a readable output and
display it onto an LCD screen.

Contact Tyler at tylerovens@me.com if you have any questions
 */

#include "Wire.h" //allows communication over i2c devices


const int pressureInput = A1; //select the analog input pin for the pressure transducer
float pressureZero = 95; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds

float pressureValue = 0; //variable to store the value coming from the pressure transducer
float precioncero=0; 

void setup() //setup routine, runs once when system turned on or reset
{
  Serial.begin(baudRate); //initializes serial communication at set baud rate bits per second
  
  for(int i =0; i < 10; i++){
    precioncero+= analogRead(A1); 
  }
  precioncero= precioncero/10; 
  
}


void loop() //loop routine runs over and over again forever
{
  pressureValue = analogRead(pressureInput); //reads value from input pin and assigns to variable
  //pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi
  pressureValue = ((pressureValue-precioncero)*pressuretransducermaxPSI)/(pressureMax-precioncero); //conversion equation to convert analog reading to psi
  Serial.print(pressureValue, 1); //prints value from previous line to serial
  Serial.println("psi"); //prints label to serial
  //Serial.println(analogRead(pressureInput)); 
  //Serial.println(analogRead(precioncero)); 
 
  delay(sensorreadDelay); //delay in milliseconds between read values
}
