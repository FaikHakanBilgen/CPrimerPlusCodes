//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 3.03.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MSG "I am a symbolic string constant"
#define MAXLENGTH 81
#define MSG2 "I'm special"
#define SLEN 40
#define LIM 5
#define STLEN 81
#define STLEN2 14
#define STLEN3 10
#define DEF "I am a #defined string."
#define SIZE 80
#define SIZE2 30
#define BUGSIZE 13
#define ANSWER "Grant"
// #define SIZE3 40
#define SIZE3 80
#define LIM3 10
#define STOP "quit"
#define LISTSIZE 6
#define SIZE4 40
#define LIM4 5
#define WORDS "beast"
#define SIZE5 40
#define TARGETSIZE5 7
#define LIM5 5
#define MAX 20

#define SIZE6 81
#define LIM6 20
#define HALT ""

#define LIMIT7 81

#define LIM8 30

void listing11_1(void);
void listing11_2(void);
void listing11_3(void);
void listing11_3_2(void);
void listing11_3_3(void);
void listing11_3_4(void);
void listing11_4(void);
void listing11_6(void);
void listing11_7(void);
void listing11_8(void);
void listing11_9(void);
void listing11_10(void);
void listing11_11(void);
char* s_gets(char *st, int n);
char* s_gets2(char *st, int n);
void listing11_12(void);
void listing11_13(void);
void listing11_17(void);
void fit(char *string, unsigned int size);
void listing11_18(void);
void listing11_19(void);
void listing11_20(void);
void listing11_21(void);
void listing11_22(void);
void listing11_23(void);
void listing11_24(void);
void listing11_25(void);
void listing11_26(void);
void listing11_27(void);
void listing11_28(void);
void listing11_29(void);
void stsrt(char *strings[], int n);
void listing11_30(void);
void listing11_32( int, char *[]);
void ToUpper(char *);
int PunctCount(const char *);
void listing11_33(void);

// This is listing 11.31 for command line argument
int main(int argc, const char * argv[])
{
    int count;
    
//  Listing 11.31
//    printf("The command line has %d arguments:\n", argc - 1);
//    for(count = 0; count < argc; count++)
//    {
//        printf("%d: %s\n", count, argv[count]);
//    }
//    printf("\n");
    
    printf("\n*** This is content for Chapter 11 ***\n");
    
    
    
//    listing11_1();
//    listing11_2();
//    listing11_3();
//    listing11_3_2();
//    listing11_3_3();
//    listing11_3_4();
//    listing11_4();
//    listing11_6();
//    listing11_7();
//    listing11_8();
//    listing11_9();
//    listing11_10();
//    listing11_11();
//    listing11_12();
//    listing11_13();
//    listing11_17();
    listing11_18();
//    listing11_19();
//    listing11_20();
//    listing11_21();
//    listing11_22();
//    listing11_23();
//    listing11_24();
//    listing11_25();
//    listing11_26();
//    listing11_27();
//    listing11_28();
//    listing11_29();
//    listing11_30();
    
//    listing11_32(argc, argv);
    
//    listing11_33();
    return 0;
}

