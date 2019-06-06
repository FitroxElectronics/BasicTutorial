#include <IRremote.h>

// ตั้งค่า กำหนดขาของภาครับและตัวแปรเก็บข้อมูลสัญญาณที่ถอดรหัสได้
const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
// เริ่ม Serial Monitor และโมดูลภาครับ
  Serial.begin(9600);
  irrecv.enableIRIn();
  
// เซ็ตขารีเลย์เป็น OUTPUT
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT); 
   pinMode(10, OUTPUT); 
   pinMode(11, OUTPUT); 

// ปิดรีเลย์ไว้เป็นค่าเริ่มต้นโดยตั้งเป็น HIGH (รีเลย์เป็นแบบ Active Low ทำงานเมื่อ Low)
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
}

void loop(){
// เริ่มทำงานหากรับสัญญาณได้
  if (irrecv.decode(&results)){

    // ตรวจรหัสสัญญาณแล้วเปิดปิดรีเลย์ตามช่อง
        switch(results.value){
          case 0xFFA25D:
          digitalWrite(11, !digitalRead(11));
          break;
          case 0xFF629D:
          digitalWrite(10, !digitalRead(10));
          break;
          case 0xFFE21D:
          digitalWrite(9, !digitalRead(9));
          break;
          case 0xFF22DD:
          digitalWrite(8, !digitalRead(8));
          break;
        }
        
    // เตรียมพร้อมรับสัญญาณต่อไป
        key_value = results.value;
        irrecv.resume();
  }
}
