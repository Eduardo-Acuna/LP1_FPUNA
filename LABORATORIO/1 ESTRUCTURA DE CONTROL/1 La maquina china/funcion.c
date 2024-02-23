#include "header.h"

int decodificador(int n, int k) {
    for (int i = 0; i < k; i++) {
        if (n % 10 != 0) {
            n--;
        } else {
            n /= 10;
        }
    }
    return n;

}


