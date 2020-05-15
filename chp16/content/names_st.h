//
//  names_st.h
//  content
//
//  Created by Faik Hakan Bilgen on 13.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef names_st_h
#define names_st_h

#include <stdio.h>
#include <string.h>

#define SLEN 32

struct names_st
{
    char    first[SLEN];
    char    last[SLEN];
};

typedef struct names_st names;

void get_names(names*);
void show_names(const names*);
char * s_gets(char *st, int n);

void listing16_8(void);

#endif /* names_st_h */
