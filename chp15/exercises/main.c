//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 9.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "chp15exercises.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Exercises of Chapter 15 ***\n");
    //exercise15_1();
    //exercise15_2(argc, argv);
    //exercise15_3();
    //exercise15_4();
    exercise15_5();
    return 0;
}


void exercise15_1(void)
{
    puts("\n*** Exercise 15.1 ***\n");
    char binstr[10];
    
    puts("Enter a binary number");
    while ( scanf("%s", binstr) == 1 &&  !isalpha(binstr[0]) )
    {
        while( getchar()!='\n')
            continue;;
        
        printf("%s equals to %d\n", binstr, bin_str(binstr));
        puts("Enter a binary number");
    }
    
    return;
}

int bin_str(const char *cp)
{
    int val = 0;
    
    while ( *cp != '\0' )
    {
        val = (val << 1) + ( *cp - '0'  );
        cp++;
    }
    
    return val;
}

void exercise15_2(int argc, const char * argv[])
{
    char binstr1[65], binstr2[65], binstr3[65];
    int i1, i2, i3;
    
    strcpy(binstr1, argv[1]);
    strcpy(binstr2, argv[2]);
    
    i1 = bin_str(binstr1);
    i2 = bin_str(binstr2);
    
    printf("~%s is ", binstr1);
    show_bstr( itobs( ~i1, binstr1 ) );
    
    putchar('\n');
    printf("~%s is ", binstr2);
    show_bstr( itobs( ~i2, binstr2 ) );
    putchar('\n');
    
    strcpy(binstr1, argv[1]);
    strcpy(binstr2, argv[2]);
        
    i3 = i1 & i2;
    itobs( i3, binstr3);
    
    show_bstr(binstr1); printf(" & "); show_bstr(binstr2); printf(" = "); show_bstr(binstr3); putchar('\n');
    
    i3 = i1 | i2;
    itobs( i3, binstr3);
    
    show_bstr(binstr1); printf(" | "); show_bstr(binstr2); printf(" = "); show_bstr(binstr3); putchar('\n');
    
    i3 = i1 ^ i2;
    itobs( i3, binstr3);
    
    show_bstr(binstr1); printf(" ^ "); show_bstr(binstr2); printf(" = "); show_bstr(binstr3); putchar('\n');
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    
    for ( i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    
    ps[size]= '\0';
    
    return ps;
}

void show_bstr(const char* str)
{
    int i = 0;
    
    while ( str[i] )
    {
        putchar(str[i]);
        
        if ( ++i % 4 == 0 && str[i] )
            putchar(' ');
    }
}


void exercise15_3(void)
{
    int number;
    
    puts("\n*** Exercise 15.3 ***\n");
    
    puts("Enter an integer");
    while( scanf("%d", &number) == 1 )
    {
        printf("There are %d on bits in %d\n", counton(number), number);
        puts("Enter an integer");
    }
    
    return;
}


int counton(int i)
{
    int count = 0;
    
    while ( i > 0 )
    {
        if ( (i & 1) == 1 )
            count++;
        
        i >>= 1;
    }
    
    return count;
}

void exercise15_4(void)
{
    int number, pos;
    
    puts("\n*** Exercise 15.4 ***\n");
    
    puts("Enter an integer and a bit position");
    while( scanf("%d %d", &number, &pos) == 2 )
    {
        printf("%d's bit at position %d is %s\n", number, pos, isbitset(number, pos) == 1 ? "set" : "not set" );
        puts("Enter an integer and a bit position");
    }
    
    return;
}

int isbitset(int number, int pos)
{
    int mask = 1;
    
    mask <<= --pos;
    
    if ( ( number & mask ) == mask )
        return 1;
    else
        return 0;
}

void exercise15_5(void)
{
    unsigned int number, pos;
    
    puts("\n*** Exercise 15.4 ***\n");
    
    puts("Enter an integer and number of bits to rotate left");
    while( scanf("%u %d", &number, &pos) == 2 )
    {
        printf("%u rotated to left %d bits equals to %u\n", number, pos, rotate_l(number, pos));
        puts("Enter an integer and number of bits to rotate left");
    }
    
    return;

}

unsigned int rotate_l(unsigned int number, int pos)
{
    int i;
    unsigned int mask =  1 << ( (CHAR_BIT * sizeof(int)) - 1 );
    
    for ( i = 0; i < pos; i++ )
        if ( (number & mask) == mask )
            number = ( (number << 1) + 1 ) ;
        else
            number <<= 1;
        
    return number;
}
