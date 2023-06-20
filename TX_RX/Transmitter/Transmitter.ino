/*Transmitter program
 * https://srituhobby.com
 */
//Include libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//Include CE and CSN pins respectively
RF24 radio(7, 8);
//Create an address to identify the receiver
const byte address[6] = "00001";

void setup() {
//Begin the serial monitor and RF24 library
  Serial.begin(9600);
  radio.begin();
//set the adress
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
//Set that module as transmitter
  radio.stopListening();
}

void loop() {
//  const char text[] = "Hello World";
//  radio.write(&text, sizeof(text));
//  delay(1000);

    delay(5);
//Get the values from the potentiometer
    int value = analogRead(A0);
//Convert these values from 0 to 180
    value = map(value, 0, 1024, 0, 180);
//Print these values on the serial monitor
    Serial.println(value);
//Send these values to the receiver
    radio.write(&value, sizeof(value));
}