// กำหนด Pin ที่จะใช้งาน
#define trig 9
#define echo 10

// ประกาศตัวแปร
long duration;             // สำหรับเก็บค่าเวลาที่เสียงเดินทาง
int distance;              // สำหรับเก็บค่าระยะทางที่คำนวณได้

void setup() {
pinMode(trig, OUTPUT);     // กำหนดขา trig เป็น output
pinMode(echo, INPUT);   // กำหนดขา echo เป็น input
Serial.begin(9600);        // เริ่ม Serial เพื่อใช้ Serial Monitor
}

void loop() {
// เคลียร์ค่าขา trig ป้องกันกรณีสถานะค้างเก่าค้างอยู่
digitalWrite(trig, LOW);
delayMicroseconds(2);

// ให้ขา trig ส่งคลื่นออกไป 10 ไมโครวินาทีแล้วปิด (ตามสเปคการรับสัญญาณ)
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

// จับเวลาจนกว่าจะมีคลื่นเสียงมากระทบ echo โดยคำสั่ง pulseIn
duration = pulseIn(echo, HIGH);

// คำนวณหาระยะตามสูตรข้างต้น
distance = (duration*0.034)/2;

// แสดงค่าทาง Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

// หน่วงเวลา 1 วินาที
delay(1000);
}
