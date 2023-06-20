/*Receiver program
 * https://srituhobby.com
 */
//Include libraries
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//Create an object for the RF library and enter the CE and CSN pins, respectively
RF24 radio(D4, D2);
//Create an object for the servo library
Servo servo;
//Create an address to identify the transmitter
const byte address[6] = "00001";

void setup() {
//Begin the serial monitor and RF24 library
  Serial.begin(9600);
  radio.begin();
//Include the servo motor pin
  servo.attach(D0);
//Set the address
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
//Set that module as a receiver
  radio.startListening();
}
void loop() {
  
  //  if (radio.available()) {
  //    char text[32] = "";
  //    radio.read(&text, sizeof(text));
  //    Serial.println(text);
  //  }

  delay(5);
//Check the transmit data using the IF condition
  if (radio.available()) {
    while (radio.available()) {
      int value = 0;
//Get the transmit values
      radio.read(&value, sizeof(value));
//Write these values on the servo
      servo.write(value);
//Print these values on the serial monitor
      Serial.println(value);
    }
  }
}