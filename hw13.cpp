#include <stdio.h>

struct Time {
    int h;
    int m;
};

void print_time(struct Time c) {

    int mm = 60*c.h + c.m;

    printf ("%d", mm);

}

struct Time scan_time2() {

    struct Time res;
    scanf ("%d:%d", &res.h, &res.m);
    return res;
}

int main() {
    struct Time a;
    a = scan_time2();
    print_time(a);
    return 0;
}
