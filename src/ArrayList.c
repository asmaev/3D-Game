#ifndef _ARRAYLIST_C_
#define _ARRAYLIST_C_


#include "../include/ArrayList.h"

//creer et initialiser une liste dyn
void newArrayList(arrayList *l){
    l->capacity = CAPACITY;
    l->items = (void**)malloc(sizeof( void*)*l->capacity);
    l->size = 0;
}
//recup de la taille
int sizeArray(arrayList * l){
    return l->size;
}

//maj de la capacite reallocation de mem
void resizeArray(arrayList *l, int c){
    void** elements = (void**)realloc(l->items,sizeof( void*)*c);
    if(elements != NULL){
        l->items = elements;
        l->capacity = c;
    }
}

//ajout d'un element
void addItem(arrayList *l, void* element){
    if(l->size == l->capacity){
        resizeArray(l,l->capacity*2);      //on double la taille 
                                          //pour ne pas avoir a reallouer de la mem a chaque fois
    }
    l->items[l->size++] = element;
}

//mettre un element a un indice precis dans la liste
void setItem(arrayList *l, void* element, int index){
    if(index >= 0  && index <= l->size){
        l->items[index] = element;
    }
}

//recup d'un element a un indice precis dans la liste
void* getItem(arrayList *l, int index){
     if(index >= 0  && index <= l->size){
         return l->items[index];
    }
     return NULL;
}


//suppression d'un element
void deleteItem(arrayList *l, int index){
    if(index < 0 && index >= l->size){
        return;
    } 
    l->items[index] = NULL;
    //decaler les elements et liberer
    for(int i = index ; i < l->size ; i++){
        l->items[i] = l->items[i+1];
        l->items[i] = NULL;
    }
    l->size--;
    //suppression => mem alloue--
    if(l->size > 0 && l->size == l->capacity/4){   //si 1/4 de la liste est rempli
        resizeArray(l,l->capacity/2);             //on garde 1/2
    }
}

//liberation de la mem
void freeArray(arrayList* l){
    free(l->items);
}

#endif
