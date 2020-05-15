//
//  main.c
//  content
//
//  Created by teos on 12.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>

#define SQUARES 65
#define FORMAT "%s! C is cool!\n"

const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;

void listing5_3(void);
void listing5_4(void);
void listing5_5(void);
void listing5_14(void);
void listing5_16(void);
void review5_6(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("This is content\n");
    
//    listing5_3();
//    listing5_4();
//    listing5_5();
//    listing5_14();
//    listing5_16();
    
    review5_6();
    return 0;
}

void listing5_3(void)
{
    int jane, tarzan, cheeta;
    cheeta = tarzan = jane = 68;
    
    printf("\n*** Listing 5.3 ***\n");
    printf("                  cheeta    tarzan    jane\n");
    printf("First round score %4d  %8d %8d\n", cheeta, tarzan, jane);
        
    return;
}

void listing5_4(void)
{
    int num = 1;
    
    printf("\n*** Listing 5.4 ***\n");
    
    while (num < 21)
    {
        printf("%4d %6d\n", num, num*num);
        num = num + 1;
    }
    
    return;
}

void listing5_5(void)
{
    const double CROP = 2E16;
    double current, total;
    int count = 1;
    
    printf("\n*** Listing 5.4 ***\n");
    
    printf("Square\tGrains\tTotal\t");
    printf("fraction of \n");
    printf("      \tadded \tgrains\t");
    printf("world total\n");
    
    total = 0;
    current = 1;
    
    while(count<SQUARES)
    {
        total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
        current = current * 2;
        count = count+1;
    }
    
    printf("That's all!\n");
    
    return;
}

void listing5_14(void)
{
    char ch;
    int i;
    float fl;
    
    printf("\n*** Listing 5.14 ***\n");
    
    fl = i = ch = 'C';
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = ch + 1;
    i = fl + 2 * ch;
    fl = 2.0 * ch + i;
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
    ch = 1107;
    printf("Now ch = %c\n", ch);
    ch = 80.89;
    printf("Now ch = %c\n", ch);
    
    return;
}

void listing5_16(void)
{
    double distk, distm;
    double rate;
    int min, sec;
    int time;
    double mtime;
    int mmin, msec;
    
    printf("\n*** Listing 5.16 ***\n");
    
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%lf", &distk);
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);
    // converts time to pure seconds
    time = min * S_PER_M + sec;
    // converts kilometers to miles
    distm = M_PER_K * distk;
    // miles per sec x sec per hour = mph
    rate = distm / time * S_PER_H;
    // time / distance = time per mile
    mtime = (double) time / distm;
    mmin = (int) mtime / S_PER_M;
    msec = (int) mtime % S_PER_M;
    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
    
    return;
}

void review5_6(void)
{
    printf("\n*** Review 5.14 ***\n");
    //printf(FORMAT, FORMAT);
    printf("%s\n", "faik\nfaik");
    return;
}
