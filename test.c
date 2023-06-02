#include <stdio.h>

typedef struct input{
    int imp; // 단위 N*s
    int acc; // 단위 m/s^2
    int av; // 단위 rpm
    int tmp; // 단위 c
    int smd; // 단위 m/s
    int mass; // 단위 kg
} input;

int main() {
    int imp, acc, av, tmp, smd, mass;
    
    imp = 20;
    acc = 1;
    av = 250;
    tmp = 25;
    smd = 1;
    mass = 2;

    // int input[] = {imp, acc, av, tmp, smd}; // 배열의 경우
    input input = {imp, acc, av, tmp, smd, mass}; // 구조체의 경우
}

// 입력데이터
void function(input* input) {
    input->
}

void output() {
    
}