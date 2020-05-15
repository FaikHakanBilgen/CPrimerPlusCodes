//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 28.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>     // for randomization
#include <string.h>
#include <ctype.h>      // for charecter functions
#include <stdbool.h>    // for bool
#include <limits.h>     // for max/min integer
#include <float.h>      // for maximum flat
#include <time.h>       // for time function for initializing the random seed
#include "chp14ex.h"

struct month months[MONTHS] =
{
    { "January", "jan", 31, 1 },
    { "February", "feb", 28, 2 },
    { "March", "mar", 31, 3 },
    { "April", "apr", 30, 4 },
    { "May", "may", 31, 5 },
    { "June", "jun", 30, 6 },
    { "July", "jul", 31, 7 },
    { "August", "aug", 31, 8 },
    { "September", "sep", 30, 9 },
    { "October", "oct", 31, 10 },
    { "November", "nov", 30, 11 },
    { "December", "dec", 31, 12 }
};

struct month year[MONTHS] =
{
    { "January", "jan", 31, 1 },
    { "February", "feb", 28, 2 },
    { "March", "mar", 31, 3 },
    { "April", "apr", 30, 4 },
    { "May", "may", 31, 5 },
    { "June", "jun", 30, 6 },
    { "July", "jul", 31, 7 },
    { "August", "aug", 31, 8 },
    { "September", "sep", 30, 9 },
    { "October", "oct", 31, 10 },
    { "November", "nov", 30, 11 },
    { "December", "dec", 31, 12 }
};

struct month leapyear[MONTHS] =
{
    { "January", "jan", 31, 1 },
    { "February", "feb", 29, 2 },
    { "March", "mar", 31, 3 },
    { "April", "apr", 30, 4 },
    { "May", "may", 31, 5 },
    { "June", "jun", 30, 6 },
    { "July", "jul", 31, 7 },
    { "August", "aug", 31, 8 },
    { "September", "sep", 30, 9 },
    { "October", "oct", 31, 10 },
    { "November", "nov", 30, 11 },
    { "December", "dec", 31, 12 }
};

const int Flights[FLIGHTCOUNT] = {102, 311, 444, 519};

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Exercises for Chapter 14 ***");
    
    srand((unsigned int) time(0));
    
    //exercise14_1();
    //exercise14_2();
    //exercise14_3();
    //exercise14_4();
    //exercise14_5();
    //exercise14_6();
    
    // exercise14_8(); Directly implemented 14.9
    exercise14_9();
    return 0;
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

int days(int month)
{
    int i, total;
    
    if ( month < 0 || month > 12 )
        return -1;
    
    for( i = 0, total = 0; i < month; i++ )
        total += months[i].days;
    
    return total;
        
}

int days2(const char *month)
{
    bool monthfound = false;
    int total = 0, i = 0;
    
    while ( i < MONTHS && !monthfound )
    {
        total += months[i].days;
        
        if ( ! strcmp(months[i++].name, month)  )
            monthfound = true;
    }
    
    return monthfound ? total : -1;
    
}

void exercise14_1(void)
{
    char monnm[MONLEN];
    
    puts("\n*** Exercise 14.1 ***\n");
    
    puts("Enter the month name (press ENTER to exit)");
    
    while ( s_gets(monnm, MONLEN) != NULL  && monnm[0] != '\0' )
    {
        printf("Until the end of %s there are %d days\n", monnm, days2(monnm));
        puts("Enter the month name (press ENTER to exit)");
    }
    
    puts("Bye.");
}

int GetMonth()
{
    int i;
    int mon = -1;
    char monnm[10];
    
    puts("Enter a month ( 1-12, Jan-Dec or January-December ) ");
    
    while ( s_gets(monnm, MONLEN) != NULL )
    {
        
        if ( strstr("123456789101112", monnm) != NULL )
        {
            mon = atoi(monnm);
            
            if ( mon < 0 || mon > MONTHS )
            {
                puts("Enter a month ( 1-12, Jan-Dec or January-December ) "); // This is for faster execution. Omitting the below if checks
                continue;
            }
            else
                return mon;
                
        }
        
        if ( strstr("janfebmaraprmayjunjulaugsepoctnovdec", monnm) != NULL )
        {
            for( i=0; i < MONTHS; i++ )
                if ( !strcmp(months[i].abv, monnm) )
                    return i+1;
        }
                
        if ( strstr("JanuaryFebruaryMarchAprilMayJuneJulyAugustSeptemberOctoberNovemberDecember", monnm) != NULL )
        {
            for( i=0; i < MONTHS; i++ )
                if ( !strcmp(months[i].name, monnm) )
                    return i+1;
        }
        
        puts("Enter a month ( 1-12, Jan-Dec or January-December ) ");
    }
    
    return -1; // Just to supress the compiler warning. Normally the program should never reach here.
}


