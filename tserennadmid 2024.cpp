#include <stdio.h>

int main() {
    int n;
    printf("hemjeeg oruul ");
    scanf("%d", &n);

    int a[n];
    printf("Husnegtiin utgiig oruul: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int maxCount = 0;
    int maxElement = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElement = a[i];
        }
    }

    if (maxCount > 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] == maxElement) {
                printf("Hamgiin ih davtagdsan element %d\n", maxElement);
                break;
            }
        }
    } else {
        printf("davtagdsan element bhku\n");
    }

    return 0;
}
