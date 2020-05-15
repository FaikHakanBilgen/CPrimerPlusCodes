//
//  testInternalLinkage.c
//  content
//
//  Created by Faik Hakan Bilgen on 13.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "chp16content.h"

void myfunc(void)
{
    //calling eatline results in compilation error. It prohibts the usage in a different file.
    // /Users/faik/work/C/CPrimerPlus/chp16/content/content/chp16content.h:57:13: Function 'eatline' has internal linkage but is not defined
    // /Users/faik/work/C/CPrimerPlus/chp16/content/content/testInternalLinkage.c:9:10: In file included from /Users/faik/work/C/CPrimerPlus/chp16/content/content/testInternalLinkage.c:9:
    //eatline();
    listing16_13();
}
