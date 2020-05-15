//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 11.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "chp16exercises.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Exercises of Chapter 16 ***\n");
    //exercise16_2();
    exercise16_4();
    return 0;
}


void exercise16_2(void)
{
    double d1, d2;
    
    puts("\n*** Exercise 16.4 ***\n");
    
    puts("Enter two numbers");
    
    while (  scanf("%lf%lf", &d1, &d2) == 2 )
    {
        printf("The harmonic mean of %.4lf and %.4lf is %.4lf\n", d1, d2, HARMEAN(d1, d2));
        puts("Enter two numbers");
    }
    
    puts("Bye!");
    
    return;
}

void exercise16_4(void)
{
    double d;
    
    puts("\n*** Exercise 16.4 ***\n");
    
    puts("Please enter a duration in seconds");
    
    while ( scanf("%lf", &d) == 1 )
    {
        printf("Waiting for %.2lf seconds\n", d);
        delaytime(d);
        puts("Please enter a duration in seconds");
    }
    
    return;
}

void delaytime(double dur)
{
    double d1, delta;
     
    
    d1 = (double)clock();
    delta = 0.0;
    
    while ( delta <= dur)
    {
        delta = ( (double)clock() - d1) / CLOCKS_PER_SEC;
        //printf("%lf\n", delta);
    }
}
