//
//  chp14Types.h
//  content
//
//  Created by Faik Hakan Bilgen on 28.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp14Types_h
#define chp14Types_h

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
#define LEN 20
#define LENC 30
#define SLEN 81
#define FUNDLEN 50
#define N 2

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

struct namect
{
    char *fname;
    char *lname;
    int letters;
};

struct names
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

struct flex
{
    size_t count;
    double average;
    double scores[];
};

enum spectrum { red, orange, yellow, green, blue, violet };

char* s_gets(char *st, int n);
void listing14_1(void);
void listing14_2(void);
void listing14_3(void);
void listing14_4(void);

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);
void listing14_10(void);
void listing14_11(void);
void showFlex(const struct flex *p);
void listing14_12(void);
double sum(const struct funds money[], int n);
void listing14_13(void);
void listing14_14(void);
void listing14_15(void);

char showmenu(void);
void eatline(void);
void show( void (*fp)(char*), char *str );
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);
void listing14_16(void);

#endif /* chp14Types_h */
