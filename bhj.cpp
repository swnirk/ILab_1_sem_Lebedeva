#include <stdio.h>

struct Time {

    int h1;
    int m1;
};

int main () {

    int h, m, mm, sum;

    scanf ("%d %d %d", &h, &m, &mm);

    sum = h*60 + m + mm;

    struct Time res;

    res.h1 = sum/60;
    res.m1 = sum%60;

    printf ("%d\n%d", res.h1, res.m1);

    return 0;
}














