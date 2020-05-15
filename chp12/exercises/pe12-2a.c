//
//  pe12-2a.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 18.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "pe12-2a.h"

/* 0: metric 1: US*/
int internalmode;
float distance, fuel, consumption;

void set_mode(int mode)
{
    if ( mode < -1 || mode > 1 )
    {
        puts("Invalid specified. Mode 1(US) is used.");
        internalmode = mode = 1;
    }
    else
        internalmode = mode;
}

int GetMode(void)
{
    int mode;
    
    printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
    scanf("%d", &mode);
    
    if ( mode < -1 || mode > 1 )
    {
        puts("Invalid specified. Mode 1(US) is used.");
        mode = 1;
    }
 
    return mode;
}


void get_info(void)
{
    printf("Enter distance traveled in %s: ", ( internalmode ? "miles" : "kilometers" ));
    scanf("%f", &distance);
    printf("Enter fuel consumed in %s: ", (internalmode ? "gallons" : "liters"));
    scanf("%f", &fuel);
    return;
}

void show_info(void)
{
    if ( !internalmode )
        printf("Fuel consumption is %4.2f liters per 100 km.\n", ( fuel / distance ) * 100.0F );
    else
        printf("Fuel consumption is %4.1f miles per gallon.\n",  (distance / fuel) );
    
    return;
}

void GetInfo(int mode, float *distance, float *fuel)
{
    printf("Enter distance traveled in %s: ", ( mode ? "miles" : "kilometers" ));
    scanf("%f", distance);
    printf("Enter fuel consumed in %s: ", ( mode ? "gallons" : "liters"));
    scanf("%f", fuel);
    return;
}

void ShowInfo(int mode, float distance, float fuel)
{
    if ( !mode )
        printf("Fuel consumption is %4.2f liters per 100 km.\n", ( fuel / distance ) * 100.0F );
    else
        printf("Fuel consumption is %4.1f miles per gallon.\n",  (distance / fuel) );
    
    return;
}

