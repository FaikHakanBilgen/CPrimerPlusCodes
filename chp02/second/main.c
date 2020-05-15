//
//  main.c
//  second
//
//  Created by teos on 31.01.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int n, n2, n3;
    
    /* This program has a semantic error */
    n = 5;
    n2 = n * n;
    n3 = n  * n2;
    printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
     
    return 0;
}
