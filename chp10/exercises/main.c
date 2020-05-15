//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 29.02.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <float.h>

#define MONTHS 12
#define YEARS 5

void exercise10_1(void);
void exercise10_2(void);
void copy_arr(double dest[], const double src[], int len );
void copy_ptr(double *dest, const double *src, int len );
void copy_ptrs(double *dest, const double *src, double *srcEnd);
void exercise10_3(void);
int largest(int ar[], int len);
void exercise10_4(void);
int largestD(double dar[], int len);
void exercise10_5(void);
double minmaxDiff(double dar[], int len);
void exercise10_6(void);
void reverseDAr(double dar[], int len);
void exercise10_7(void);
void exercise10_8(void);
void exercise10_9(void);
void copy_arr_vla(int rows, int cols, double source[rows][cols], double dest[rows][cols]);
void display_vla_arrays(int rows, int cols, double source[rows][cols], double dest[rows][cols]);
void exercise10_10(void);
void array_sum(int arr1[], int arr2[], int arr3[], int len);
void exercise10_11(void);
void display_arr(int arr[][5], int rows);
void double_arr(int arr[][5], int rows);
void exercise10_12(void);
void sum_peryear(const float rain[][MONTHS], int years);
void avg_monthly(const float rain[][MONTHS], int years);
void exercise10_13(void);
void store_arr(double arr[][5], int len);
double avg_row(double arr[], int len);
double avg_all(double arr[][5], int rows);
double max_all(double arr[][5], int rows);
void reportAll(double arr[][5], int rows, double avg, double max);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("\n*** Chapter 10 Exercises ***\n");
    exercise10_1();
    exercise10_2();
    exercise10_3();
    exercise10_4();
    exercise10_5();
    exercise10_6();
    exercise10_7();
    exercise10_8();
    exercise10_9();
    exercise10_10();
    exercise10_11();
    exercise10_12();
    exercise10_13();
    return 0;
}


/*
  YEAR    RAINFALL(inches)
  2010            32.4
  2011            37.9
  2012            49.8
  2013            44.0
  2014            32.9

 The yearly average is 39.4 inches.

 MONTHLY AVERAGES:

  Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
  7.3 7.3 4.9 3.0 2.3 0.6 1.2 0.3 0.5 1.7 3.6 6.7
 */
void exercise10_1(void)
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
    
    printf("\n*** Exercise 10.1 ***\n");
    
    printf(" YEAR\tRAINFALL\(inches)\n");
    
    for(year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtot=0; month<MONTHS; month++)
//            subtot += rain[year][month];
            subtot += *(*(rain+year)+month);
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
//            subtot += rain[year][month];
            subtot += *(*(rain+year)+month);
        printf("%4.1f", subtot / YEARS);
    }
    printf("\n\n");
    
    
    
    return;
}

void exercise10_2(void)
{
    int i;
    double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    
    printf("\n*** Exercise 10.2 ***\n");
    
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source+5);
    
    for(i = 0; i < 5; i++)
        printf("target1[%d]=%.1f, target2[%d]=%.1f, target3[%d]=%.1f\n", i, target1[i], i, target2[i], i, target3[i]);
    
    return;
}

void copy_arr(double dest[], const double src[], int len )
{
    int i;
    
    for(i = 0; i < len; i++)
        dest[i] = src[i];
}

void copy_ptr(double *dest, const double *src, int len )
{
    while( len-- > 0)
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    return;
}

void copy_ptrs(double *dest, const double *src, double *srcEnd)
{
    while ( src != srcEnd )
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    return;
}

