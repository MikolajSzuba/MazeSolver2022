/*//////////////////////////////////////////////////////////

            Merge Sort

    zrobione przez Mikołaj Szuba
            01.07.2023

//////////////////////////////////////////////////////////*/

#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

LEptr mergesort(LEptr first) {

    if (first == NULL || first->next == NULL) {
        return first;
    }

    LEptr second = strip_monoprefix(first);
    if(second!=NULL){ //strasznie długo walczyłem z tym problemem :(
    first = mergesort(first);
    second = mergesort(second);
    }

    return merge_monotonic(first, second);
}
LEptr strip_monoprefix(LEptr first) {

    if (first == NULL || first->next == NULL) {
        return NULL;
    }

    //lista nie skalda sie z jednego elementu wiec przesekujemy element dalej
    LEptr prev = first;
    LEptr cur = first->next;

    while (cur != NULL && cur->data >= prev->data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL) {
        LEptr second_list = cur;
        prev->next = NULL;
        return second_list;
    }

    return NULL;
}
LEptr merge_monotonic(LEptr L, LEptr R) {

    //sprawdzamy czy 1 lista nie jest pusta
    if (L == NULL) {
        return R;
    }
    if (R == NULL) {
        return L;
    }

    LEptr sorted_list = NULL;
    LEptr last_elem = NULL;
    //ustawiamy 1 element
    if (L->data >= R->data) {
        sorted_list = R;
        R = R->next;
    } else {
        sorted_list = L;
        L = L->next;
    }

    last_elem = sorted_list;
    
    //dopisujemy kolejne elementy do next
    while (L != NULL && R != NULL) {
        if (L->data <= R->data) {
            last_elem->next = L;
            L = L->next;
        } else {
            last_elem->next = R;
            R = R->next;
        }
        last_elem = last_elem->next;
    }
    //ustawiamy najwiekszy element na koncu
    if (L != NULL) {
        last_elem->next = L;
    }

    if (R != NULL) {
        last_elem->next = R;
    }

    return sorted_list;
}

void push(LEptr* first, int new_data) {

    LEptr new_element = (LEptr)malloc(sizeof(element));
    new_element->data = new_data;
    new_element->next = *first;
    *first = new_element;
}
void printList(LEptr first) {

    while (first != NULL) {
        printf("%d ", first->data);
        first = first->next;
    }
    printf("\n");
}
void freeList(LEptr first) {
    while (first != NULL) {
        LEptr temp = first;
        first = first->next;
        free(temp);
    }
}


/*
int main() {
  
    LEptr list = NULL;
    push(&list, 4);
    push(&list, 2);
    push(&list, 7);
    push(&list, 1);
    push(&list, 5);

    printf("Przed sortowaniem: ");
    printList(list);

    list = mergesort(list);

    printf("Po sortowaniu: ");
    printList(list);

    freeList(list);

    return 0;
}
*/