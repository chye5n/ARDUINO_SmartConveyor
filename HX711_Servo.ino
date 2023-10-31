#include <HX711.h>
#include <Servo.h>
#define calibration_factor -472
int DOUT = 3;
int CLK = 2;
Servo servo1;
Servo servo2;
int value1 = 0;
int value2 = 0;
HX711 scale(DOUT, CLK);
int a = digitalRead(3);

void setup() {
  Serial.begin(9600);
  Serial.println("TEST");
  scale.set_scale(calibration_factor);
  scale.tare();
  Serial.println("Readings : ");
  servo1.attach(5);
  servo2.attach(6);
  
}

void loop() 
{
  Serial.print("Reading : ");
  Serial.print(scale.get_units(), 1);
  Serial.println("g ");
 
  if(scale.get_units() <= 2000)
  {
    value1 = 90;
    value2 = 270;
    servo1.write(value1);
    servo2.write(value2);
    delay(3000);
    value1 = 0;
    servo1.write(value1);
    delay(2000);
  }
  if(scale.get_units() > 2000)
  {
    value2 = 90;
    value1 = 0;
    servo1.write(value1);
    servo2.write(value2);
    delay(3000);
    value2 = 270;
    servo2.write(value2);
    delay(2000);
  }
}