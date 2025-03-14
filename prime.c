#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int check_prime(long long num) {
    if (num == 2) {
        return 1;
    }

    long long upper_lim = (long long)ceil(sqrt(num));
    for (long long i = 2; i <= (upper_lim); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    long long response;
    printf("Enter a positive integer larger than 1 (entering invalid inputs lead to undefined behaviour): ");
    scanf("%lld", &response);

    if (check_prime(response) == 1) {
        printf("Prime\n");
    } else {
        printf("Not prime\n");
    }

    return 0;
}
