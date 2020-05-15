//
//  main.c
//  exercises
//
//  Created by teos on 14.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include <math.h>

#define STRING6_8 "Enter two floating point numbers (or q to quit): "
#define STRING6_10 "Enter lower and upper limits: "
#define STRING6_10_2 "The sums of the squares from %d to %d is %d\n"
#define STRING6_12 "Enter the number of terms: "

const int LETTER_COUNT = 26;
const int ARRAY_SIZE = 8;
const int MAX_CHARS = 255;
const int DUNBARS_NUMBER = 150;

void exercise6_1(void);
void exercise6_2(void);
void exercise6_3(void);
void exercise6_4(void);
void exercise6_5(void);
void exercise6_6(void);
void exercise6_7(void);
void exercise6_8(void);
void exercise6_9(void);
float exercise6_9Calc(float f1, float f2);
void exercise6_10(void);
void exercise6_11(void);
void exercise6_12(void);
void exercise6_13(void);
void exercise6_14(void);
void exercise6_15(void);
void exercise6_16(void);
void exercise6_17(void);
void exercise6_18(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("This is exercises!\n");
    
//    exercise6_1();
//    exercise6_2();
//    exercise6_3();
//    exercise6_4();
//    exercise6_5();
//    exercise6_6();
//    exercise6_7();
//    exercise6_8();
//    exercise6_9();
//    exercise6_10();
//    exercise6_11();
//    exercise6_12();
//    exercise6_13();
//    exercise6_14();
//    exercise6_15();
//    exercise6_16();
//    exercise6_17();
  
    exercise6_18();
    
    return 0;
}

void exercise6_1(void)
{
    char lowerCaseLetters[LETTER_COUNT];
    int index;
    
    printf("\n*** Exercise 1 ***\n");
    
    for(index=0; index!=LETTER_COUNT; index++)
        lowerCaseLetters[index] = 'a' + index;
    
    for(index=0; index!=LETTER_COUNT; index++)
        printf("%c ", lowerCaseLetters[index]);
    
    printf("\n");
    return;
}

void exercise6_2(void)
{
    int i, j;
    printf("\n*** Exercise 2 ***\n");
    
    for(i = 1; i<=5; i++)
    {
        for(j=1;j<=i;j++)
            printf("%c", '$');
        
        printf("\n");
    }
    
    printf("\n");
    
    return;
}

void exercise6_3(void)
{
    int i, j;
    
    printf("\n*** Exercise 3 ***\n");
    
    for(i = 0; i<=5; i++)
    {
        for(j=0;j<=i;j++)
            printf("%c", 'F'-j);
        
        printf("\n");
    }
    
    printf("\n");
    
    return;
}

void exercise6_4(void)
{
    int i, j;
    char ch = 'A';
    
    printf("\n*** Exercise 4 ***\n");
    
    for(i = 0; i<=5; i++)
    {
        for( j=0;j<=i;j++)
            printf("%c", ch++);
        
        printf("\n");
    }
    
    printf("\n");
    
    return;
}

void exercise6_5(void)
{
    int row, rows, column, columns;
    char downTo = 'A', startFrom;
    
    
    printf("\n*** Exercise 5 ***\n");

    printf("Please enter the starting uppercase letter of the Letter Pyramid: ");
    scanf("%c", &startFrom);
    
    rows = startFrom - downTo + 1;
    columns = 2 * (startFrom - downTo) + 1;
    
    printf("rows=%d, columns=%d\n", rows, columns);
    
    for(row = 1; row <= rows; row++)
    {
        for(column=0; column <= columns / 2 +1; column++)
        {
            printf("%c", downTo+column);
        }
        printf("\n");
    }
    return;
}

void exercise6_6(void)
{
    int start, stop, current;
    
    printf("\n*** Exercise 6 ***\n");
    
    printf("Please enter the start and stop numbers: ");
    scanf("%d%d", &start, &stop);
    
    for(current = start; current <= stop; current++)
        printf("%d\t%d\t%d\n", current, current*current, current*current*current);
    
    return;
}

void exercise6_7(void)
{
    char aWord[20];
    int index;
    
    printf("\n*** Exercise 7 ***\n");
    
    printf("Please enter your word: ");
    scanf("%s", aWord);
    
    for(index = strlen(aWord)-1; index >= 0; index--)
        printf("%c ", aWord[index]);

    printf("\n");
    return;
}

void exercise6_8(void)
{
    float f1, f2;
    
    printf("\n*** Exercise 8 ***\n");
    
    printf("%s", STRING6_8);
    
    while( scanf("%f%f", &f1, &f2) == 2 )
    {
        printf("%f\n", fabs(f1-f2)/(f1*f2) );
        printf("%s", STRING6_8);
    }
    
    printf("\n");
    return;
}

