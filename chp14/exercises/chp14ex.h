//
//  chp14ex.h
//  exercises
//
//  Created by Faik Hakan Bilgen on 6.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp14ex_h
#define chp14ex_h

#define MONLEN 10
#define MONTHS 12

#define MINYEAR 0
#define MAXYEAR 2100

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

#define NAMELEN 20
#define SSNLEN 10

#define MAXSCORES 3
#define CSIZE 4

#define TEAMSIZE 18
#define GAMESFILE "games.dat"
#define GAMECOUNT 5

#define SEATS 12
#define FLIGHTCOUNT 4
#define FLIGHTSFILE "flights.dat"

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct month
{
    char name[MONLEN];
    char abv[4];
    int days;
    int no;
};

struct date
{
    int day;
    int month;
    int year;
};

struct name
{
    char    fname[NAMELEN];
    char    mname[NAMELEN];
    char    lname[NAMELEN];
};

struct person
{
    char        ssn[SSNLEN];
    struct name nm;
};

struct sname
{
    char fname[NAMELEN];
    char lname[NAMELEN];
};

struct student
{
    struct sname name;
    float  scores[MAXSCORES];
    float  avg;
};

struct player
{
    int no;
    char fname[NAMELEN];
    char lname[NAMELEN];
};

struct gamestat
{
    int bat;
    int hits;
    int walks;
    int RBI;
};

struct playergame
{
    struct player   p;
    struct gamestat s;
};

struct playerstat
{
    struct player       plyr;
    struct gamestat     cumstat;
    float batavg;
};

struct seat
{
    int  no;
    bool assigned;
    char lname[NAMELEN];
    char fname[NAMELEN];
};

typedef struct seat Seat;

struct flight
{
    int     fno;
    int     capacity;
    Seat    seats[SEATS];
};

typedef struct flight Flight;



char* s_gets(char *st, int n);
void exercise14_1(void);
int days(int month);
int days2(const char *month);
int DaysPassed(const struct date* pd);
int GetMonth(void);
struct date* GetDate(void);
void exercise14_2(void);
void exercise14_3(void);
void OrderByValue( struct book *sbooks, int len );
void OrderByTitle( struct book *sbooks, int len );
void exercise14_4(void);
void printperson(struct person *pp, int len);
void printperson2(struct person pp);

void GetScores( struct student *ps, int len);
void CalcAvg(struct student *ps);
float ClassAvg( struct student *ps, int csz );
void eatNewLine(void);
void ShowStudent( struct student *ps);
void exercise14_5(void);

void exercise14_6(void);
void GetTeamGames(const char* fn, int teamsize, int gamecount);
void FillGamesFile(const char* fn, int teamsize, int gamecount);
struct player* GeneratePlayer(int playerno);
struct gamestat* GenerateGameStat(void);
char* GenerateName(int nmlen);
void WriteGamePlayerStat(const struct playergame *pg, FILE *fp);
void GeneratePlayerGames(int playerno, int gamecount, FILE *fp);

void exercise14_9(void);
char showmenu(void);

void ShowEmptySeatNumber( Flight fl  );
void ShowEmptySeats( Flight fl  );
void ShowSeats( Flight fl );
void CopyFlight( Flight *pf, Flight fl );
Flight* GetFlights(const char *flgflnm, int flightcount);
void WriteFlights(const char *flgflnm, const Flight* pf, int flightcount);
void assignseat(Flight *pf);
void removeassignment(Flight *pf);
int ShowTopMenu(void);
bool isseatavailable(Flight fl, int seatno);
int GetFlightID(int fno);
#endif /* chp14ex_h */
