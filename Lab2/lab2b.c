#include <stdio.h>
#include <math.h>

int main() {
    printf("Field | On field | Sum\n");
    printf("------+---------------------+----------------------------------\n");
    {
        unsigned char sum = 0;
        for (int i = 0; i < 8; i++) {
            unsigned char curr = pow(2, i);
            sum += curr;
            printf("%5d |%20u |%21u (= %2.2e)\n", i + 1, curr, sum, (float) sum);
        }
    }
    printf("------+---------------------+----------------------------------\n");
    {
        unsigned int sum = 255;
        for (int i = 8; i < 16; i++) {
            unsigned int curr = pow(2, i);
            sum += curr;
            printf("%5d |%20u |%21u (= %2.2e)\n", i + 1, curr, sum, (float) sum);
        }
    }
    printf("------+---------------------+----------------------------------\n");
    {
        unsigned long sum = 65535;
        for (int i = 16; i < 32; i++) {
            unsigned long curr = pow(2, i);
            sum += curr;
            printf("%5d |%20lu |%21lu (= %2.2e)\n", i + 1, curr, sum, (float) sum);
        }
    }
    printf("------+---------------------+----------------------------------\n");
    {
        unsigned long long sum = 4294967295;
        for (int i = 32; i < 64; i++) {
            unsigned long long curr = pow(2, i);
            sum += curr;
            printf("%5d |%20llu |%21llu (= %2.2e)\n", i + 1, curr, sum, (float) sum);
        }
    } // 1.012e+12 tons = 1 012 000 000 000 tons > 735 800 000 tons (exceeds the real number ~1428 times)

    return 0;
}
