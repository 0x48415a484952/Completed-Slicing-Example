#include <stdio.h>
#include <unistd.h>

#define SIZE (10)

int count(long number) {
    int count = 0;
    while(number != 0) {
        count++;
        number /= SIZE;
    }
    return count;
}

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
    for(int i = 0; i < SIZE; i++) {
        if(invalidCodes[i] == userInput) return 1;
    }
    return 0;
}

int * explodeAndReverse(long number) {
    static int array[SIZE - 1];
    for(int i = 0; i < SIZE; i++) {
        array[i] = number % SIZE;
        number /= SIZE;
    }
    return array;
}

int calculateSumOfArrayWithKeyValue(int *ptr) {
    int sum = 0;
    int j = 1;
    for(int i = 1; i < SIZE; i++) {
        sum += ++j * ptr[i];
    }
    return sum;
}

int checkNationalCodeValidation(long userInput) {
    if(checkUserInputAgainstInvalidCodes(userInput)) {
        return 0;
    } else if(count(userInput) == SIZE) {
        int * reversedArray;
        reversedArray = explodeAndReverse(userInput);
        int controlNum = reversedArray[0];
        int sum = calculateSumOfArrayWithKeyValue(reversedArray);
        int recurrent = sum % (SIZE + 1);
        if( (recurrent > 1) && (controlNum == ((SIZE + 1) - recurrent)) ) {
            return 1;
        } else if(recurrent == 0 && controlNum == 0) {
            return 1;
        } else if(recurrent == 1 && controlNum == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

}

int main() {
    long nationalCode;
    printf("Enter a National Code: ");
    scanf("%ld", &nationalCode);
    if(checkNationalCodeValidation(nationalCode)) {
        printf("valid \n");
    } else {
        printf("not valid \n");
    }
    return 0;
}