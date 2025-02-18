
#include "labirynt.h"
#include "labirynt.c"
#include "stos.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  const char* nazwa_pliku = "lab.pgm";
  char* nazwa="nowylab.pgm";
  
  Labirynt* labirynckik=PGM2labirynt(nazwa_pliku);

  wsp_t poczatek={0,1};
  int w=poczatek.w;
  int k=poczatek.k;

  stos_t* xd= spacer(labirynckik,w,k);

  
  for(int i=0;i<=xd->gura;i++){
    printf("%d: %d %d\n",i,xd->tablica[i].w,xd->tablica[i].k);
  }
  
  
  labirynt2PGM(nazwa,labirynckik);
  zwolnij_labirynt(labirynckik);
  zwolnij_stos(xd);
  return 0;
}

