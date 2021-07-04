/*기본 설정*/

//조만간 헤더파일이나 만듭시다!
#include "src\segment.h"

//폭탄 선 제거 설정
void setup() {
  Serial.begin(115200); //시리얼 통신을 보드레이트 115200으로 시작
//  analogReference(INTERNAL2V56);  //아날로그 값 증폭
  for(int i = 22; i < 30; i++) { pinMode(i, INPUT); }//자르는 선 감지핀 설정
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
//  세그먼트 설정
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
//  세그먼트 기본 셋팅
  analogWrite(d1, 255);
  analogWrite(d2, 255);
  analogWrite(d3, 255);
  analogWrite(d4, 255);
//  소수점 켜기(둘째자리, 0.01초 단위로 보여주기 위함)
  digitalWrite(d2, LOW);
  digitalWrite(p, HIGH);    //소수점 켜기
  digitalWrite(d2, HIGH);
//  무작위 수 설정
  randomSeed(analogRead(A0));
  r = random(22, 30);   //랜덤값을 22~29까지 사이에서 뽑음
  Serial.println(analogRead(A0));  //랜덤값 출력
  Serial.println(r);  //랜덤값 출력
}

void loop() {     //반복 루프
  if(analogRead(A0) < 800) { qwert(); }
}
void qwert() {
//  폭탄 선 자르기 관련 코드
  if(digitalRead(r) == LOW) { boom(); }       //선이 잘리면
  if(digitalRead(22) == LOW) { c1 = 1; }
  if(digitalRead(23) == LOW) { c2 = 1; }
  if(digitalRead(24) == LOW) { c3 = 1; }
  if(digitalRead(25) == LOW) { c4 = 1; }
  if(digitalRead(26) == LOW) { c5 = 1; }
  if(digitalRead(27) == LOW) { c6 = 1; }
  if(digitalRead(28) == LOW) { c7 = 1; }
  if(digitalRead(29) == LOW) { c8 = 1; }
  if(c1+c2+c3+c4+c5+c6+c7+c8 >= 6) { safe(); }          //몇 개 까지 잘라야 성공인가
  count = millis();    //시간 재는 역할
//  카운팅 코드
  times = time_lit;
  times -= count;
//  만약 제한시간이 다 된다면
  if(times < 0) {
    n1 = n2 = n3 = n4 = 0;  //데이타 클리어
    int nit = 0;  //while문 반복 횟수 저장 변수
    while(true) {   //무한반복
      nit++;
  tone(buzzer1, 466);
      if(nit > 5) {noTone(buzzer1);}   //부저 끄기      //b-e-e-p
//      시간이 다 됐으므로 '0000' 출력
      analogWrite(d1, 0);
      analogWrite(d2, 0);
      analogWrite(d3, 0);
      analogWrite(d4, 0);
      setdightNUM(0);
      analogWrite(R1, 255);
      analogWrite(G1, 127);
      analogWrite(R2, 255);
      analogWrite(G2, 127);
      delay(500);
      noTone(buzzer1);   //부저 끄기
      analogWrite(d1, 255);
      analogWrite(d2, 255);
      analogWrite(d3, 255);
      analogWrite(d4, 255);
      analogWrite(R1, 0);
      analogWrite(G1, 0);
      analogWrite(R2, 0);
      analogWrite(G2, 0);
      delay(500);
    }
  }
  check();
  ONdight(0);   //최종적으로 시간 보여주는 코드
}
//시간 체킹 코드
void check() {
  if(times >= 10000) {      //밀리초 값이 10000이상일 때

  //  십의 자리 측정
    n1 = times/10000;

  //  일의 자리 측정
    n2 = times/1000;
    while(n2 > 0) { n2 -= 10; }
    n2 *= -1;
    if(!(n2 == 0)) { n2 = n2+(5-n2)*2; }

  //  소숫점 한자리 측정
    n3 = times/100;
    while(n3 > 0) { n3 -= 10; }
    n3 *= -1;
    if(!(n3 == 0)) {n3 = n3+(5-n3)*2;}

  //  소숫점 두자리 측정
    n4 = times/10;
    while(n4 > 0) { n4 -= 10; }
    n4 *= -1;
    if(!(n4 == 0)) { n4 = n4+(5-n4)*2; }
  } else {                  //밀리초 값이 1000 미만일 때
  //  십의 자리 측정
    n1 = 0;

  //  일의 자리 측정
    n2 = times/1000;

  //  소숫점 한자리 측정
    n3 = times/100;
    while(n3 > 0) {
      n3 -= 10;
    }
    n3 *= -1;
    if(!(n3 == 0)) {n3 = n3+(5-n3)*2; }

  //  소숫점 두자리 측정
    n4 = times/10;
    while(n4 > 0) {
      n4 -= 10;
    }
    n4 *= -1;
    if(!(n4 == 0)) { n4 = n4+(5-n4)*2; }
  }
}
//터졌을 때
void boom() {
  Serial.println("BOOM!");
  tone(buzzer1, 466);
  analogWrite(R1, 255);
  analogWrite(G1, 15);
  analogWrite(B1, 15);
  analogWrite(R2, 255);
  analogWrite(G2, 15);
  analogWrite(B2, 15);
  while(true) {
    for(int i = 0; i < 255; i++) { ONdight(i); }    //세그먼트 깜박임 효과
    noTone(buzzer1);
  for(int i = 255; i > 0; i++) { ONdight(i); }    //세그먼트 깜박임 효과
    noTone(buzzer1);   //부저 끄기
  }
}
//폭탄 해체 성공 시
void safe() {
  Serial.println("SAFE!");
//  도미솔도 연주
  tone(buzzer1, 523, 500);
  analogWrite(R1, 15);
  analogWrite(G1, 235);
  analogWrite(B1, 235);
  analogWrite(R2, 15);
  analogWrite(G2, 235);
  analogWrite(B2, 235);
  delay(500);
  noTone(buzzer1);
  tone(buzzer1, 659, 500);
  delay(500);
  noTone(buzzer1);
  tone(buzzer1, 784, 500);
  delay(500);
  noTone(buzzer1);
  tone(buzzer1, 1047, 1500);
  while(true) { ONdight(0); }   //세그먼트에 해체 성공한 시간 출력
}

