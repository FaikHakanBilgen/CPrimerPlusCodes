//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 29.02.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#define SIZE 4
#define MARBLESIZE 10
#define MONTHS 12
#define YEARS 5
#define ROWS 3
#define COLS 4

void listing10_2(void);
void listing10_3(void);
void listing10_4(void);
void listing10_5(void);
void listing10_6(void);
void listing10_7(void);
void listing10_10(void);
int sum(int ar[], int n);
void listing10_11(void);
int sump(int *start, int *end);
void listing10_12(void);
void listing10_14(void);
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
void listing10_15(void);
void listing10_15_2(void);
void listing10_16(void);
void listing10_18(void);
int sum2d(int rows, int cols, int ar[rows][cols]);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("\n*** Chapter 10 Contents ***\n");
    listing10_2();
    listing10_3();
    listing10_4();
    listing10_5();
    printf("\n*** Listing 10.6 ***\n");
    listing10_6();
    listing10_7();
    listing10_10();
    listing10_11();
    listing10_12();
    listing10_14();
    listing10_15();
    listing10_15_2();
    listing10_16();
    listing10_18();
    return 0;
}

void listing10_2(void)
{
    printf("\n*** Listing 10.2 *** \n");
    
    int no_data[SIZE]; // uninitialized array
    int i;
    
    printf("%2s%14s\n", "i", "no_data[i]");
    
    for(i=0; i<SIZE; i++)
        printf("%2d%14d\n", i, no_data[i]);
    
    return;
}

void listing10_3(void)
{
    int some_data[SIZE] = {1492, 1066};
    int i;
    
    printf("\n*** Listing 10.3 ***\n");
    
    printf("%2s%14s\n", "i", "some_data[i]");
    
    for (i=0; i<SIZE; i++)
    {
        printf("%2d%14d\n", i, some_data[i]);
    }
    
    return;
}

void listing10_4(void)
{
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
    int index;
    
    printf("\n*** Listing 10.4 ***\n");
    
    for(index = 0; index < sizeof days / sizeof days[0]; index++)
        printf("Month %2d has %d days.\n", index+1, days[index]);
        
    return;
}

void listing10_5(void)
{
    int days[MONTHS] = {31, 28, [4]=31, 30, 31, [1] = 29};
    int i;
        
    printf("\n*** Listing 10.5 ***\n");
    
    for(i=0; i < MONTHS; i++)
        printf("%2d %d\n", i+1, days[i]);
    
    return;
}

void listing10_6(void)
{
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;
    
    printf("value1 = %d, value2 = %d\n", value1, value2);
    for( i = -1; i <= SIZE; i++ )
        arr[i] = 2 * i + 1;
    
    for( i = -1; i < 7; i++)
        printf("%2d %d\n", i, arr[i]);
    
    printf("value1 = %d, value2 = %d\n", value1, value2);
    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[0]: %p\n", &arr[0]);
    printf("address of arr[1]: %p\n", &arr[1]);
    printf("address of arr[2]: %p\n", &arr[2]);
    printf("address of arr[3]: %p\n", &arr[3]);
    printf("address of arr[4]: %p\n", &arr[4]);
    printf("address of value1: %p\n", &value1);
    printf("address of value2: %p\n", &value2);
    
    return;
}

void listing10_7(void)
{
    const float rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    int year, month;
    float subtot, total;
    
    printf("\n*** Listing 10.7 ***\n");
    
    printf(" YEAR\tRAINFALL\(inches)\n");
    
    for(year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtot=0; month<MONTHS; month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010+year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total/YEARS);
    
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
    printf(" Nov Dec\n");
    
    for(month=0; month < MONTHS; month++)
    {
        for(year=0, subtot=0; year < YEARS; year++)
            subtot += rain[year][month];
        printf("%4.1f", subtot / YEARS);
    }
    printf("\n\n");
    
    return;
}
    
