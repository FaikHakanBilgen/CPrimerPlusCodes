//
//  main.c
//  content
//
//  Created by teos on 14.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>

#define ROWS 6
#define CHARS 10
#define SIZE 10
#define PAR 72

void listing6_9(void);
void listing6_14(void);
void listing6_17(void);
void listing6_18(void);
void listing6_19(void);
void listing6_20(void);
double power(double n, int p);
void CommaOperatorTest(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("This is content!\n");
//    listing6_9();
    listing6_14();
    listing6_17();
    listing6_18();
    listing6_19();
    listing6_20();
    CommaOperatorTest();
    return 0;
}

void listing6_9(void)
{
    long num;
    long sum = 0L;
    _Bool input_is_good;
    
    printf("\n*** Listing 6.9 ***\n");
    printf("Please enter and an integer to be summed ");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num)==1);
    while (input_is_good) {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        input_is_good = (scanf("%ld", &num) == 1);
    }
    
    printf("Those integers sum to %ld.\n", sum);
    
    printf("sizeof input_is_good is %zd bytes\n", sizeof input_is_good);
    
    return;
}

void CommaOperatorTest(void)
{
    int x, y, z;
    
    printf("\n*** CommaOperatorTest ***\n");
    
    x = ( y=3, ( z = ++y + 2) + 5);
    
    printf("x=%d, y=%d, z=%d\n", x,y,z);

    return;
}

void listing6_14(void)
{
    int t_ct;
    double time, power_of_2;
    int limit;
    
    printf("\n*** Listing 6.14 ***\n");
    
    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);
    
    for (time=0, power_of_2=1, t_ct=1; t_ct <= limit; t_ct++, power_of_2 *= 2) {
        time+= 1.0 / power_of_2;
        printf("time = %f when terms = %d.\n", time, t_ct);
    }
    
    return;
}

void listing6_17(void)
{
    int row;
    char ch;

    printf("\n*** Listing 6.17 ***\n");
    
    for(row=0; row < ROWS; row++)
    {
        for (ch='A'; ch < ('A'+CHARS); ch++)
            printf("%c", ch);
        printf("\n");
    }
    
    return;
}

void listing6_18(void)
{
    const short ROWS2 = 6;
    const short CHARS2 = 6;
    
    short row;
    char ch;
    
    printf("\n*** Listing 6.18 ***\n");
    
    for( row = 0; row < ROWS2; row++ )
    {
        for ( ch = 'A' + row; ch < 'A' + CHARS2; ch++  )
            printf("%c", ch);
        
        printf("\n");
    }
    
    return;
}

void listing6_19(void)
{
    int index, scores[SIZE];
    int sum = 0;
    float average;
    
    printf("\n*** Listing 6.19 ***\n");
    
    printf("Enter %d golf scores:\n", SIZE);
    for(index = 0; index != SIZE; index++)
        scanf("%d", &scores[index]);
    
    printf("The scores read in are as follows:\n");
    for(index = 0; index != SIZE; index++)
        printf("%5d", scores[index]);
    printf("\n");
    
    for(index=0; index!=SIZE; index++)
        sum+=scores[index];
    
    average = (float)sum / SIZE;
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);
    
    return;
}

void listing6_20(void)
{
    double x, xpow;
    int exp;
    
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit\n");
    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow=power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    
    printf("Hope you enjoyed this power trip -- bye!\n");
    
    return;
}

double power(double n, int p)
{
    double pow = 1;
    int i;
    
    for(i=1;i<=p;i++)
        pow *= n;
    
    return pow;
}
