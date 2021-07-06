#include "functions.h"

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
