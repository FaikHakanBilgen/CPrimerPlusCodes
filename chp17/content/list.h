//
//  list.h
//  content
//
//  Created by Faik Hakan Bilgen on 16.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef TSIZE
#define TSIZE 45
#endif

#define LIST173

//#ifdef LIST173
//
///* General Type Definitions */
//struct film
//{
//    char title[TSIZE];
//    int rating;
//};
//
//typedef struct film Item;
//
//typedef struct node
//{
//    Item item;
//    struct node* next;
//} Node;
//
//typedef Node *List;
//
///* Function Prototypes                                                  */
//
///* operation:       initialize a list                                   */
///* preconditions:   plist points to a list                              */
///* postconditions:  the list is initialized to empty                    */
//void InitializeList(List *plist);
//
///* operation:       determine if list is empty                          */
///* preconditions:   plist points to an initialized list                 */
///* postconditions:  function returns True if the list is empty          */
///*                  and returns False otherwise                         */
//bool ListIsEmpty(const List *plist);
//
///* operation:       determine if the list is full                       */
///* preconditions:   plist points to an initialized list                 */
///* postconditions:  function returns True if the list is full           */
///*                  and returns False otherwise                         */
//bool ListIsFull(const List *plist);
//
///* operation:       determine the number of items in list               */
///* preconditions:   plist points to an initialized list                 */
///* postconditions:  function returns number of items in list            */
//unsigned int ListItemCount(const List *plist);
//
///* operation:       add item to end of list                             */
///* preconditions:   item is an item to be added to list                 */
///*                  plist points to an initialized list                 */
///* postconditions:  if possible, function adds item to end              */
// /*                 of list and returns True; otherwise the             */
///*                  function returns False                              */
//unsigned int AddItem(Item item, List *plist);
//
///* operation:       apply a function to each item in list               */
///* preconditions:   plist points to an initialized list                 */
///*                  pfun points to a function that takes an             */
///*                  Item argument and has no return value               */
///* postconditions:  the function pointed to by pfun is                  */
///*                  executed once for each item in the list             */
//void Traverse(const List *plist, void (*pfun)(Item item));
//
///* operation:       free allocated memory, if any                       */
///* preconditions:   plist points to an initialized list                 */
///* postconditions:  any memory allocated for the list is freed          */
///*                  and the list is set to empty                        */
//void EmptyTheList(List *plist);
//
//#endif


#endif /* list_h */
