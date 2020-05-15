//
//  main.c
//  content
//
//  Created by teos on 18.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STRING_FOR_7_5_1 "Please enter an integer for analysis: "
#define STRING_Q_FOR_QUIT "\nEnter q to quit.\n"
#define PERIOD '.'
#define STOP '|'

void listing7_3(void);
void listing7_5(void); // Finding Prime Number
void listing7_6(void);
void listing7_7(void);
void listing7_11(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Chapter 7 / Content\n");
    
    listing7_3();
    listing7_5();
    listing7_6();
    listing7_7();
    listing7_11();
    return 0;
}

void listing7_3(void)
{
    char ch;
    
    printf("\n*** Listing 7.3 ***\n");
    
    while ( (ch = getchar()) != '\n' )
    {
        if(isalpha(ch))
            putchar(ch+1);
        else
            putchar(ch);
    }
    putchar(ch); // Display the newline. It is elegant
    
    return;
}

void listing7_5(void)
{
    unsigned long num;
    unsigned long div;
    bool isprime = true;
    
    printf("\n*** Listing 7.5 ***\n");
    
    printf(STRING_FOR_7_5_1);
    printf(STRING_Q_FOR_QUIT);
    
    while (scanf("%lu", &num ) == 1)
    {
        for (div = 2, isprime=true; div*div <= num; div++)
        {
            if (num % div == 0)
            {
                if ( (div * div) != num )
                    printf("%lu is divisible by %lu and %lu\n", num, div, num/div);
                else
                    printf("%lu is divisible by %lu\n", num, div);
                isprime = false;
            }
        }
        
        if (isprime)
            printf("%lu is prime.\n", num);
        printf(STRING_FOR_7_5_1);
        printf(STRING_Q_FOR_QUIT);
    }
    printf("Bye!\n");
    
    return;
}

void listing7_6(void)
{
    char ch;
    int charcount = 0;
    
    printf("\n*** Listing 7.6 ***\n");
    
    while ( (ch = getchar()) != PERIOD )
    {
        if ( ch != '"' && ch != '\'' )
            charcount++;
    }
    
    printf("There are %d non-quote characters.\n", charcount);
    
    return;
}

void listing7_7(void)
{
    char c;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false;
        
    printf("\n*** Listing 7.7 ***\n");
    
    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';
    
    while ((c = getchar()) != STOP)
    {
        n_chars++;
        if ( c == '\n')
            n_lines++;
        
        if ( !isspace(c) && !inword )
        {
            inword = true;
            n_words++;
        }
        
        if ( isspace(c) && inword )
            inword = false;
        prev = c;
    }
    
    if ( prev != '\n' )
        p_lines = 1;
    
    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
    
    return;
}

void listing7_11(void)
{
    char ch;
    
    printf("\n*** Listing 7.11 ***\n");
    
    
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.\n");
    
    while ((ch = getchar()) != '#')
    {
        if ('\n' == ch)
            continue;
        
        if (islower(ch))
            switch (ch) {
                case 'a':
                    printf("argali, a wild sheep of Asia\n");
                    break;
                case 'b':
                    printf("babirusa, a wild pig of Malay\n");
                    break;
                case 'c':
                    printf("coati, racoonlike mamal\n");
                    break;
                case 'd':
                    printf("desman, aquatic, molelike critter\n");
                    break;
                case 'e':
                    printf("echidna, the spiny anteater\n");
                    break;
                case 'f':
                    printf("fisher, brownish marten\n");
                    break;
                    
                default:
                    printf("That's a stumper!\n");               
            }
        else
            printf("I recognize only lower case letters.\n");
        
        while (getchar()!='\n')
            continue;
        
        printf("Please type another letter or a #.\n");
    }
    
    printf("Bye!\n");
    
    return;
}
