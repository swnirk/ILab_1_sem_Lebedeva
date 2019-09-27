#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int line ( float b, float c, float* x1);
int solve_sqr (float a, float b, float c, float* x1, float* x2);

//! what func is do: solves quadratic equations
//! @param[in] a, b, c, *x1 = x1, *x2 = x2
//! @return printf ("") if condition is met

int main()
{
    int nroots = 0;

    float a=0, b=0, c=0;

    printf ("enter a:  \n");

    printf ("enter b:  \n");

    printf ("enter c:  \n");

    scanf ("%f", &a);

    scanf ("%f", &b);

    scanf ("%f", &c);

    // printf("%f %f %f\n\n", a, b, c);

    float x1 = 0, x2 = 0;

    // nroots = solve_sqr(a, b, c, &x1, &x2);

    if (a == 0 )
    {

        nroots = line (b, c, &x1);

    }


    else if (a == 0 && b == 0 && c == 0)

    {

        printf ("Any solves");

    }

    else

    {

        nroots = solve_sqr (a, b, c, &x1, &x2);

    }




    switch ( nroots )
    {

        case 2:

            printf ("Answer is %f, %f\n", x1, x2);

            break;

        case 1:

            printf ("Answer is %.2f", x1);

            break;

        case 0:

            printf ("No roots");

            break;

    }

}
//! what func is do: solves line equations
//! @param[in] b, c, *x1 = x1
//! @return return 1 if condition is met

int line (float b, float c, float* x1)
{
    if (b == 0) return 0;

    else if (c == 0)

    {

        *x1 = 0;

        return 1;
    }

    else

    {


        *x1 = -c/b;

        return 1;
    }
}

//! what func is do: solve quatratic equations
//! @param [in] a, b, c, *x1 = x1, *x2 = x2
//! @return return 2 if two roots; return 1 if one root; return 0 else

int solve_sqr (float a, float b, float c, float* x1, float* x2)

{
    // printf("%f %f %f\n\n", a, b, c);

    float dis = b*b - 4*a*c;

    // printf("%f\n", dis);

    if (dis>0)

    {
        *x1 = (-b + sqrt(dis))/2*a;

        *x2 = (-b - sqrt(dis))/2*a;

        return 2;

    }

    else if (dis == 0)
     {

        *x1 = -b/2*a;

        return 1;

     }

    else

    {
         return 0;

    }
}

//! what func is do: compare two numbers
//! @param[in] num1, num2, dispr
//! @return return 1 if two numbers are equal; return 0 if two numbers aren`t equal

bool is_equal ( float num1, float num2, float dispr)

{
   if (abs(num1 - num2) < dispr) return 1;

   else                          return 0;
}











