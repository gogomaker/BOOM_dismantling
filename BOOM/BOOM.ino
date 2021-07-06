/*기본 설정*/

//조만간 헤더파일이나 만듭시다!

#include "src\functions.h"


        //   a     b     c     d     e     f     g
#define _0 {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}
#define _1 {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW}
#define _2 {HIGH, HIGH, LOW,  HIGH, HIGH, LOW, HIGH}
#define _3 {HIGH, HIGH, HIGH, HIGH, LOW,  LOW, HIGH}
#define _4 {LOW,  HIGH, HIGH, LOW,  LOW, HIGH, HIGH}
#define _5 {HIGH, LOW,  HIGH, HIGH, LOW, HIGH, HIGH}
#define _6 {HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH}
#define _7 {HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW}
#define _8 {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}
#define _9 {HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH}
int num_bit[10][7] = { _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 };
int n1 = 1, n2 = 5, n3, n4 = 0; //다이트 숫자 값 임시 저장소
int count = 0;    //시간 측�
int times = time_lit; 
int c1, c2, c3, c4, c5, c6, c7, c8 = 0;
int r = 0;

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
