//
//  tree.h
//  content
//
//  Created by Faik Hakan Bilgen on 17.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct item
{
    char    petname[20];
    char    petkind[20];
} Item;

#define MAXITEMS 10

typedef struct trnode
{
    Item            item;
    struct trnode   *left;
    struct trnode   *right;
} Trnode;

typedef struct tree
{
    Trnode *root;
    int size;
} Tree;


/* Operation:       initialize a tree to empty          */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  the tree is initialized to empty    */
void InitializeTree(Tree *ptree);

/* Operation:       determine if tree is empty          */
/* Precondition:    ptree points to a tree              */
/* Postconditions:  function returns true if tree is    */
/*                  empty and returns false otherwise   */
bool TreeIsEmpty(const Tree *ptree);

/* Operation:       determine if tree is full           */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  function returns true if tree is    */
/*                  full and returns false otherwise    */
bool TreeIsFull(const Tree  *ptree);

/* Operation:       determine number of items in tree   */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  function returns number of items in */
/*                  tree                                */
int TreeItemCount(const Tree *ptree);

/* Operation:       add an item to a tree               */
/* Preconditions:   pi is address of item to be added   */
/*                  ptree points to an initialized tree */
bool AddItem(const Item *pi, Tree *ptree);

/* Operation:       find an item in a tree              */
/* Preconditions:   pi points to an item                */
/*                  ptree points to an initialized tree */
bool InTree(const Item *pi, const Tree *ptree);

/* Operation:       delete an item from a tree          */
/* Preconditions:   pi is address of item to be deleted */
/*                  ptree points to an initialized tree */
/* Postconditions:  if possible, function deletes item  */
/*                  from tree and returns true;         */
/*                  otherwise the function returns false*/
bool DeleteItem(const Item *pi, Tree *ptree);

/* Operation:       apply a function to each item in    */
/*                  the tree                            */
/* Preconditions:   ptree points to a tree              */
/*                  pfun points to a function that takes*/
/*                  an Item argument and has no return  */
/*                  value                               */
/* Postconditions:  the function pointed to by pfun is  */
/*                  executed once for each item in tree */
void Traverse(const Tree *ptree, void (*pfun)(Item item));

/* Operation:       delete everything from a tree       */
/* Preconditions:   ptree points to an initialized tree */
/* Postconditions:  tree is empty                       */
void DeleteAll(Tree *ptree);


#endif /* tree_h */
