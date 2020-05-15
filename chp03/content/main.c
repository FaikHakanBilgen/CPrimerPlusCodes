//
//  main.c
//  content
//
//  Created by teos on 2.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <inttypes.h>

void listing3_3(void);
void listing3_4(void);
void listing3_5(void);
void listing3_6(void);
void listing3_7(void);
void listing3_75(void);
void listing3_8(void);
void intOverflow(void);
void intUnderflow(void);
void TestIntegerTypeAndFormats(void);
void TestCharStorage(void);
void TestConsecutiveStrings(void);
void floatOverflow(void);
void TestFloat(void);
void BadCount(void);
void EscapeTest(void);

int main(int argc, const char * argv[])
{
    printf("\n****** Listing 3.3 ******\n");
    listing3_3();
    
    printf("\n****** Listing 3.4 ******\n");
    listing3_4();
    
    printf("\n****** Listing 3.5 ******\n");
    listing3_5();
    
    printf("\n****** Listing 3.6 ******\n");
    listing3_6();
    
    printf("\n****** Listing 3.7 ******\n");
    listing3_7();
    
    printf("\n****** Listing 3.75 ******\n");
    listing3_75();
    
    printf("\n****** Listing 3.8 ******\n");
    listing3_8();
    
    printf("\n\n/******** Overflow Test ********/\n");
    intOverflow();
    printf("\n/******** Underflow Test ********/\n");
    intUnderflow();
    
    printf("\n/******** Integer Type and Formats ********/\n");
    TestIntegerTypeAndFormats();

    // TestCharStorage();
    printf("\n/******** Consecutive Strings in printf() ********/\n");
    TestConsecutiveStrings();
    
    printf("\n/******** Float Overflow Test ********/\n");
    floatOverflow();
    
    printf("\n/******** Test Float ********/\n");
    TestFloat();
    
    printf("\n/******** Bad Count ********/\n");
    BadCount();
    
    printf("\n/******** Escape Test ********/\n");
    EscapeTest();
    
    return 0;
}


void listing3_3(void)
{
    int x = 100;
    
    printf("dec = %d; octal = %o; hex = %x\n", x ,x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
}

void listing3_4(void)
{
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig= %lld and not %d\n", verybig, verybig);
    
    return;
}

void listing3_5(void)
{
    char ch;
    
    printf("Please enter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d\n", ch, ch);
    
    return;
}

void listing3_6(void)
{
    int32_t me32;
    
    me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);
    
    return;
}

void listing3_7(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    
    printf("%f can be written %e\n", aboat, aboat);
    // next line requires C99 or later compliance
    printf("And it's a %a in hexadecimal, powers of 2 notation\n", aboat);
    printf("%f can be written %e\n", abet, abet);
    printf("%Lf can be written %Le\n", dip, dip);
    
    return;
}

void listing3_75(void)
{
    float a, b;
    
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    
    printf("%f\t%e\n", a, a);
    
    return;
}

void listing3_8(void)
{
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type float has a size of %zd bytes.\n", sizeof(float));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type long double has a size of %zd bytes.\n", sizeof(long double) );
    
    return;
}

void intUnderflow(void)
{
    short  si=0;
    unsigned short  usi=0;
    
    int i = 0;
    unsigned int ui = 0;
    
    long l = 0;
    unsigned long ul = 0;
    
    printf("\n\nshort int : %d\t", si);
    printf("short int -1: %d\n", --si);
    printf("unsigned short int: %u\t", usi);
    printf("unsigned short int -1: %u\n", --usi);
    
    
    printf("int : %d\t", i);
    printf("int -1: %d\n", --i);
    printf("unsigned int: %u\t", ui);
    printf("unsigned int -1: %u\n", --ui);
    
    printf("long : %ld\t", l);
    printf("long -1: %ld\n", --l);
    printf("unsigned long : %lu\t", ul);
    printf("unsigned long  -1: %lu\n", --ul);
    
    return;
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
    float big = 3.4E38;
    float toobig = 3.4E38 * 100.0F;
    
    printf("big is %f\n", big);
    printf("too big is %f\n", toobig);
    
    return;
}

void TestIntegerTypeAndFormats(void)
{
    short s = 32767;
    int i = 2147483647;
    long l = 9223372036854775807L;
    
    unsigned short us = 65535;
    unsigned int ui = 4294967295;
    unsigned long ul = 18446744073709551615LU;
    
    
    printf("\n******** Signed Output *******\n");
    printf("short dec = %hd octal = %ho hex = %hx\n", s, s, s);
    printf("int   dec = %d  octal = %o  hex = %x\n", i, i, i);
    printf("long dec = %ld octal = %lo hex = %lx\n", l, l, l);
    
    printf("\n******** Unsigned Output *******\n");
    printf("unsigned short dec = %hu octal = %ho hex = %hx\n", us, us, us);
    printf("unsigned int   dec = %u  octal = %o  hex = %x\n", ui, ui, ui);
    printf("unsigned long  dec = %lu  octal = %lo  hex = %lx\n", ul, ul, ul);
    
    return;
}

void TestCharStorage(void)
{
    char c = 'FATE';
    
    printf("%S\n", c);
}


void TestConsecutiveStrings(void)
{
    printf("This is the first part" "and this is the second part\n");
}

void TestFloat(void)
{
    float pi = 3.1415926536;
    double pi2 = 3.1415926536;
    long double pi3 = 3.1415926536;
    
    printf("float pi is %10.10f\tdouble pi is %10.10f\tlong double pi is %10.10Lf\n", pi, pi2, pi3);
    
    return;
}

void BadCount(void)
{
    int n = 4;
    int m = 5;
    
    float f = 7.0f;
    float g = 8.0f;
    
    printf("%d\n", n, m);
    printf("%d %d %d\n", n);
    printf("%d %d\n", f, g);
    
    return;
}

void EscapeTest(void)
{
    float salary;
    
    printf("\aEnter your desired monthly salary:");
    printf(" $_______\b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");
    
    return;
}