struct date* GetDate()
{
    struct date *dt = NULL;
    struct month *ayear;
        
    dt = malloc(sizeof(struct date));
    
    if ( dt == NULL )
    {
        fprintf(stderr, "GetDate could not allocate memory for date structure\n");
        exit(1);
    }
    
    puts("Please enter a year:");
    
    while ( scanf("%d", &(dt->year)) != 1 && dt->year > MINYEAR && dt->year < MAXYEAR  )
    {
        puts("Please enter a year greater than 0 and less 2100");
    }
    
    // eatline :)
    while (getchar()!='\n')
        continue;
    
    if ( dt->year % 4 == 0 )
        ayear = leapyear;
    else
        ayear = year;
    
    
    dt->month = GetMonth();
    
    printf("Please enter a day greater than %d and less %d : ", 0, ayear[dt->month].days);
    
    while ( scanf("%d", &(dt->day)) != 1 && dt->day > 0 && dt->year < ayear[dt->month].days )
    {
        printf("Please enter a day greater than %d and less %d : ", 0, ayear[dt->month].days);
    }
    
    // eatline :)
    while (getchar()!='\n')
        continue;
    
    return dt;
}

int DaysPassed(const struct date* pd)
{
    int i;
    int days = 0;
    struct month *ayear;
    
    if ( pd->year % 4 == 0 )
        ayear = leapyear;
    else
        ayear = year;
    
    for ( i=0; i < pd->month-1; i++ )
        days += ayear[i].days;
    
    days += pd->day;
    
    return days;
}

void exercise14_2(void)
{
    struct date *pdt = NULL;
    
    puts("\n*** Exercise 14.2 ***\n");
    
    pdt = GetDate();
    
    printf("%d days passed from January, 1 %d until %s, %d %d\n", DaysPassed(pdt), pdt->year, months[pdt->month].name, pdt->day, pdt->month);
    
    return;
}

void exercise14_3(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    
    puts("\n*** Exercise 14.3 ***");
    
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
        printf("Here is the list of your books (Order by record no):\n");
        
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        
        printf("\n");
        
        
        OrderByValue(library, count);
        
        printf("Here is the list of your books (Order by incresing value):\n");
        
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        
        printf("\n");
        
        
        OrderByTitle(library, count);
        
        printf("Here is the list of your books (Order by title):\n");
        
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        
        printf("\n");
        
    }
    else
        printf("No books? Too bad.\n");
    
    return;
}

void OrderByValue( struct book *sbooks, int len )
{
    int i, j, index;
    float min;
    struct book temp;
    
    for( i = 0; i < len; i++ )
    {
        min = sbooks[i].value;
        index = i;
        
        for ( j = i; j < len; j++ )
            if ( sbooks[j].value < min )
            {
                index = j;
                min = sbooks[j].value;
            }
        
        if ( index != i )
        {
            strcpy(temp.author, sbooks[index].author);
            strcpy(temp.title, sbooks[index].title);
            temp.value = sbooks[index].value;
                    
            strcpy( sbooks[index].author, sbooks[i].author);
            strcpy( sbooks[index].title, sbooks[i].title);
            sbooks[index].value = sbooks[i].value;
            
            strcpy( sbooks[i].author, temp.author );
            strcpy( sbooks[i].title, temp.title);
            sbooks[i].value = temp.value;
        }
    }
}


