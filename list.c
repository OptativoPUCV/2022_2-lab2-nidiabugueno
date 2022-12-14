#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *list = (List *)malloc(sizeof(List));
    list->head =  NULL;
    list->tail = NULL;
    list->current = NULL;
  
    return list;
}

void * firstList(List * list) {
    if(!list->head) return NULL;
    list -> current = list -> head;
    return (list->current->data);
}

void * nextList(List * list) {
    if(list -> current == NULL) return NULL;
    if(list -> current -> next != NULL)
      list -> current = list->current->next;
    else{
      return NULL;
    }
    return list->current->data;
  }

void * lastList(List * list) {
    if(!list -> tail) return NULL;
    list -> current = list -> tail;
    return (list->current->data);
  }

void * prevList(List * list) {
    if(list -> current && list -> current -> data)
    {
        list -> current = list -> current -> prev;
        if (list -> current == NULL) return NULL;
        return list -> current -> data;
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node * nodoaux = createNode(data);
  
    if (list -> head != NULL){
      nodoaux -> next = list -> head;
      list -> head -> prev = nodoaux;
      list -> head = nodoaux;
    }
    else if (list->head == NULL){
      list -> head = nodoaux;
      list -> tail = nodoaux;
      list -> current = nodoaux;
    }
}

void pushBack(List * list, void * data) {
    list -> current = list -> tail;
    pushCurrent(list,data);

}

void pushCurrent(List * list, void * data) {
    Node *nodo = createNode(data);
    
    if(list -> head == NULL){
      list -> head = nodo; 
    } 
    else if(list -> current -> next != NULL)
    {
        list -> current -> next = nodo;
        nodo -> next = list -> current -> next;
        nodo -> prev = list -> current;
    }else{
        list -> tail = nodo;
        nodo -> prev = list -> current;
        list -> current -> next = nodo;
    }
}
  


void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  
  Node* nodo = createNode(data);
  if (nodo != NULL){
      
    if(list->current->next == NULL)  {
        nodo->prev = list->tail;
        if(list->tail){
            list->tail->next = nodo;
        }
        list->tail = nodo;
        nodo->next = NULL;
    }

  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}