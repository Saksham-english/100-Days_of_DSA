#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int a[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    for( ; i < p && j < q; ) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    for( ; i < p; i++) {
        printf("%d ", a[i]);
    }

    for( ; j < q; j++) {
        printf("%d ", b[j]);
    }

    return 0;
}
 /* Start from the first element of both logs

Compare the two arrival times

Add the smaller one to the final log

Move forward in that log

Repeat until all entries are included /*    