void listing11_1(void)
{
    char words[MAXLENGTH] = "I am a string in an array.";
    const char *pt1 = "Something is pointing at me.";
    
    printf("\n*** Listing 11.1 ***\n");
    
    puts("Here are some strings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    words[8] = 'p';
    puts(words);
    
    return;
}

void listing11_2(void)
{
    printf("\n*** Listing 11.2 ***\n");
    printf("%s, %p, %c\n", "We", "are", *"space farers");
    
    return;
}

void listing11_3(void)
{
    char ar[] = MSG2;
    const char* pt = MSG2;
    
    printf("\n*** Listing 11.3 ***\n");
    
    printf("address of \"I'm special\"  : %16p \n", "I'm special");
    printf("               address ar : %16p \n", ar);
    printf("               address pt : %16p \n", pt);
    printf("          address of MSG2 : %16p \n", MSG2);
    printf("address of \"I'm special\"  : %16p \n", "I'm special");
    
    return;
}

void listing11_3_2(void)
{
    int i=0;
    double mydouble = 4.5;
    const char* pt1 = "Something is pointing at me";
    const char ar[] = "Something is pointing at me2";
    char ar2[]="deneme";
    char *cp;
    
    printf("\n*** constants, arrays and pointer ***\n");
    
    
    
    printf("\n using pt1++\n");
    while (*pt1 != '\0') {
//      *pt1 = 'a';
        pt1++;
        printf("%c", *pt1);
    }
    printf("\n");
    
    pt1 = ar;
    printf("%s\n", pt1);
    printf("\n");

    // array content is treated as constant !!!
    // COMPILER ERROR: Cannot assign to variable 'ar' with const-qualified type 'const char [29]'
//    for(i=0; i < (sizeof ar) / sizeof(char); i++)
//        ar[i] = 'X';    //Cannot assign to variable 'ar' with const-qualified type 'const char [29]'

    // ar is handled as an address constant
    // COMPILER ERROR: Cannot increment value of type 'const char [29]'
//    while (*pt1 != '\0') {
//        printf("%c", *ar);
//        ar++;
//    }

    // clang warns for discarding the const qualifier
    // visualc does not allow it at all
    // in clang case most probably the string is stored in a memory page which might be read only
    // hence trying yo write there creates an exception ECX_BAD_ACCESS code=2
    
    cp = ar;

    pt1 = ar2;
    
    // COMPILER ERROR: Read-only variable is not assignable
    //pt1[3] = 'L';
    
    printf("cp=%p\tar=%p\n", cp, ar);
    printf("pt=%p\t&pt=%p\n", pt1, &pt1);
    printf("cp=%p\t&cp=%p\n", cp, &cp);
    printf("i=%d, &i=%p\n",i, &i );
    printf("mydouble = %lf &mydouble = %p\n ", mydouble, &mydouble);
    printf("ar2=%s\t&ar2=%p", ar2, ar2);
    
    //*cp = 'X';
    //cp[0]='X';
    
//    for(i=0; i < 10; i++)
//        cp[i] = 'X';
//
//    for(i=0; i < (sizeof ar) / sizeof(char); i++)
//        printf("%c", ar[i] );
//
    printf("\n");
    
    
    return;
}


void listing11_3_3(void)
{
    int to=6, i;
    char heart[] = "I love Tillie";
    const char *head = "I love Millie";
    
    printf("\n*** Array and Pointer differences ***\n");
    
    printf("\n*** Array Notation ***\n");
    for(i = 0; i < to; i++)
        putchar(heart[i]);
    
    putchar('\n');
    
    for(i = 0; i < to; i++)
        putchar(head[i]);
    
    putchar('\n');
    
    // Cannot increment value of type 'char [14]'
    printf("\n*** Pointer Notation - I ***\n");
//    for(i = 0; i < to; i++)
//        putchar(*(heart++));
//
//    putchar('\n');
    
    while( *head !='\0' )
        putchar(*(head++));
    
    putchar('\n');
    
    printf("\n*** Pointer Notation - II ***\n");
    for(i = 0; i < to; i++)
        putchar(*(heart +i));
    
    putchar('\n');
    
    for(i = 0; i < to; i++)
        putchar(*(head +i));
    
    putchar('\n');
    
    return;
}

void listing11_3_4(void)
{
    char *p1 = "Klingon";
    char carr[] = "Mlingon";
       
    printf("\n*** Changing elements of char array\n");
    
    printf("%s\n", carr);
    carr[0] = 'K';
    printf("%s\n", carr);
    //p1[0] = 'F';            // Bus error: Thread 1: EXC_BAD_ACCESS (code=2, address=0x100001f6b)
    printf("Klingon");
    printf(": Beware the %ss!\n", p1);
    
    return;
}

void listing11_4(void)
{
    int i;
    
    const char *mytalents[LIM] =
    {   "Adding members swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    
    //const
    char yourtalents[LIM][SLEN] =
    {   "Walking in a straight line",
        "Sleeping",
        "Watching television",
        "Mailing letters",
        "Reading email"
    };
    
    printf("\n*** Listing 11.4 ***\n");
    
    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for(i=0; i < LIM; i++)
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

    // Read-only variable is not assignable
    // mytalents[0][0] ='E';
    yourtalents[0][0] = 'V';
    
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for(i=0; i < LIM; i++)
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    
    
    return;
}

void listing11_6(void)
{
    char words[STLEN];
    
    printf("\n*** Listing 11.5 ***\n");
    
    puts("Enter a string, please.");
    gets(words);
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");
    
    return;
}

void listing11_7(void)
{
    char words[STLEN2];
    
    printf("\n*** Listing 11.7 ***\n");
    
    puts("Enter a string, please.");
    fgets(words, STLEN2, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN2, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
    
    return;
}

void listing11_8(void)
{
    char words[STLEN3];
    
    printf("\n*** Listing 11.8 ***\n");
    
    puts("Enter strings (empty line to quit):");

    while(fgets(words, STLEN3, stdin)!=NULL && words[0]!='\n')
        fputs(words, stdout);
    
    return;
}

void listing11_9(void)
{
    int i;
    char words[STLEN3];
    
    printf("\n*** Listing 11.9 ***\n");
    
    puts("Enter strings (empty line to quit):");
    
    while(fgets(words, STLEN3, stdin) != NULL && words[0] != '\n' )
    {
        i = 0;
        
        while( words[i] != '\n' && words[i] != '\0' )
            i++;
        
        if ( words[i] == '\n' )
            words[i] = '\0';
        else
            while ( getchar() != '\n' )
                continue;
        
        puts(words);
    }
    
    puts("Done.");
    
    return;
}

char* s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    
    ret_val = fgets(st, n, stdin);
    if ( ret_val )
    {
        while (st[i] != '\n' && st[i] != '\0' )
            i++;
        
        if ( st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    
    return ret_val;
}

void listing11_10(void)
{
    printf("\n*** Listing 11.10 ***\n");
    
    return;
}

void listing11_11(void)
{
    char name1[11], name2[11];
    int count;
 
    printf("\n*** Listing 11.11 ***\n");
    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s and %s.\n", count, name1, name2);
    
    return;
}

void listing11_12(void)
{
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";
    
    printf("\n*** Listing 11.12 ***\n");
    
    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2+4);
    
    return;
}

void listing11_13(void)
{
    int i;
    char side_a[] = "Side A";
    char dont[] = { 'W', 'O', 'W', '!'};
    char side_b[] = "Side B";
    char *cp;
    
    printf("\n*** Listing 11.13 ***\n");
    
    printf("&side_a=%p, &dont=%p, &side_b=%p\n", side_a, dont, side_b);
    
    cp = side_b;
    
    for(i=0; i<19; i++)
        putchar(*(cp+i));
    
    putchar('\n');
    puts(dont);
    
    return;
}

void listing11_17(void)
{
    char msg[]="Things should be as simple as possible,"
    " but not simpler.";
    
    puts("\n*** Listing 11.14 ***\n");
    
    puts(msg);
    fit(msg, 38);
    puts(msg);
    puts("Let's look at some more of the string.");
    puts(msg+39);
    
    return;
    
}

void fit(char *string, unsigned int size)
{
    if (strlen(string) > size)
        string[size]='\0';
}

void listing11_18(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes";
    
    puts("\n*** Listing 11.18 ***\n");
    
    puts("What is your favorite flower?");
  //  if ( s_gets(flower, SIZE) )
      if ( s_gets2(flower, SIZE) )
    {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    
    puts("bye");
    return;
}

void listing11_19(void)
{
    char flower[SIZE2];
    char addon[] = "s smell like old shoes";
    char bug[BUGSIZE];
    int available;
    
    puts("\n*** Listing 11.19 ***\n");
    
    puts("What is your favorite flower?");
    s_gets(flower, SIZE2);
    
    if ( ( strlen(addon) + strlen(flower) + 1 ) <= SIZE2 )
        strcat(flower, addon);
    
    puts(flower);
    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) -1;
    strncat(bug, addon, available);
    puts(bug);
    
    return;
}

void listing11_20(void)
{
    char try[SIZE3];
    
    puts("\n*** Listing 11.20 ***\n");
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE3);
    
    while (try!=ANSWER) {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE3);
    }
    puts("That's right!");
    return;
}

void listing11_21(void)
{
    char try[SIZE3];
    
    puts("\n*** Listing 11.21 ***\n");
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE3);
    
    while ( strcmp(try, ANSWER) != 0 ) {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE3);
    }
    puts("That's right!");
    return;
}

