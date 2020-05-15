//
//  main.c
//  exercises
//
//  Created by teos on 12.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>

#define MINUTES_IN_HOUR 60.0
#define DAYS_IN_WEEK 7
#define FEET_TO_CM 30.48
#define INCH_TO_CM 2.54
#define EX4_INPUT_STRING "Enter a height in centimeters (<=0 to quit): "
#define EX8_INPUT_STRING "Enter next number for first operand (<= 0 to quit): "
#define EX9_INPUT_STRING "Enter the degree in Fahrenheit (q to quit): "

void exercise5_1(void);
void exercise5_2(void);
void exercise5_3(void);
void exercise5_4(void);
void exercise5_5(void);
void exercise5_6(void);
void exercise5_7(void);
void exercise5_7_cube(double number);
void exercise5_8(void);
void exercise5_9(void);
void exercise5_9_Temparatures(double fahrenheit);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("This is exercises\n");
    
    exercise5_1();
    exercise5_2();
    exercise5_3();
    exercise5_4();
    exercise5_5();
    exercise5_6();
    exercise5_7();
    exercise5_8();
    exercise5_9();
    
    return 0;
}

void exercise5_1(void)
{
    int     minutes;
    float   hours;
        
    printf("\n*** Exercise 5.1 ***\n");
        
    printf("Please enter the time in minutes: ");
    scanf("%d", &minutes);
    
    while(minutes > 0)
    {
        hours = minutes / MINUTES_IN_HOUR;
        printf("%d minutes equals to %.2f hours\n", minutes, hours);
        printf("Please enter the time in minutes: ");
        scanf("%d", &minutes);
    }
    
    return;
}

void exercise5_2(void)
{
    int start, stop;
    const int upTo = 11;
    
    printf("\n*** Exercise 5.2 ***\n");
    
    printf("Please enter an integer: ");
    scanf("%d", &start);
    stop = start + upTo;
    
    while (start<stop)
        printf("%d ", start++);
   
    printf("\n");
    return;
}

void exercise5_3(void)
{
    int days, weeks, remainingDays;
    printf("\n*** Exercise 5.3 ***\n");
    
    printf("Enter the number of days: ");
    scanf("%d", &days);
    
    weeks = days / DAYS_IN_WEEK;
    remainingDays = days % DAYS_IN_WEEK;
    
    printf("%d days equals to %d weeks and %d days\n", days, weeks , remainingDays);
    return;
}

void exercise5_4(void)
{
    float heightcm, heightIn;
    short heightFt;
        
    printf("\n*** Exercise 5.4 ***\n");
    
    printf("%s", EX4_INPUT_STRING);
    scanf("%f", &heightcm);
    
    while (heightcm > 0)
    {
        heightFt = heightcm / FEET_TO_CM;
        heightIn = (heightcm - (heightFt * FEET_TO_CM)) / INCH_TO_CM;
        printf("%.1f cm = %hd feet, %.1f inches\n", heightcm, heightFt, heightIn);
        
        printf("%s", EX4_INPUT_STRING);
        scanf("%f", &heightcm);
    }
    
    printf("bye\n");
    return;
}

void exercise5_5(void)
{
    int count, sum, stop;
    
    printf("\n*** Exercise 5.5 ***\n");
    
    count = 0;
    sum = 0;
    
    printf("Enter the limit for summation: ");
    scanf("%d", &stop);
    
    while (count++ < stop)
        sum = sum + count;
    
    printf("sum = %d\n", sum);
    
    return;
}

void exercise5_6(void)
{
    int count, sum, stop;
    
    printf("\n*** Exercise 5.6 ***\n");
    
    count = 0;
    sum = 0;
    
    printf("Enter the limit for summation of squares: ");
    scanf("%d", &stop);
    
    while (count++ < stop)
        sum = sum + count * count;
    
    printf("sum = %d\n", sum);
    
    return;
}

void exercise5_7(void)
{
    double number;
    
    printf("\n*** Exercise 5.7 ***\n");
    
    printf("Enter a number: ");
    scanf("%lf", &number);
    
    exercise5_7_cube(number);
    
    return;
}

void exercise5_7_cube(double number)
{
    double cube;
    
    cube = number * number * number;
    
    printf("The cube of %.2f is %.2f\n", number, cube);
    
    return;
}

void exercise5_8(void)
{
    int operand1, operand2;
        
    printf("\n*** Exercise 5.8 ***\n");
    
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &operand2);
    printf("Now enter the first operand: ");
    scanf("%d", &operand1);
    
    while (operand1 > 0) {
        printf("%d %% %d is %d\n", operand1, operand2, operand1 % operand2);
        printf("%s", EX8_INPUT_STRING);
        scanf("%d", &operand1);
    }
    
    printf("Done\n");
    return;
}

void exercise5_9(void)
{
    double fahrenheit;
    printf("\n*** Exercise 5.9 ***\n");
    
    printf(EX9_INPUT_STRING);
    
    while (scanf("%lf", &fahrenheit) == 1) {
        exercise5_9_Temparatures(fahrenheit);
        printf(EX9_INPUT_STRING);
    }
    
    return;
}

void exercise5_9_Temparatures(double fahrenheit)
{
    double celcius, kelvin;
    const double Fahrenheit_To_Celcius1 = 5.0 / 9.0;
    const double Fahrenheit_To_Celcius2 = 32.0;
    const double Celcius_To_Kelvin_Offset = 273.16;
    
    celcius = Fahrenheit_To_Celcius1 * ( fahrenheit - Fahrenheit_To_Celcius2 );
    kelvin = celcius + Celcius_To_Kelvin_Offset;
    
    printf("%.2f Fahrenheit is %.2f Celcius and %.2f Kelvin\n", fahrenheit, celcius, kelvin);
}
