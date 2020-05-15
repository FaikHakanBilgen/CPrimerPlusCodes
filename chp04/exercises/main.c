//
//  main.c
//  exercises
//
//  Created by teos on 9.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include <float.h>


void exercise4_1(void);
void exercise4_2(void);
void exercise4_3(void);
void exercise4_4(void);
void exercise4_5(void);
void exercise4_6(void);
void exercise4_7(void);
void exercise4_8(void);

int main(int argc, const char * argv[]) {
    // insert code here...
//    exercise4_1();
//    exercise4_2();
    // exercise4_3();
    
    //exercise4_4();
    //exercise4_5();
    //exercise4_6();
    //exercise4_7();
    exercise4_8();
    
    return 0;
}

void exercise4_1(void)
{
    char firstName[20], lastName[20];
    
    printf("\nExercise 4.1\n");
    
    printf("Please enter your first name and last name: ");
    scanf("%s%s", firstName, lastName);
    printf("%s, %s\n", lastName, firstName);
    
    return;
}

void exercise4_2(void)
{
    char firstName[20];
    
    printf("\nExercise 4.2\n");
    
    printf("Please enter your name: ");
    scanf("%s", firstName);
    
    printf("\"%s\"\n", firstName);
    printf("\"%20s\"\n", firstName);
    printf("\"%-20s\"\n", firstName);
    printf("\"%*s\"\n", strlen(firstName)+3, firstName);
    
    return;
}

void exercise4_3(void)
{
    float f;
    
    printf("\nExercise 4.3\n");
    
    printf("Please enter a floating-point number: ");
    scanf("%f", &f);
    printf("The input is %.1f, %.1e\n", f, f);
    printf("The input is %.3f, %.3e\n", f, f);
    
    return;
}

void exercise4_4(void)
{
    const float inch2feet = 0.08333F;
    printf("\nExercise 4.4\n");
    
    float height;
    char name[20];
    
    printf("Please enter your name and height in inches: ");
    scanf("%s%f", name, &height);
    
    printf("%s, you are %.3f feet tall\n", name, height*inch2feet);
    return;
}

void exercise4_5(void)
{
    float downloadSpeed, downloadSize, downloadTime;
    
    printf("\nExercise 4.5\n");
    
    printf("What is the download speed (Mbs) and the size of the file to be downloaded (MB) ?");
    scanf("%f%f", &downloadSpeed, &downloadSize);
    
    downloadTime = downloadSize * 8 / downloadSpeed;
    
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.\n", downloadSpeed, downloadSize, downloadTime);
    return;
}

void exercise4_6(void)
{
    char firstName[20], secondName[20];
    
    printf("\nExercise 4.6\n");
    printf("Please enter your name and surname: ");
    scanf("%s%s", firstName, secondName);
    
    printf("%s %s\n", firstName, secondName);
    printf("%-*d %-*d\n", strlen(firstName), strlen(firstName), strlen(secondName), strlen(secondName));
    
    return;
}

void exercise4_7(void)
{
    printf("\nExercise 4.7\n");
    
    double d = 1.0/3.0;
    float f = 1.0F/3.0F;
    
    printf("The double value is %.4f and %.12f and %.16f\n", d, d, d);
    printf("The float value is %.4f and %.12f and %.16f\n", f, f, f);
    
    printf("FLT_DIG is %d and DBL_DIG is %d\n", FLT_DIG, DBL_DIG);
    
    return;
}

void exercise4_8(void)
{
    float miles, gallons, milesPerGallon, literPerKm;
    const float gallons2Liter = 3.785F;
    const float miles2km = 1.609F;
    const float conversionConstant = miles2km / gallons2Liter;
    
    printf("\nExercise 4.8\n");
    
    printf("How many miles did you travel and how many gallons of gasoline did you consume? ");
    scanf("%f%f", &miles, &gallons);
    
    milesPerGallon = miles / gallons;
    literPerKm = 100.0F / ( milesPerGallon * conversionConstant );
    printf("miles-per-gallon was %.1f\nliters-per-100-km was %.1f\n", milesPerGallon, literPerKm);
        
    return;
}
