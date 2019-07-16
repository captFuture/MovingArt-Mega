#include <Arduino.h>
#include <Wire.h>

byte addr[12] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C};
byte mot[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int motnum;

void setup() {
  Wire.begin();
  //Wire.onReceive(receiveEvent); // data received from NANO
  Serial.begin(115200);
  Serial.println("I2C Master ready!");
}

void loop() {
  delay(500);

/* ------------------------------------------------------------------*/

  // Motor 1
  if(mot[0] == 0){
    Serial.println("Write data to 0x01");
    sendEvent(1,3,100,addr[0]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[0]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x01");
    nanoStatus(addr[0], 0, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

  // Motor 2
  if(mot[1] == 0){
    Serial.println("Write data to 0x02");
    sendEvent(1,3,100,addr[1]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[1]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x02");
    nanoStatus(addr[1], 1, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

  // Motor 3
  if(mot[2] == 0){
    Serial.println("Write data to 0x03");
    sendEvent(1,3,100,addr[2]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[2]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x03");
    nanoStatus(addr[2], 2, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

  // Motor 4
  if(mot[3] == 0){
    Serial.println("Write data to 0x04");
    sendEvent(1,3,100,addr[3]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[3]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x04");
    nanoStatus(addr[3], 3, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

  // Motor 5
  if(mot[4] == 0){
    Serial.println("Write data to 0x05");
    sendEvent(1,3,100,addr[4]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[4]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x05");
    nanoStatus(addr[4], 4, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

  // Motor 6
  if(mot[5] == 0){
    Serial.println("Write data to 0x06");
    sendEvent(1,3,100,addr[5]); //send and request from device with i2c address
    //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
    mot[5]=1; // motor is running
  }else{
    Serial.println("Ask status of 0x06");
    nanoStatus(addr[5], 5, false);
    //nanoStatus(adresse, motornummer, neubeginn nach ende);
  }

/* ------------------------------------------------------------------*/

// Motor 7
if(mot[6] == 0){
  Serial.println("Write data to 0x07");
  sendEvent(1,3,100,addr[6]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[6]=1; // motor is running
}else{
  Serial.println("Ask status of 0x07");
  nanoStatus(addr[6], 6, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

// Motor 8
if(mot[7] == 0){
  Serial.println("Write data to 0x08");
  sendEvent(1,3,100,addr[7]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[7]=1; // motor is running
}else{
  Serial.println("Ask status of 0x08");
  nanoStatus(addr[7], 7, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

// Motor 9
if(mot[8] == 0){
  Serial.println("Write data to 0x09");
  sendEvent(1,3,100,addr[8]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[8]=1; // motor is running
}else{
  Serial.println("Ask status of 0x09");
  nanoStatus(addr[8], 8, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

// Motor 10
if(mot[9] == 0){
  Serial.println("Write data to 0x0A");
  sendEvent(1,3,100,addr[9]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[9]=1; // motor is running
}else{
  Serial.println("Ask status of 0x0A");
  nanoStatus(addr[9], 9, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

// Motor 11
if(mot[10] == 0){
  Serial.println("Write data to 0x0B");
  sendEvent(1,3,100,addr[10]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[10]=1; // motor is running
}else{
  Serial.println("Ask status of 0x0B");
  nanoStatus(addr[10], 10, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

// Motor 12
if(mot[11] == 0){
  Serial.println("Write data to 0x0C");
  sendEvent(1,3,100,addr[11]); //send and request from device with i2c address
  //sendEvent(richtung, umdrehungen, geschwindigkeit, adresse);
  mot[11]=1; // motor is running
}else{
  Serial.println("Ask status of 0x0C");
  nanoStatus(addr[11], 11, false);
  //nanoStatus(adresse, motornummer, neubeginn nach ende);
}

/* ------------------------------------------------------------------*/


  for (int i=0; i<12; i++)
  {
    Serial.print(mot[i]); Serial.print("|");
  }
  Serial.println();


}

void nanoStatus(byte addr, int motnum, bool reset){
  Wire.requestFrom(addr,3);
  Serial.println("Received status from Nano: ");
  int x = 0;
  byte nanostatus[3];
  while (Wire.available()) {
    byte answer = Wire.read();
    nanostatus[x]=answer;
    x++;
  }
  if(nanostatus[2] == 0){ // reset Motor if cycle is finished
    if(reset){
      Serial.print("Cycle finished Resetting Motor: "); Serial.println(addr);
      mot[motnum] = 0;
    }else{
      Serial.print("Cycle finished Stop Motor: "); Serial.println(addr);
    }
  }
  for (int i=0; i<3; i++)
  {
    Serial.print(nanostatus[i]);
    Serial.print("|");
  }
  Serial.println();
}


void sendEvent(int cmd, int rev, int speed, byte addr) {
  byte sendevent[4];
  Wire.beginTransmission(addr);

  sendevent[0] = cmd;
  sendevent[1] = rev;
  sendevent[2] = speed;
  sendevent[3] = addr;

  Serial.print("Sending Event: ");
  for (int i=0; i<4; i++)
  {
    Serial.print(sendevent[i]);
    Wire.write(sendevent[i]);
    Serial.print("|");
  }
  Serial.println();
  Wire.endTransmission();
}
