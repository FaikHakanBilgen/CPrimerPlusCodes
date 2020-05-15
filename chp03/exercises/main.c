//
//  main.c
//  exercises
//
//  Created by teos on 7.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <float.h>

void intOverflow(void);
void floatUnderflow(void);
void floatOverflow(void);
void exercise01(void);
void exercise02(void);
void exercise03(void);
void exercise04(void);
void exercise05(void);
void exercise06(void);
void exercise07(void);
void exercise08(void);

int main(int argc, const char * argv[])
{
    
    exercise01();
    exercise02();
    exercise03();
    exercise04();
    exercise05();
    exercise06();
    exercise07();
    exercise08();
    
    return 0;
}


void intOverflow(void)
{
    short si=32767;
    unsigned short int usi=65535;
    
    int i = 2147483647;
    unsigned int ui = 4294967295;
    
    long l =            9223372036854775807L;
    unsigned long ul = 18446744073709551615LU;
    
    
    printf("\n\nshort int : %d\t", si);
    printf("short int +1: %d\n", ++si);
    printf("unsigned short int: %u\t", usi);
    printf("unsigned short int +1: %u\n", ++usi);
    
    
    printf("int : %d\t", i);
    printf("int +1: %d\n", ++i);
    printf("unsigned int: %u\t", ui);
    printf("unsigned int +1: %u\n", ++ui);
    
    printf("long : %ld\t", l);
    printf("long +1: %ld\n", ++l);
    printf("unsigned long : %lu\t", ul);
    printf("unsigned long +1: %lu\n", ++ul);
    
    return;
}

void floatOverflow(void)
{
    float big = FLT_MAX;
    double bigger = DBL_MAX;
    long double biggest = LDBL_MAX;
    
    printf("big is %f\nbig+1 is %f\n", big, big + 1.0F);
    printf("bigger is %f\nbigge2 is %f\n", bigger, bigger * 10.0 );
    printf("biggest is %Lf\nbigges2 is %Lf\n", biggest, biggest * 10.0L);
    
    return;
}

void floatUnderflow(void)
{
    float big = FLT_MIN;
    double bigger = DBL_MIN;
    long double biggest = LDBL_MIN;
    
    printf("big is %f\n", --big);
    printf("bigger is %f\n", --bigger);
    printf("biggest is %Lf\n", --biggest);
    
    return;
}

void exercise01(void)
{
    printf("\n*** EXERCISE 1       ***\n");
    printf("\n*** Integer Overflow ***\n");
    intOverflow();
    printf("\n*** Float Overflow   ***\n");
    floatOverflow();
    printf("\n*** Float Underflow  ***\n");
    floatUnderflow();
    printf("\n");
    
    return;
}

void exercise02(void)
{
    char c;
    
    printf("\n*** EXERCISE 2       ***\n");
    printf("Please enter a number: ");
    scanf("%d", &c);
    printf("\nThe number is %d and the ASCII equivalent is %c\n", c, c);
    
    return;
}

void exercise03(void)
{
    printf("\n*** EXERCISE 3       ***\n");
    
    printf("\a");
    printf("Startled by the sudden sound, Sally shouted,\n\"By the Great Pumpkin, what was that!\"\n");
    
    return;
}

void exercise04(void)
{
    float f;
    
    printf("\n*** EXERCISE 4       ***\n");
    
    printf("Enter a floating-point value: ");
    scanf("%f", &f);
    printf("\nfixed-point notation: %f\nexponential notation: %e\np notation: %a\n", f, f, f);
    
    return;
}

void exercise05(void)
{
    float age, secYear, secAge;
    secYear = 3.156E7F;
    
    printf("\n*** EXERCISE 5       ***\n");
    
    printf("Please enter your age: ");
    scanf("%f", &age);
    
    secAge = secYear * age;
    
    printf("You've lived %f seconds\n", secAge);
    
    return;
}

void exercise06(void)
{
    float massH2O = 3.0E-23F;
    float massQuartH2O = 950.0F;
    float quartCount;
    
    printf("\n*** EXERCISE 6       ***\n");
    
    printf("How many quart of water do you have? ");
    scanf("%f", &quartCount);
    printf("This is %e water molecules\n",  quartCount * massQuartH2O / massH2O );
    
    return;
}

void exercise07(void)
{
    float cmPerIn = 2.54F;
    float heightIn;
        
    printf("\n*** EXERCISE 7       ***\n");
    printf("Enter your height in inches: ");
    scanf("%f", &heightIn);
    printf("You're %f in or %f cm tall\n", heightIn, heightIn * cmPerIn);
    
    return;
}

void exercise08(void)
{
    float cups;
    float pint2Cup = 2.0F;
    float cup2Ounce = 8.0F;
    float ounce2tblspn = 2.0F;
    float tblspn2teaspn = 3.0F;
    
    printf("\n*** EXERCISE 8       ***\n");
    
    printf("How many cups ? ");
    scanf("%f", &cups);
    printf("%f cups is %f pints, %f ounces, %f tablespoons and %f teaspoons\n", cups, cups / pint2Cup, cups * cup2Ounce, cups * cup2Ounce * ounce2tblspn, cups * cup2Ounce * ounce2tblspn * tblspn2teaspn);
    
    return;    
}
