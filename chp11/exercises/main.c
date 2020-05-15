//
//  main.c
//  exercises
//
//  Created by teos on 3.03.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LINELEN 100
#define MENULEN 5
#define MAXSTRINGS 10

const char* g_menu[MENULEN] = { "1. Print Strings", "2. Order and print Strings", "3. Print Strings in Increasing Length", "4. Order Strings based on Their First Characters", "5. Quit" };

void exercise11_1(void);
void getnextn(int n, char input[n]);

void exercise11_2(void);
void getnextn2(int n, char input[n]);

void exercise11_3(void);
void getnextn3(char *cp);

void exercise11_4(void);
void getnextn4(char *cp, int limit);

void exercise11_5(void);
char* searchstr(const char *cp, char ch);

void exercise11_6(void);
int is_within(const char *cp, char ch);

void exercise11_7(void);
char* mystrncpy(char* s1, char* s2, int n);

void exercise11_8(void);
char* string_in(char* s1, char* s2);

void exercise11_9(void);
void reverse(char* s);

void exercise11_10(void);
void removespace(char *cp);

void exercise11_11(void);
int getstrings(char input[][LINELEN], int strcount);
int getstrings2(char input[][LINELEN], int strcount);
int menu(int n, const char* mn[n]);
void printstrings(int strcnt, char strings[][LINELEN] );
void GetString(char *retStr);

int main(int argc, const char * argv[])
{
   
    printf("\n*** Exercises for Chapter 11 ***\n");
//    exercise11_1();
//    exercise11_2();
//    exercise11_3();
//    exercise11_4();
//    exercise11_5();
//    exercise11_6();
//    exercise11_7();
//    exercise11_8();
//    exercise11_9();
//    exercise11_10();
    exercise11_11();
    return 0;
}


void exercise11_1(void)
{
    char input[20];
    puts("\n*** Exercise 11.1 ***\n");
    
    puts("\nEnter an input less than or equal to 10 characters:");
    getnextn(10, input);
    
    while ( strncmp(input, "quit", 4) )
    {
        fputs(input, stdout);
        puts("\nEnter an input less than or equal to 10 characters:");
        getnextn(20, input);
    }
    
    return;
}


void getnextn(int n, char input[n])
{
    char *ret_val;
    
    ret_val = fgets(input, n, stdin);
        
    if (ret_val)
    {
        while ( *ret_val != '\n' && *ret_val != '\0'   )
            ret_val++;
        if ( *ret_val ==  '\n' )
            return;
        else
            while (getchar() != '\n')
                continue;
    }
    
    return;
}

void exercise11_2(void)
{
    char input[20];
    puts("\n*** Exercise 11.2 ***\n");
    
    puts("\nEnter an input less than or equal to 10 characters:");
    getnextn2(10, input);
    
    while ( strncmp(input, "quit", 4) )
    {
        fputs(input, stdout);
        puts("\nEnter an input less than or equal to 10 characters:");
        getnextn2(10, input);
    }
    
    return;
}

void getnextn2(int n, char input[n])
{
    char *ret_val;
    char *place_to_stop;
    
    ret_val = fgets(input, n, stdin);
        
    if (ret_val)
    {
        while ( !isspace(*ret_val) )
            ret_val++;
        
        place_to_stop = ret_val;
                
        if ( *ret_val ==  '\n' )
        {
            *place_to_stop = '\0';
            return;
        }
        else
            while (getchar() != '\n')
                continue;
        
        *place_to_stop = '\0';
    }
    
    return;
}

void exercise11_3(void)
{
    char input[20];
    puts("\n*** Exercise 11.3 ***\n");
    
    puts("\nEnter an input including a word:");
    getnextn3(input);
    
    while ( strncmp(input, "quit", 4) )
    {
        fputs(input, stdout);
        puts("\nEnter an input including a word:");
        getnextn3(input);
    }
    
    return;
}

void getnextn3(char *cp)
{
    char ch;
    _Bool wordStarted = false;
    _Bool wordComplete = false;
    int i = 0;
        
    ch = getchar();
    
    while (!wordComplete )
    {
        if ( !isspace(ch) )
        {
            if ( isalpha(ch) )
            {
                cp[i++] = ch;
                
                if (!wordStarted)
                    wordStarted = true;
            }
            if ( isnumber(ch) )
            {
                i=0;
                wordStarted = false;
            }
        }
        else
        {
            if ( wordStarted )
                break;
        }
        ch = getchar();
    }
    
    cp[i] = '\0';
    
    if (ch!='\n')
        while (getchar() != '\n')
            continue;
    
    return;
}

