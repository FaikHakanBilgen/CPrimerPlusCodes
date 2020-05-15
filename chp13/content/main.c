//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 19.03.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
#define MAX 41
#define CNTL_Z 81
#define SLEN 81
#define BUFSIZE 4096
#define ARSIZE 1000

void listing13_1(int argc, const char * argv[]);
void listing13_2(int argc, const char * argv[]);
void listing13_3(void);
void listing13_4(void);
void listing13_5(void);
void append(FILE *source, FILE *dest);
char* s_gets(char *st, int n);
void listing13_6(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    puts("\n*** Content for Chapter 13 ***");
    //listing13_1( argc, argv );
    //listing13_2( argc, argv );
    //listing13_3();
    //listing13_4();
    //listing13_5();
    listing13_6();
    return 0;
}

void listing13_1(int argc, const char * argv[])
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
       
    puts("\n*** Listing 13.1 ***");
    
    
    if ( argc != 2 )
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ( ( fp = fopen( argv[1], "r")) == NULL )
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    while ( (ch = getc(fp)) != EOF  )
    {
        putc(ch, stdout);
        count++;
    }
    
    if ( fclose(fp) != 0)
        printf("Error in closing file %s\n", argv[1]);
    
    printf("File %s has %lu characters\n", argv[1], count);
    
    return;
}

void listing13_2(int argc, const char * argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
    
    puts("\n*** Listing 13.2 ***");
    
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ( (in = fopen(argv[1], "r")) == NULL )
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    strncpy(name, argv[1], LEN - 5);
    name[LEN-5] = '\0';
    strcat(name, ".red");
    
    if ( (out = fopen(name, "w" )) == NULL)
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

void listing13_3(void)
{
    FILE *fp;
    char words[MAX];
    
    puts("\n*** Listing 13.3 ***");
    
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    
    while ( (fscanf( stdin, "%40s", words) == 1) && ( words[0] != '#' ) )
        fprintf(fp, "%s\n", words);
    
    puts("File contents:");
    rewind(fp);
    
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    
    puts("Done!");
    
    if (fclose(fp)!= 0)
        fprintf(stderr, "Error closing the file\n");
    
    return;
}

void listing13_4(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;
    
    puts("\n*** Listing 13.4 ***");
    
    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    
    if (( fp = fopen(file, "rb")) == NULL)
    {
        printf("reverse can'it open %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    
    for( count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        
        if ( ch != CNTL_Z && ch != '\r' )
            putchar(ch);
    }
    
    putchar('\n');
    fclose(fp);
    
    
    return;
}

void listing13_5(void)
{
    FILE *fa, *fs;
    int files = 0;
    char file_app[SLEN];
    char file_src[SLEN];
    int ch;
    
    puts("\n*** Listing 13.5 ***");
    
    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if ( (fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    puts("Enter name of first source file (empty line to quit):");
    
    while ( s_gets(file_src, SLEN) && file_src[0] != '\0' )
    {
        if ( strcmp(file_src, file_app) == 0 )
            fputs("Can't append file to itself\n", stderr);
        else
            if ( ( fs = fopen(file_src, "r")) == NULL)
                fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    
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

void listing13_6(void)
{
    double numbers[ARSIZE];
    double value;
    const char* file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;
    
    puts("\n*** Listing 13.6 ***");
    
    for( i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i+1);
    
    if ( (iofile = fopen(file, "wb")) == NULL )
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    
    if ( (iofile = fopen(file, "rb")) == NULL )
    {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while ( scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    
    fclose(iofile);
    puts("Bye!");
    
    return;
}
