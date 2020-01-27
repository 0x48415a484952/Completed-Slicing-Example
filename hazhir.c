#include <stdio.h>
#include <unistd.h>

// checkUserNationalCodeAgainstInvalidCodes(userInput) {
//     for(int i = 0; i <= size)
// }

int count(long number) {
    int count = 0;
    while(number != 0) {
        count++;
        number /= 10;
    }
    return count;
}

int countArray(long array) {
    int count = 0;
    count = sizeof(array) / sizeof(long);
    return count;
}

//we have a warning here
int checkUserInputAgainstInvalidCodes(long userInput) {
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
    for(int i = 0; i < countArray(invalidCodes); i++) {
        if(invalidCodes[i] == userInput) return 1;
    }
}

int splitNumber(long number) {
    int array[9];
    for(int i = 9; i >= 0; i--) {
        array[i] = number % 10;
        number /= 10;
    }
    //printing splited number
    // for(int i = 0; i < 10; i++) {
    //     printf("%d \n", array[i]);
    // }
    return array;
}

int reverseArray(long array[]) {
    int reversedArray[9];
    for(int i = 0; i <= 9; i++) {
        reversedArray[9 - i] = array[i];
    }

    //printing reversedArray
    for(int i = 0; i < 10; i++) {
        printf("%d \n", reversedArray[i]);
    }
}

// int explodeAndReverse(long number) {
//     long array = 
// }

int main() {
    long nationalCode;
    printf("Enter a National Code: ");
    scanf("%ld", &nationalCode);
    printf("Your National Code Is: %ld \n and the size of it is: %d \n", nationalCode, count(nationalCode));
    // printf("the splited version of your national code is: %d \n", splitNumber(nationalCode));
    // splitNumber(nationalCode);
    reverseArray(splitNumber(nationalCode));
    if(checkUserInputAgainstInvalidCodes(nationalCode)) {
        printf("not valid \n");
    } else {
        printf("valid \n");
    }
    return 0;
}