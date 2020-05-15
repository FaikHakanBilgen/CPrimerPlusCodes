//
//  main.c
//  content
//
//  Created by teos on 9.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <string.h>     // for strlen() prototype
#include <limits.h>
#include <float.h>

#define DENSITY 62.4    // human density in lbs per cu ft
#define PRAISE "You are an extraordinary being."
#define PI 3.141593
#define PAGES 959
#define BLURB "Authentic imitation!"
#define PAGES2 336
#define WORDS 65618
#define Q "His Hamlet was funny without being vulgar."
#define BOOK "War and Peace"

void listing4_1(void);
void listing4_2(void);
void listing4_3(void);
void listing4_4(void);
void listing4_5(void);
void listing4_6(void);
void listing4_7(void);
void listing4_8(void);
void listing4_9(void);
void listing4_10(void);
void listing4_11(void);
void listing4_12(void);
void listing4_13(void);
void listing4_14(void);
void listing4_15(void);
void listing4_16(void);
void review2(void);
void review5(void);

int main(int argc, const char * argv[])
{

    // listing4_1();
//    listing4_2();
//    listing4_3();
//    listing4_4();
//    listing4_5();
//    listing4_6();
//    listing4_7();
//    listing4_8();
//    listing4_9();
//    listing4_10();
//    listing4_11();
//    listing4_12();
//    listing4_13();
//    listing4_14();
//    listing4_15();
//    listing4_16();
    
//    review2();
    review5();
    
    return 0;
}

void listing4_1(void)
{
    float weight, volume;
    int size, letters;
    char name[40];
    
    printf("\n*** Listing 4.1 ***\n");
    
    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);
    
    size = sizeof name;
    letters = strlen(name);
    
    volume = weight / DENSITY;
    
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters, \n", letters);
    printf("and we have %d bytes to store it.\n", size);
    
    return;
}

void listing4_2(void)
{
    char name[40];
    
    printf("\n*** Listing 4.2 ***\n");
    
    printf("What's your name? ");
    scanf("%s", name);
    
    printf("Hello, %s. %s\n", name, PRAISE);
    return;
}

void listing4_3(void)
{
    char name[40];
    
    printf("\n*** Listing 4.3 ***\n");
    
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name is %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name);
    printf("The phrase of praise has %zd letters ", strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);

    return;
}

void listing4_4(void)
{
    float area, circum, radius;
    
    printf("\n*** Listing 4.4 ***\n");
    
    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);
    
    return;
}

void listing4_5(void)
{
    printf("\n*** Listing 4.5 ***\n");
    
    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    
    return;
}

void listing4_6(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;
    
    printf("\n*** Listing 4.6 ***\n");
    printf("The %d contestants ate %f berry pies.\n", number, pies);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing,\n");
    printf("%c%d\n", '$', 2 * cost);
    
    return;
}

void listing4_7(void)
{
    printf("\n*** Listing 4.7 ***\n");
    
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);
    
    return;
}

void listing4_8(void)
{
    printf("\n*** Listing 4.8 ***\n");
    
    const double RENT = 3852.99;
    
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3e*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%10.4E*\n", RENT);
    printf("*%10.5E*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);
    
    return;
}

void listing4_9(void)
{
    printf("\n*** Listing 4.9 ***\n");
    
    printf("%x %X %#x\n", 31, 31, 31);
    printf("**%d**% d**% d**\n", 42, 42, -42);
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
    
    return;
}

void listing4_10(void)
{
    printf("\n*** Listing 4.10 ***\n");
    
    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);
    
    return;
}

void listing4_11(void)
{
    short num = PAGES2;
    short mnum = -PAGES2;
    
    printf("\n*** Listing 4.11 ***\n");
    
    
    printf("num as short and unsigned short: %hd %hu\n", num, num);
    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
    printf("num as int and char: %d %c\n", num, num);
    printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);
    
    return;
}

void listing4_12(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    
    int sz = sizeof(float);
    
    printf("\n*** Listing 4.12 ***\n");
    
    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
    
    printf("size of float is %zd\n", sz );
    
    return;
}

void listing4_13(void)
{
    int bph20 = 212;
    int rv;
    
    printf("\n*** Listing 4.13 ***\n");
    
    rv = printf("%d F is water's boiling point.\n", bph20);
    printf("The printf() function printed %d characters.\n", rv);
    
    return;
}

void listing4_14(void)
{
    printf("\n*** Listing 4.14 ***\n");
    
    printf("Here's one way to print a ");
    printf("long string.\n");
    
    printf("Here's another way to print a \
long string.\n");
    
    printf("Here's the newest way to print a "
           "long string.\n");
    
    return;
}

void listing4_15(void)
{
    printf("\n*** Listing 4.15 ***\n");
    
    int age;
    float assets;
    char pet[30];
    
    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);
    
    return;
}

void listing4_16(void)
{
    printf("\n*** Listing 4.16 ***\n");
    
    unsigned width, precision;
    int number = 256;
    double weight = 242.5;
    
    printf("Enter a field width:\n");
    scanf("%d", &width);
    printf("The number is :%*d:\n", width, number);
    printf("Now enter a width and a precision:\n");
    scanf("%d %d", &width, &precision);
    printf("Weight = %*.*f\n", width, precision, weight);
    printf("Done!\n");
    
    return;
}

void review2(void)
{
    printf("2.a\n");
    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    printf("2.b\n");
    printf("%c%c%c\n", 'H', 105, '\41');
    printf("2.c\n");
    printf("%s\nhas %d characters.\n", Q, strlen(Q));
    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);
    printf("2.c2\n");
    printf("\"%s\"\nhas %d characters.\n", Q, strlen(Q));
    return;
}

void review5(void)
{
    float cost = 12.99;
    float percent = 80.0;
    printf("This copy of \"%s\" sells for $%.2f.\nThat is %2.0f%% of list.\n", BOOK, cost, percent);
    
    return;
}
