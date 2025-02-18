#include "labirynt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//obsluga stosu
stos_t * nowy_stos( unsigned rozmiar ){

  stos_t* trasa=malloc(sizeof(stos_t));

  if (trasa == NULL) {
    printf("Błąd alokacji pamięci.\n");
    return NULL;
  }

  trasa->dlugosc_trasy=rozmiar;
  trasa->gura=-1;
  trasa->tablica=malloc(rozmiar*sizeof(wsp_t));

  if (trasa->tablica == NULL) {
    printf("Błąd alokacji pamięci.\n");
    free(trasa);

    return NULL;
  }

  return trasa;
}
void zwolnij_stos( stos_t * S ){
  free(S->tablica);
  free(S);
}

// testy
int stos_pusty( stos_t * S ){
  return S->gura==-1;
} 
int stos_pelny( stos_t * S ){
  return S->gura==S->dlugosc_trasy-1;
}

// modyfikowanie stosu
void stos_dodaj(stos_t* S, wsp_t w) {

  if (!stos_pelny(S)) {

    S->gura++;
    S->tablica[(S->gura)] = w;
    
  }
  else {
    printf("Błąd: Stos jest pełny. Nie można dodać elementu.\n");
  }
}
wsp_t stos_zdejmij( stos_t * S ){

  wsp_t usuniete;

  if(!stos_pusty(S)){

    usuniete=S->tablica[S->gura];
    S->gura--;
  }
  else{

    printf("Blad: Stos jest pusty (%d). Nie mozna usunac elementu.\n",S->gura);
  }

  return usuniete;
}

wsp_t stos_szczytowy( stos_t * S ){

  wsp_t pozycja;

  if(!stos_pusty(S)){

    pozycja=S->tablica[S->gura];
  }
  else{

    printf("Błąd: Stos jest pusty.\n");

  }
  return pozycja;
}
