#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct perso
	{
    
    SDL_Surface *sprites[4];
	int frame;
	int direction;
	SDL_Rect pos;
	SDL_Rect posspritesheet;
    double vitesse,vitesseV,dx,acceleration;
	}perso;

    void init(perso* p);
void afficherPerso(perso *p,SDL_Surface* screen);
void deplacerPerso(perso *p,int dt);
void animerPerso(perso *p);
void saut(perso *p,int dt);












 #endif
