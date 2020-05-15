//
//  main.c
//  exercises
//
//  Created by teos on 31.01.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>

void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);
void jolly(void);
void deny(void);
void ex5(void);
void br(void);
void ic(void);
void ex6(void);
void smile(void);
void ex7(void);
void ex8(void);
void one_three(void);
void two(void);

int main(int argc, const char * argv[])
{
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    ex7();
    ex8();
    return 0;
}

void ex1(void)
{
    printf("Gustav Mahler\n");
    printf("Gustav\nMahler\n");
    printf("Gustav ");
    printf("Mahler\n");
    
    return;
}

void ex2(void)
{
    printf("Faik Hakan Bilgen\n");
    printf("Caferaga Mah. Nezihe Gürbüz Sok.\n");
    printf("No:5 D:7 K:2 Eda Apt.\n");
    printf("Kadıköy/İstanbul\n");
    
    return;
}

// The following function does not consider the 366 days every 4 years
void ex3(void)
{
    int ageYears, ageDays;
    ageYears = 47;
    
    ageDays = ageYears * 365;
    
    printf("I'm %d years old. This is approximately %d days.\n", ageYears, ageDays);
    
    return;
}

void ex4(void)
{
    jolly();
    deny();
}

void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
    return;
}

void deny(void)
{
    printf("Which nobody can deny!\n");
    return;
}

void ex5(void)
{
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf(",\n");
    br();
    printf("\n");
}

void br(void)
{
    printf("Brazil, Russia");
}

void ic(void)
{
    printf("India, China");
}

void ex6(void)
{
    int toes;
    toes=10;
    printf("toes = %d, twice the toes = %d, toes squared = %d\n", toes, toes*2, toes*toes);
}

void smile(void)
{
    printf("Smile!");
}

void ex7(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
}

void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}

void two(void)
{
    printf("two\n");
}

void ex8(void)
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");
}
