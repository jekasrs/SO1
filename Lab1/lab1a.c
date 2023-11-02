#include <stdio.h>

int main() {
    int firstOperand = 7;
    int secondOperand = 3;

    printf("Simple calculator:\n");
    printf("------------------\n");
    printf("%d + %d = %d \n",  firstOperand, secondOperand, firstOperand + secondOperand);
    printf("%d - %d = %d \n",  firstOperand, secondOperand, firstOperand - secondOperand);
    printf("%d * %d = %d \n",  firstOperand, secondOperand, firstOperand * secondOperand);
    printf("%d / %d = %d \n",  firstOperand, secondOperand, firstOperand / secondOperand);
    printf("%d %% %d = %d \n", firstOperand, secondOperand, firstOperand % secondOperand);
    return 0;
}
