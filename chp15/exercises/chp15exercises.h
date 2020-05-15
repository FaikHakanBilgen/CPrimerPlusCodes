//
//  chp15exercises.h
//  exercises
//
//  Created by Faik Hakan Bilgen on 11.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef chp15exercises_h
#define chp15exercises_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>


void exercise15_1(void);
int bin_str(const char *cp);

void exercise15_2(int argc, const char * argv[]);
char *itobs(int, char *);
void show_bstr(const char*);

void exercise15_3(void);
int counton(int i);

void exercise15_4(void);
int isbitset(int number, int pos);

void exercise15_5(void);
unsigned int rotate_l(unsigned int number, int pos);


#endif /* chp15exercises_h */
