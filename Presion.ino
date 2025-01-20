
/* This example demonstrates how to take a standard 3-wire pressure transducer
and read the analog signal, then convert the signal to a readable output and
display it onto an LCD screen.

Contact Tyler at tylerovens@me.com if you have any questions
 */

//#include "Wire.h" //allows communication over i2c devices



void Presion_setup() //setup routine, runs once when system turned on or reset
{
  Serial.begin(baudRate); //initializes serial communication at set baud rate bits per second
  
  for(int i =0; i < 10; i++){
    pressureZero+= analogRead(A1); 
  }
  pressureZero= pressureZero/10; 
  
}


void Presion_loop() //loop routine runs over and over again forever
{
  pressureValue = analogRead(pressureInput); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); //conversion equation to convert analog reading to psi
  //pressureValue = ((pressureValue-precioncero)*pressuretransducermaxPSI)/(pressureMax-precioncero); //conversion equation to convert analog reading to psi
  Serial.print(pressureValue, 1); //prints value from previous line to serial
  Serial.println("psi"); //prints label to serial
  //Serial.println(analogRead(pressureInput)); 
 
  delay(sensorreadDelay); //delay in milliseconds between read values
}