void exercise6_9(void)
{
    float f1, f2;
    
    printf("\n*** Exercise 9 ***\n");
    
    printf("%s", STRING6_8);
    
    while( scanf("%f%f", &f1, &f2) == 2 )
    {
        printf("%f\n", exercise6_9Calc(f1, f2) );
        printf("%s", STRING6_8);
    }
    
    printf("\n");
    return;
}

float exercise6_9Calc(float f1, float f2)
{
    return fabs(f1-f2)/(f1*f2);
}

void exercise6_10(void)
{
    int lower, upper, current, sum;

    printf("\n*** Exercise 10 ***\n");
    
    printf(STRING6_10);
    for( sum=0, scanf("%d%d", &lower, &upper); upper > lower; scanf("%d%d", &lower, &upper), sum=0)
    {
        for(current = lower; current <= upper; current++)
            sum += current*current;
        
        printf(STRING6_10_2, lower, upper, sum);
        printf(STRING6_10);
    }
    
    return;
}

void exercise6_11(void)
{
    int i, intArr[ARRAY_SIZE];
    
    printf("\n*** Exercise 11 ***\n");
    printf("Enter 8 integers\n");
    
    for(i=0; i!=ARRAY_SIZE; i++)
        scanf("%d", &intArr[i]);
    
    printf("\n");
    
    for(i=ARRAY_SIZE-1; i>=0; i--)
        printf("%d ", intArr[i]);
    
    printf("\n");
    return;
}

void exercise6_12(void)
{
    float series1, series2;
    int limit, current;
    float minusOne;
    
    printf("\n*** Exercise 12 ***\n");
    
    printf("Enter the number of terms: ");
    for (scanf("%d", &limit); limit > 0; scanf("%d", &limit)) {
        for (minusOne = -1.0, current = 1, series1=0.0, series2 = 0.0; current <= limit; current++) {
            minusOne *= -1.0;
            series1 += 1.0 / current;
            series2 += minusOne / current;
        }
        printf("Sum of Series1 = %f, Sum of Series2 = %f\n", series1, series2);
        printf("Enter the number of terms: ");
    }
    
    return;
}

void exercise6_13(void)
{
    int index, intArray[ARRAY_SIZE];
    
    printf("\n*** Exercise 13 ***\n");
    
    intArray[0] = 1;
    
    for(index=1; index!=ARRAY_SIZE; index++)
        intArray[index] = intArray[index-1] * 2;
    
    index=0;
    do {
        printf("%d ", intArray[index++]);
    } while (index!=ARRAY_SIZE);
    
    printf("\n");
    return;
}

void exercise6_14(void)
{
    double doubles1[ARRAY_SIZE], doubles2[ARRAY_SIZE];
    int index;
    
    printf("\n*** Exercise 14 ***\n");
    
    printf("Enter 8 double values: ");
    for(index = 0; index!=ARRAY_SIZE; index++)
    {
        scanf("%lf", &doubles1[index]);
    }
    
    doubles2[0] = doubles1[0];
    for(index = 1; index!=ARRAY_SIZE; index++)
        doubles2[index] = doubles2[index-1] + doubles1[index];
    
    for(index=0; index!=ARRAY_SIZE; index++)
        printf("%f ", doubles1[index] );
    
    printf("\n");
    
    for(index=0; index!=ARRAY_SIZE; index++)
        printf("%f ", doubles2[index] );
    
    printf("\n");
    return;
}

void exercise6_15(void)
{
    int index;
    char chars[MAX_CHARS];
    
    printf("\n*** Exercise 15 ***\n");
    printf("Enter an input line:\n");
    
    index=0;
    do {
        scanf("%c", &chars[index]);
    } while (chars[index++]!='\n');
    
    //for(index = 0; chars[index]!= '\n'; index++);
    
    for(; --index>=0; )
        printf("%c", chars[index]);
    
    printf("\n");
    return;
}

void exercise6_16(void)
{
    float dei;
    printf("\n*** Exercise 16 ***\n");
    return;
}

void exercise6_17(void)
{
    float money=1000000.0F;
    int years=0;

    printf("\n*** Exercise 17 ***\n");
    
    do {
        money *= 1.08;
        money -= 100000;
        years++;
        printf("year=%d, balance=%f\n", years, money);
    } while (money > 0);
    
    printf("It took %d years for Chuckie to empty his account\n", years);
    
    return;
}

void exercise6_18(void)
{
    int friends = 5, weeks = 1;
    
    printf("\n*** Exercise 18 ***\n");
    
    while(friends < DUNBARS_NUMBER)
    {
        friends -= weeks++;
        friends *=2;
        printf("Week = %d Friends = %d\n", weeks, friends);
    }
    printf("\n");
    return;
}
