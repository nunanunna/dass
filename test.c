#include <stdio.h>

int main() {
    //압출력 형식
    int num[10];
    char data[10][10];

    for(int i=0; i<10; i++) {
        printf("\n%d번 째 숫자를 입력해주세요 : ", i+1);
        scanf("%d", &num[i]);

        printf("%d번 째 문자열을 입력해주세요 : ", i+1);
        scanf("%s", data[i]);
    }
    for(int i=0; i<10; i++) {
        printf("%d번 째 숫자는 %d\n", i+1, num[i]);
        printf("%d번 째 문자열은 %s\n\n", i+1, data[i]);
    }
}

