#include <Arduino.h>
#define clockPin1 10		// clock on pin 10
#define clockPin2 11		// clock on pin 11
#define latchPin 9			// latch on pin 9
#define data1 	8			// display 00:xx
#define data2	7			// display xx:00

byte A;
byte B;
byte C;
byte D;
int firsts = 0;
int lasts = 0;
byte firsts_formatted;
byte lasts_formatted;

byte toHex(int tmp);
void format();
void disp(int D, int B);

void setup(){
  pinMode(clockPin1, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(latchPin, OUTPUT); 
  pinMode(data1, 	OUTPUT);
  pinMode(data2, 	OUTPUT);
}

void loop(){
  while(lasts < 10){
    if(firsts==100){
      lasts++;
      firsts=0;
    }
    
    format();
    disp(lasts_formatted, firsts_formatted);
    delay(10);
    firsts++;
  }
  lasts = 0;
}

byte toHex(int tmp){  
  switch (tmp){
    case 0:
    	tmp = tmp<<4;
    	break;
    case 1:
    	tmp = 0x1;
    	break;
    case 2:
    	tmp = 0x2;
    	break;
    case 3:
    	tmp = 0x3;
    	break;
    case 4:
    	tmp = 0x4;
    	break;
    case 5:
    	tmp = 0x5;
    	break;
    case 6:
    	tmp = 0x6;
    	break;
    case 7:
    	tmp = 0x7;
    	break;
    case 8:
    	tmp = 0x8;
    	break;
    case 9:
    	tmp = 0x9;
    	break;
    default:
    	break;
    return tmp;
  }  
}

void format(){
  A = firsts / 10;
  B = firsts % 10;
  C = lasts / 10;
  D = lasts % 10;
  int tmp1 = toHex(A);
  int tmp2 = toHex(B);
  int tmp3 = toHex(C);
  int tmp4 = toHex(D);
  firsts_formatted = (tmp1<<4)|tmp2;
  lasts_formatted = (tmp3<<4)|tmp4;
}

void disp(int D, int B){
  digitalWrite(latchPin, LOW); 
  shiftOut(data1, clockPin1, MSBFIRST, B);
  shiftOut(data2, clockPin2, MSBFIRST, D); 
  digitalWrite(latchPin, HIGH);
}
