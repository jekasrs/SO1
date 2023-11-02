#include <stdio.h>

int main() {
    int arr[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 8; i > 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("+----");
        }
        printf("+\n");
        for (int j = 0; j < 8; j++) {
            printf("| %c%d ", arr[j], i);
        }
        printf("|\n");
    }

    for (int j = 0; j < 8; j++) {
        printf("+----");
    }
    printf("+\n");

    return 0;
}