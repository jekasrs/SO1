#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char year[5];

    printf("Enter your year of birth: ");

    bool valid = false;
    while (!valid) {
        if (scanf("%4s", year) == 1) {
            valid = true;
            for (int i = 0; i < 4; i++) {
                if (!isdigit(year[i])) {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid) {
            printf("Invalid value, enter your year of birth: ");
            while (getchar() != '\n');
        }
    }

    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += year[i] - '0';

    printf("The digit sum of %s is %c + %c + %c + %c = %d .", year, year[0], year[1], year[2], year[3], sum);
    return 0;
}
