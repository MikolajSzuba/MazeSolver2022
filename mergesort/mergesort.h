#ifndef MERGESORT_H
#define MERGESORT_H

struct _lel;
typedef struct _lel *LEptr;
struct _lel {
  int data;
  LEptr next;
} element;

//sortowanie
LEptr mergesort(LEptr first);
LEptr strip_monoprefix(LEptr first);
LEptr merge_monotonic(LEptr L, LEptr R);

//obsluga listy
void push(LEptr* first, int new_data);
void printList(LEptr first);
void freeList(LEptr first);

#endif