void OrderByTitle( struct book *sbooks, int len )
{
    int i, j, index;
    char title[MAXTITL];
    
    struct book temp;
    
    for( i = 0; i < len; i++ )
    {
        strcpy( title, sbooks[i].title);
        index = i;
        
        for ( j = i; j < len; j++ )
            
            if ( strcmp(sbooks[j].title, title) < 0 )
            {
                index = j;
                strcpy( title, sbooks[j].title);
            }
            
        
        if ( index != i )
        {
            strcpy(temp.author, sbooks[index].author);
            strcpy(temp.title, sbooks[index].title);
            temp.value = sbooks[index].value;
                    
            strcpy( sbooks[index].author, sbooks[i].author);
            strcpy( sbooks[index].title, sbooks[i].title);
            sbooks[index].value = sbooks[i].value;
            
            strcpy( sbooks[i].author, temp.author );
            strcpy( sbooks[i].title, temp.title);
            sbooks[i].value = temp.value;
        }
    }
}


void exercise14_4(void)
{
    int i;
    struct person people[5] =
    {
        { "302039823", { "Flossie", "Middle", "Dribble" } },
        { "012345678", { "Faik", "Hakan", "Bilgen" } },
        { "123456789", { "Umut", "Kadir", "Korkmaz" } },
        { "234567890", { "Mete", "Deniz", "Bektur" } },
        { "345678901", { "Zerrin", "", "Bilgen" } }
    };
    puts("\n*** Exercise 14.4 ***\n");
    
    printperson(people, 5);
    
    printf("\n\n");
    
    for( i = 0; i < 5; i++ )
        printperson2(people[i]);
    
    return;
}

void printperson(struct person *pp, int len)
{
    int i;
    
    for( i = 0; i < len; i++ )
    {
        printf("%s, %s ", pp[i].nm.lname, pp[i].nm.fname);
        
        if ( pp[i].nm.mname[0] == '\0' )
            printf("--- ");
        else
            printf("%c. --- ", pp[i].nm.mname[0]);
        
        printf("%s\n", pp[i].ssn);
        
    }
}

void printperson2(struct person pp)
{
    printf("%s, %s ", pp.nm.lname, pp.nm.fname);
    
    if ( pp.nm.mname[0] == '\0' )
        printf("--- ");
    else
        printf("%c. --- ", pp.nm.mname[0]);
    
    printf("%s\n", pp.ssn);
    
}


void exercise14_5(void)
{
    int i;
    
    struct student students[CSIZE] =
    {
        { {"Umut", "Korkmaz"}  },
        { {"Alper", "Sensan"}  },
        { {"Uluc", "Batmaz"}   },
        { {"Tolga", "Erton"}   }
    };
  

    puts("\n*** Exercise 14.5 ***\n");
    
//    for( i = 0; i < CSIZE; i++ )
//        printf("name: %s surname: %s\n", students[i].name.fname, students[i].name.lname);

    GetScores(students, CSIZE);
    
    for( i = 0; i < CSIZE; i++ )
        CalcAvg( &(students[i]) );
    
    
    for( i = 0; i < CSIZE; i++ )
        ShowStudent( &(students[i]) );
        
    printf("\nClass average is %.2f\n", ClassAvg(students, CSIZE) );

    return;
}


void ShowStudent( struct student *ps)
{
    printf("%s, %s Scores: %.2f, %.2f, %.2f Average: %.2f\n", ps->name.lname, ps->name.fname, ps->scores[0], ps->scores[1], ps->scores[2], ps->avg );
}

void GetScores( struct student *ps, int len)
{
    int i;
    
    for( i = 0; i < len; i++ )
    {
        printf("Please enter three scores for %s, %s\n", ps[i].name.fname, ps[i].name.lname);
        
        while ( scanf("%f%f%f", &(ps[i].scores[0]), &(ps[i].scores[1]), &(ps[i].scores[2]) ) != 3 )
        {
            printf("Please enter three scores for %s, %s\n", ps[i].name.fname, ps[i].name.lname);
            eatNewLine();
        }
        eatNewLine();
                
    }
}

void CalcAvg(struct student *ps)
{
    int i;
    float total = 0.0F;
    
    for ( i = 0; ps->scores[i]; i++ )
        total += ps->scores[i];
    
    ps->avg = total / (float)MAXSCORES;
}

float ClassAvg( struct student *ps, int csz )
{
    int i, j;
    float total = 0.0F;
    
    for ( i = 0; i < csz; i++ )
        for ( j = 0; j < MAXSCORES; j++ )
            total += ps[i].scores[j];
       
    return total / (float) ( i * j );
}

void eatNewLine(void)
{
    while( getchar() != '\n' )
        continue;
}


