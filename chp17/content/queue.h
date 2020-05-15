//
//  queue.h
//  content
//
//  Created by Faik Hakan Bilgen on 17.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct node
{
    Item    item;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int items;
} Queue;

/* Operation:       initialize the queue                            */
/* Precondition:    pq points to a queue                            */
/* Postcondition:   queue is initialized to being empty             */
void InitializeQueue(Queue *pq);

/* Operation:       check if queue is full                          */
/* Precondition:    pq points to previously initialized queue       */
/* Postcondition:   returns True if the queue is full, else False   */
bool QueueIsFull(const Queue *pq);

/* Operation:       check if queue is empty                         */
/* Precondition:    pq points to previously initialized queue       */
/* Postcondition:   returns True if the queue is empty, else False  */
bool QueueIsEmpty(const Queue *pq);

/* Operation:       determine number of items in the queue          */
/* Precondition:    pq points to previously initialized queue       */
/* Postcondition:   Returns number of items in the queue            */
int QueueItemCount(const Queue *pq);

/* Operation:       add item to rear of queue                       */
/* Precondition:    pq points to previously initialized queue       */
/*                  item is to be placed at rear of queue           */
/* Postcondition:   if queue is not empty, item is placed at        */
/*                  rear of queue and function returns              */
/*                  True; otherwise, queue is unchanged and         */
/*                  function returns False                          */
bool EnQueue(Item item, Queue *pq);

/* Operation:       remove item from front of queue                 */
/* Precondition:    pq points to previously initialized queue       */
/* Postcondition:   if queue is not empty, item at head of queue    */
/*                  is copied to *pitem and deleted from            */
/*                  queue, and function returns True; if the        */
/*                  operation empties the queue, the queue is       */
/*                  reset to empty. If the queue is empty to        */
/*                  begin with, queue is unchanged and the          */
/*                  function returns False                          */
bool DeQueue(Item *pitem, Queue *pq);

/* Operation:       empty the queue                                 */
/* Precondition:    pq points to previously initialized queue       */
/* Postcondition:   the queue is empty                              */
void EmptyTheQueue(Queue *pq);

#endif /* queue_h */
