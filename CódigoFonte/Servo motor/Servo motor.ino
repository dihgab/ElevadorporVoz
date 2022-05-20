#include <Servo.h>
Servo motor;

void setup()
{
  motor.attach(3); //pino de sinal ligado na porta 3
  motor.write(0);
}

void loop()
{
  motor.write(0);
  delay(1000);
  motor.write(45);
  delay(1000);
  motor.write(90);
  delay(1000);
  motor.write(135);
  delay(1000); 
  motor.write(180);
  delay(1000); 
  
  
  
}