//다이트 넘버 설정 코드들
void ONdight(int ars) {   //ars는 원래 다이트 밝기 조절을 위해 쓴 변수이다. 근데 쓰질 않는 것 같다.
  //  10자리
  clearLEDs();                  //숫자 겹침 현상 해결
  analogWrite(d1, ars);         //자리에 숫자 쓰기 시작
  setdightNUM(n1);              //자리에 해당 숫자를 적음
  delayMicroseconds(waittime);  //숫자를 선명하게 보이게 함
  analogWrite(d1, 255);         //자리에 숫자 쓰기 끝
//  1자리
  clearLEDs();
  analogWrite(d2, ars);
  setdightNUM(n2);
  digitalWrite(p, HIGH);        //소수점 켜기
  delayMicroseconds(waittime);
  analogWrite(d2, 255);
//  소숫점 1자리
  clearLEDs();
  analogWrite(d3, ars);
  setdightNUM(n3);
  delayMicroseconds(waittime);
  analogWrite(d3, 255);
//  소숫점 2자리
  clearLEDs();
  analogWrite(d4, ars);
  setdightNUM(n4);
  delayMicroseconds(waittime);
  analogWrite(d4, 255);
}
void setdightNUM(int n) {
  digitalWrite(a, num_bit[n][0]);
  digitalWrite(b, num_bit[n][1]);
  digitalWrite(c, num_bit[n][2]);
  digitalWrite(d, num_bit[n][3]);
  digitalWrite(e, num_bit[n][4]);
  digitalWrite(f, num_bit[n][5]);
  digitalWrite(g, num_bit[n][6]);
}
void clearLEDs() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}
