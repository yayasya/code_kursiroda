/////asuuuuuuuuuu
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
VR myVR(2, 3);   // 2:RX 3:TX, you can choose your favourite pins.
uint8_t records[7]; // save record
uint8_t buf[64];
int echoPin_2 = 4;    // Echo
int echoPin_3 = 7;    // Echo
int echoPin_4 = 8;    // Echo
int echoPin_1 = 3;    // Echo
int trigPin = 2;    //Trigger
int cm_1, cm_2;
int buzzer = 13;
int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

#define maju    (0)
#define mundur   (1)
#define belok_kanan    (2)
#define belok_kiri   (3)
#define stopp  (4)

void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup() {
  //Serial Port begin
  myVR.begin(9600);

  Serial.begin(115200);
  Serial.println("Voice Control car");
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(echoPin_4, INPUT);
  pinMode(buzzer, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)maju) >= 0) {
    Serial.println("red loaded");
  }

  if (myVR.load((uint8_t)mundur) >= 0) {
    Serial.println("orange loaded");
  }
  if (myVR.load((uint8_t)belok_kanan) >= 0) {
    Serial.println("blue loaded");
  }

  if (myVR.load((uint8_t)belok_kiri) >= 0) {
    Serial.println("yellow loaded");
  }
   if (myVR.load((uint8_t)stopp) >= 0) {
    Serial.println("off loaded");
  }

   
}


void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
voice();
  cm_1 = ultra(trigPin, echoPin_4, 4);
  cm_2 = ultra(trigPin, echoPin_1, 1);
  if (cm_1 or cm_2 < 50)
  {
    digitalWrite(buzzer, HIGH);

  }


}
