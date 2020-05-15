//
//  chp17Content.h
//  content
//
//  Created by Faik Hakan Bilgen on 15.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp17Content_h
#define chp17Content_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

#define TSIZE   45
#define FMAX    5

#define FILMLINKEDLIST

#ifndef FILMLINKEDLIST

    struct film
    {
        char title[TSIZE];
        int rating;
    };

#endif

#define LIST173

#ifndef  LIST173

    struct film
    {
        char title[TSIZE];
        int rating;
        struct film *next;
    };

#endif

char* s_gets(char *st, int n);
void listing17_1(void);
void listing17_2(void);

void listing17_3(void);

void listing17_8(void);


char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
void listing17_12(void);

void eatnl(void);


#endif /* chp17Content_h */
