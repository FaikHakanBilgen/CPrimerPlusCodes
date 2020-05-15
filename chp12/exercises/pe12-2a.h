//
//  pe12-2a.h
//  exercises
//
//  Created by Faik Hakan Bilgen on 18.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef pe12_2a_h
#define pe12_2a_h

#include <stdio.h>
void set_mode(int mode);
void get_info(void);
void show_info(void);

int GetMode(void);
void ShowInfo(int mode, float distance, float fuel);
void GetInfo(int mode, float *distance, float *fuel);
#endif /* pe12_2a_h */