void listing10_10(void)
{
    int marbles[MARBLESIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;
    
    printf("\n*** Listing 10.10 ***\n");
    
    answer = sum(marbles, MARBLESIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of the marbles is %zd bytes.\n", sizeof marbles);
        
    return;
}

int sum(int ar[], int n)
{
    int i, total = 0;
    
    for(i = 0; i < n; i++)
        total += ar[i];
    
    printf("The size of ar is %zd bytes.\n", sizeof ar);
    
    return total;
}

void listing10_11(void)
{
    int marbles[MARBLESIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;
    
    printf("\n*** Listing 10.11 ***\n");
    
    answer = sump(marbles, marbles + MARBLESIZE);
    printf("TURN - 1 : The total number of marbles is %ld.\n", answer);
    
    answer=0;
    answer = sump(marbles, marbles + MARBLESIZE);
    printf("TURN - 2 : The total number of marbles is %ld.\n", answer);
    
    return;
}

int sump(int *start, int *end)
{
    int total = 0;
    
    while (start<end)
    {
        total += *start;
        start++;
    }
    
    return total;
}

void listing10_12(void)
{
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;
    
    ptr1 = urn;             // assign an address to a pointer
    ptr2 = &urn[2];         // assign an address to a pointer
    
    
    printf("\n*** Listing 10.12 ***\n");
    
    // dereference a pointer and take the address of a pointer
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *pt1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    
    // pointer addition
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer :\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr3, *(ptr3) );
    
    ptr1++;     // increment a pointer
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    
    ptr2--;     // decrement a pointer
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    
    --ptr1;     // restore to original value
    ++ptr2;     // restore to original value
    
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    
    // subtract one pointer from another
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2-ptr1);
    
    // subtract an integer from a pointer
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
    
    return;
}


void listing10_14(void)
{
    double dip[SIZE] = {20.0, 17.66, 8.2, 15.3};
    
    printf("\n*** Listing 10.14 ***\n");
    
    printf("The original dip array:\n");
    show_array(dip, SIZE);
    mult_array(dip, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE);
    
    return;
}

void show_array(const double ar[], int n)
{
    int i;
    
    for(i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    
    for(i = 0; i < n; i++)
        ar++;
    
    for(i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    
    
    putchar('\n');
    
    return;
}

void mult_array(double ar[], int n, double mult)
{
    int i;
    
    for(i = 0; i < n; i++)
        ar[i] *= mult;
    
    return;
}

void listing10_15(void)
{
    int zippo[4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
    
    printf("\n*** Listing 10.15 ***\n");
    printf("zippo    = %p, zippo + 1    = %p\n", zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0]+1);
    printf("*zippo   = %p, *zippo+1     = %p\n", *zippo, *zippo+1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("*zippo[0]   = %d\n", *zippo[0]);
    printf("**zippo     = %d\n", **zippo);
    printf("zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2)+1) );
    
    return;
}

/*****************************************************************************************************************************************
 *** Listing 10.15.2 ***

 Array notation
 zippo[0][0] = 2; &zippo[0][0] = 0x7ffee1606aa0    zippo[0][1] = 4; &zippo[0][1] = 0x7ffee1606aa4
 zippo[1][0] = 6; &zippo[1][0] = 0x7ffee1606aa8    zippo[1][1] = 8; &zippo[1][1] = 0x7ffee1606aac
 zippo[2][0] = 1; &zippo[2][0] = 0x7ffee1606ab0    zippo[2][1] = 3; &zippo[2][1] = 0x7ffee1606ab4
 zippo[3][0] = 5; &zippo[3][0] = 0x7ffee1606ab8    zippo[3][1] = 7; &zippo[3][1] = 0x7ffee1606abc

 Pointer notation
  *(*(zippo + 0) + 0) = 2, (*(zippo + 0) + 0) = 0x7ffee1606aa0     *(*(zippo + 0) + 1) = 4, (*(zippo + 0) + 1) = 0x7ffee1606aa4
  *(*(zippo + 1) + 0) = 6, (*(zippo + 1) + 0) = 0x7ffee1606aa8     *(*(zippo + 1) + 1) = 8, (*(zippo + 1) + 1) = 0x7ffee1606aac
  *(*(zippo + 2) + 0) = 1, (*(zippo + 2) + 0) = 0x7ffee1606ab0     *(*(zippo + 2) + 1) = 3, (*(zippo + 2) + 1) = 0x7ffee1606ab4
  *(*(zippo + 3) + 0) = 5, (*(zippo + 3) + 0) = 0x7ffee1606ab8     *(*(zippo + 3) + 1) = 7, (*(zippo + 3) + 1) = 0x7ffee1606abc
 
 *****************************************************************************************************************************************/

void listing10_15_2(void)
{
    int i, j;
    int zippo[4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
    
    printf("\n*** Listing 10.15.2 ***\n");
    
    printf("\nArray notation\n");
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 2; j++)
            printf("zippo[%d][%d] = %d; &zippo[%d][%d] = %p\t", i, j, zippo[i][j], i, j, &zippo[i][j]);
        
        printf("\n");
    }
    
    printf("\nPointer notation\n");
    for(i = 0; i < 4; i++)
    {
        for( j = 0; j < 2; j++)
            printf(" *(*(zippo + %d) + %d) = %d, (*(zippo + %d) + %d) = %p\t", i, j, *(*(zippo+i)+j), i, j, (*(zippo+i)+j) );
        
        printf("\n");
    }
    
    return;
}

void listing10_16(void)
{
    int zippo[4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
    int (*pz)[2];
    
    printf("\n*** Listing 10.16 ***\n");
    
    pz = zippo;
    
    printf("pz = %p, pz + 1 = %p\n", pz, pz+1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf("*pz = %p, *pz + 1 = %p\n", *pz, *pz+1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("*pz[0] = %d\n", *pz[0]);
    printf("**pz = %d\n", **pz);
    printf("pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2)+1) = %d\n", *(*(pz+2)+1));
    
    return;
}

void listing10_18(void)
{
    int i, j;
    int rs = 3;
    int cs = 10;
    
    int junk[ROWS][COLS] =
    { {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };
    
    int morejunk[ROWS-1][COLS+2] = {
        {20, 30, 40, 50, 60, 70},
        {5, 6, 7, 8, 9, 10}
    };
    
    int varr[rs][cs];
    
    printf("\n*** Listing 10.18 ***\n");
    
    
    for(i=0; i < rs; i++)
        for(j=0; j < cs; j++)
            varr[i][j] = i * j + j;
    
    printf("3x4 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk));
    
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS-1, COLS+2, morejunk));
    
    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n", sum2d(rs, cs, varr));
    
    
    return;
}

int sum2d(int rows, int cols, int ar[rows][cols])
{
    int r, c, tot = 0;
    
    for(r=0; r<rows; r++)
        for(c=0;c<cols; c++)
            tot += ar[r][c];
    
    return tot;
}
    
