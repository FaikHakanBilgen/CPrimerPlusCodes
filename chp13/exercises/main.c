//
//  main.c
//  exercises
//
//  Created by Faik Hakan Bilgen on 19.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 41
#define SLEN 80
#define KB 1024
#define LINESIZE 100
#define BUFSIZE 4096
#define MAXLINESIZE 256

char* s_gets(char *st, int n);
void exercise13_1(void);
void exercise13_2(int argc, const char * argv[]);
void exercise13_3(void);
void exercise13_4(int argc, const char * argv[]);
void DisplayFile(const char* filename);
void exercise13_5(int argc, const char * argv[]);
void append(FILE *source, FILE *dest);
void exercise13_6(void);
void exercise13_7(int argc, const char * argv[]);
void exercise13_8(int argc, const char * argv[]);
int countChar(const char* filename, char ch);
void exercise13_9(void);
void exercise13_10(void);
void exercise13_11(int argc, const char * argv[]);
void exercise13_12(void);
void exercise13_13(int rows, int cols);
void exercise13_14(void);
void correctglitch(int arr[][30], int rows);

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Exercises for Chapter 13 ***");
    //exercise13_1();
    //exercise13_2(argc, argv);
    //exercise13_3();
    //exercise13_4(argc, argv);
    //exercise13_5(argc, argv);
    //exercise13_6();
    //exercise13_7(argc, argv);
    //exercise13_8(argc, argv);
    //exercise13_9();
    //exercise13_10();
    //exercise13_11(argc, argv);
    //exercise13_12();
    //exercise13_13(20, 30);
    exercise13_14();
    return 0;
}

void exercise13_1(void)
{
    int ch;
    char file_src[SLEN];
    FILE *fp;
    unsigned long count = 0;

    puts("\n*** Exercise 13.1 ***");
    
    puts("Enter name of first source file (empty line to quit):");
    
    s_gets(file_src, SLEN);
    
    if ( file_src[0] == '\0' )
    {
        puts("You didn't enter a source file name. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
        
    if ( ( fp = fopen( file_src, "r")) == NULL )
    {
        printf("Can't open %s\n", file_src);
        exit(EXIT_FAILURE);
    }
    
    while ( (ch = getc(fp)) != EOF  )
    {
        putc(ch, stdout);
        count++;
    }
    
    if ( fclose(fp) != 0)
        printf("Error in closing file %s\n", file_src);
    
    printf("File %s has %lu characters\n", file_src, count);
    
    return;
}


char* s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    
    ret_val = fgets(st, n, stdin);
    
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
            {
                continue;
            }
    }
    
    return ret_val;
}


