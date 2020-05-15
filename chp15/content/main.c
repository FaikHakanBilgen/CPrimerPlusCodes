//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 9.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//


#include "chp15contents.h"


const char *colors[8] = { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Contents of Chapter 15 ***\n");
    //listing15_1();
    //listing15_2();
    //listing15_3();
    //listing15_4();
    listing15_5();
    return 0;
}


void listing15_1(void)
{
    char bin_str[ CHAR_BIT * sizeof(int) + 1];
    int number;
    
    puts("\n*** Listing 15.1 ***\n");
    
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    
    while ( scanf("%d", &number) == 1 )
    {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    
    puts("Bye!");
    
    return;
}

void listing15_2(void)
{
    char bin_str[ CHAR_BIT * sizeof(int) + 1];
    int number;
    
    puts("\n*** Listing 15.2 ***\n");
    
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    
    while( scanf("%d", &number) == 1 )
    {
        itobs(number, bin_str);
        printf("%d is\n", number);
        show_bstr(bin_str);
        putchar('\n');
        
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    
    puts("Bye!");
    
    return;
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

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    
    while ( bits-- > 0 )
    {
        mask |= bitval;
        bitval <<= 1;
    }
    
    return num ^ mask;
}


void listing15_3(void)
{
    struct box_probs box = { true, YELLOW, true, GREEN, DASHED};
    
    puts("\n*** Listing 15.3 ***\n");
    printf("Original box settings:\n");
    show_settings(&box);
    
    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);
    
    return;
}

void show_settings(const struct box_probs *pb)
{
    printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent" );
    
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    
    printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
    
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    
    switch (pb->border_style) {
        case SOLID:
            printf("solid.\n");
            break;
            
        case DOTTED:
            printf("dotted.\n");
            break;
            
        case DASHED:
            printf("dashed.\n");
            break;
            
        default:
            printf("unknown type.\n");
            break;
    }
}

void listing15_4(void)
{
    union Views box = { true, YELLOW, true, GREEN, DASHED};
    char bin_str[ CHAR_BIT * sizeof(unsigned int) + 1];
    
    puts("\n*** Listing 15.4 ***\n");
    
    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    
    printf("bits are %s\n", itobs(box.us_view, bin_str));
    box.us_view &= ~FILL_MASK;  /* clear fill bits */
    box.us_view |= ( FILL_BLUE | FILL_GREEN );
    box.us_view ^= OPAQUE;
    box.us_view &= ~STYLE_MASK;
    box.us_view |= B_DOTTED;
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n", itobs(box.us_view, bin_str));
    
    return;
}

void show_settings1(unsigned short us)
{
    printf("Box is %s.\n", ( us & OPAQUE ) == OPAQUE ? "opaque": "transparent" );
    
    printf("The fill color is %s.\n", colors[ (us >> 1) & 0x7 ]);
    
    printf("Border %s.\n", ( us & BORDER ) == BORDER ? "shown" : "not shown");
    printf("The border style is ");
    switch (us & STYLE_MASK)
    {
        case B_SOLID:
            printf("solid.\n");
            break;
        
        case B_DOTTED:
            printf("dotted.\n");
            break;
        
        case B_DASHED:
            printf("dashed.\n");
            break;
        
        default:
            printf("unknown type.\n");
            break;
    }
    printf("The border color is %s.\n", colors[( us >> 9 ) & 0x7] );
}

void listing15_5(void)
{
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char _Alignas(double) cz;
       
    puts("\n*** Listing 15.5 ***\n");
    
    printf("char    alignment: %zd\n", _Alignof(char));
    printf("double  alignment: %zd\n", _Alignof(double));
    printf("&dx: %p\n", &dx);
    printf("&ca: %p\n", &ca);
    printf("&cx: %p\n", &cx);
    printf("&dz: %p\n", &dz);
    printf("&cb: %p\n", &cb);
    printf("&cz: %p\n", &cz);
    
    return;
}
