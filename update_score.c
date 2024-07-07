#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "update_score.h"

void initialiser_score (int valeur_score, score *s )
{
SDL_Surface *texte1=NULL; // l'affichage du texte score sous forme d'une chaine 
SDL_Surface *number1=NULL;// affichage de la valeur du score sous forme d'une chaine de caractere 
TTF_Font *police=NULL;
s->valeur_score=0;
s->police = TTF_OpenFont("outils/avocado.ttf", 35);

SDL_Color black={0,0,0}; 


s->position_number.x=850;
s->position_number.y=20;

s->position_texte.x=700;
s->position_texte.y=20;


}

// AFFICHAGE
void afficher_score(score *s,SDL_Surface *ecran,int valeur_score)
{
SDL_Color black={0,0,0}; 
char texte[20];
strcpy(texte,"Score :"); // variable pouur l'affichage du message score sur l ecran 

char number[20]; //tableau de chaine de c ou on va stocker la valeur du score 
sprintf(number, "%d ", s->valeur_score);
s->texte1= TTF_RenderText_Blended(s->police,texte,black);
s->number1= TTF_RenderText_Blended(s->police,number,black);
 SDL_BlitSurface(s->texte1, NULL, ecran,&s->position_texte);
SDL_BlitSurface(s->number1, NULL, ecran,&s->position_number);
SDL_Flip(ecran);
}

//UPDATE

void update_score  (score *s)
{
  
	(s->valeur_score)+=5;	


}


void free_score( score s)
{
SDL_FreeSurface(s.texte1);
SDL_FreeSurface(s.number1);

}
  
