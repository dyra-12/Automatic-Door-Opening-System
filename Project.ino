#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define SERVO_PIN 6
#define PIR_PIN 4

void rotateServo(int degrees){
  int pulseWidth=(degrees*11)+500; 
  PORTD |=(1<<SERVO_PIN);
  _delay_us(pulseWidth);
  PORTD &= ~(1<<SERVO_PIN);
  _delay_us(19500);
}

int main(void) {
  DDRD |= (1<<SERVO_PIN);
  DDRD &= ~(1 << PIR_PIN);
  Serial.begin(9600);
  while(1){
    if(PIND & (1<<PIR_PIN)){
      Serial.println("Motion Detected");
      Serial.println("Welcome!");
      rotateServo(180);
    } else {
      Serial.println("Motion not Detected");
      rotateServo(0);
    }
  }
  return 0;
}