// กำหนดขาที่จะใช้งาน
int ledPin = 13;
int pirPin = 2;

int value = 0;

void setup() {
// กำหนดขา ledPin เป็น Output และ pirPin เป็น Input ต่อกับโมดูล
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);

// กำหนดให้ LED ดับในตอนเริ่มต้น
  digitalWrite(ledPin, LOW);
}

void loop() {
// digitalRead สถานะจากขาโมดูล
  value = digitalRead(pirPin);

// ให้ LED มีสถานะเดียวกับ value (โมดูลตรวจจับได้ value อ่านได้ HIGH LED ก็จะติดสว่างตามด้วย)
  digitalWrite(ledPin, pirValue);  
}