void exercise10_3(void)
{
    int ar1[] = {1,10,2,3,30, 100, -1};
    int ar2[] = {100, 90, 80, 70, 60};
    int ar3[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
    
    
    printf("\n*** Exercise 10.3 ***\n");
    printf("Largest of ar1 is %d\n", largest(ar1, 7));
    printf("Largest of ar2 is %d\n", largest(ar2, 5));
    printf("Largest of ar3 is %d\n", largest(ar3, 10));
}

int largest(int ar[], int len)
{
    int i, max = 0;
    
    for(i = 0; i < len; i++)
        max = ar[i] > max ? ar[i] : max;
        
    return max;
}

void exercise10_4(void)
{
    double dar1[] = {1.2, 10.90, 2.0, 3.89, 30.6, 100.01, -1.8};
    double dar2[] = {100.10, 90.20, 80.30, 70.40, 60.50};
    double dar3[] = {1.9, 2.8, 3.7, 4.6, 5.5, 6.4, 7.3, 8.2, 8.2, 10.1};
    
    printf("\n*** Exercise 10.4 ***\n");
    
    printf("Largest of dar1 is %d\n", largestD(dar1, 7));
    printf("Largest of dar2 is %d\n", largestD(dar2, 5));
    printf("Largest of dar3 is %d\n", largestD(dar3, 10));
    
    return;
}

int largestD(double dar[], int len)
{
    int i, j=0;
    double max = 0.0;
    
    for(i = 0; i < len; i++)
        if ( dar[i] > max )
        {
            j = i;
            max = dar[i];
        }
        
    return j;
}

void exercise10_5(void)
{
    double dar1[] = {1.2, 10.90, 2.0, 3.89, 30.6, 100.01, -1.8};
    double dar2[] = {100.10, 90.20, 80.30, 70.40, 60.50};
    double dar3[] = {1.9, 2.8, 3.7, 4.6, 5.5, 6.4, 7.3, 8.2, 8.2, 10.1};
    
    printf("\n*** Exercise 10.5 ***\n");
    
    printf("max - min of dar1 is %lf\n", minmaxDiff(dar1, 7));
    printf("max - min of dar2 is %lf\n", minmaxDiff(dar2, 5));
    printf("max - min of dar3 is %lf\n", minmaxDiff(dar3, 10));
        
    return;
}

double minmaxDiff(double dar[], int len)
{
    int i;
    double min = DBL_MAX, max = DBL_MIN;
        
    for( i = 0; i < len; i++ )
    {
        if ( dar[i] > max )
            max = dar[i];
                
        if ( dar[i] < min )
            min = dar[i];
    }
    
    return max - min;
}

void exercise10_6(void)
{
    int i;
    double dar1[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double dar2[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    
    printf("\n*** Exercise 10.6 ***\n");
    reverseDAr(dar1, 5);
    reverseDAr(dar2, 6);
    
    for( i = 0; i < 5; i++ )
        printf("%lf, ", dar1[i]);
    
    printf("\n");
    
    for( i = 0; i < 6; i++ )
        printf("%lf, ", dar2[i]);
    
    printf("\n");
    return;
}

void reverseDAr(double dar[], int len)
{
    int i;
    double tmp;
    
    for(i=0; i < (len/2) ; i++)
    {
        tmp = dar[i];
        dar[i] = dar[len-1-i];
        dar[len-1-i] = tmp;
    }
}

void exercise10_7(void)
{
    int i, j;
    double src[][5] = { {1.0, 2.0, 3.0, 4.0, 5.0}, {6.0, 7.0, 8.0, 9.0, 10.0}};
    double dst[2][5];
    
    printf("\n*** Exercise 10.7 ***\n");
    
    for( i = 0; i < 2; i++)
        copy_arr(dst[i], src[i], 5);
    
    for(i=0; i<2; i++)
    {
        for(j=0; j<5; j++)
            printf("dst[%d][%d]=%lf ", i, j, dst[i][j]);
        printf("\n");
    }
    return;
}

void exercise10_8(void)
{
    int i;
    double source[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target1[3];
    
    printf("\n*** Exercise 10.8 ***\n");
    
    copy_ptr(target1, &source[2], 3);
    
    for(i=0; i<3; i++)
        printf("target1[%d]=%lf ", i, target1[i] );
    
    printf("\n");
    return;
}

void exercise10_9(void)
{
    double source[3][5] = { {1.1, 2.1, 3.1, 4.1, 5.1}, {1.2, 2.2, 3.2, 4.2, 5.2}, {1.3, 2.3, 3.3, 4.3, 5.3} };
    double dest[3][5];
    
    printf("\n*** Exercise 10.9 ***\n");
    
    copy_arr_vla(3, 5, source, dest);
    display_vla_arrays(3, 5, source, dest);
    
    return;
}

void copy_arr_vla(int rows, int cols, double source[rows][cols], double dest[rows][cols])
{
    int i, j;
    
    for(i=0; i< rows; i++)
        for(j=0; j< cols; j++)
            dest[i][j] = source[i][j];
}

void display_vla_arrays(int rows, int cols, double source[rows][cols], double dest[rows][cols])
{
    int i, j;
    
    for(i=0; i< rows; i++)
    {
        for(j=0; j< cols; j++)
            printf("source[%d][%d]=%lf, dest[%d][%d]=%lf ", i, j, source[i][j], i, j, dest[i][j]);
        printf("\n");
    }
    
}

void exercise10_10(void)
{
    int arr[4], i;
    printf("\n*** Exercise 10.10 ***\n");
    
    array_sum( (int[4]){2, 4, 5, 8} , (int[4]){1, 0, 4, 6}, arr, 4);
    
    for(i=0; i<4; i++)
        printf("arr[%d]=%d ", i, arr[i]);
    
    printf("\n");
    return;
}

void array_sum(int arr1[], int arr2[], int arr3[], int len)
{
    int i;
    
    for(i=0; i < len; i++)
        arr3[i] = arr1[i] + arr2[i];
    
    return;
}

void exercise10_11(void)
{
    int arr[][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
    
    printf("\n*** Exercise 10.11 ***\n");
    
    display_arr(arr, 3);
    double_arr(arr, 3);
    display_arr(arr, 3);
    
    return;
}

void display_arr(int arr[][5], int rows)
{
    int i, j;
    for ( i=0; i< rows; i++ )
    {
        for( j = 0; j< 5; j++)
            printf("arr[%d][%d]=%d ", i, j, arr[i][j]);
        
        printf("\n");
    }
    printf("\n");
    return;
}

void double_arr(int arr[][5], int rows)
{
    int i, j;
    for ( i=0; i< rows; i++ )
        for( j = 0; j< 5; j++)
            arr[i][j] = arr[i][j] * 2;
    
    return;
}

void exercise10_12(void)
{
    const float rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    printf("\n*** Exercise 10.12 ***\n");
    
    sum_peryear(rain, YEARS);

    avg_monthly(rain, YEARS);

    printf("\n\n");
    
    return;
}

void sum_peryear(const float rain[][MONTHS], int years)
{
    int month, year;
    float subtot, total = 0.0;
    
    printf(" YEAR\tRAINFALL\(inches)\n");
    
    for(year = 0, total = 0; year < years; year++)
    {
        for (month = 0, subtot=0; month<MONTHS; month++)
            subtot += *(*(rain+year)+month);
        printf("%5d %15.1f\n", 2010+year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total/years);
    
}

void avg_monthly(const float rain[][MONTHS], int years)
{
    int month, year;
    float subtot, total = 0.0;

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
    printf(" Nov Dec\n");
    
    for(month=0; month < MONTHS; month++)
    {
        for(year=0, subtot=0; year < years; year++)
            subtot += *(*(rain+year)+month);
        printf("%4.1f", subtot / years);
    }

}



void exercise10_13(void)
{
    double arr[3][5];
    
    printf("\n*** Exercise 10.13 ***\n");
    
    store_arr(arr, 3);
        
    reportAll(arr, 3, avg_all(arr, 3),  max_all(arr, 3));
        
}

void store_arr(double arr[][5], int len)
{
    int i;
    
    for (i = 0; i< len; i++)
        scanf("%lf %lf %lf %lf %lf", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4] );
    
}


double avg_row(double arr[], int len)
{
    int i;
    double total = 0.0;
    
    for(i = 0; i < len; i++)
        total += arr[i];
    
    return total / len;
}

double avg_all(double arr[][5], int rows)
{
    int i, j;
    double total = 0.0;
    
    for(i = 0; i < rows; i++)
        for(j = 0; j < 5; j++)
            total += arr[i][j];
    
    return total / (rows * 5.0);
}

double max_all(double arr[][5], int rows)
{
    int i, j;
    double max = 0.0;
    
    for(i=0;i<rows;i++)
        for(j=0;j<5;j++)
            max = arr[i][j] > max ? arr[i][j] : max;
    
    return max;
}

void reportAll(double arr[][5], int rows, double avg, double max)
{
    int i;
    
    for (i = 0; i< 3; i++)
    {
        printf("Average of arr[%d][0] %lf, arr[%d][1] %lf, arr[%d][2] %lf, arr[%d][3] %lf and arr[%d][4] %lf is %lf",
               i, arr[i][0], i, arr[i][1], i, arr[i][2],  i, arr[i][3], i, arr[i][4], avg_row(arr[i], 5) );
        
        printf("\n");
    }
    
    printf("The average of the array elements is %lf\n", avg );
    printf("The maximum of the array elements is %lf\n", max );
}
