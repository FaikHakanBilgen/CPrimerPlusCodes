//
//  main.c
//  content
//
//  Created by teos on 20.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define STOP '#'

void listing8_1(void);
void listing8_2(void);
void listing8_4(void);
void listing8_5(void);
void listing8_5Display(char cr, int lines, int width);

void review8_1(void);
void review8_2(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("\n*** Content of Chapter 8 ***\n");
    //listing8_1();
    //listing8_2();
    //listing8_4();
    //listing8_5();
    
    //review8_1();
    review8_2();
    
    return 0;
}

// This is called echo
void listing8_1(void)
{
    char ch;
    
    printf("\n*** Listing 8.1 ***\n");
    
    while ((ch=getchar())!=STOP)
        putchar(ch);
    
    printf("\n");
    return;
}

void listing8_2(void)
{
    int ch;
    
    printf("\n*** Listing 8.2 ***\n");
    
    while ((ch=getchar()) != EOF) {
        putchar(ch);
    }
    
    printf("\n");
    return;
}

void listing8_4(void)
{
    int guess = 1;
    
    printf("\n*** Listing 8.4 ***\n");
    
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number%d?", guess);
    
    while (getchar()!='y')
    {
        printf("Well, then, is it %d?\n", ++guess);
        
        // when getchar executes it does not remove the newline character from the input buffer
        // hence in the next cycle of the loop getchar returns the remaining newline character from the buffer and
        // does not give a chance to the user to input.
        // The following loop iterates in the buffer so that newline is read and the next call to getchar will
        // get the new input
        while ( (getchar()!='\n'))
            continue;
    }
    printf("I knew I could do it!\n");
    
    return;
}

void listing8_5(void)
{
    int ch;
    int rows, cols;
    
    printf("\n*** Listing 8.5 ***\n");
    
    printf("Enter a character and two integers:\n");
    while ( ( ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        
        listing8_5Display(ch, rows, cols);
        while ( ( ch = getchar()) != '\n')
            continue;
        
        printf("Enter another character and two integers:\n");
        printf("Enter a newline to quit.\n");
    }
    
    return;
}

void listing8_5Display(char cr, int lines, int width)
{
    int row, col;
    
    for(row = 1; row <= lines; row++)
    {
        for(col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');
    }
}

void review8_1(void)
{
    putchar(getchar());
    //getchar(putchar()); compilation error
}

void review8_2(void)
{
    putchar('H');
    putchar('\007');
    putchar('\n');
    printf("ABCDEF");
    putchar('\b');
    printf("GHIJKL");
}