void exercise14_6(void)
{
    GetTeamGames(GAMESFILE, TEAMSIZE, GAMECOUNT);
}

void FillGamesFile(const char* fn, int teamsize, int gamecount)
{
    int i, j;
    FILE *fp;
    
    fp = fopen(fn, "a+b");
    
    if ( fp == NULL )
        fprintf(stderr, "could not open file %s\n", fn);
        
    for( i = 0; i < teamsize; i++ )
        for( j = 0; j < gamecount; j++ )
            GeneratePlayerGames(i+1, gamecount, fp);
    
    fclose(fp);
}

void GetTeamGames(const char* fn, int teamsize, int gamecount)
{
    int i, no;
    unsigned long rd;
    FILE *fp = NULL;
    struct playergame pg;
    struct playerstat *ts;
    struct gamestat tmst;
    
    fp = fopen(fn, "r+b");
    
    if ( !fp )
        FillGamesFile(GAMESFILE, TEAMSIZE, GAMECOUNT);
    
    fp = fopen(fn, "r+b");
    if ( !fp )
    {
        fprintf(stderr, "Problem accessing the games file: %s\n", GAMESFILE);
        exit(1);
    }
    
    ts = (struct playerstat*) malloc(sizeof(struct playerstat) * teamsize);
    
    for( i = 0; i < teamsize; i++ )
    {
        ts[i].plyr.no = i + 1;
        ts[i].plyr.fname[0] = '\0';
        ts[i].plyr.lname[0] = '\0';
        ts[i].cumstat.bat = 0;
        ts[i].cumstat.hits = 0;
        ts[i].cumstat.walks = 0;
        ts[i].cumstat.RBI = 0;
        ts[i].batavg = 0.0F;
    }
       
    
    while ( ( rd = fread(&pg, sizeof(struct playergame), 1, fp) ) != 0 )
    {
        no = pg.p.no - 1;
        
        if ( ts[ no ].plyr.fname[0] == '\0' )
        {
            strcpy(ts[no].plyr.fname, pg.p.fname);
            strcpy(ts[no].plyr.lname, pg.p.lname);
        }
        
        ts[no].cumstat.bat += pg.s.bat;
        ts[no].cumstat.hits += pg.s.hits;
        ts[no].cumstat.RBI += pg.s.RBI;
        ts[no].cumstat.walks += pg.s.walks;
    }
    
    if ( fclose(fp) != 0 )
        fprintf(stderr, "Error closing the file %s \n", GAMESFILE);
    
    for( i = 0; i < TEAMSIZE; i++ )
        ts[i].batavg = (float)ts[i].cumstat.hits / (float)ts[i].cumstat.RBI;
    
    tmst.bat = tmst.hits = tmst.RBI = tmst.walks = 0;
    
    for( i = 0; i < TEAMSIZE; i++ )
    {
        printf("%2d %s %s %4d %4d %4d %4d %.2f\n", ts[i].plyr.no, ts[i].plyr.fname, ts[i].plyr.lname, ts[i].cumstat.bat, ts[i].cumstat.hits, ts[i].cumstat.walks, ts[i].cumstat.RBI, ts[i].batavg);
        tmst.bat  += ts[i].cumstat.bat;
        tmst.hits += ts[i].cumstat.hits;
        tmst.walks += ts[i].cumstat.walks;
        tmst.RBI += ts[i].cumstat.RBI;
    }
    
    free(ts);
    
    printf("%d %19s %19s %d %d %d %d %.2f\n", 0, "", "", tmst.bat, tmst.hits, tmst.walks, tmst.RBI, (float)tmst.hits / (float)tmst.RBI );
        
}

void GeneratePlayerGames(int playerno, int gamecount, FILE *fp)
{
    int i;
    struct player    *ply;
    struct gamestat  *pgs;
    struct playergame *pg;
    
    ply = GeneratePlayer(playerno);
        
    pg = malloc(sizeof(struct playergame));
        
    strcpy( pg->p.fname, ply->fname);
    strcpy( pg->p.lname, ply->lname);
    pg->p.no = ply->no;
    
    for( i = 0; i < gamecount; i++ )
    {
        pgs = GenerateGameStat();
        pg->s = *pgs;
        WriteGamePlayerStat(pg, fp);
        free(pgs);
    }
    
}

