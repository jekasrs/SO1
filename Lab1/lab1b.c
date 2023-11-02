#include <stdio.h>

int main() {
    int firstOperand, secondOperand;

    printf("Enter first operand: ");
    while (scanf("%d", &firstOperand) == 0)
    {
        printf("Invalid value, enter first operand:");
        while (getchar() != '\n');
    }

    printf("Enter second operand: ");
    while (scanf("%d", &secondOperand) == 0)
    {
        printf("Invalid value, enter second operand:");
        while (getchar() != '\n');
    }

    printf("Simple calculator:\n");
    printf("------------------\n");
    printf("%d + %d = %d \n",  firstOperand, secondOperand, firstOperand + secondOperand);
    printf("%d - %d = %d \n",  firstOperand, secondOperand, firstOperand - secondOperand);
    printf("%d * %d = %d \n",  firstOperand, secondOperand, firstOperand * secondOperand);

    if (secondOperand != 0)
    {
        printf("%d / %d = %d \n",  firstOperand, secondOperand, firstOperand / secondOperand);
        printf("%d %% %d = %d \n", firstOperand, secondOperand, firstOperand % secondOperand);
    }

    return 0;
}

// if 'scanf' cannot convert input into integer then he leaves it(input) in a buffer and returns 0
// to clear the buffer we need to remove these characters from buffer by getchar before the end
