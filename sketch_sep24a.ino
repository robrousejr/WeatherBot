#include <LiquidCrystal.h>
#include "LedControl.h"
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
LedControl lc=LedControl(5,2,3,1);
unsigned long delaytime=500;
int i = 0; 
void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);

Serial.begin(9600); // set the baud rate
Serial.println("Ready"); // print "Ready" once

}
void loop() {
char inByte;
if(Serial.available()){ // only send data back if data has been sent
inByte = Serial.read(); // read the incoming data
if(inByte == '?'){
  lcd.clear();
  i = 0;
  }else{
    if(inByte == '&'){
      byte l[8]={B11110111,B00000000,B11101111,B00000000,B11011111,B00000000,B10111111,B00000000};

  lc.setRow(0,0,l[0]);
  lc.setRow(0,1,l[1]);
  lc.setRow(0,2,l[2]);
  lc.setRow(0,3,l[3]);
  lc.setRow(0,4,l[4]);
  lc.setRow(0,5,l[5]);
  lc.setRow(0,6,l[6]);
  lc.setRow(0,7,l[7]);
      }
     if(inByte == '$'){
  byte k[8]={B11111111,B10000001,B10100101,B10000001,B10100101,B10111101,10000001,B11111111};

  lc.setRow(0,0,k[0]);
  lc.setRow(0,1,k[1]);
  lc.setRow(0,2,k[2]);
  lc.setRow(0,3,k[3]);
  lc.setRow(0,4,k[4]);
  lc.setRow(0,5,k[5]);
  lc.setRow(0,6,k[6]);
  lc.setRow(0,7,k[7]);
      }if(inByte == '_'){
  byte i[]={B00010000,B01001010,B00000000,B10101010,B00000000,B10101001,B00000100,B10101001};
  byte j[]={B10101001,B00100000,B00000010,B00101000,B10000010,B00100000,B01001000,B00100001};

  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  lc.setRow(0,5,i[5]);
  lc.setRow(0,6,i[6]);
  lc.setRow(0,7,i[7]);
  delay(delaytime);

  lc.setRow(0,0,j[0]);
  lc.setRow(0,1,j[1]);
  lc.setRow(0,2,j[2]);
  lc.setRow(0,3,j[3]);
  lc.setRow(0,4,j[4]);
  lc.setRow(0,5,j[5]);
  lc.setRow(0,6,j[6]);
  lc.setRow(0,7,j[7]);
  delay(delaytime);
        }
        if(inByte == '@'){
           byte a[8]={B00000000,B00000000,B00011000,B00100100,B00100100,B00011000,B00000000,B00000000};
  byte b[8]={B00010000,B00100000,B00011000,B00100100,B00100100,B00011000,B00000000,B00000000};
  byte c[8]={B00010000,B00100000,B00011010,B00100101,B00100100,B00011000,B00000000,B00000000};
  byte d[8]={B00010000,B00100000,B00011010,B00100101,B00100100,B00011000,B00000100,B00001000};
  byte e[8]={B00010000,B00100000,B00011010,B00100101,B10100100,B01011000,B00000100,B00001000};

  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  lc.setRow(0,5,a[5]);
  lc.setRow(0,6,a[6]);
  lc.setRow(0,7,a[7]);
  delay(delaytime);

  
  lc.setRow(0,0,b[0]);
  lc.setRow(0,1,b[1]);
  lc.setRow(0,2,b[2]);
  lc.setRow(0,3,b[3]);
  lc.setRow(0,4,b[4]);
  lc.setRow(0,5,b[5]);
  lc.setRow(0,6,b[6]);
  lc.setRow(0,7,b[7]);
  delay(delaytime);

  
  lc.setRow(0,0,c[0]);
  lc.setRow(0,1,c[1]);
  lc.setRow(0,2,c[2]);
  lc.setRow(0,3,c[3]);
  lc.setRow(0,4,c[4]);
  lc.setRow(0,5,c[5]);
  lc.setRow(0,6,c[6]);
  lc.setRow(0,7,c[7]);
  delay(delaytime);

  
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  lc.setRow(0,5,d[5]);
  lc.setRow(0,6,d[6]);
  lc.setRow(0,7,d[7]);
  delay(delaytime);

  
  lc.setRow(0,0,e[0]);
  lc.setRow(0,1,e[1]);
  lc.setRow(0,2,e[2]);
  lc.setRow(0,3,e[3]);
  lc.setRow(0,4,e[4]);
  lc.setRow(0,5,e[5]);
  lc.setRow(0,6,e[6]);
  lc.setRow(0,7,e[7]);
  delay(delaytime);

          }if(inByte == '^'){
             byte f[8]={B01000000,B01000000,B00000000,B00010000,B00010000,B00000000,B00000010,B00000010};
  byte g[8]={B01000100,B01000000,B00010010,B00010010,B00000000,B00100000,B00100010,B10000010};
  byte h[8]={B00010010,B10010010,B10000000,B00101010,B00100010,B00000000,B10000100,B10010100};

  lc.setRow(0,0,f[0]);
  lc.setRow(0,1,f[1]);
  lc.setRow(0,2,f[2]);
  lc.setRow(0,3,f[3]);
  lc.setRow(0,4,f[4]);
  lc.setRow(0,5,f[5]);
  lc.setRow(0,6,f[6]);
  lc.setRow(0,7,f[7]);
  delay(delaytime);

  lc.setRow(0,0,g[0]);
  lc.setRow(0,1,g[1]);
  lc.setRow(0,2,g[2]);
  lc.setRow(0,3,g[3]);
  lc.setRow(0,4,g[4]);
  lc.setRow(0,5,g[5]);
  lc.setRow(0,6,g[6]);
  lc.setRow(0,7,g[7]);
  delay(delaytime);

  lc.setRow(0,0,h[0]);
  lc.setRow(0,1,h[1]);
  lc.setRow(0,2,h[2]);
  lc.setRow(0,3,h[3]);
  lc.setRow(0,4,h[4]);
  lc.setRow(0,5,h[5]);
  lc.setRow(0,6,h[6]);
  lc.setRow(0,7,h[7]);
  delay(delaytime);
            }if(inByte == '>'){
  byte m[8]={B10000110,B01001001,B10000111,B00000000,B00000000,B01100011,B10010010,B11100001};
  byte n[8]={B00100010,B00100011,B11000000,B00011000,B00100100,B00111000,B00000011,B11000100};

  lc.setRow(0,0,m[0]);
  lc.setRow(0,1,m[1]);
  lc.setRow(0,2,m[2]);
  lc.setRow(0,3,m[3]);
  lc.setRow(0,4,m[4]);
  lc.setRow(0,5,m[5]);
  lc.setRow(0,6,m[6]);
  lc.setRow(0,7,m[7]);
  delay(delaytime);

  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  lc.setRow(0,5,n[5]);
  lc.setRow(0,6,n[6]);
  lc.setRow(0,7,n[7]);
  delay(delaytime);

  lc.setRow(0,0,m[0]);
  lc.setRow(0,1,m[1]);
  lc.setRow(0,2,m[2]);
  lc.setRow(0,3,m[3]);
  lc.setRow(0,4,m[4]);
  lc.setRow(0,5,m[5]);
  lc.setRow(0,6,m[6]);
  lc.setRow(0,7,m[7]);
  delay(delaytime);

  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  lc.setRow(0,5,n[5]);
  lc.setRow(0,6,n[6]);
  lc.setRow(0,7,n[7]);
  delay(delaytime);
              }
Serial.println(inByte); // send the data back in a new line so that it is not all one long line
lcd.print(inByte);
i++;
if(i > 15){
  lcd.setCursor(0,1);
  i = 0;
  }
delay(100); // delay for 1/10 of a second
  }
 }
}