void WriteGamePlayerStat(const struct playergame *pg, FILE *fp)
{
    fwrite(pg, sizeof(struct playergame), 1, fp);
}


struct player* GeneratePlayer(int playerno)
{
    struct player *pp;
    char *cp;
    
    pp = malloc( sizeof(struct player) );
    
    pp->no = playerno;
    cp = GenerateName(NAMELEN);
    strcpy( pp->fname, cp);
    free(cp);
    
    cp = GenerateName(NAMELEN);
    strcpy( pp->lname, cp);
    free(cp);
    
    return pp;
}

struct gamestat* GenerateGameStat()
{
    struct gamestat *gs;
    
    gs = malloc(sizeof(struct gamestat));
    
    gs->bat = rand() % 100;
    gs->hits = rand() % 100;
    gs->RBI = rand() % 100;
    gs->walks = rand() % 100;
    
    return gs;
}

char* GenerateName(int nmlen)
{
    int i;
    char *cp;
    
    cp = malloc(sizeof(char) * nmlen);
    
    cp[0] = (rand() % 26) + 65;              // Initial Character is in upper and the rest is in lower case
    cp[nmlen-1] = '\0';
    
    for( i = 1; i < nmlen - 1; i++ )
        cp[i] = ( rand() % 26 ) + 97;
    
    return cp;
}

void exercise14_9(void)
{
    char choice;
    int i, j;
    int fID, fno;
    puts("\n*** Exercise 14.9 ***\n");
    
    Flight *flights = NULL;
    
    flights = GetFlights(FLIGHTSFILE, FLIGHTCOUNT);
    
    // The flights file is not found. Initialize the flights to initial values.
    if ( flights == NULL )
    {
        flights = (Flight*)malloc(sizeof(Flight) * 4);
        for( i = 0; i < FLIGHTCOUNT; i++ )
        {
            flights[i].capacity = SEATS;
            flights[i].fno = Flights[i];
            
            for( j = 0; j < SEATS; j++ )
            {
                flights[i].seats[j].assigned = false;
                flights[i].seats[j].no = j;
                strcpy(flights[i].seats[j].fname, "");
                strcpy(flights[i].seats[j].lname, "");
            }
        }
    }
    
    while ( ( fno = ShowTopMenu() ) != 0 )
    {
        fID = GetFlightID(fno);
        while ( (choice = showmenu()) != 'f' )
        {
            switch (choice) {
                case 'a':
                    ShowEmptySeatNumber(flights[fID]);
                    break;
                
                case 'b':
                    ShowEmptySeats(flights[fID]);
                    break;
                
                case 'c':
                    ShowSeats( flights[fID]);
                    break;
                
                case 'd':
                    assignseat(&flights[fID]);
                    break;
                
                case 'e':
                    removeassignment(&flights[fID]);
                    break;
                
                case 'f':
                    break;
            }
        }
    }
    
    WriteFlights(FLIGHTSFILE, flights, FLIGHTCOUNT);
    free(flights);
    
    return;
}

int GetFlightID(int fno)
{
    int i;
    
    for( i = 0; i < FLIGHTCOUNT; i++)
        if ( Flights[i] == fno )
            return i;
    
    return 0;
}
                              
int ShowTopMenu()
{
    int i;
    int choice;
    
    
    printf("Please select a flight (0 to exit): ");
    for( i = 0; i < FLIGHTCOUNT; i++ )
    {
        printf("%d ", Flights[i]);
    }
    printf("\n");
    scanf("%d", &choice);
    
    eatNewLine();


    return choice;
}

char showmenu(void)
{
    char ans;
    
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    
    ans = tolower(getchar());
    eatNewLine();
    
    while (strchr( "abcdef", ans ) == NULL )
    {
        puts("Please enter one of a/b/c/d/e/f");
        ans = tolower(getchar());
        eatNewLine();
    }
    
    return ans;
}

bool isseatavailable(Flight fl, int seatno)
{
    return !fl.seats[seatno].assigned;
}

void assignseat(Flight *pf)
{
    int seatno;
    
    printf("FLIGHT NO: %d\n", pf->fno);
    puts("Select seat number:");
    scanf("%d", &seatno );
    if ( !isseatavailable( *pf, seatno) )
    {
        printf("This seat is taken please select an available seat\n");
        return;
    }
    
    eatNewLine();
    
    puts("Please enter the first name");
    s_gets(pf->seats[seatno].fname, NAMELEN);
    
    puts("Please enter the last name");
    s_gets(pf->seats[seatno].lname, NAMELEN);
    
    pf->seats[seatno].assigned = true;
    
    puts("The seat is assigned successfully.");
}

