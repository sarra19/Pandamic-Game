#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

//structure ennemi

typedef struct Ennemi
	{	
    SDL_Surface *images[2][4];
	int frame;
	int directionX,directionY;// 0 ou 1
	SDL_Rect pos,posmin,posmax;
	}Ennemi;

//entetes des fonctions
void init_Ennemi (Ennemi *E);
void afficher_Ennemi (Ennemi *E,SDL_Surface *screen);
void animation (Ennemi *E);
int collision (SDL_Rect E,SDL_Rect personnage);
void deplacer( Ennemi * E);
void deplacerIA( Ennemi * E, SDL_Rect posPerso);




















#endif // DS_H_INCLUDED
