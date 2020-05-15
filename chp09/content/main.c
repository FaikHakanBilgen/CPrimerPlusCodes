 //
//  main.c
//  content
//
//  Created by teos on 22.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <stdbool.h>
#include "hotel.h"

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

void listing9_1(void);
void listing9_1Starbar(void);
void listing9_2(void);
void listing9_2show_n_char(char ch, int num);
void listing9_3(void);
int listing9_3imin(int, int);
void listing9_9(void);

int main(int argc, const char * argv[])
{
    printf("\n*** Content of Chapter 9 ***\n\n");
//    listing9_1();
//    listing9_2();
//    listing9_3();
    listing9_9();
    return 0;
}

void listing9_1(void)
{
    printf("\n*** Listing 9.1 ***\n\n");
    
    listing9_1Starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    listing9_1Starbar();
    
    return;
}

void listing9_1Starbar(void)
{
    int count;
    
    for(count = 1; count <= WIDTH; count++)
        putchar('*');
    
    putchar('\n');
    return;
}

void listing9_2(void)
{
    int spaces;
    printf("\n*** Listing 9.1 ***\n\n");
    
    listing9_2show_n_char('*', WIDTH);
    putchar('\n');
    listing9_2show_n_char(SPACE, 12);
    printf("%s\n", NAME);
    spaces=(WIDTH - strlen(ADDRESS))/2;
    listing9_2show_n_char(SPACE, spaces);
    printf("%s\n", ADDRESS);
    listing9_2show_n_char(SPACE, (WIDTH- strlen(PLACE))/2);
    printf("%s\n", PLACE);
    listing9_2show_n_char('*', WIDTH);
    putchar('\n');
    
    return;
}

void listing9_2show_n_char(char ch, int num)
{
    int count;
    
    for (count=1; count<=num; count++)
        putchar(ch);
}

void listing9_3(void)
{
    int evil1, evil2;
    
    printf("\n*** Listing 9.3 ***\n");
   
    printf("Enter a pair of integers (q to quit):\n");
    while (scanf("%d %d", &evil1, &evil2))
    {
        printf("The lesser of %d and %d is %d.\n", evil1, evil2, listing9_3imin(evil1, evil2) );
        printf("Enter a pair of integers (q to quit):\n");
    }
    
    printf("Bye.\n");
    
    return;
}

int listing9_3imin(int n, int m)
{
    int min;
    
    if (n < m)
        min = n;
    else
        min = m;
    
    return min;
}

void listing9_9(void)
{
    int nights;
    double hotel_rate;
    int code;
    
    while ( (code = menu()) != QUIT )
    {
        switch (code) {
            case 1:
                hotel_rate = HOTEL1;
                break;
            case 2:
                hotel_rate = HOTEL2;
                break;
            case 3:
                hotel_rate=HOTEL3;
                break;
            case 4:
                hotel_rate = HOTEL4;
                break;
            default:
                hotel_rate = 0.0;
                printf("Oops!\n");
                break;
        }
        nights = getnights();
        showprice(hotel_rate, nights);
    }
    
    return;
}
