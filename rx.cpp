

// SimpleRx - the slave or the receiver
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};

RF24 radio(CE_PIN, CSN_PIN);
uint8_t ledPin = A1;
uint8_t buttonState;

//===========

void getData();


void setup()
{
  digitalWrite(ledPin,HIGH);
  pinMode(ledPin, OUTPUT);
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, thisSlaveAddress);
  radio.startListening();
}

//=============

void loop()
{
  getData();
}

//==============

void getData()
{
  if (radio.available())
  {
    radio.read(&buttonState, sizeof(buttonState));
    digitalWrite(ledPin,LOW);
    delay(500);
    digitalWrite(ledPin,HIGH);
  }
}
