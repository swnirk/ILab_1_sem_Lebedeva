#include <stdio.h>
struct Time {
    int h;
    int m;
};

struct Time min2time(int mm) {
    // ��� ����� �������� ���
    struct Time res;
    res.h = mm/60;
    res.m = mm%60;
    return res;
}

int  main() {
    int mm;
    struct Time res;

    scanf("%d", &mm);    // ��������� ����� � 0:00

    res = min2time(mm);        // ��������� ���� � ������

    printf("%02d:%02d\n", res.h, res.m);          // �������� ���������

    return 0;
}
