//
//  main.c
//  exercises
//
//  Created by teos on 20.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void exercise8_1(void);
void exercise8_2(void);
void exercise8_3(void);
void exercise8_4(void);
void exercise8_5(void);
void exercise8_6(void);
char get_first(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("\n*** Exercises Chapter 8 ***\n");
    
//    exercise8_1();
//    exercise8_2();
//    exercise8_3();
//    exercise8_4();
//    exercise8_5();
    exercise8_6();
    return 0;
}

void exercise8_1(void)
{
    char ch;
    int count=0;
    
    printf("\n*** Exercise 8.1 ***\n");
    
    while ((ch=getchar())!=EOF)
        count++;
    
    printf("There are %d characters in the input\n", count);
    return;
}

void exercise8_2(void)
{
    int ch, count=1;
    
    printf("\n*** Exercise 8.2 ***\n");

    while ((ch=getchar())!=EOF)
    {
        
        if ( iscntrl(ch) )
            switch (ch)
            {
                case 0:
                    printf("^@:0");
                    break;
        
                case '\t':
                    printf("%s:%d", "\\t", '\t');
                    break;
                    
                case '\n':
                    printf("%s:%d", "\\n", '\n');
                    break;
                    
                default:
                    printf("^%c:%d", 'A'+ch-1, ch);
                    break;
            }
        else
            printf("%c:%d", ch, ch);
        
        // This is for 10 pairs per line
        printf("%c", count++ % 10 ? ' ' : '\n');
    }
    
    printf("\n");
    return;
}

void exercise8_3(void)
{
    int ch;
    int ucCount = 0, lcCount = 0, others = 0;
    
    while ((ch=getchar())!=EOF)
    {
        if (isalpha(ch))
            if (isupper(ch))
                ucCount++;
            else
                lcCount++;
        else
            others++;
    }
    
    printf("\nThere are %d upper case, %d lower case and %d other characters\n", ucCount, lcCount, others);
}

void exercise8_4(void)
{
    int ch, wordCount=0, wordLength=0;
    bool inWord = false;
    
    while ((ch=getchar())!=EOF)
    {
        if ( ispunct(ch) || isspace(ch) )
        {
            if (inWord)
                inWord=false;
        }
        
        if ( isalpha(ch))
        {
            if (!inWord)
            {
                wordCount++;
                inWord=true;
            }
            wordLength++;
        }
    }
    
    printf("\nThere %s %d word%sand average word length is %d characters\n", wordCount>1?"are":"is", wordCount,
            wordCount>1?"s ":" ", wordLength/wordCount);
    return;
}

void exercise8_5(void)
{
    int guess=50, prevGuess=0, delta=0;
    char response;
    
    printf("Pick an integer from 1 to 100. I will try guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\na l if it is low or h if it is high.\n");
    printf("Uh...is your number %d? \n", guess);
    
    while ((response=getchar())!='y')
    {
        if (guess>prevGuess)
            delta = (guess-prevGuess)/2;
        else
            delta = (prevGuess-guess)/2;
        
        if (response=='l')
        {
            prevGuess= guess;
            guess += delta;
            printf("Well, then, is it %d? ", guess);
        }
        
        if (response=='h')
        {
            prevGuess= guess;
            guess -= delta;
            printf("Well, then, is it %d? ", guess);
        }
        
        if ( response!='h' && response!='l' )
            printf("Sorry, I understand only y, l and h\n");
        
        while (getchar()!='\n')
            continue;
    }
    
    printf("I knew I could do it!\n");
    
    return;
}

void exercise8_6(void)
{
    int ch;
    
    printf("Enter the letter of your choice:\n");
    printf("a. advice   b.bell\n");
    printf("c. count    d. quit\n");
    
    ch=get_first();
    
    while ( ch != 'q')
    {
        printf("The first nonspace char is %c\n", ch);
        ch = get_first();
    }
}


char get_first(void)
{
    int ch;
    
    while (isspace(ch=getchar()))
        continue;
    
    while (getchar()!='\n')
        continue;
    
    return ch;
}
