//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 14.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "diceroll.h"

void listing12_1(void);
void listing12_2(void);
void listing12_3(void);
void listing12_4(void);
void trystat(void);
void critic(void);
int units = 0;

void listing12_5(void);
void report_count(void);
void accumulate(int k);
int count = 0;

extern int rand0(void);
void listing12_8(void);

extern void srand1(unsigned int x);
extern int rand1(void);
void listing12_10(void);

void listing12_13(void);

void listing12_14(void);

void listing12_15(void);
int static_store = 30;
const char *pcg = "String Literal";


int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Content for Chapter 12 ***");
//    listing12_1();
//    listing12_2();
//    listing12_3();
//    listing12_4();
//    listing12_5();
//    listing12_8();
//    listing12_10();
//    listing12_13();
//    listing12_14();
    listing12_15();
    return 0;
}


void listing12_1(void)
{
    int x = 30;
    
    puts("\n*** Listing 12.1 ***");
    printf("x in outer block: %d at %p\n", x, &x);
    {
        int x = 77;
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    while (x++ < 33) {
        int x = 100;
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    return;
    
}

void listing12_2(void)
{
    puts("\n*** Listing 12.2 ***");
    
    int n = 8;
    
    printf("    Initially, n = %d at %p\n", n, &n);
    
    for( int n=1; n < 3; n++)
        printf("    loop 1: n = %d at %p\n", n, &n);
    
    printf("After loop 1, n = %d at %p\n", n, &n);
    
    for( int n = 1; n < 3; n++ )
    {
        printf(" loop 2 index n = %d at %p\n", n, &n);
        int n = 6;
        printf("    loop 2: n = %d at %p\n", n, &n);
        n++;
    }
    printf("After loop 2, n = %d at %p\n", n, &n);
}

void listing12_3(void)
{
    int count;
    
    puts("\n*** Listing 12.3 ***");
    
    for(count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
    
    return;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1;
    
    printf("fade = %d and stay = %d\n", fade++, stay++);
}

void listing12_4(void)
{
    extern int units;
    puts("\n*** Listing 12.4 ***");
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    
    while (units != 56) {
        critic();
    }
    
    printf("You must have looked it up!\n");
    
    return;
}

void critic(void)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}

void listing12_5(void)
{
    int value;
    register int i;
    
    puts("\n*** Listing 12.5 ***");
    
    printf("Enter a positive integer (0 to quit): ");
    while ( scanf("%d", &value) == 1 && value > 0 )
    {
        ++count;
        for( i = value; i >= 0; i--)
            accumulate(i);
        
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    
    return;
}

void report_count(void)
{
    printf("Loop executed %d times\n", count);
}

void listing12_8(void)
{
    int count;
    
    for (count = 0; count < 5; count++)
        printf("%d\n", rand0());
}

void listing12_10(void)
{
    int count;
    unsigned seed;
    
    puts("\n*** Listing 12.10 ***");
    
    printf("Please enter your choice for seed.\n");
    
    while(scanf("%u", &seed) == 1)
    {
        srand1(seed);
        for ( count = 0; count < 5; count++)
            printf("%d\n", rand1());
        printf("Please enter your next seed (q to quit):\n");
    }
    printf("Done\n");
    
    return;
}

void listing12_13(void)
{
    int dice, roll;
    int sides;
    int status;
    
    puts("\n*** Listing 12.13 ***");
    
    srand( (unsigned int) time(0));     /* randomize seed */
    printf("Enter the number of sides per die, 0 to stop.\n");
    
    while (scanf("%d", &sides) == 1 && sides > 0)
    {
        printf("How many dice?\n");
        
        if ( ( status = scanf("%d", &dice)) != 1 )
        {
            if ( status == EOF )
                break;
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                
                while ( getchar() != '\n' )
                    continue;
                
                printf("How many sides? Enter 0 to stop.\n");
                continue;
            }
        }
        
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("How many sides? Enter 0 to stop.\n");
    }
    
    printf("The rollem() function was called %d times.\n", roll_count);
    printf("GOOD FORTUNE TO YOU!\n");
    
    return;
}

void listing12_14(void)
{
    double *ptd;
    int max = 0;
    int number;
    int i = 0;
    
    puts("*** Listing 12.14 ***\n");
    
    puts("What is the maximum number of type double entries?");
    
    if ( scanf("%d", &max) != 1 )
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    
    ptd = (double *)malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter the values (q to quit):");
    while ( i < max && scanf("%lf", &ptd[i]) == 1 )
        ++i;
    
    printf("Here are your %d entries:\n", number = i);
    for( i = 0; i < number; i++ )
    {
        printf("%7.2f ", ptd[i]);
        if ( i % 7 == 6 )
            putchar('\n');
    }
    
    if ( i % 7 != 0 )
        putchar('\n');
    
    puts("Done.");
    free(ptd);
    
    return;
}

/*
 *** Listing 12.15 ***
 static_store: 30 at      0x10e713080       FILE
   auto_store: 40 at   0x7ffee14ef9ec       STACK
          *pi: 35 at   0x7fa97dc01a50       HEAP
   String Literal at      0x10e7119c0       FILE
  Auto char Array at   0x7ffee14ef9f0       STACK
   Dynamic String at   0x7fa97dc01a60       HEAP
    Quoted String at      0x10e711f4e

 */

void listing12_15(void)
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int  *pi;
    char *pcl;
    
    puts("\n*** Listing 12.15 ***");
    
    pi = (int *) malloc(sizeof(int));
    *pi = 35;
    pcl = (char*)malloc(strlen("Dynamic string") + 1 );
    strcpy(pcl, "Dynamic String");
    
    printf("static_store: %d at %16p\n", static_store, &static_store);
    printf("  auto_store: %d at %16p\n", auto_store, &auto_store);
    printf("         *pi: %d at %16p\n", *pi, pi);
    printf("  %s at %16p\n", pcg, pcg);
    printf(" %s at %16p\n", auto_string, auto_string);
    printf("  %s at %16p\n", pcl, pcl);
    printf("   %s at %16p\n", "Quoted String", "Quoted String");
    
    free(pi);
    free(pcl);
    
    return;
}
