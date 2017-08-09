#include <Servo.h>

Servo servo1;
Servo servo2;
int ldrlt = 0; //LDR sol üst
int ldrrt = 1; //LDR sağ üst
int ldrld = 2; //LDR sol alt
int ldrrd = 3;




void setup() 
{
  servo1.attach(9);
  servo1.writeMicroseconds(1475);
  servo2.attach(10);
  servo2.writeMicroseconds(1475);

Serial.begin(9600);



}

void loop() 
{
  int lt = analogRead(ldrlt); // sol üst
int rt = analogRead(ldrrt); // sağ üst
int ld = analogRead(ldrld); // sol alt
int rd = analogRead(ldrrd); // sağ alt
int avt = (lt + rt) ; // average value top
int avd = (ld + rd) ; // average value down
int dn1=  (lt + ld);
int dn2=  (rt + rd);
 
 Serial.print("1. ");
Serial.println(avt);
delay(1000);
Serial.print("2. ");
Serial.println(avd);
delay(1000);
 Serial.print("3. ");
Serial.println(dn1);
delay(1000);
 Serial.print("4. ");
Serial.println(dn2);
delay(1000);

  if (avt<avd)
  {
    
      servo1.writeMicroseconds(1515);
      delay(42);
      servo1.writeMicroseconds(1475);
      delay(200);
      
    
  }
  else if (avt>avd)
  { 
    
     servo1 .writeMicroseconds(1425);
     delay(24);
     servo1.writeMicroseconds(1475);
     delay(100);     
   
   }
  else
  {
    delay(24);
    servo1.writeMicroseconds(1475);
    delay(24);
    }

  if (dn1<dn2)
  {
    
      servo2.writeMicroseconds(1515);
      delay(42);
      servo2.writeMicroseconds(1475);
      delay(100);  
    
  }
  else if (dn2<dn1)
  { 
    
     servo2.writeMicroseconds(1425);
     delay(24);
     servo2.writeMicroseconds(1475);
     delay(100);
   }
  
  else
  {
    delay(24);
    servo2.writeMicroseconds(1475);
    delay(24);
    }

  
}
