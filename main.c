#include <stdio.h>

int main() {
    long nationalCode;
    int count = 0;
    long invalidCodes[] = {
        1111111111,
        2222222222,
        3333333333,
        4444444444,
        5555555555,
        6666666666,
        7777777777,
        8888888888,
        9999999999,
        0000000000
    };
    int array[9];
    int sum = 0;
    int controlNum;
    int recurrent;
    printf("Enter a National Code: ");
    scanf("%ld", &nationalCode);
    for(int i = 0; i <= 9; i++) {
        if(invalidCodes[i] == nationalCode) {
            printf("Invalid \n");
            return 0;
        }
    }
    for(int i = 0; i <= 9; i++) {
        array[i] = nationalCode % 10;
        nationalCode /= 10;
    }
    int j = 1;
    for(int i = 1; i <= 9; i++) {
        sum += ++j * array[i];
    }

    controlNum = array[0];
    recurrent = sum % 11;
    if( (recurrent > 1) && (controlNum == (11 - recurrent)) ) {
        printf("Valid \n");
        return 1;
    } else if(recurrent == 0 && controlNum == 0) {
        printf("Valid \n");
        return 1;
    } else if(recurrent == 1 && controlNum == 1) {
        printf("Valid \n");
        return 1;
    } else {
        printf("Invalid \n");
        return 0;
    }
    printf("Invalid \n");
    return 0;
}