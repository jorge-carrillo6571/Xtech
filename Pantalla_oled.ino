void oled_setup(void) {
  u8g2.begin();
}
void floatToString(char* buffer, float number, int decimals) {
  dtostrf(number, 6, decimals, buffer);
}
//void escribir_pantalla (float ph, float presion,const char* numero){
void escribir_pantalla(float ph, char* numero, float presion){
  char buffer[10];  // Buffer to hold the converted number
  char buffer2[10]; 
  floatToString(buffer, ph, 2);
  floatToString(buffer2, presion,2); 
  //floatToString(buffer2,presion,2);
  //sprintf(buffer, "%f", ph);
  //sprintf(buffer2, "%f", presion);

  
  u8g2.clearBuffer();               // Clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "pH: "); // Choose a suitable font
  u8g2.drawStr(25, 10, buffer);
  u8g2.drawStr(0,30,"Psi: "); 
  u8g2.drawStr(55,30,buffer2); 

  //u8g2.drawStr(0, 30, "Presion: "); // Choose a suitable font
  //u8g2.drawStr(55, 30, buffer2);
  u8g2.drawStr(0, 50, "Servicio en:");    // Draw the label
  u8g2.drawStr(70, 50, numero);

  u8g2.sendBuffer(); 


}


