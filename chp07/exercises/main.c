//
//  main.c
//  exercises
//
//  Created by teos on 18.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '#'
#define SPACE ' '
#define NEWLINE '\n'
#define EXCLAMATION_MARK '!'
#define PERIOD '.'


void exercise7_1(void);
void exercise7_2(void);
void exercise7_3(void);
void exercise7_4(void);
void exercise7_5(void);
void exercise7_6(void);

int main(int argc, const char * argv[]) {

    printf("Chapter 7 / Exercises\n");

//    exercise7_1();
//    exercise7_2();
//    exercise7_3();
//    exercise7_4();
//    exercise7_5();
  
    exercise7_6();
    return 0;
}

void exercise7_1(void)
{
    char ch;
    int spaces = 0, newlines = 0, otherchars=0;
    
    printf("\n*** Exercise 7.1 ***\n");
    
    printf("Enter input and terminate with #\n");
    
    while( (ch=getchar()) != STOP)
    {
        switch (ch) {
            
            case SPACE:
                spaces++;
                break;
            
            case NEWLINE:
                newlines++;
                break;
                
            default:
                otherchars++;
        }
    }
    
    printf("You have entered %d spaces, %d newlines and %d other characters\n", spaces, newlines, otherchars);
    return;
}

void exercise7_2(void)
{
    char ch;
    int count=1;
    
    printf("\n*** Exercise 7.2 ***\n");

    printf("Enter input and terminate with #\n");
    
    while( (ch=getchar()) != STOP)
        printf("%c:%d%c", ch, ch, count++ % 8 ? SPACE : NEWLINE);

    printf("\n");
    return;
}

void exercise7_3(void)
{
    int num, oddCount = 0, evenCount = 0, oddSum = 0, evenSum = 0;
    
    printf("\n*** Exercise 7.3 ***\n");
    printf("Enter integers. O will terminate the input\n");
    
    while( scanf("%d", &num) == 1)
    {
        if ( num==0 )
            break;
        // If the modulo operation results in non-zero it means an odd number
        if ( num%2 )
        {
            oddSum += num;
            oddCount++;
        }
        else
        {
            evenSum += num;
            evenCount++;
        }
    }
    
    printf("even numbers = %d, average of even numbers = %.2f, odd number = %d, average of odd numbers = %.2f\n",
           evenCount, (float)evenSum / (float)evenCount, oddCount, (float)oddSum / (float)oddCount );
    
    return;
}

void exercise7_4(void)
{
    char ch;
    int count=0;
        
    printf("\n*** Exercise 7.4 ***\n");

    printf("Enter input and terminate with #\n");
    
    while( (ch=getchar()) != STOP)
    {
        count++;
        if ( ch == PERIOD )
            putchar(EXCLAMATION_MARK);
        else
            if ( ch == EXCLAMATION_MARK )
            {
                putchar(EXCLAMATION_MARK);
                putchar(EXCLAMATION_MARK);
            }
            else
            {
                putchar(ch);
                count--;
            }
        
    }
    
    printf("\nTotal changes=%d\n", count);
    
    return;
}

void exercise7_5(void)
{
    char ch;
    int count=0;
        
    printf("\n*** Exercise 7.4 ***\n");
    printf("Enter input and terminate with #\n");
    
    while( (ch=getchar()) != STOP)
    {
        count++;
        switch (ch)
        {
            case PERIOD:
                putchar(EXCLAMATION_MARK);
                break;
        
            case EXCLAMATION_MARK:
                putchar(EXCLAMATION_MARK);
                putchar(EXCLAMATION_MARK);
                break;
            
            default:
                putchar(ch);
                count--;
        }
    }
    
    printf("\nTotal changes=%d\n", count);
    
    return;
}

void exercise7_6(void)
{
    char ch, prevch='z';
    int count=0;
    
    printf("\n*** Exercise 7.6 ***\n");
    
    while( (ch=getchar()) != STOP)
    {
        if ( prevch =='e' && tolower(ch) =='i' )
            count++;
            
        prevch = tolower(ch);
    }
    
    printf("%d ei sequence is found\n", count);
    return;
}
