//
//  main.c
//  content
//
//  Created by Faik Hakan Bilgen on 15.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "chp17Content.h"
//#include "list.h"
//#include "queue.h"

void showmovies(Item item);

int main(int argc, const char * argv[]) {

    puts("\n*** Contents of Chapter 17 ***\n");
    //listing17_1();
    //listing17_2();
    //listing17_3();
    //listing17_8();
    listing17_12();
    return 0;
}


char* s_gets(char *st, int n)
{
    char *retval;
    char *find;
    
    retval = fgets(st, n, stdin);
    
    if (retval)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    
    return retval;
}

//void listing17_1(void)
//{
//    struct film movies[FMAX];
//    int i = 0;
//    int j;
//
//    puts("Enter first movie title:");
//    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0' )
//    {
//        puts("Enter your rating (0-10):");
//        scanf("%d", &movies[i++].rating);
//
//        eatnl();
//        puts("Enter next movie title (empty line to stop):");
//    }
//
//    if ( i==0 )
//        printf("No data entered. ");
//    else
//        printf("Here is the movie list:\n");
//
//    for( j = 0; j < i; j++ )
//        printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
//
//    printf("\nBye!\n");
//
//}
//
//void listing17_2(void)
//{
//    #ifndef LIST173
//        struct film *head = NULL;
//        struct film *prev = NULL, *current;
//        char input[TSIZE];
//
//        puts("\n*** Listing 17.2 ***\n");
//
//        /* Gather and store information */
//        puts("Enter first movie title:");
//        while (s_gets(input, TSIZE) != NULL && input[0] != '\0' )
//        {
//            current = (struct film *) malloc(sizeof(struct film));
//
//            if (head == NULL)
//                head = current;
//            else
//                prev->next = current;
//
//            current->next = NULL;
//            strcpy(current->title, input);
//            puts("Enter your rating (0-10):");
//            scanf("%d", &current->rating);
//
//            eatnl();
//            puts("Enter next movie title (empty line to stop):");
//            prev = current;
//        }
//
//        /* Show list of movies */
//        if (head == NULL)
//            printf("No data entered.\n");
//        else
//            printf("Here is the movie list:\n");
//
//        current = head;
//
//        while ( current != NULL)
//        {
//            printf("Movie: %s Rating: %d\n", current->title, current->rating);
//            current = current->next;
//        }
//
//        /* Program done, so free allocated memory */
//        current = head;
//        while ( head != NULL )
//        {
//            current = head;
//            head = current->next;
//            free(current);
//        };
//    #endif
//
//    printf("Bye!\n");
//
//    return;
//}
//
//void listing17_3(void)
//{
//    List movies;
//    Item temp;
//
//    puts("\n*** Listing 17.3 ***\n");
//
//    /* Initialize */
//    InitializeList(&movies);
//    if ( ListIsFull(&movies) )
//    {
//        fprintf(stderr, "No memory available! Bye!\n");
//        exit(1);
//    }
//
//    /* Gather and store */
//    puts("Enter first movie title:");
//    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
//    {
//        puts("Enter your rating (0-10):");
//        scanf("%d", &temp.rating);
//        eatnl();
//
//        if (AddItem(temp, &movies) == false)
//        {
//            fprintf(stderr, "Problem allocating memory\n");
//            break;
//        }
//
//        if (ListIsFull(&movies))
//        {
//            puts("The list is now full.");
//            break;
//        }
//        puts("Enter next movie title (empty line to stop):");
//    }
//
//    /* Display */
//    if ( ListIsEmpty(&movies))
//        printf("No data entered.\n");
//    else
//    {
//        printf("Here is the movie list:\n");
//        Traverse(&movies, showmovies);
//    }
//
//    printf("You entered %d movies.\n", ListItemCount(&movies));
//
//    /* Clean up*/
//    EmptyTheList(&movies);
//    printf("Bye!\n");
//
//}
//
//void showmovies(Item item)
//{
//    printf("Movie: %s Rating: %d\n", item.title, item.rating);
//}

//void listing17_8(void)
//{
//    Queue   line;
//    Item    temp;
//    char    ch;
//    
//    puts("\n*** Listing17.8 ***\n");
//    
//    InitializeQueue(&line);
//    puts("Testing the Queue interface. Type a to add a value,");
//    puts("type d to delete a value, and type q to quit.");
//    
//    while ( ( ch=getchar()) != 'q' )
//    {
//        if ( ch != 'a' && ch != 'd' )
//            continue;
//        
//        if ( ch == 'a' )
//        {
//            printf("Integer to add: ");
//            scanf("%d", &temp);
//            if ( !QueueIsFull(&line) )
//            {
//                printf("Putting %d into queue\n", temp);
//                EnQueue(temp, &line);
//            }
//            else
//                puts("Queue is full!");
//        }
//        else
//        {
//            if (QueueIsEmpty(&line))
//            {
//                puts("Nothing to delete!");
//            }
//            else
//            {
//                DeQueue(&temp, &line);
//                printf("Removing %d from queue\n", temp);
//            }
//        }
//        
//        printf("%d items in queue\n", QueueItemCount(&line));
//        puts("Type a to add d to delete, q to quit:");
//    }
//    
//    EmptyTheQueue(&line);
//    puts("Bye!");
//    
//    
//}



char menu(void)
{
    int ch;
    
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    
    while ( ( ch = getchar()) != EOF )
    {
        eatnl();
        ch = tolower(ch);
        if ( strchr("alrfndq", ch) == NULL )
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    
    if ( ch == EOF )
        ch = 'q';
    
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;
    
    if ( TreeIsFull(pt) )
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, 20);
        puts("Please enter pet type:");
        s_gets(temp.petkind, 20);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void droppet(Tree *pt)
{
    Item temp;
    
    if (TreeIsEmpty(pt))
    {
        puts("No entries");
        return;
    }
    
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, 20);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, 20);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if ( DeleteItem(&temp, pt) )
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}
void findpet(const Tree *pt)
{
    Item temp;
    
    if ( TreeIsEmpty(pt) )
    {
        puts("No entries!");
        return;
    }
    
    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, 20);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, 20);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    
    if ( InTree(&temp, pt) )
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void printitem(Item item)
{
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}
void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void listing17_12(void)
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ( ( choice = menu()) != 'q' )
    {
        switch (choice)
        {
            case 'a':
                addpet(&pets);
                break;
            
            case 'l':
                showpets(&pets);
                break;
                
            case 'f':
                findpet(&pets);
                break;
            
            case 'n':
                printf("%d pets in club\n", TreeItemCount(&pets));
                break;
            
            case 'd':
                droppet(&pets);
                break;
                
            default:
                puts("Switching error!");
                break;
        }
    }
    DeleteAll(&pets);
    puts("Bye.");
        
}




void eatnl()
{
    while (getchar()!='\n')
        continue;
}