void listing11_22(void)
{
    puts("\n*** Listing 11.22 ***\n");
    
    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A"));
    
    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B"));
    
    printf("strcmp(\"B\", \"A\") is ");
    printf("%d\n", strcmp("B", "A"));
    
    printf("strcmp(\"C\", \"A\") is ");
    printf("%d\n", strcmp("C", "A"));
    
    printf("strcmp(\"Z\", \"a\") is ");
    printf("%d\n", strcmp("Z", "a"));
    
    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple"));
    
    return;
}

void listing11_23(void)
{
    char input[LIM3][SIZE3];
    int ct = 0;
    
    puts("\n*** Listing 11.23 ***\n");
    
    printf("Enter up to %d lines (type quit to quit):\n", LIM3);
    
    while( ct < LIM3 && s_gets(input[ct], SIZE3) != NULL && strcmp( input[ct], STOP) != 0 )
    {
        ct++;
    }
    
    printf("%d strings entered\n", ct);
    
    return;
}

void listing11_24(void)
{
    const char *list[LISTSIZE] =
    {
        "astronomy", "astounding",
        "astrophysics", "ostracize",
        "asterism", "astrophobia"
    };
    int count = 0;
    int i;
    
    puts("\n*** Listing 11.24 ***\n");
    
    for(i=0; i < LISTSIZE; i++)
        if ( strncmp(list[i], "astro", 5) == 0 )
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    
    printf("The list contained %d words beginning" " with astro.\n", count);
        
    return;
}

