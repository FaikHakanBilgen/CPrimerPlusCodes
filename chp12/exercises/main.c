//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 14.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pe12-2a.h"


void exercise12_1(void);
int critic(void);
void exercise12_2(void);
void exercise12_3(void);
void exercise12_4(void);
void exercise12_5(void);
void exercise12_6(void);
int aFunction(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Exercises for Chapter 12 ***");
    // exercise12_1();
//    exercise12_2();
//    exercise12_3();
//    exercise12_4();
//    exercise12_5();
    exercise12_6();
    return 0;
}


void exercise12_1(void)
{
    puts("\n*** Exercise 12.1 ***");

    int units;
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    
    while (units != 56) {
        units = critic();
    }
    
    printf("You must have looked it up!\n");

    return;
}

int critic(void)
{
    int number;
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &number);
    return number;
}

void exercise12_2(void)
{
    int mode;
    puts("\n*** Exercise 12.2 ***");
    
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    
    while ( mode >= 0) {
        
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    
    return;
}

void exercise12_3(void)
{
    int mode;
    float fuel, distance;
    puts("\n*** Exercise 12.3 ***");
    
    mode = GetMode();
    
    while ( mode >= 0)
    {
        GetInfo(mode, &distance, &fuel);
        ShowInfo(mode, distance, fuel);
        mode = GetMode();
    }
    
    printf("Done.\n");
    
    return;
}

void exercise12_4(void)
{
    int i, limit, count = 0;
    puts("\n*** Exercise 12.4 ***");
    
    printf("How many times you want the function to be called? ");
    scanf("%d", &limit);
    
    for(i = 0; i < limit; i++)
        count = aFunction();
    
    printf("The function is called %d times.\n", count);
    return;
}


int aFunction(void)
{
    static int callcount = 0;
    
    printf("aFunction is called %d times.\n", ++callcount);
    
    return callcount;
}

void exercise12_5(void)
{
    int i, j, max = 0;
    int arr[100];
    srand( (unsigned int) time(0));
    
    for( i = 0; i < 100; i++)
        arr[i] = rand() % 10 + 1;
    
    for(i=0; i< 100; i++)
        printf("%d, ", arr[i]);
    
    printf("\n");
    
    for(i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
            if ( i!=j )
            {
                if ( arr[j] > arr[i] )
                {
                    max = arr[j];
                    arr[j] = arr[i];
                    arr[i] = max;
                }
            }
    }
    
    for(i=0; i< 100; i++)
        printf("%d, ", arr[i]);
    
    printf("\n");
    return;
}

void exercise12_6(void)
{
    int i, j;
    int count[11];
    
    puts("\n*** Exercise 12.6 ***");
        
    for(i = 0; i < 10; i++)
    {
        srand( (unsigned int) time(0));
    
        for(j=0; j<11; j++)
            count[j] = 0;
        
        for(j = 0; j < 1000; j++)
        {
            count[ rand() % 10 + 1 ]++;
        }
        
        printf("Iteration: %2d\n", i);
        for(j=1; j<11; j++)
            printf("%2d: %4d\n", j, count[j] );
        
    }
    
    return;
}
