#include <Servo.h> // include Servo library
  
Servo servo2; // horizontal servo

  
Servo servo1; // vertical servo

// LDR pin connections
// name = analogpin;
int ldrlt = A0; //LDR top left
int ldrrt = A1; //LDR top rigt
int ldrld = A2; //LDR down left
int ldrrd = A3; //ldr down rigt
  
void setup()
{
Serial.begin(9600);
// servo connections
// name.attacht(pin);
servo2.attach(9);
servo1.attach(10);

  servo1.writeMicroseconds(1475);
  
  servo2.writeMicroseconds(1475);
}
  
void loop()
{
int lt = analogRead(ldrlt); // top left
int rt = analogRead(ldrrt); // top right
int ld = analogRead(ldrld); // down left
int rd = analogRead(ldrrd); // down rigt

int tol = 1;
  
int avt = (lt + rt)*10 ; // average value top
int avd = (ld + rd)*10 ; // average value down
int avl = (lt + ld)*10 ; // average value left
int avr = (rt + rd)*10 ; // average value right
  
int ver = avt - avd; // check the diffirence of up and down
int hor = avl - avr;// check the diffirence og left and rigt
int dvert=abs(ver);
int dhoriz=abs(hor);
 Serial.print("1. ");
Serial.println(avt);
delay(1000);
Serial.print("2. ");
Serial.println(avd);
delay(1000);
 Serial.print("3. ");
Serial.println(avl);
delay(1000);
 Serial.print("4. ");
Serial.println(avr);
delay(1000);
  Serial.print("ver. ");
Serial.println(dvert);
delay(1000);
 Serial.print("hor ");
Serial.println(dhoriz);
delay(1000);
  
if ( dvert > tol)
{
if (avt < avd)
{

      servo1.writeMicroseconds(1515);
      delay(42);
      servo1.writeMicroseconds(1475);
      delay(200);
}
else if (avt > avd)
{

     servo1 .writeMicroseconds(1425);
     delay(24);
     servo1.writeMicroseconds(1475);
     delay(100);
}

}
if (  dhoriz > tol)
{
if (avl >avr)
{
      servo2.writeMicroseconds(1515);
      delay(42);
      servo2.writeMicroseconds(1475);
      delay(100); 
}
else if (avl < avr)
{
servo2.writeMicroseconds(1425);
     delay(24);
     servo2.writeMicroseconds(1475);
     delay(100);

}
}
}


