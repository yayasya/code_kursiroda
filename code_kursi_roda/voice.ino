void voice()
{
 
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case maju:
      // digitalWrite(Red, HIGH); 
        break;
        
      case mundur:
    //  digitalWrite(Orange, HIGH); 
        break;

      case belok_kanan:
     //  digitalWrite(Blue, HIGH); 
        break;
        
      case belok_kiri:
       //digitalWrite(Yellow, HIGH); 
        break;
        case stopp:
//       digitalWrite(Red, LOW);
//       digitalWrite(Orange, LOW); 
//       digitalWrite(Blue, LOW);
//       digitalWrite(Yellow, LOW); 
        break;
        
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}
