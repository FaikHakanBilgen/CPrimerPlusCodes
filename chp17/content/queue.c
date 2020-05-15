//
//  queue.c
//  content
//
//  Created by Faik Hakan Bilgen on 17.04.2020.
//  Copyright © 2020 Faik Hakan Bilgen. All rights reserved.
//

#include "queue.h"

void InitializeQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
    if ( pq->items == MAXQUEUE )
        return true;
    else
        return false;
}

bool QueueIsEmpty(const Queue *pq)
{
    if ( pq->items == 0 )
        return true;
    else
        return false;
}

int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
    Node *pn;
    
    if ( QueueIsFull(pq) )
        return false;
    
    pn = (Node*)malloc(sizeof(Node));
    
    pn->item = item;
    pn->next = NULL;
    
    if ( QueueIsEmpty(pq) )
        pq->front = pn;
    else
        pq->rear->next = pn;
    
    pq->rear = pn;
    pq->items++;
    
    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    Node *np;
    if (QueueIsEmpty(pq))
        return false;
    
    np = pq->front;
    *pitem = np->item;
        
    pq->front = np->next;
    
    free(np);
    
    pq->items--;
    
    if ( pq->items == 0 )
        pq->rear = NULL;
    
    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Node *np = NULL;
    
    np = pq->front;
    
    while ( np != NULL )
    {
        pq->front = pq->front->next;
        free(np);
        np = pq->front;
    }
    
    pq->front = NULL;
    pq->rear = NULL;
    pq->items=0;
}


