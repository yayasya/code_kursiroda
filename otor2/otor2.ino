#define in1 5
#define in2 6
#define in3 18
#define in4 17
//variabel pwm
int FPWM[] = {255, 225, 200, 175, 150,125, 100, 75, 50, 25, 0};

void setup()
{
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //  pinMode(in3, OUTPUT);
  //  pinMode(in4, OUTPUT);

}

void loop()
{
  Serial.print("asuuuuuuuuuuuuuuuuuuu");
  for (int i = 0; i < 12; i = i+1)
  {
    analogWrite(in1, FPWM[i]);
    analogWrite(in2, 0);
    delay(500);
    Serial.println(FPWM[i]);
  }
}


//void majumundur() {
//
// if (FPWM > 35) {
//    analogWrite(in1, FPWM);
//    analogWrite(in2, 0);
//    analogWrite(in3, FPWM);
//    analogWrite(in4, 0);
//    Serial.print("MAJU   ");
//    Serial.println(FPWM);
//  }
//  else if (BPWM > 35) {
//    analogWrite(in1, 0);
//    analogWrite(in2, BPWM);
//    analogWrite(in3, 0);
//    analogWrite(in4, BPWM);
//    Serial.print("MUNDUR   ");
//    Serial.println(BPWM);
//  }
//
//}
//
//void kirikanan() {
//
//  if (LPWM > 35) {
//    analogWrite(in1, LPWM);
//    analogWrite(in2, 0);
//    analogWrite(in3, 0);
//    analogWrite(in4, LPWM);
//
//    Serial.print("KIRI   ");
//    Serial.println(LPWM);
//  }
//  // else if ( abs(Ps3.data.analog.button.l1)){ //COMBINASI
//  //   digitalWrite(in1, HIGH);
//  //   digitalWrite(in2, LOW);
//  //   digitalWrite(in3, HIGH);
//  //   digitalWrite(in4, LOW);
//
//  //   Serial.print("KIRI   ");
//  //   Serial.println(Ps3.data.analog.button.l1,DEC);
//  //   }
//
//  else if (RPWM > 35) {
//    analogWrite(in1, 0);
//    analogWrite(in2, RPWM);
//    analogWrite(in3, RPWM);
//    analogWrite(in4, 0);
//
//    Serial.print("KANAN   ");
//    Serial.println(RPWM);
//  }
//
//  //  else if ( abs(Ps3.data.analog.button.r1)){ //COMBINASI
//  //   digitalWrite(in1, LOW);
//  //   digitalWrite(in2, HIGH);
//  //   digitalWrite(in3, LOW);
//  //   digitalWrite(in4, HIGH);
//
//  //   Serial.print("KANAN   ");
//  //   Serial.println(Ps3.data.analog.button.r1,DEC);
//  //   }
//
//}
//
//void majubelok() {
//
// if (LPWM > 35 && FPWM > 35) {
//    analogWrite(in1, FPWM);
//    analogWrite(in2, 0);
//    analogWrite(in3, 200);
//    analogWrite(in4, 0);
//    Serial.print("MAJU KIRI");
//    Serial.println(FPWM);
//  }
//  else if (RPWM > 35 && FPWM > 35) {
//    analogWrite(in1, 200);
//    analogWrite(in2, 0);
//    analogWrite(in3, FPWM);
//    analogWrite(in4, 0);
//    Serial.print("MAJU KANAN");
//    Serial.println(FPWM);
//  }
//
//}
//
//void mundurbelok() {
//
// if (LPWM > 35 && BPWM > 35) {
//    analogWrite(in1, 0);
//    analogWrite(in2, 200);
//    analogWrite(in3, 0);
//    analogWrite(in4, BPWM);
//    Serial.print("MUNDUR KIRI");
//    Serial.println(BPWM);
//  }
//  else if (RPWM > 35 && BPWM > 35) {
//    analogWrite(in1, 0);
//    analogWrite(in2, BPWM);
//    analogWrite(in3, 0);
//    analogWrite(in4, 200);
//    Serial.print("MUNDUR KANAN");
//    Serial.println(BPWM);
//  }
//
//}
//
//void brake() {
//
// if (Ps3.data.analog.button.r1) {
//    analogWrite(in1, 255);
//    analogWrite(in2, 255);
//    analogWrite(in3, 255);
//    analogWrite(in4, 255);
//    Serial.print("BRAKE");
//    Serial.println(Ps3.data.analog.button.r1);
//  }
//     else if (LPWM <= 35 && RPWM <= 35 && FPWM <= 35 && BPWM <= 35) {
//    analogWrite(in1, 0);
//    analogWrite(in2, 0);
//    analogWrite(in3, 0);
//    analogWrite(in4, 0);
//    Serial.print("STOP   ");
//    Serial.println(RPWM);
//  }
//
//}
