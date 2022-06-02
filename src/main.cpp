#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "LowPower.h"

// Use pin 2 as wake up pin
const int wakeUpPin = 2;
uint8_t buttonState = 0;

#define CE_PIN A0
#define CSN_PIN A1

const byte slaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

void send();

void wakeUp()
{
  // Just a handler for the pin interrupt.
}
void setup()
{
  pinMode(wakeUpPin, INPUT);
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setRetries(3, 5); // delay, count
  radio.openWritingPipe(slaveAddress);
}

//====================

void loop()
{
  // Allow wake up pin to trigger interrupt on low.
  attachInterrupt(0, wakeUp, LOW);

  // Enter power down state with ADC and BOD module disabled.
  // Wake up when wake up pin is low.
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  radio.powerUp();
  // Disable external pin interrupt on wake up pin.
  detachInterrupt(0);

  // Do something here
  // Example: Read sensor, data logging, data transmission.
  send();
  
  radio.powerDown();
  //only send once, so while button held wait here.
  while (!digitalRead(wakeUpPin))
  {
    delay(50);
  }
}

//====================

void send()
{
  bool rslt = 0;
  while (!rslt)
  {
    rslt = radio.write(&buttonState, sizeof(buttonState));
    delay(100);
  }
}