void exercise11_4(void)
{
    char input[20];
    puts("\n*** Exercise 11.4 ***\n");
    
    puts("\nEnter an input including a word:");
    getnextn4(input, 10);
    
    while ( strncmp(input, "quit", 4) )
    {
        fputs(input, stdout);
        puts("\nEnter an input including a word:");
        getnextn4(input, 10);
    }
    
    return;
}

void getnextn4(char *cp, int limit)
{
    char ch;
    _Bool wordStarted = false;
    _Bool wordComplete = false;
    int i = 0;
        
    ch = getchar();
    
    while (!wordComplete && i < limit-1 )
    {
        if ( !isspace(ch) )
        {
            if ( isalpha(ch) )
            {
                cp[i++] = ch;
                
                if (!wordStarted)
                    wordStarted = true;
            }
            if ( isnumber(ch) )
            {
                i=0;
                wordStarted = false;
            }
        }
        else
        {
            if ( wordStarted )
                break;
        }
        ch = getchar();
    }
    
    cp[i] = '\0';
    
    if (ch!='\n')
        while (getchar() != '\n')
            continue;
    
    return;
}

void exercise11_5(void)
{
    char input[20];
    char ch;
    char *cp;
    
    puts("\n*** Exercise 11.5 ***\n");
    
    puts("\nEnter a string and search character:");
    scanf("%s %c", input, &ch);
    
    while ( strncmp(input, "quit", 4) )
    {
        cp = searchstr( input, ch);
        printf("This is the rest of the string: %s\n", cp == NULL ? "N/A" : cp);
        
        puts("\nEnter a string and search character:");
        scanf("%s %c", input, &ch);
    }
    
    return;
}

char* searchstr(const char *cp, char ch)
{
    while (*cp)
        if ( *cp== ch )
            return cp;
        else
            cp++;
    
    return NULL;
}

void exercise11_6(void)
{
    char input[20];
    char ch;
    int i = 0;
    
    puts("\n*** Exercise 11.6 ***\n");
    
    puts("\nEnter a string and search character:");
    scanf("%s %c", input, &ch);
    
    while ( strncmp(input, "quit", 4) )
    {
        i = is_within(input, ch);
        printf("The string \"%s\" %s the character %c\n", input, i ? "contains" : "does not contain", ch);
        
        puts("\nEnter a string and search character:");
        scanf("%s %c", input, &ch);
    }
    
    return;
}

int is_within(const char *cp, char ch)
{
    while (*cp)
        if ( *cp== ch )
            return 1;
        else
            cp++;
    
    return 0;
}

void exercise11_7(void)
{
    char s1[20];
    char s2[20];
    char *str;
    int i = 0;
    
    puts("\n*** Exercise 11.7 ***\n");
    
    puts("\nEnter two strings and number of characters to copy:");
    scanf("%s %s %d", s1, s2, &i);
    
    while ( strncmp(s1, "quit", 4) )
    {
        str = mystrncpy(s1, s2, i);
        
        printf("The string \"%s\" copied %d characters into string \"%s\" ends up with %s\n", s2, i, s1, str);
        
        puts("\nEnter two strings and number of characters to copy:");
        scanf("%s %s %d", s1, s2, &i);
    }
    
    return;
}

char* mystrncpy(char* s1, char* s2, int n)
{
    int i;
    
    for(i = 0; s2[i] && i < n; i++)
        s1[i] = s2[i];
    
    s1[i] = '\0';
    
    return s1;
}

void exercise11_8(void)
{
    char s1[20];
    char s2[20];
    char *str;
    
    puts("\n*** Exercise 11.8 ***\n");
    
    puts("\nEnter two strings :");
    scanf("%s %s", s1, s2);
    
    while ( strncmp(s1, "quit", 4) )
    {
        str = string_in(s1, s2);
        
        printf("The string \"%s\" %s the string \"%s\" starting from %s\n", s1, str==NULL ? "does not contain" : "contains", s2, str==NULL ? "N/A" : str);
        
        puts("\nEnter two strings :");
        scanf("%s %s", s1, s2);
    }
    
    return;
}

char* string_in(char* s1, char* s2)
{
    int i, j;
    
    for(i=0; i < strlen(s1); i++)
        if ( s1[i] == s2[0] )
        {
            for(j=0; j < strlen(s2) && i+j < strlen(s1) ; j++)
                if ( s1[i+j] != s2[j] )
                    break;
 
            // found return
            if (i+j < strlen(s1))
                return s1+i;
        }
    
    return NULL;
    
}

