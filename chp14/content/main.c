//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 28.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "chp14Types.h"

const char *msgs[5] =
{
    "    Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together",
    "over a delicious ",
    " and have a few laughs"
};

const char * colors[] = { "red", "orange", "yellow", "green", "blue", "violet" };

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Content for Chapter 14 ***\n");
    //listing14_1();
    //listing14_2();
    //listing14_3();
    //listing14_4();
    //listing14_10();
    //listing14_11();
    //listing14_12();
    //listing14_13();
    listing14_14();
    //listing14_15();
    //listing14_16();
    return 0;
}


void listing14_1(void)
{
    struct book library;
    
    puts("\n*** Listing 14.1 ***\n");
    
    
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    
    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");
    
    return;
}

void listing14_2(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    
    puts("\n*** Listing 14.2 ***");
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0' )
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        
        while ( getchar() != '\n' )
            continue;
        
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    
    if ( count > 0 )
    {
        printf("Here is the list of your books:\n");
        
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
    
    return;
}

void listing14_3(void)
{
    struct guy fellow =
    {
        {"Ewen", "Williams"},
        "grilled salmon",
        "personality coach",
        68112.0
    };
    
    puts("\nListing 14.3 ***\n");
    
    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    
    if ( fellow.income > 150000.0 )
        puts("!!");
    else if ( fellow.income > 75000.0 )
        puts("!");
    else
        puts(".");
    
    printf("\n%40s%s\n", " ", "See you soon,");
    printf("%40s%s\n", " ", "Shalala");
    
    return;
}

void listing14_4(void)
{
    struct guy fellow[2] =
    {
        {
            {"Ewen", "Williams"},
            "grilled salmon",
            "personality coach",
            68112.0
        },
        {
            {"Rodney", "Swillbelly"},
            "tripe",
            "tabloid editor",
            232400.0
        }
    };
    
    struct guy *him;
    
    puts("\n*** Listing 14.4 ***\n");
    
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("pointer #1: %p #2: %p\n", him, him+1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
    
    him++;
    
    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);
       
    
    return;
}


void getinfo(struct namect *pst)
{
    char temp[SLEN];
    
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    
    pst->fname = (char*)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(pst->fname, temp);
    
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname  = (char*)malloc(sizeof(char) * ( strlen(temp) + 1 ));
    strcpy(pst->lname, temp);
    
    return;
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
}

void listing14_10(void)
{
    struct namect person;
    
    puts("\n*** Listing 14.10 ***\n");
    
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
        
    return;
}


void listing14_11(void)
{
    struct book readfirst;
    int score;
    
    puts("\n*** Listing 14.11 ***\n");
    
    printf("Enter test score: ");
    scanf("%d", &score);
    
    if (score >= 84)
        readfirst = (struct book) { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25 };
    else
        readfirst = (struct book) { "Mr. Bouncy's Nice Hat", "Fred Winsome", 5.99 };
    
    printf("Your assigned reading:\n");
    printf("%s by %s: $%.2f\n", readfirst.title, readfirst.author, readfirst.value);
    
    return;
}

void showFlex(const struct flex *p)
{
    int i;
    printf("Scores : ");
    for ( i = 0; i < p->count; i++)
        printf("%g ", p->scores[i]);
    
    printf("\nAverage: %g\n", p->average);
}

void listing14_12(void)
{
    struct flex *pf1, *pf2;
    int n = 5;
    int i;
    int tot = 0;
    
    puts("\n*** Listing 14.12 ***\n");
    
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for( i = 0; i < n; i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    
    pf1->average = tot / n;
    showFlex(pf1);
    
    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for( i = 0; i < n; i++ )
    {
        pf2->scores[i] = 20.0 - i / 2.0;
        tot += pf2->scores[i];
    }
    
    pf2->average = tot / n;
    showFlex(pf2);
    free(pf1);
    free(pf2);
    
    return;
}

char* s_gets(char *st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val=fgets(st, n, stdin);
    
    if (ret_val)
    {
        find = strchr(st, '\n');
        
        if (find)
            *find = '\0';
        else
            while ( getchar() != '\n' )
                continue;
    }
    
    return ret_val;
}

double sum(const struct funds money[], int n)
{
    double total = 0.0;
    int i;
    
    for(i = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;
    
    return total;
    
}

void listing14_13(void)
{
    struct funds jones[N] =
    {
        {
            "Garlic-Melon Bank",
            4032.27,
            "Luck's Savings and Loan",
            8543.94
        },
        {
            "Honest Jack's Bank",
            3620.88,
            "Party Time Savings",
            3802.91
        }
    };

    puts("\n*** Listing 14.13 ***\n");
    printf("The Joneses have a total of %.2f.\n", sum(jones, N));
    
    return;
}

void listing14_14(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    
    puts("\n*** Listing 14.14 ***\n");
    
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    
    rewind(pbooks);
    
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks)) {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: %.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    
    filecount = count;
    
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full", stderr);
        exit(2);
    }
    
    puts("Please add new book title.");
    puts("Press [enter] at the start of a line to stop.");
    
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        
        while (getchar()!='\n')
            continue;
        
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    
    if ( count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].author, library[index].title, library[index].value);
        
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
        puts("No books? Too bad.\n");
    
    puts("Bye.\n");
    fclose(pbooks);
    
    return;
}

void listing14_15(void)
{
    char choice[LENC];
    enum spectrum color;
    bool color_is_found = false;
    
    puts("Enter a color (empty line to quit):");
    
    while (s_gets(choice, LENC) != NULL && choice[0]!='\0')
    {
        for (color = red; color <= violet; color++)
        {
            if ( strcmp(choice, colors[color]) == 0 )
            {
                color_is_found = true;
                break;;
            }
        }
        
        if ( color_is_found )
            switch (color)
            {
                case red:
                    puts("Roses are red.");
                    break;
                    
                case orange:
                    puts("Poppies are orange.");
                    break;
                
                case yellow:
                    puts("Sunflowers are yellow.");
                    break;
                    
                case green:
                    puts("Grass is green.");
                    break;
                    
                case blue:
                    puts("Bluebells are blue.");
                    break;
                    
                case violet:
                    puts("Violets are violet.");
                    break;
                    
                default:
                    break;
            }
        else
            printf("I don't know about the color %s.\n", choice);
        
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
        
    }
    
    puts("Goodbye!");
    
    return;
}

char showmenu(void)
{
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase       l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    
    ans = getchar();
    ans = tolower(ans);
    eatline();
    
    while ( strchr("ulton", ans) == NULL )
    {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    
    return ans;
}

void eatline(void)
{
    while ( getchar() != '\n')
        continue;
}

void show( void (*fp)(char*), char *str )
{
    (*fp)(str);
    puts(str);
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char *str)
{
    while (*str)
    {
        if ( islower(*str) )
            *str = toupper(*str);
        else
            if (isupper(*str))
                *str = tolower(*str);
        
        str++;
    }
}

void Dummy(char *str)
{
    
}

void listing14_16(void)
{
    char line[SLEN];
    char copy[SLEN];
    char choice;
    void (*pfun)(char*);
    
    puts("Enter a string (empty line to quit)");
    
    while (s_gets(line, SLEN) && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice)
            {
                case 'u':
                    pfun = ToUpper;
                    break;
                case 'l':
                    pfun = ToLower;
                    break;
                case 't':
                    pfun = Transpose;
                    break;
                case 'o':
                    pfun = Dummy;
                    break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
    
    return;
}
