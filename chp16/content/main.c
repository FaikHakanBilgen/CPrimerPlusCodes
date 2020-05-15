//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 11.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "chp16content.h"
#include "names_st.h"
#include "names_st.h"   // the ifndef macros prohibits double inclusion !!!

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Contents of Chapter 16 ***\n");
    //listing16_1();
    //listing16_2();
    //listing16_3();
    //listing16_4();
    //listing16_5();
    //listing16_8();
    //listing16_9();
    //listing16_11();
    //listing16_12();
    //listing16_13();
    //listing16_16();
    //listing16_17();
    //listing16_18();
    listing16_20();
    return 0;
}


void listing16_1(void)
{
    int x = TWO;
        
    puts("\n*** Listing 16.1 ***\n");
    
    PX;
    x = FOUR;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");
    
    return;
}

void listing16_2(void)
{
    int x = 5;
    int z;
    
    puts("\n*** Listing 16.2 ***\n");
    
    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z);
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x+2));
    printf("Evaluating 100/SQUARE(2): ");
    PR(100/SQUARE(2));
    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x));
    printf("After incrementing, x is %x.\n", x);
    
    return;
}

void listing16_3(void)
{
    int y = 5;
    
    puts("\n*** Listing 16.3 ***\n");
    
    PSQR(y);
    PSQR(2 + 4);
    
    return;
}

void listing16_4(void)
{
    int XNAME(1) = 14;                  // becomes int x1 = 14;
    int XNAME(2) = 20;                  // becomes int x2 = 20;
    int x3 = 30;
    puts("\n*** Listing 16.4 ***\n");
    
    PRINT_XN(1);                        // becomes printf("x1 = %d\n", x1);
    PRINT_XN(2);
    PRINT_XN(3);
    
    return;
}

void listing16_5(void)
{
    double x = 48;
    double y;
    puts("\n*** Listing 16.5 ***\n");
    
    y = sqrt(x);
    PR2(1, "x = %g\n", x);
    PR2(2, "x = %.2f, y = %.4f\n", x, y);
    return;
}

void listing16_8(void)
{
    puts("\n*** Listing 16.8 ***\n");
    
    names candidate;
    
    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    
    return;
}

void listing16_9(void)
{
    int i;
    int total = 0;
    
    puts("\n*** Listing 16.9 ***\n");
    
    for ( i = 1; i <= LIMIT; i++ )
    {
        total += 2*i*i + 1;
#ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
#endif
        printf("Grand total = %d\n", total);
    }
    
    return;
}


void listing16_11(void)
{
    names winner = { "Less", "Ismoor"};
    
    puts("\n*** Listing 16.10 ***\n");
    
    printf("The winner is %s %s.\n", winner.first, winner.last);
    
    return;
}

void listing16_12(void)
{
    puts("\n*** Listing 16.12 ***\n");
    
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s.\n", __func__);
    why_me();
    return;
}

void why_me(void)
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}


void listing16_13(void)
{
    int d = 5;
    
    puts("\n*** Listing 16.13 ***\n");
    
    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0*d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));
    
    switch (_Generic(d * 2.0, int:0, double:1)) {
        case 0:
            printf("d is integer\n");
            break;
        case 1:
            printf("d is double\n");
            break;
        default:
            break;
    }
    
    
    return;
}

void listing16_13_5(void)
{
    puts("\n*** Listing 16.13.5 ***\n");
    eatline();
    return;
}

void static inline eatline(void)
{
    while( getchar() != '\n' )
        continue;
}

void listing16_16(void)
{
    int n;
    puts("\n*** Listing 16.16 ***\n");

    atexit(sign_off);    
    puts("Enter an integer");
    if ( scanf("%d", &n) != 1 )
    {
        puts("That's no integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n, ( n % 2 == 0) ? "even" : "odd");
    
    return;
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeaSaw Software!");
}

void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to you upon failure of your program.");
}


void fillarray(double ar[], int n)
{
    int index;
    
    for ( index = 0; index < n; index++ )
        ar[index] = (double)rand() / ((double) rand() + 0.1);
}

void showarray(double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++ )
    {
        printf("%9.4f ", ar[index]);
        if ( index % 6 == 5 )
            putchar('\n');
    }
    
    if ( index % 6 != 0 )
        putchar('\n');
    
}

int mycomp( const void *p1, const void *p2 )
{
    const double *a1 = (const double*) p1;
    const double *a2 = (const double*) p2;
    
    if ( *a1 < *a2 )
        return -1;
    else
        if ( *a1 == *a2 )
            return 0;
        else
            return 1;
}

void listing16_17(void)
{
    double vals[NUM];
    
    puts("\n*** Listing 16.17 ***\n");
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
    
    return;
}

void listing16_18(void)
{
    double x, y, z;
    puts("\n*** Listing 16.18 ***\n");
    
    puts("Enter a pair of numbers ( 0 0 to quit): ");
    while ( scanf("%lf%lf", &x, &y) == 2  && ( x!=0 || y != 0 ) )
    {
        z = x * x - y * y;
        assert( z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers:");
    }
    
    puts("Done");
    
    
    return;
}


void listing16_20(void)
{
    int values[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int target[SIZE];
    double curious[SIZE / 2] = { 2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30 };
    
    puts("\n*** Listing 16.20 ***\n");
    
    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("target (copy of values):");
    show_array(target, SIZE);
    
    puts("\nUsing memmove() with overlapping ranges:");
    memmove( values+2, values, 5 * sizeof(int) );
    puts("values -- elements 0-5 copied to 2-7");
    show_array(values, SIZE);
    
    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target -- 5 doubles into 10 int positions:");
    show_array(target, SIZE/2);
    show_array(target+5, SIZE/2);
    return;
}

void show_array(const int ar[], int n)
{
    int i;
    
    for( i = 0; i < n; i++ )
        printf("%d ", ar[i]);
    
    putchar('\n');
}
