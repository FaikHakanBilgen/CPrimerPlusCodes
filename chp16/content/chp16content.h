//
//  chp16content.h
//  content
//
//  Created by Faik Hakan Bilgen on 11.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp16content_h
#define chp16content_h

//#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define TWO 2 /* You can use comments if you like*/
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde" /* a backslash continues a definition */
                     /* to the next line */
#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

#define SQUARE(X) X*X
#define PR(X)   printf("The result is %d.\n", X)

#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)) )

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);

#define PR2(X, ...) printf("Message " #X ": " __VA_ARGS__)

//#define JUST_CHECKING
#define LIMIT 4

#define MYTYPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)

#define NUM 40

#define SIZE 10

_Static_assert( sizeof(double) == 2 * sizeof(int), "double not twice int size");

void listing16_1(void);
void listing16_2(void);
void listing16_3(void);
void listing16_4(void);
void listing16_5(void);
void listing16_9(void);
void listing16_10(void);
void listing16_11(void);
void listing16_12(void);
void why_me(void);
void listing16_13(void);
void listing16_13_5(void);
void static inline eatline(void);

void listing16_16(void);
void sign_off(void);
void too_bad(void);

void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp( const void *p1, const void *p2 );
void listing16_17(void);


void listing16_18(void);

void listing16_20(void);
void show_array(const int ar[], int n);
#endif /* chp16content_h */
