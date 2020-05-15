//
//  tree.c
//  content
//
//  Created by Faik Hakan Bilgen on 17.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "tree.h"

/* Local Data Type */
typedef struct pair
{
    Trnode* parent;
    Trnode* child;
} Pair;

/* prototypes for local functions */
static Trnode* MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode* root, void (* pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

/* Operation:       initialize a tree to empty          */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  the tree is initialized to empty    */
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

/* Operation:       determine if tree is empty          */
/* Precondition:    ptree points to a tree              */
/* Postconditions:  function returns true if tree is    */
/*                  empty and returns false otherwise   */
bool TreeIsEmpty(const Tree *ptree)
{
    return ptree->size == 0;
}

/* Operation:       determine if tree is full           */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  function returns true if tree is    */
/*                  full and returns false otherwise    */
bool TreeIsFull(const Tree  *ptree)
{
    return ptree->size == MAXITEMS;
}

/* Operation:       determine number of items in tree   */
/* Preconditions:   ptree points to a tree              */
/* Postconditions:  function returns number of items in */
/*                  tree                                */
int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

/* Operation:       add an item to a tree               */
/* Preconditions:   pi is address of item to be added   */
/*                  ptree points to an initialized tree */
bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node;
    
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    
    if (SeekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }
    
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    
    /* succeeded in creating a new node */
    ptree->size++;
    
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    
    return true;
    
}

/* Operation:       find an item in a tree              */
/* Preconditions:   pi points to an item                */
/*                  ptree points to an initialized tree */
bool InTree(const Item *pi, const Tree *ptree)
{
    return ( SeekItem(pi, ptree).child == NULL ) ? false : true ;
}

/* Operation:       delete an item from a tree          */
/* Preconditions:   pi is address of item to be deleted */
/*                  ptree points to an initialized tree */
/* Postconditions:  if possible, function deletes item  */
/*                  from tree and returns true;         */
/*                  otherwise the function returns false*/
bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;
    
    look = SeekItem(pi, ptree);
    if ( look.child == NULL )
        return false;
    
    if ( look.parent == NULL )
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child )
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    
    ptree->size--;
    
    return true;
}

/* Operation:       apply a function to each item in    */
/*                  the tree                            */
/* Preconditions:   ptree points to a tree              */
/*                  pfun points to a function that takes*/
/*                  an Item argument and has no return  */
/*                  value                               */
/* Postconditions:  the function pointed to by pfun is  */
/*                  executed once for each item in tree */
void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if ( ptree != NULL )
        InOrder(ptree->root, pfun);
}

/* Operation:       delete everything from a tree       */
/* Preconditions:   ptree points to an initialized tree */
/* Postconditions:  tree is empty                       */
void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}



static Trnode* MakeNode(const Item *pi)
{
    Trnode *new_node;
    
    new_node = (Trnode*)malloc(sizeof(Trnode));
    
    if ( new_node != NULL )
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    
    return new_node;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;
    
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0 )
        return true;
    else
        if ( comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0 )
            return true;
        else
            return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;
    
    if ((comp1=strcmp(i1->petname, i2->petname))>0)
        return true;
    else if ( comp1 == 0 && strcmp(i1->petkind, i2->petkind)>0)
        return true;
    else
        return false;
}

static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft( &new_node->item, &root->item))
    {
        if ( root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if ( root->right == NULL )
            root->right=new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr, "Location error in AddNode()\n");
        exit(1);
    }
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    
    if ( look.child == NULL )
        return look;
    
    while ( look.child != NULL )
    {
        if ( ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if ( ToRight(pi, &(look.child->item)) )
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }
    
    return look;
}

static void DeleteNode(Trnode **ptr)
{
    Trnode *temp;
    
    if ( (*ptr)->left == NULL )
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL )
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for ( temp = (*ptr)->left; temp->right != NULL; temp = temp->right )
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

static void InOrder(const Trnode* root, void (* pfun)(Item item))
{
    if ( root != NULL )
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode *ptr)
{
    Trnode *pright;
    
    if ( ptr != NULL )
    {
        pright = ptr->right;
        DeleteAllNodes(ptr->left);
        free(ptr);
        DeleteAllNodes(pright);
    }
}
