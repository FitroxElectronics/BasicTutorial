#include <DHT.h>                                   // รวม Library DHT ไว้ใน Project

DHT dht(2, DHT22);                                // กำหนด DHT Sensor ชื่อ dht ต่อกับ Pin 2 และเป็นเซ็นเซอร์ DHT22
                                                             // (สามารถเปลี่ยน 2 และเปลี่ยน DHT22 เป็น DHT11 หรือ DHT21 ตามชนิดเซ็นเซอร์ที่ใช้)
// ประกาศตัวแปร
float temp_c;                                         
float temp_f;                                         
float humidity;                                      

void setup(){
     Serial.begin(9600);                           // เริ่มต้นใช้งาน Serial ที่ 9600kbps สำหรับติดต่อกับคอมพิวเตอร์เพื่อใช้ Serial Monitor
     dht.begin();                                     // เริ่มต้นใช้งาน เซ็นเซอร์ DHT ที่ชื่อ dht
}

void loop(){
    temp_c = dht.readTemperature();      // คำสั่ง readTemperature เป็นคำสั่งอ่านค่าอุณหภูมิในหน่วยองศาเซลเซียส
    temp_f = dht.readTemperature(true); // หากต้องการค่าอุณหภูมิในหน่วยองศาฟาเรนไฮต์ให้ใส่ true ลงไปในวงเล็บของคำสั่ง
    humidity = dht.readHumidity();          // คำสั่ง readHumidity เป็นคำสั่งอ่านค่าความชื้นในอากาศเป็นเปอร์เซ็นต์

// แสดงค่าออกทาง Serial Monitor
    Serial.print("Temperature is ");
    Serial.print(temp_c);
    Serial.print(" C : : ");
    Serial.print(temp_f);
    Serial.print(" F >> Humidity ");
    Serial.print(humidity);
    Serial.println(" %");

// DHT22 อ่านค่าความถี่สูงสุด 0.5Hz (2 วินาที/ครั้ง) ต้องหน่วงเวลาอย่างน้อย 2 วินาที
    delay(2000);
}
