//
//  chp15contents.h
//  content
//
//  Created by Faik Hakan Bilgen on 9.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp15contents_h
#define chp15contents_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

/* BIT-FIELD CONSTANTS */
/* Line Styles */
#define SOLID  0
#define DOTTED 1
#define DASHED 2

/* Primary Colors */
#define BLUE  4
#define GREEN 2
#define RED   1

/* Mixed Colors */
#define BLACK 0
#define YELLOW ( RED | GREEN)
#define MAGENTA ( RED | BLUE)
#define CYAN ( GREEN | BLUE)
#define WHITE ( RED | GREEN | BLUE )

/* BITWISE CONSTANTS */
#define OPAQUE      0x1
#define FILL_BLUE   0x8
#define FILL_GREEN  0x4
#define FILL_RED    0x2
#define FILL_MASK   0xE
#define BORDER      0x100
#define BORDER_BLUE 0x800
#define BORDER_RED  0x200
#define BORDER_MASK 0xE00
#define B_SOLID     0x0
#define B_DOTTED    0x1000
#define B_DASHED    0x2000
#define STYLE_MASK  0x3000

struct box_probs
{
    bool opaque                 : 1;
    unsigned int fill_color     : 3;
    unsigned int                : 4;
    bool show_border            : 1;
    unsigned int border_color   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2;
};

union Views
{
    struct box_probs st_view;
    unsigned short us_view;
};


void listing15_1(void);
void listing15_2(void);

char *itobs(int, char *);
void show_bstr(const char*);
int invert_end(int num, int bits);

void listing15_3(void);
void show_settings(const struct box_probs *pb);

void listing15_4(void);
void show_settings1(unsigned short);

void listing15_5(void);
#endif /* chp15contents_h */
