#include <stdio.h>
int main() {
    float number;

    printf("Enter your number: ");
    scanf("%f", &number);

    if (number >= 1 && number <= 10) {
        printf("Inside ranges\n");
    } else if (number >=29 && number <=51 ) {
        printf("Inside ranges\n");
    } else {
        printf("Outside ranges\n");
    }
    return 0;
}