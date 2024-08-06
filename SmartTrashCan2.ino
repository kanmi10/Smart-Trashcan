#include <Servo.h>

// 핀 설정
int trigPin = 9;
int echoPin = 8;
int servoPin = 7;

// 서보 모터 객체 생성
Servo myServo;

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);

  // 초음파 센서 핀 모드 설정
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // 서보 모터 핀 설정
  myServo.attach(servoPin);

  // 서보 모터 초기 위치 설정
  myServo.write(0);
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

  // 시리얼 모니터에 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 거리에 따라 서보 모터 위치 설정
  int angle = map(distance, 0, 200, 0, 180); // 거리 값을 각도로 매핑 (0~200cm를 0~180도로)
  angle = constrain(angle, 0, 180); // 각도 범위를 0~180도로 제한
  myServo.write(angle);

  delay(500);
}