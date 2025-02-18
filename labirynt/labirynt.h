#ifndef _LABIRYNT_H_
#define _LABIRYNT_H_

#include <stdint.h>

#define MAXWIDTH	512

typedef enum { 
  WOLNE = 0, ZAJETE=1 , ODWIEDZONE=2 } pole_t;

// współrzędne (w,k)
typedef struct {
  int w;
  int k;
} wsp_t;

//stos
typedef struct {

  int gura;
  int dlugosc_trasy;
  wsp_t* tablica;

} stos_t;

stos_t * nowy_stos( unsigned rozmiar );
void zwolnij_stos( stos_t * S );

// testy
int stos_pusty( stos_t * S ); 
int stos_pelny( stos_t * S );

// modyfikowanie stosu
void stos_dodaj( stos_t * S, wsp_t w );
wsp_t stos_zdejmij( stos_t * S );
// odczytuje szczyt, ale go nie pobiera
wsp_t stos_szczytowy( stos_t * S );

//labirynt
typedef struct _labirynt {
  unsigned short LW, LK;
  char** Pole;  //próbowałem użyć pole_t ale zajmuje 4 zamiast 1 bajtow __attribute__((packed)) nie działa, wina minGW compilera ( windows :( )
} Labirynt;

#define ROZMIAR_WIERSZA	    sizeof(((Labirynt *)NULL)->Pole[0])


stos_t * spacer( Labirynt * L, unsigned w, unsigned k );


Labirynt * nowy_labirynt( short l_wierszy, unsigned l_kolumn );
void zwolnij_labirynt( Labirynt * );
int labirynt2PGM(const char* nazwaPliku, const Labirynt* labirynt);
Labirynt * PGM2labirynt(const char* nazwa_pliku);


//fnkcje pomocnicze

wsp_t znajdz_wejscie(Labirynt* L);
wsp_t koniec(Labirynt* L);
int krok(stos_t* S, Labirynt* L);
void ekipa_sprzatajaca(stos_t* S, Labirynt* L);


#endif	//_LABIRYNT_H_
