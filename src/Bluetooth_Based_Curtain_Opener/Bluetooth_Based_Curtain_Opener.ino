/*********************************************************

              Bluetooth based Curtain Opener
                 Author : Kapil H. Sonone
           R&D Enginner, AVM Infotech (I) Pvt. Ltd.

*********************************************************/

#include <SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial ble(2, 3); //(RX, TX)
Servo motor;

const int motorPin = 5;
String k = " ";

void setup() {
  Serial.begin(9600);
  motor.attach(motorPin);
  ble.begin(9600);
  motor.write(90);
}
void loop() {
  if (ble.available() > 0) {
    k = ble.readString();
    k.trim();
    Serial.println(k);

    if (k == "O") {
      Serial.println("Opening Curtain");
      motor.write(10);
      delay(3000);
      motor.write(90);
    }
    else if (k == "C") {
      Serial.println("Closing Curtain");
      motor.write(170);
      delay(3000);
      motor.write(90);
    }
    else {
      Serial.println("Motor Stop");
      motor.write(90);
    }
    ble.flush();
    Serial.flush();
  }
}
