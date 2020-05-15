//
//  main.c
//  exercises
//
//  Created by teos on 22.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define STR7 "\n*** Exercise 9.7 ***\n"
#define STR_1 ""


void exercise9_7(void);
int exercise9_7AlphaOrder(char ch);
void exercise9_8(void);
double exercise9_8power(double n, int p);
double exercise9_8powerR(double n, int p);
void exercise9_10(void);
void exercise9_10_to_base_n(unsigned long n, int base);

void exercise9_11(void);
unsigned long fibonacciR(unsigned n);
unsigned long fibonacciL(unsigned n);

int main(int argc, const char * argv[])
{
    
    printf("\n*** Chapter 9 Exercises ***\n");
    //exercise9_7();
    //exercise9_8();
    //exercise9_10();
    exercise9_11();
    return 0;
}

void exercise9_7(void)
{
    int ch;
    int order;
    
    printf(STR7);
    
    while ( (ch = getchar()) != EOF )
    {
        order = exercise9_7AlphaOrder(ch);
        if ( order !=0 )
            printf("%c is the %d character in the alphabet\n", ch, order);
    }
    
    printf("Bye!\n");
    return;
}

int exercise9_7AlphaOrder(char ch)
{
    if ( !isalpha(ch) )
        return -1;
    else
        return tolower(ch) - 'a' + 1;
}

void exercise9_8(void)
{
    double base;
    int pwr;
    double result;
    
    printf("Enter a number and power: ");
    while ( scanf("%lf%d", &base, &pwr)==2 )
    {
        result = exercise9_8powerR(base, pwr);
        if ( base ==0 && pwr == 0 )
            printf("0 to the power of 0 is undefined\n");
        else
            printf("%lf to the power of %d equals %lf\n", base, pwr, result);
        printf("Enter a number and power:");
    }
    
    printf("Bye.\n");
    return;
}

double exercise9_8power(double n, int p)
{
    double pwr = 1;
    int i, upper;
    
    upper = p < 0 ? p*-1 : p;
    
    for (i=0; i< upper; i++)
        pwr *= n;
    
    if ( n == 0 )
        return 0;
    
    return p < 0 ? 1.0/pwr :  pwr;
    
}

double exercise9_8powerR(double n, int p)
{
    int absP;
    double result = 0.0;
    
    absP = p < 0 ? p*-1 : p;
    
    if (n==0)
        return 0.0;
    
    if (p==0)
        return 1.0;
    
    if ( absP > 0 )
        result = n * exercise9_8powerR(n, absP-1);
    
    if ( p < 0 )
        result = 1.0 / result;
    
    return result;
        
}

void exercise9_10(void)
{
    unsigned long number;
    int base;
    
    printf("\n*** Exercise 9.10 ***\n");
    printf("Enter an integer and a base (q to quit):");
    while (scanf("%lu%d", &number, &base ) == 2)
    {
        printf("Base %d equivalent: ", base);
        exercise9_10_to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer and a base (q to quit):");
    }
    return;
}

void exercise9_10_to_base_n(unsigned long n, int base)
{
    int r;
    
    r = n % base;
    
    if ( n >= base  )
        exercise9_10_to_base_n( n / base, base);
    
    putchar( '0' + r);
    
    return;
}

void exercise9_11(void)
{
    unsigned int num;
    
    printf("\n*** Exercise 9.11 ***\n");
    
    printf("Enter a number (q to quit): ");
    while (scanf("%u", &num) == 1)
    {
        printf("The fibonacci number of %u is %lu\n", num, fibonacciL(num));
        printf("The fibonacci number of %u is %lu\n", num, fibonacciR(num));        
        printf("Enter a number (q to quit): ");
    }
    
    return;
}

unsigned long fibonacciR(unsigned n)
{
    if (n>2)
        return fibonacciR(n-1) + fibonacciR(n-2);
    else
        return 1;
}

unsigned long fibonacciL(unsigned n)
{
    unsigned long c_2, c_1, c;
    unsigned i;
    
    c=0;
    c_2 = c_1 = 1;
    
    if ( n < 3 && n > 0 )
        c = 1;
    
    for(i=3; i <= n; i++)
    {
        c = c_1 + c_2;
        c_2 = c_1;
        c_1 = c;
    }
    
    return c;
}
