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
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop(){
// เริ่มทำงานหากรับสัญญาณได้
  if (irrecv.decode(&results)){

    // เช็คการกดปุ่มค้าง ให้สัญญาณ = สัญญาณล่าสุดที่เข้ามา
        if (results.value == 0xFFFFFFFF){
          results.value = key_value;
        }

    // ตรวจรหัสสัญญาณแล้วกระพริบไฟตามจำนวน
        switch(results.value){
          case 0xFFA25D:
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          break;
          
          case 0xFF629D:
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          break;
          
          case 0xFFE21D:
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          break;
        }
        
    // เตรียมพร้อมรับสัญญาณต่อไป
        key_value = results.value;
        irrecv.resume();
  }
}