void exercise13_2(int argc, const char * argv[])
{
    FILE *fsrc, *fdest;
    unsigned long rdbytes;
    char buffer[KB];
    
    if ( argc < 3 )
    {
        printf("Usage: %s source_filename destination_filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ( ( fsrc = fopen(argv[1], "rb")) == NULL )
    {
        fprintf(stderr, "Could not open %s for input.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    if ( ( fdest = fopen(argv[2], "wb")) == NULL )
    {
        fprintf(stderr, "Could not open %s for output.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    while ( ( rdbytes = fread(buffer, sizeof(char), KB, fsrc)) != 0 )
    {
        fwrite(buffer, sizeof(char), rdbytes, fdest);
    }
    
    fclose(fsrc);
    fclose(fdest);
    printf("%s copied into %s\n", argv[1], argv[2]);
}

void exercise13_3(void)
{
    int ch;
    char file_src[SLEN], file_dest[SLEN];
    FILE *fsrc, *fdest;
    
    puts("\n*** Exercises 13.3 ***");
    
    puts("Enter the name of the source file name: ");
    
    s_gets(file_src, SLEN);
    
    if ( file_src[0] == '\0' )
    {
        fprintf(stderr, "You didn't enter a source file name. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter the name of the destination file name: ");
    
    s_gets(file_dest, SLEN);
    
    if ( file_dest[0] == '\0' )
    {
        fprintf(stderr, "You didn't enter a destination file name. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
    
    if ( (fsrc = fopen(file_src, "r")) == NULL)
    {
        fprintf(stderr, "%s could not be opened for reading\n", file_src);
        exit(EXIT_FAILURE);
    }
    
    if ( ( fdest = fopen(file_dest, "w") ) == NULL )
    {
        fprintf(stderr, "%s could not be opened for writing\n", file_dest);
        exit(EXIT_FAILURE);
    }
    
    while ( ( ch = getc(fsrc)) != EOF )
    {
        if ( isalpha(ch) )
            ch = toupper(ch);
        
        putc(ch, fdest);
    }
    
    if ( fclose(fsrc) != 0 || fclose(fdest) != 0 )
    {
        fprintf(stderr, "Problem happened while closing files.\n");
    }
    
    return;
}

void exercise13_4(int argc, const char * argv[])
{
    int i;
    
    puts("\n*** Exercise 13.4 ***");
    
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s file1 file2 ...", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    for( i = 1; i < argc; i++)
        DisplayFile(argv[i]);
    
    
    return;
}

void DisplayFile(const char* filename)
{
    int i;
    FILE *fp;
    unsigned long readcount;
    char buffer[KB];
    
    if ( (fp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Error happened opening %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    printf("\nContent of %s\n", filename);
    printf("=====================\n");
    
    while ( (readcount = fread(buffer, sizeof(char), KB, fp)) != 0)
    {
        for(i = 0; i < readcount; i++)
            printf("%c", buffer[i]);
    }
    
    if ( fclose(fp) != 0)
        fprintf(stderr, "Error while closing file %s\n", filename);
    
    return;
}

void exercise13_5(int argc, const char * argv[])
{
    FILE *fa, *fs;
    int i;
    int ch;
    
    puts("\n*** Exercise 13.5 ***");
    
    if ( (fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    for( i = 2; i < argc; i++)
    {
        if ( strcmp(argv[i], argv[1] ) == 0 )
            fputs("Can't append file to itself\n", stderr);
        else
            if ( ( fs = fopen(argv[i], "r")) == NULL)
                fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
            
            fclose(fs);
            
            printf("File %s appended.\n", argv[i]);
        }
    }
    
    printf("Done appending. %d files appended.\n", i-2);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    
    while ( (ch = getc(fa)) != EOF )
        putchar(ch);
    
    puts("Done displaying.");
    fclose(fa);

    return;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    
    while ( (bytes=fread(temp, sizeof(char), BUFSIZE, source)) > 0 )
        fwrite(temp, sizeof(char), bytes, dest);
}

void exercise13_6(void)
{
    FILE *in, *out;
    int ch;
    char file_src[SLEN], file_out[SLEN];
    int count = 0;

    puts("\n*** Exercise 13.6 ***");
    
    puts("Enter name of source file (empty line to quit):");
    
    s_gets(file_src, SLEN);
    
    if ( file_src[0] == '\0' )
    {
        puts("You didn't enter a source file name. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
        
    if ( ( in = fopen( file_src, "r")) == NULL )
    {
        printf("Can't open %s\n", file_src);
        exit(EXIT_FAILURE);
    }
    
    strncpy(file_out, file_src, SLEN - 5);
    file_out[SLEN-5] = '\0';
    strcat(file_out, ".red");
    
    if ( (out = fopen(file_out, "w" )) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    
    while ( (ch = getc(in)) != EOF )
    {
        if ( count++ % 3 == 0 )
            putc(ch, out);
    }
    
    if ( fclose(in) != 0 || fclose(out) != 0 )
        fprintf(stderr, "Error in closing files\n");
    
    
    return;
}

void exercise13_7(int argc, const char * argv[])
{
    FILE *f1, *f2;
    char *r1, *r2, *found;
    char line1[LINESIZE], line2[LINESIZE];
    char oneLine[LINESIZE*2 + 1];
    
    puts("\n*** Exercise 13.7 ***");
    
    if ( argc < 2 )
    {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ( (f1 = fopen(argv[1], "r")) == NULL )
    {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    if ( (f2 = fopen(argv[2], "r")) == NULL )
    {
        fprintf(stderr, "Error opening file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    r1 = fgets(line1, LINESIZE, f1);
    r2 = fgets(line2, LINESIZE, f2);
    
    while ( r1 != NULL || r2 != NULL )
    {
        
        if ( r1 && r2 )
        {
            found = strchr(line1, '\n');
            if (found)
                *found = '\0';
            strncpy(oneLine, line1, LINESIZE);
            strcat(oneLine, line2);
            printf("%s", oneLine);
        }
        else
        {
            if ( r1 != NULL )
                printf("F1: %s", line1);
            if ( r2 != NULL )
                printf("F2: %s", line2);
        }
        
        r1 = fgets(line1, LINESIZE, f1);
        r2 = fgets(line2, LINESIZE, f2);
        
    }
    
    if ( fclose(f1) != 0 || fclose(f2) != 0 )
    {
        fprintf(stderr, "Error happened while closing the files\n");
    }
        
    return;
}

void exercise13_8(int argc, const char * argv[])
{
    char ch, c;
    int i;
    int count = 0;
    
    puts("\n*** Exercise 13.8 ***");
    
    
    if ( argc < 2 )
    {
        fprintf(stderr, "usage: %s char file1 file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ch = argv[1][0];
    
    if ( argc > 2 )
    {
        for ( i = 2; i < argc; i++ )
        {
            if ( (count = countChar(argv[i], ch)) != -1 )
            {
                printf("There are %d %c characters in %s\n", count, ch, argv[i]);
            }
        }
    }
    else
    {
        puts("Enter a character stream to analyze");
        while ( (c = getc(stdin)) != EOF && c != '\n' )
        {
            if ( c == ch )
                count++;
        }
        printf("There has been %d of %c from stdin", count, c);
    }
    
    return;
}

int countChar(const char* filename, char ch)
{
    int count = 0;
    char c;
    FILE* fp;
    
    if ( (fp = fopen(filename, "r")) == NULL )
    {
        fprintf(stderr, "%s could not be opened\n", filename);
        return -1;
    }
    
    while ( (c = getc(fp)) != EOF)
    {
        if ( c == ch )
            count++;
    }
    
    if ( fclose(fp)!=0 )
    {
        fprintf(stderr, "Error closing %s\n", filename);
    }
    
    return count;
}

void exercise13_9(void)
{
    FILE *fp;
    char words[MAX];
    int count = 1;
    
    puts("\n*** Exercise 13.9 ***");
    
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // The file is opened for append therefore it will be forwarded to the end
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
        count++;

    printf("Word count: %d\n", count);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    
    while ( (fscanf( stdin, "%40s", words) == 1) && ( words[0] != '#' ) )
        fprintf(fp, "%3d%s\n", count++, words);
    
    puts("File contents:");
    rewind(fp);
    
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    
    puts("Done!");
    
    if (fclose(fp)!= 0)
        fprintf(stderr, "Error closing the file\n");
    
    return;
}

void exercise13_10(void)
{
    int pos;
    int ch;
    char file_src[SLEN];
    FILE *fp;
    unsigned long count = 0;

    puts("\n*** Exercise 13.10 ***");
    
    puts("Enter name of first source file (empty line to quit):");
    
    s_gets(file_src, SLEN);
    
    if ( ( fp = fopen(file_src, "r")) == NULL )
    {
        fprintf(stderr, "Could not open %s\n", file_src);
        exit(EXIT_FAILURE);
    }
    
    puts("Enter the position within the file from where the reading should start");
    while ( scanf("%d", &pos) == 1 && pos > 0 )
    {
        fseek(fp, pos, SEEK_SET);
        while ( ( ch = fgetc(fp) )!= '\n' && ch != EOF  )
            printf("%c", ch);
        
        printf("\n");
        puts("Enter the position within the file from where the reading should start");
    }
    
    if ( fclose(fp) != 0 )
    {
        fprintf(stderr, "Could not close %s\n", file_src);
    }
    
    return;
}

void exercise13_11(int argc, const char * argv[])
{
    FILE *fp;
    char *linestart;
    char line[MAXLINESIZE];
    
    
    puts("\n*** Exercise 13.11 ***");
    
    if ( argc < 3 )
    {
        fprintf(stderr, "Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ( (fp=fopen(argv[2], "r")) == NULL  )
    {
        fprintf(stderr, "Could not open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    while ( ( linestart= fgets(line, MAXLINESIZE, fp)) != NULL )
    {
        if ( strstr(line, argv[1]) != NULL )
            printf("%s", line);
    }
    
    if ( fclose(fp) != 0  )
    {
        fprintf(stderr, "could not close %s", argv[2]);
    }
    
    return;
}

void exercise13_12(void)
{
    const char* filename="image.txt";
    FILE *fp;
    int i, j;
    int ch;
    
    char mtrx[20][31];
    
    puts("\n*** Exercise 13.12 ***");
    
    if ( (fp=fopen(filename, "r")) == NULL )
    {
        fprintf(stderr, "couldn't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    i = j = 0;
    
    while ( ( ch = fgetc(fp) ) != EOF )
    {
        if ( ch == '\n' )
        {
            i++;
            j=0;
            continue;
        }
        
        if ( ch != ' ' )
            mtrx[i][j++] = ch;
    }
            
    for( i = 0; i < 20; i++)
    {
        for( j = 0; j < 30; j++)
        {
            switch (mtrx[i][j]) {
                
                case '0':
                    ch = ' ';
                    break;
                
                case '1':
                ch = '.';
                break;
                
                case '2':
                ch = '\'';
                break;
                
                case '3':
                ch = ':';
                break;
                
                case '4':
                ch = '~';
                break;
                
                case '5':
                ch = '*';
                break;
                
                case '6':
                ch = '=';
                break;
                
                case '7':
                ch = ' ';
                break;
                
                case '8':
                ch = '%';
                break;
                    
                case '9':
                ch = '#';
                break;
                    
                default:
                    break;
            }
            putchar(ch);
        }
        
        printf("\n");
    }
    
    if ( fclose(fp) != 0 )
        fprintf(stderr, "Could not close %s\n", filename);
    
    
    return;
}

void exercise13_13(int rows, int cols)
{
    const char* filename="image.txt";
    FILE *fp;
    int i, j;
    int ch;
    
    char mtrx[rows][cols+1];
    
    
    puts("\n*** Exercise 13.13 ***");
    
    if ( (fp=fopen(filename, "r")) == NULL )
    {
        fprintf(stderr, "couldn't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    i = j = 0;
    
    while ( ( ch = fgetc(fp) ) != EOF )
    {
        if ( ch == '\n' )
        {
            i++;
            j=0;
            continue;
        }
        
        if ( ch != ' ' )
        {
            mtrx[i][j++] = ch;
        }
    }
    
    
    
    for( i = 0; i < rows; i++)
    {
        for( j = 0; j < cols; j++)
        {
            switch (mtrx[i][j]) {
                
                case '0':
                    ch = ' ';
                    break;
                
                case '1':
                ch = '.';
                break;
                
                case '2':
                ch = '\'';
                break;
                
                case '3':
                ch = ':';
                break;
                
                case '4':
                ch = '~';
                break;
                
                case '5':
                ch = '*';
                break;
                
                case '6':
                ch = '=';
                break;
                
                case '7':
                ch = ' ';
                break;
                
                case '8':
                ch = '%';
                break;
                    
                case '9':
                ch = '#';
                break;
                    
                default:
                    break;
            }
            putchar(ch);
        }
        
        printf("\n");
    }
    
    if ( fclose(fp) != 0 )
        fprintf(stderr, "Could not close %s\n", filename);
    
    
    
    
    
    return;
}


void exercise13_14(void)
{
    const char* filename="image.txt";
    FILE *fp;
    int i, j;
    int ch;
    
    const int rows = 20;
    const int cols = 30;
    char mtrxBk[rows][cols+1];
    int img[rows][cols];
    
    char mtrx[rows][cols+1];
    
    puts("\n*** Exercise 13.14 ***");
    
    if ( (fp=fopen(filename, "r")) == NULL )
    {
        fprintf(stderr, "couldn't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    i = j = 0;
    
    while ( ( ch = fgetc(fp) ) != EOF )
    {
        if ( ch == '\n' )
        {
            i++;
            j=0;
            continue;
        }
        
        if ( ch != ' ' )
        {
            mtrx[i][j++] = ch;
            mtrxBk[i][j] = ch;
        }
    }
        
    puts("\n*** RAW DATA ***");
    
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++ )
            printf( "%c", mtrx[i][j] );
    
        printf("\n");
    }

    puts("\n*** INTEGER DATA ***");
    
    for ( i = 0; i < rows; i++)
        for ( j = 0; j < cols; j++ )
            img[i][j] = (int)((int)mtrx[i][j] - '0');

    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++ )
            printf( "%d", img[i][j] );
        printf("\n");
    }

    
    
//    puts("\n*** FIRST CONVERSION ***");
//
//    for( i = 0; i < rows; i++)
//    {
//        for( j = 0; j < cols; j++)
//        {
//            switch (mtrx[i][j]) {
//
//                case '0':
//                    ch = ' ';
//                    break;
//
//                case '1':
//                    ch = '.';
//                    break;
//
//                case '2':
//                    ch = '\'';
//                    break;
//
//                case '3':
//                    ch = ':';
//                    break;
//
//                case '4':
//                    ch = '~';
//                    break;
//
//                case '5':
//                    ch = '*';
//                    break;
//
//                case '6':
//                    ch = '=';
//                    break;
//
//                case '7':
//                    ch = ' ';
//                    break;
//
//                case '8':
//                    ch = '%';
//                    break;
//
//                case '9':
//                    ch = '#';
//                    break;
//
//                default:
//                    break;
//            }
//            putchar(ch);
//        }
//
//        printf("\n");
//    }
    
    
    if ( fclose(fp) != 0 )
        fprintf(stderr, "Could not close %s\n", filename);
    
    
    puts("\n*** AFTER GLITCH CORRECTION ***");
    correctglitch(img, 20);
    
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++ )
            printf( "%d", img[i][j] );
        printf("\n");
    }
    
    
//
//
//    for( i = 0; i < rows; i++)
//    {
//        for( j = 0; j < cols; j++)
//        {
//            switch (mtrx[i][j]) {
//
//                case '0':
//                    ch = ' ';
//                    break;
//
//                case '1':
//                ch = '.';
//                break;
//
//                case '2':
//                ch = '\'';
//                break;
//
//                case '3':
//                ch = ':';
//                break;
//
//                case '4':
//                ch = '~';
//                break;
//
//                case '5':
//                ch = '*';
//                break;
//
//                case '6':
//                ch = '=';
//                break;
//
//                case '7':
//                ch = ' ';
//                break;
//
//                case '8':
//                ch = '%';
//                break;
//
//                case '9':
//                ch = '#';
//                break;
//
//                default:
//                    break;
//            }
//            putchar(ch);
//        }
//
//        printf("\n");
//    }
       
}

void correctglitch(int arr[][30], int rows)
{
    int r, c;
    int cols = 30;
    int count, left, right, up, down, current, avg;
        
    
    for ( r = 0 ; r < rows; r++)
    {
        for( c = 0; c < cols; c++ )
        {
            count = left = right = up = down = avg = 0;
            current = arr[r][c];
            
            if ( (c - 1) >= 0 )
            {
                left = arr[r][c-1];
                
                if ( abs(left - current) > 1 )
                    count++;
            }
            
            if ( (c + 1) <= cols )
            {
                right = arr[r][c+1];
                
                if ( abs(right - current) > 1 )
                    count++;
            }
            
            if ( (r - 1) >= 0 )
            {
                up = arr[r-1][c];
                
                if ( abs(up - current) > 1 )
                    count++;
            }
            
            if ( (r + 1) <= rows )
            {
                down = arr[r+1][c];
                
                if ( abs(down - current) > 1 )
                    count++;
            }
            
            if ( count > 0 )
            {
                avg = (int) ( (double)(right + left + up + down)/(double)count );
                arr[r][c] = avg;
            }
            
        }
    }
    
}
