#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include "ennemi.h" 
int main () 
{
Imm ecran,ennemi,bg;
   int done=0;
   SDL_Init(SDL_INIT_EVERYTHING);
   init(&ennemi,&ecran,&bg);
   ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); 
while(!done){
   display(&ecran,&ennemi,&bg);
}
   SDL_FreeSurface(ennemi.srf[0]);
   SDL_FreeSurface(bg.srf[0]);
return 0;
}
