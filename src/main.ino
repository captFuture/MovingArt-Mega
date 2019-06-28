#include <Arduino.h>
#include <Wire.h>

/* i2c pins on the mega are 20 (SDA), 21 (SCL)
connection example of more than one devicce
https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/
*/


/* i2c scanner
void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000);           // wait 5 seconds for next scan
}

*/

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("I2C Master ready!");
}

void loop() {
  delay(50);
  Serial.println("Write data to slaves");

  nanoStatus(0x01); // send and request from device with i2c address 0x001
}

void nanoStatus(byte addr){
  Wire.beginTransmission(addr);
  Wire.write(1); // send 1 (start command) to slave -> will respond with actual value or start new cycle
    // probably a byte array should be sent with command and speed or whatever :D
  Wire.endTransmission();

  Wire.requestFrom(addr,10); // i do not know if this works correctly -> check nano sendEvent()
    String response = "";
    while (Wire.available()) {
        char b = Wire.read();
        response += b;
    }
    Serial.println(response);
}

void nanoStop(byte addr){
  Wire.beginTransmission(addr);
  Wire.write(1); // send 0 (stop command) ... probably not needed ... but just in case
  Wire.endTransmission();
}
