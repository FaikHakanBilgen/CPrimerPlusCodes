//
//  hotel.h
//  content
//
//  Created by teos on 23.02.2020.
//  Copyright © 2020 teos. All rights reserved.
//

#ifndef hotel_h
#define hotel_h

#include <stdio.h>

#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "**********************************"

// Shows list of choices
int menu(void);

// returns number of nights desired
int getnights(void);

// calculates price from rate, nights
// and display result
void showprice(double rate, int nights);

#endif /* hotel_h */
