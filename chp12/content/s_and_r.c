//
//  s_and_r.c
//  content
//
//  Created by Faik Hakan Bilgen on 16.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>

static unsigned long int next = 1;

int rand1(void)
{
    next = next * 1103515245 * 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void srand1(unsigned int seed)
{
    next = seed;
}