void listing11_25(void)
{
    char qwords[LIM4][SIZE4];
    char temp[SIZE4];
    int i = 0;
    
    puts("\n*** Listing 11.25 ***\n");
    
    printf("Enter %d words beginning with q:\n", LIM4);
    
    while (i < LIM4 && s_gets(temp, SIZE4)) {
        if (temp[0]!='q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strcpy(qwords[i], temp);
            i++;
        }
    }
    
    puts("Here are the words accepted:\n");
    for( i = 0; i < LIM4; i++)
        puts(qwords[i]);
    
    return;
}

void listing11_26(void)
{
    const char* orig = WORDS;
    char copy[SIZE4] = "Be the best that you can be.";
    char *ps;
    
    puts("\n*** Listing 11.26 ***\n");

    puts(orig);
    puts(copy);
    
    ps = strcpy(copy+7, orig);
    puts(copy);
    puts(ps);
    
    return;
}

void listing11_27(void)
{
    char qwords[LIM5][SIZE5];
    char temp[SIZE5];
    int i = 0;
    
    puts("\n*** Listing 11.27 ***\n");
    
    
    printf("Enter %d words beginning with q:\n", LIM5);
    
    while ( i < LIM5 && s_gets(temp, SIZE5))
    {
        if (temp[0]!='q')
            printf("%s doesn't start with q!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGETSIZE5-1);
            qwords[i][TARGETSIZE5-1] = '\0';
            i++;
        }
    }
    
    puts("Here are the words accepted:\n");
    for(i=0; i < LIM5; i++)
        puts( qwords[i] );
    
    return;
}

void listing11_28(void)
{
    char first[MAX];
    char last[MAX];
    char formal[2*MAX+10];
    double prize;
    
    puts("\n*** Listing 11.28 ***\n");
    
    puts("Enter your first name:");
    s_gets(first, MAX);
    puts("Enter your last name:");
    s_gets(last, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    
    puts(formal);
    
    return;
}

void listing11_29(void)
{
    char input[LIM6][SIZE6];
    char *ptstr[LIM6];
    int ct = 0;
    int k;
    
    puts("\n*** Listing 11.29 ***\n");
    
    printf("Input up to %d lines, and I will sort them.\n", LIM6);
    printf("To stop, press the Enter key at a line's start.\n");
    
    while (ct < LIM6 && s_gets(input[ct], SIZE6) != NULL && input[ct][0] != '\0'  )
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    
    stsrt(ptstr, ct);
    puts("\nHere's the sorted list:\n");
    for (k=0; k < ct; k++)
        puts(ptstr[k]);
    
    return;
}

void stsrt(char *strings[], int n)
{
    char *temp;
    int top, seek;
    
    for( top = 0; top < n - 1; top++ )
        for ( seek = top + 1; seek < n; seek++)
            if ( strcmp(strings[top], strings[seek]) > 0 )
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

void listing11_30(void)
{
    char line[LIMIT7];
    char *find;
    
    puts("Please enter a line:");
    fgets(line, LIMIT7, stdin);
    find=strchr(line, '\n');
    
    if (find)
        *find='\0';
    
    ToUpper(line);
    
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
    puts("\n*** Listing 11.30 ***\n");
    return;
}

void ToUpper(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char *str)
{
    int ct = 0;
    
    while(*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    
    return ct;
}

void listing11_32( int argc, char *argv[])
{
    int i, times;
    
    puts("\n*** Listing 11.32 ***\n");
    
    if (argc < 2 || ( times = atoi(argv[1])) < 1 )
        printf("Usage: %s positive-number\n", argv[0]);
    else
        for( i = 0; i < times; i++)
            puts("Hello, good looking!");
            
    return;
}

void listing11_33(void)
{
    char number[LIM8];
    char *end;
    long value;
    
    puts("\n*** Listing 11.33 ***\n");
    
    puts("Enter a number (empty line to quit):");
    while ( s_gets(number, LIM8) && number[0] != '\0' )
    {
        value = strtol(number, &end, 10);
        
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16);
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        
        puts("Next number:");
    }
    
    puts("Bye!\n");
    
    return;
}

char* s_gets2(char *st, int n)
{
    char *ret_val;
    
    ret_val = fgets(st, n, stdin);
    if ( ret_val )
    {
        while ( *st != '\n' && *st != '\0'   )
            st++;
        if ( *st == '\n' )
            *st = '\0';
        else
            while (getchar() != '\n')
            continue;
    }
    
    return ret_val;
}
