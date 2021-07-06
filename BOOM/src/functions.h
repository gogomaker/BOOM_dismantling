#ifndef __FUNCTIONS_H__
# define __FUNCTIONS_H__

#include <Arduino.h>

#define buzzer1 30 
#define buzzer2 31 
#define time_lit 10000
#define R1 8
#define G1 7
#define B1 9
#define R2 11
#define G2 12
#define B2 10
#define a 34
#define b 35
#define c 36 
#define d 37
#define e 38
#define f 39
#define g 40
#define p 41    //The decimal point
//Set DIG1, DIG2, DIG3, DIG4
#define d1 2   //Thousand
#define d2 3   //Hundred
#define d3 4    //Ten
#define d4 5   //One
#define waittime 250  //세그먼트 대기 시간
extern int r;
extern int times; 
extern int c1, c2, c3, c4, c5, c6, c7, c8;
extern int num_bit[10][7];
extern int n1, n2, n3, n4; //다이트 숫자 값 임시 저장소
extern int count;    //시간 측�

void check();
//터졌을 때
void boom();
//폭탄 해체 성공 시
void safe();

//다이트 넘버 설정 코드들
void ONdight(int ars);
void setdightNUM(int n);
void clearLEDs();


#endif