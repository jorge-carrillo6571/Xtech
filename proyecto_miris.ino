//-----------------------------Conexiones----------------------
/*Pantalla
Cs 10 
DC 9 
RES 8 
SDA 11
SCK 13
VCC 5V 
GND GND 
*/
/*SENSOR PH 
PO A0
GND GND 
VCC 5V 
*/

/*Celda de Carga 
DT 2 
SCK 3
GND GND 
VCC 5V 

*/

/*SENSOR DE PRESION 
VERDE A0 
ROJO 5V 
NEGRO GND



*/



//----------------LIBRERIAS PANTALLA ---------------------
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
//--------------------------------------------------------------------------

//VARIABLES PARA CONTADOR -----------------------------------------------




unsigned long previousMillis = 0;    
const long interval = 60000;          
int counter = 30;                     
//char segundo ; 
char segundo[10];
//--------------------------------celda de carga--------------
/*
#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
float sensor_presion= 1; 
HX711 scale;
*/
//--------------------------------------------------------------


//---------------------sensor PH-----------------------

#include <Wire.h>
//float calibration_value = 21.34; 
int phval = 0; 

int avgval; 
int buffer_arr[10],temp; 

float ph_act; 


//--------------------------sensor presion-------------


const int pressureInput = A1; //select the analog input pin for the pressure transducer
float pressureZero = 94.5; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 250; //constant integer to set the sensor read delay in milliseconds

float pressureValue = 0; //variable to store the value coming from the pressure transducer
float precioncero=0; 


void setup(void) {
  Serial.begin(57600);
  oled_setup(); 
  //celda_setup();
  Presion_loop(); 
}


void loop(void) {
  unsigned long currentMillis = millis();

    // Check if 1 second has passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last update time
    counter--;
    if(counter < 1){
      counter = 30; 
    }  
  }

  //celda_loop();
  ph_loop();
  Presion_loop(); 
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);                     // Increment the counter
  
    // Convert the counter to a string

  itoa(counter, segundo, 10);       // Convert the integer to a string

  
  //escribir_pantalla(ph_act,sensor_presion,segundo);
  escribir_pantalla(ph_act,segundo,pressureValue);
  if(counter % 5 ==0){
    Presion_loop(); 
  }
  delay(200); 
  
  
  
 
}

