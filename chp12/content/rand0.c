//
//  rand0.c
//  content
//
//  Created by Faik Hakan Bilgen on 16.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>

static unsigned long int next = 1;
int rand0(void);

int rand0(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

