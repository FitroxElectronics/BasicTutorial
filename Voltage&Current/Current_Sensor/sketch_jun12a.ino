// กำหนดโมดูลต่อกับขา A0
#define ACS712Pin A0

int readCurrent = 0;          // ตัวแปรเก็บค่าที่อ่านได้จาก A0
float currentValue = 0;       // ตัวแปรค่ากระแสไฟฟ้า

void setup(){
  Serial.begin(9600);
}

void loop(){
// อ่านค่าแรงดันจาก A0 เป็น ADC มีค่า 0-1023
  readCurrent = analogRead(ACS712Pin);
  
// แปลงค่า 0-1023 ที่อ่านได้ เหลือ 0-5(สมมติใช้ ACS712-ELC-5A วัดได้ 5A) โดยใช้คำสั่ง map จะได้เป็นกระแสไฟฟ้าที่วัดได้
  currentValue = map(readCurrent, 0, 1023, 0, 5);
  
// แสดงผลออกทาง Serial monitor ใช้ทศนิยม 2 หลัก
  Serial.print(currentValue, 2);
  Serial.println(" A");
  delay(1000);
}