void exercise11_9(void)
{
    char s[20];
    char *str;
    
    puts("\n*** Exercise 11.9 ***\n");
    
    puts("\nEnter a string :");
    scanf("%s", s);
    
    while ( strncmp(s, "quit", 4) )
    {
        printf("The input string is \"%s\" and the reverse of it is ", s);
        reverse(s);
        
        printf("\"%s\"", s);
        
        puts("\nEnter a string :");
        scanf("%s", s);
    }
    
    return;
}

void reverse(char* s)
{
    int i;
    char ch;
    int last, middle;
    
    last = strlen(s);
    middle = last / 2;
    last--;
    
    for ( i = 0; i < middle; i++  )
    {
        ch = s[last-i];
        s[last-i] = s[i];
        s[i] = ch;
    }
}

void exercise11_10(void)
{
    char s[LINELEN];
    char *str;
    
    puts("\n*** Exercise 11.10 ***\n");
    
    puts("\nEnter an input line:");
    getnextn(LINELEN, s);
    
    while ( strncmp(s, "quit", 4) )
    {
        printf("The input line is \"%s\", ", s);
        removespace(s);
        printf("The dehydrated line is \"%s\"\n", s);
                
        puts("\nEnter an input line:");
        getnextn(LINELEN, s);
    }
        
    return;
}

void removespace(char *cp)
{
    int i, j, n;
    n = strlen(cp);
    char ch[n];
    
    for ( i = 0, j=0; i < n; i++)
        if (! isspace(cp[i]) )
            ch[j++] = cp[i];
    
    ch[j] = '\0';
    for(i=0; i < n; i++)
        cp[i] = '\0';
    
    strncpy(cp, ch, strlen(ch));
    
    return;
}

void exercise11_11(void)
{
    int i, strcnt, choice;
    
    char strings[MAXSTRINGS][LINELEN];
    
    for(i=0; i < MAXSTRINGS; i++)
        strings[i][0]='\0';
    
    printf("\n*** Exercise 11.11 ***\n");
    
    while(1)
    {
        printf("enter 10 strings or EOF\n");

        //strcnt = getstrings2( strings, MAXSTRINGS);
        strcnt = getstrings( strings, MAXSTRINGS);
        choice = menu(MENULEN, g_menu);

        switch (choice) {
            case 1:
                printstrings(strcnt, strings);
                break;

            default:
                break;
        }

        scanf("%d", &choice);
    }
//    char myStr[100];
//    _Bool stop = false;
//    while (!stop)
//    {
//        GetString(myStr);
//        if ( myStr[0]!= -1 )
//            printf("The string is %s\n", myStr);
//        else
//        {
//            printf("The string is N/A\n");
//            stop = true;
//        }
//    }
    
}


int getstrings(char input[][LINELEN], int strcount)
{
   int ch, c;
   int i = 0, j= 0;
    
   ch = getchar();
    
   while ( ch != EOF && i < strcount  )
   {
       if ( !isspace(ch) )
           input[i][j++] = ch;
       else
       {
           input[i++][j]='\0';
           j=0;
       }
       ch = getchar();
   }

    while( (c = fgetc( stdin )) != EOF && c != '\n' );
   return i;
}


int getstrings2(char input[][LINELEN], int strcount)
{
    _Bool stop = false;
    int i = 0;
    char c;
    
    while ( !stop && i < strcount  )
    {
        if ( scanf(" %s *[^\n]", input[i]) == EOF )
        {
            stop = true;
            input[i][0] = '\0';
        }
        else
        {
           i++;
        }
        
        scanf("%*[^\n]"); getchar();
    }
    
    return i;
}



int menu(int n, const char* mn[n])
{
    int i, choice;
    
    for(i = 0; i < MENULEN; i++)
            printf("%s\n", g_menu[i]);
        
    scanf("%d", &choice);
    
    // assume the input is correct !!!
    return choice;
}


void printstrings(int strcnt, char strings[][LINELEN] )
{
    int i;
    
    for(i = 0; i < strcnt; i++)
        printf("%s, ", strings[i]);
    
    printf("\n");
}


void GetString(char *retStr)
{
    
    printf("Enter a string:\n");
    if ( scanf("%s", retStr) == EOF )
        retStr[0] = -1;
    
}
