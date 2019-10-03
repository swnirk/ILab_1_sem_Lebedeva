#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int NOROOTS = 0;
const int ONEROOT = 1;
const int TWOROOTS = 2;
const int INFROOTS = 3;

int Line(double b, double c, double *x1);

int Solve_Sqr(double a, double b, double c, double* x1, double* x2);

//! what func is do: solves quadratic equations
//! @param[in] a, b, c, *x1 = x1, *x2 = x2
//! @return printf ("") if condition is met

int main() {
    int nroots = 0;

    double x1 = 0, x2 = 0;

    double a = 0, b = 0, c = 0;

    printf("ENTER A, B, C:");

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3){
        printf ("ERROR. TRY AGAIN");
        return 1;
    }

    if (a == 0) {
        nroots = Line(b, c, &x1);
    }

    if (a != 0) {
       nroots = Solve_Sqr(a, b, c , &x1, &x2);
    }

    switch (nroots) {

        case 0: //NOROOTS

            printf("No roots");

            break;

        case 1: //ONEROOT

            printf("One Root X = %lg", x1);

            break;

        case 2: //TWOROOTS

            printf("Two Roots X1 = %lg X2 = %lg", x1, x2);

            break;

        case 3: //ANYROOTS

            printf("Any Roots");

            break;

        default:;

    }
    return 0;
}

//! what func is do: solves line equations
//! @param[in] b, c, *x1 = x1
//! @return return 1 if condition is met

int Line(double b, double c, double* x1) {

    assert (x1 != NULL);

    if (b == 0 && c == 0)
        return INFROOTS;

    if (b == 0 && c != 0)
        return NOROOTS;

    if (b!=0)
    {
        *x1 = -c/b;
        return ONEROOT;
    }
}

//! what func is do: solve quatratic equations
//! @param [in] a, b, c, *x1 = x1, *x2 = x2
//! @return return 2 if two roots; return 1 if one root; return 0 else

int Solve_Sqr(double a, double b, double c, double* x1, double* x2) {

    assert (x1 != NULL);
    assert (x2 != NULL);

    double D = b * b - 4 * a * c;

    if (D > 0 && a != 0) {
        double sq = sqrt(D);

        *x1 = (-b + sq) / (2.0 * a);

        *x2 = (-b - sq) / (2.0 * a);

        return TWOROOTS;

    }

    if (D < 0 && a != 0)
        return NOROOTS;

    if (D == 0 && a != 0)
    {
        *x1 = -b/2.0/a;
        return ONEROOT;
    }

}
