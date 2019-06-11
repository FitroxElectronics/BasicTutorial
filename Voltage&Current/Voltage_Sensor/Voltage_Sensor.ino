// กำหนดโมดูลต่อกับขา A0
#define sensorPin A0

int readVoltage = 0;          // ตัวแปรเก็บค่าที่อ่านได้จาก A0
float voltageValue = 0;       // ตัวแปรค่าแรงดันไฟฟ้า

void setup(){
  Serial.begin(9600);
}

void loop(){
// อ่านค่าแรงดันจาก A0 เป็น ADC มีค่า 0-1023
  readVoltage = analogRead(sensorPin);
  
// แปลงค่า 0-1023 ที่อ่านได้ เหลือ 0-25 โดยใช้คำสั่ง map จะได้เป็นแรงดันไฟฟ้าที่วัดได้
  voltageValue = map(readVoltage, 0, 1023, 0, 25);
  
// แสดงผลออกทาง Serial monitor ใช้ทศนิยม 2 หลัก
  Serial.print(voltageValue, 2);
  Serial.println(" V");
  delay(1000);
}
