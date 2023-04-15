#include <Arduino.h>

#define LED_PIN1 PB0
#define LED_PIN2 PB1
#define LED_PIN3 PB2
#define LED_PIN4 PB3
#define LED_PIN5 PB4

void setup() {
  // set LED pins as OUTPUT
  DDRB |= (1 << LED_PIN1);
  DDRB |= (1 << LED_PIN2);
  DDRB |= (1 << LED_PIN3);
  DDRB |= (1 << LED_PIN4);
  DDRB |= (1 << LED_PIN5);

  PORTB = 0b00000000;  // set all pins to LOW
}

void sequential_on_off(char pin1, char pin2, char pin3, char pin4, char pin5) {
  // toggle LED pins on
  int delay_ms = 500;
  PORTB ^= _BV(pin1);
  _delay_ms(delay_ms);
  PORTB ^= _BV(pin2);
  _delay_ms(delay_ms);
  PORTB ^= _BV(pin3);
  _delay_ms(delay_ms);
  PORTB ^= _BV(pin4);
  _delay_ms(delay_ms);
  PORTB ^= _BV(pin5);
  _delay_ms(delay_ms);

  // toggle LED pins off
  delay_ms = 125;
  PORTB ^= _BV(pin1);
  delay(delay_ms);
  PORTB ^= _BV(pin2);
  delay(delay_ms);
  PORTB ^= _BV(pin3);
  delay(delay_ms);
  PORTB ^= _BV(pin4);
  delay(delay_ms);
  PORTB ^= _BV(pin5);
  delay(delay_ms);
}

void blink() {
  PORTB ^= _BV(LED_PIN1);
  PORTB ^= _BV(LED_PIN2);
  PORTB ^= _BV(LED_PIN3);
  PORTB ^= _BV(LED_PIN4);
  PORTB ^= _BV(LED_PIN5);
  delay(50);

  PORTB ^= _BV(LED_PIN1);
  PORTB ^= _BV(LED_PIN2);
  PORTB ^= _BV(LED_PIN3);
  PORTB ^= _BV(LED_PIN4);
  PORTB ^= _BV(LED_PIN5);
  delay(50);
}

void from_side_to_center() {
  int delay_ms = 125;
  PORTB ^= _BV(LED_PIN1);
  PORTB ^= _BV(LED_PIN5);
  delay(delay_ms);
  PORTB = 0;
  PORTB ^= _BV(LED_PIN2);
  PORTB ^= _BV(LED_PIN4);
  delay(delay_ms);
  PORTB = 0;
  PORTB ^= _BV(LED_PIN3);
  delay(delay_ms);
  PORTB = 0;
  delay(250);
}

void from_center_to_side() {
  int delay_ms = 125;
  PORTB ^= _BV(LED_PIN3);
  delay(delay_ms);
  PORTB = 0;
  PORTB ^= _BV(LED_PIN2);
  PORTB ^= _BV(LED_PIN4);
  delay(delay_ms);
  PORTB = 0;
  PORTB ^= _BV(LED_PIN1);
  PORTB ^= _BV(LED_PIN5);
  delay(delay_ms);
  PORTB = 0;
  delay(250);
}

void loop() {
  // from top to down
  sequential_on_off(LED_PIN1, LED_PIN2, LED_PIN3, LED_PIN4, LED_PIN5);
  delay(500);

  // from down to top
  sequential_on_off(LED_PIN5, LED_PIN4, LED_PIN3, LED_PIN2, LED_PIN1);
  delay(500);

  for (int i = 1; i <= 5; i++) {
    from_side_to_center();
  }
  delay(500);

  for (int i = 1; i <= 5; i++) {
    from_center_to_side();
  }
  delay(500);

  for (int i = 1; i <= 10; i++) {
    blink();
  }
  delay(1000);
}