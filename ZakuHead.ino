#include <Servo.h>
#define LED_PIN 13
#define SERVO_PIN 10

#define MIN 60
#define MAX 120
#define CENTER 90

Servo servo;  
int pos;    

void setup() 
{
  servo.attach(SERVO_PIN);  
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  // Turn on LED
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  
  // Set Eye to center position
  servo.write(90); 
  
  // Rotate from center to side
  for (pos = CENTER; pos <= MAX; pos += 1) 
  { 
    servo.write(pos);              
    delay(20);                       
  }
  
  // Rotate from side to opposite side
  for (pos = MAX; pos >= MIN; pos -= 1) 
  {
    servo.write(pos);              
    delay(20);                       
  }
  
  // Return to center position
  for (pos = MIN; pos <= CENTER; pos += 1)
  { 
    servo.write(pos);              
    delay(20);                       
  }
}
