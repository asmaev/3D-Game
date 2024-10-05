#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_


#include <stdlib.h>


#define CAPACITY 40

//structure d'une arrayList comme celle vu en Java 
typedef struct arrayList{
    void** items; //to keep any type of elements
    int capacity;
    int size;
}arrayList;






void newArrayList(arrayList *l);
int sizeArray(arrayList * l);
void resizeArray(arrayList *l, int c);
void addItem(arrayList *l, void* element);
void setItem(arrayList *l, void* element, int index);
void* getItem(arrayList *l, int index);
void deleteItem(arrayList *l, int index);
void freeArray(arrayList* l);


#endif
