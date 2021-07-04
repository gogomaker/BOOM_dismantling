int r = 0;
#define buzzer1 30 
#define buzzer2 31 
#define time_lit 10000
int times = time_lit; 
int c1, c2, c3, c4, c5, c6, c7, c8 = 0;
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

//세그먼트 기타 설정
#define waittime 250  //세그먼트 대기 시간
int n1 = 1, n2 = 5, n3, n4 = 0; //다이트 숫자 값 임시 저장소
int count = 0;    //시간 측�
