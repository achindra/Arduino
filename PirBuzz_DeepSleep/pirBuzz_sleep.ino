/*
 * Motion Detection with Power saving deep sleep
 */

#include <avr/sleep.h>
#include <avr/wdt.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= -_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int pinBuzz = 0;
int pirPin = 1;

void setup() {
  pinMode(pinBuzz, OUTPUT);
  pinMode(pirPin, INPUT);
  sbi(GIMSK, PCIE); // Turn on Pin Change interrupt
  sbi(PCMSK, PCINT1); // Which pins are affected by the interrupt
}
void loop() {
  system_sleep();
}

void system_sleep() {
  cbi(ADCSRA, ADEN); // Switch Analog to Digital converter OFF
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode
  sleep_mode(); // System sleeps here
  sbi(ADCSRA, ADEN); // Switch Analog to Digital converter ON
}

ISR(PCINT0_vect) {
  if (digitalRead(pirPin) == LOW) {
    digitalWrite(pinBuzz, HIGH);
    delay(2500);
    digitalWrite(pinBuzz, LOW);
  }
  else {
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(2500);    // beep.beep.beep.beep..beep.beep.beep.beep
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
    delay(1500);
    digitalWrite(pinBuzz, HIGH);
    delay(1500);
    digitalWrite(pinBuzz, LOW);
  }
}
