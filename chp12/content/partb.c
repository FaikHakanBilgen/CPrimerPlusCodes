//
//  partb.c
//  content
//
//  Created by Faik Hakan Bilgen on 15.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>

extern int count;

static int total = 0;

void accumulate(int k);

void accumulate(int k)
{
    static int subtotal = 0;
    
    if ( k <= 0)
    {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}
