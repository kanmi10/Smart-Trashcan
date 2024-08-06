#include <LiquidCrystal.h>

// LCD 핀 설정
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// 초음파 센서 핀 설정
int trig = 9;
int echo = 8;

void setup() {
  // LCD 초기화
  lcd.begin(16, 2);
  lcd.print("Distance:");

  // 초음파 센서 핀 모드 설정
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 초음파 센서로부터 거리 측정
  long duration;
  int distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  // LCD에 거리 표시
  lcd.setCursor(0, 1);
  lcd.print("                "); // 이전 내용 지우기
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  // 시리얼 모니터에 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}