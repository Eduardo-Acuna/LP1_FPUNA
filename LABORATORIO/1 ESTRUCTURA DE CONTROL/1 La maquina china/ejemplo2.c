#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int buttonOff = 0;
    int buttonOn = 0;

    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d", &ai);

        if (ai == 0) {
            buttonOff++;
        } else {
            buttonOn++;
        }
    }

    if (buttonOff == 1) {
        printf("SI\n");
    } else {
        int lastButton = n - 1;
        if (buttonOn == lastButton) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
