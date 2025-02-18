/******************************************************************************
 *                                                                            *
 *                                                                            *
 *                   Wykonane przez Mikołaj Szuba                             *
 *                                                                            *
 *          Inżynieria i Analiza Danych - Rok 1, Semestr 2                    *
 *                                                                            *
 *                            10.07.2023                                      *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/


#include "labirynt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//rozwiazywanie labiryntu
stos_t * spacer( Labirynt * L, unsigned w, unsigned k ){

  wsp_t start={w,k};
  stos_t* trasa=nowy_stos(L->LK*L->LW);

  if (w==-1 || k==-1 || L->Pole[w][k]==ZAJETE){

    printf("Bledne wspolrzedne wejscia: w = %d, k = %d",w,k);
    zwolnij_stos(trasa);

    return trasa;
  }

  stos_dodaj(trasa,start);
  int wynik = krok(trasa,L);
  ekipa_sprzatajaca(trasa,L);

  if (wynik){
    printf("Udalo sie!\n");
    ekipa_sprzatajaca(trasa,L);
    return trasa;
  }
  else{
    printf("Brak wyjscia.\n");
    return trasa;
  }
}

//labirynt PGM
Labirynt* nowy_labirynt(short l_wierszy, unsigned l_kolumn) {
  Labirynt* L = malloc(sizeof(Labirynt));

  if (L == NULL) {
    printf("Błąd alokacji pamięci.\n");
    return NULL;
  }

  L->LK = l_kolumn;
  L->LW = l_wierszy;
  L->Pole=(char**)malloc(sizeof(char*) * l_wierszy);

  if (L->Pole == NULL) {

    free(L);
    printf("Błąd alokacji pamięci.\n");
    return NULL;

  }

  for (int i=0; i<l_wierszy; i++) {

    L->Pole[i]=(char*)malloc(sizeof(char)*l_kolumn);

    if (L->Pole[i] == NULL) {

      free(L->Pole);
      free(L);
      printf("Błąd alokacji pamięci dla wiersza %d\n", i);
      return NULL;

    }
  }

  return L;

}
Labirynt * PGM2labirynt(const char* nazwa_pliku){

  FILE* plik = fopen(nazwa_pliku, "rb");

  if (plik == NULL) {

    printf("Błąd: Nie można otworzyć pliku %s\n", nazwa_pliku);
    return NULL;

  }

  char format[3];
  int w, h, makswart;
  fscanf(plik, "%s\n%d %d\n%d\n", format, &w, &h, &makswart);

  if (strcmp(format, "P5") != 0 || makswart != 255) {

    printf("Zly format pliku.");
    fclose(plik);
    return NULL;

  }

  if (w > MAXWIDTH) {

    printf("Błąd: Przekroczono maksymalny rozmiar obrazu\n");
    fclose(plik);
    return NULL;

  }

  Labirynt* L = nowy_labirynt(w,h);

  if (L == NULL) {

    fclose(plik);
    return NULL;

  }

  int x, y;
  for (x = 0; x < h; x++) {
    for (y = 0; y < w; y++) {

      unsigned char piksel;
      fread(&piksel, sizeof(unsigned char), 1, plik);

      if (piksel<85){  //musi tak byc, problemy z tworzeniem pliku pgm
        L->Pole[x][y] =ZAJETE;
      }
      else if(piksel>170){
        L->Pole[x][y] =WOLNE;
      }
      else {
        L->Pole[x][y] = ODWIEDZONE;
      }
    }
  }

  fclose(plik);

  return L;
}
int labirynt2PGM(const char* nazwaPliku, const Labirynt* labirynt){

  FILE* plik = fopen(nazwaPliku, "wb");

  if (!plik) {

    return 1;
  }

  int w = labirynt->LK;
  int h = labirynt->LW;
  int makswart=255;

  fprintf(plik, "P5\n");
  fprintf(plik, "%d %d\n",w,h);
  fprintf(plik, "%d\n",makswart);

  int x, y;

  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {

      int wartoscPiksela = labirynt->Pole[y][x];

      if (wartoscPiksela==ZAJETE) {
        fputc(0, plik);
      }
      else if(wartoscPiksela==WOLNE){
        fputc(makswart, plik);
      }
      else {
        fputc(127, plik);
      }
    }
  }

  fclose(plik);

}
void zwolnij_labirynt(Labirynt* L) {

  if (L != NULL) {

    for (int i=0; i<L->LW; i++) {
      free(L->Pole[i]);
    }
    free(L->Pole);
    free(L);
  }
}

//funkcje pomocnicze
int krok(stos_t* S, Labirynt* L){

  wsp_t poz=S->tablica[S->gura];
  int x=poz.k;
  int y=poz.w;
  if(x!=L->LK-1){
    if (L->Pole[y][x+1]==WOLNE){
      
      wsp_t Q={y,x+1};
      L->Pole[y][x+1]=ODWIEDZONE;
      stos_dodaj(S,Q);
      return krok(S,L);
    }
  }

  if(y!=L->LW-1){
    if( L->Pole[y+1][x]==WOLNE){

      wsp_t Q={y+1,x};
      L->Pole[y+1][x]=ODWIEDZONE;
      stos_dodaj(S,Q);
      return krok(S,L);
    }
  }

  if(x!=0){
    if (L->Pole[y][x-1]==WOLNE){

      wsp_t Q={y,x-1};
      L->Pole[y][x-1]=ODWIEDZONE;
      stos_dodaj(S,Q);
      return krok(S,L);
    }
  }

  if(y!=0){
   if (L->Pole[y-1][x]==WOLNE){

      wsp_t k={y-1,x};
      L->Pole[y-1][x]=ODWIEDZONE;
      stos_dodaj(S,k);
      return krok(S,L);
    }
  }

  if(S->tablica[S->gura].k==L->LK-1 || S->tablica[S->gura].w==L->LW-1){

    return 1;
  }
  if(S->gura==0){
    
    stos_zdejmij(S);
    return 0;
  }
  
  stos_zdejmij(S);
  return krok(S, L);

}
void ekipa_sprzatajaca(stos_t* S, Labirynt* L) {

  int LW = L->LW-1;
  int LK = L->LK-1;
  int trasa = (S->gura);

  for (int i = 0; i < LW; i++) {
    for (int j = 0; j < LK; j++) {
      if(L->Pole[i][j]==ODWIEDZONE)
        L->Pole[i][j]=WOLNE;
      }
    }

  if(!trasa) return;
  for (int k = 0; k <= trasa; k++) {
      L->Pole[S->tablica[k].w][S->tablica[k].k]=ODWIEDZONE;
  }
}