void removeassignment(Flight *pf)
{
    int seatno;
    printf("FLIGHT NO: %d\n", pf->fno);
    puts("Select seat number:");
    scanf("%d", &seatno );
    
    if ( isseatavailable( *pf, seatno) )
    {
        printf("This seat is free please select an occupied seat\n");
        return;
    }
    
    eatNewLine();
    
    strcpy(pf->seats[seatno].fname, "");
    strcpy(pf->seats[seatno].lname, "");
    pf->seats[seatno].assigned = false;
    
    puts("The seat assignment is removed successfully");
}

void ShowEmptySeatNumber( Flight fl  )
{
    int i;
    int total = 0;
    
    for( i = 0; i < fl.capacity; i++ )
        total += fl.seats[i].assigned ? 0 : 1;
    
    printf("FLIGHT NO: %d\n", fl.fno);
    printf("There are %d seats available in flight %d\n", total, fl.fno);
}

void ShowEmptySeats( Flight fl  )
{
    int i;
    bool seatsavailable = false;
    
    printf("FLIGHT NO: %d\n", fl.fno);
    
    for( i = 0; i < fl.capacity && !seatsavailable; i++ )
        if (! fl.seats[i].assigned )
            seatsavailable = true;
    
    if ( !seatsavailable )
    {
        printf("There are no seats available for this flight\n");
        return;;
    }
    else
    {
        printf("These seats are available for flight %d :", fl.fno);
        for( i = 0; i < fl.capacity; i++ )
            if (! fl.seats[i].assigned )
                printf("%d ", fl.seats[i].no);
        
        printf("\n");
    }
}

void ShowSeats( Flight fl )
{
    int i;
    
    printf("The seat list for flight %d\n", fl.fno);
    
    for ( i = 0; i < fl.capacity; i++ )
    {
        if ( fl.seats[i].assigned )
            printf("%2d + %s, %s\n", fl.seats[i].no, fl.seats[i].lname, fl.seats[i].fname);
        else
            printf("%2d - \n", fl.seats[i].no);
    }
    return;
}

void WriteFlights(const char *flgflnm, const Flight* pf, int flightcount)
{
    FILE *fp = NULL;
    
    if ( ( fp = fopen(flgflnm, "w+b") ) == NULL )
    {
        fprintf(stderr, "Could not open file %s for writing", flgflnm);
        exit(1);
    }
    
    fwrite(pf, sizeof(Flight), flightcount, fp);
    
    if ( fclose(fp) != 0 )
    {
        fprintf(stderr, "File %s could not be closed\n", flgflnm);
        exit(1);
    }
}


Flight* GetFlights(const char *flgflnm, int flightcount)
{
    int i = 0;
    Flight *pf = NULL;
    Flight fl;
    unsigned long rd = 0;
    FILE *fp = NULL;
    
    if ( (fp =fopen(flgflnm, "rb")) == NULL )
    {
        fprintf(stderr, "File %s could not be opened\n", flgflnm);
        return NULL;
    }
    
    pf = (Flight*)malloc(sizeof(Flight) * flightcount);
    
    if ( !pf )
    {
        fprintf(stderr, "Memory could not be allocated in GetFlights\n");
        exit(1);
    }
    
    while ( (rd = fread(&fl, sizeof(Flight), 1, fp)) !=0  )
    {
        CopyFlight(&pf[i], fl);
    }
    
    if ( fclose(fp) != 0 )
    {
        fprintf(stderr, "File %s could not be closed\n", flgflnm);
        exit(1);
    }
    
    return pf;
}

void CopyFlight( Flight *pf, Flight fl )
{
    int i;
    
    pf->capacity = fl.capacity;
    pf->fno = fl.fno;
    for( i = 0; i < fl.capacity; i++ )
    {
        pf->seats[i].no = fl.seats[i].no;
        pf->seats[i].assigned = fl.seats[i].assigned;
        strcpy(pf->seats[i].fname, fl.seats[i].fname);
        strcpy(pf->seats[i].lname, fl.seats[i].lname);
    }
}
