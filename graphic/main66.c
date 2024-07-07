#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
#include "update_score.h"
#include "vie.h"


#define GRAVITY 10

int main()
{

TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran ;
ecran=SDL_SetVideoMode (1000,667,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("PANDEMIC",NULL);
score s;
int sc;
Uint32 dt, t_prev;
SDL_Event event;
perso p;
SDL_Surface *back;
back=IMG_Load("background.png");
SDL_Surface* pa;
SDL_Rect pa_pos;


pa =IMG_Load("perdu.png");
pa_pos.x=200;
pa_pos.y=100;
int continuer=1;
int right=0,left=0,up=0,l=0,r=0;
int vies=3;
vie v;
int freinage=0;
initialiser_vie(&v);
init(&p);
initialiser_score(sc,&s);

while(continuer)
{
t_prev=SDL_GetTicks();    //au début de la boucle de jeu


    SDL_BlitSurface(back,NULL,ecran,NULL);

while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=1;
                break;
                case SDLK_RIGHT:
                   
                       right=1;
                   
                   
                    
                break;
                case SDLK_UP:
                    up=1;
                break;  
                case SDLK_r:
                    r=1;
                break;
                case SDLK_l:
                    l=1;
                break;    
	    	case SDLK_v:
		gestion_vies(&v,&vies);
		break;

		case SDLK_s:

		update_score(&s);
	
		break;      

            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=0;
                break;
                case SDLK_RIGHT:
                    right=0;
                break;
                case SDLK_UP:
                    up=0;
                break;
                case SDLK_r:
                    r=0;
                break;
                case SDLK_l:
                    l=0;
                break; 
            }
        break;    
        }
    
    
    
    
    
    
    }


    if (left==1) {
    
    p.direction=1;
    deplacerPerso(&p, dt);

    

    // movePerso(&p,dt);
    }
if (right==1)
{
    p.direction=0;

    deplacerPerso(&p, dt);
//movePerso(&p,dt);
} 
if (r==1)
{
    p.direction=2;

    deplacerPerso(&p, dt);
//movePerso(&p,dt);
} 
if (l==1)
{
    p.direction=3;
    deplacerPerso(&p, dt);

//movePerso(&p,dt);
}

if ((up==1)&&( p.pos.y ==400 )) saut(&p ,dt);
if (p.direction==0)// p.acceleration+=0.005;
//movePerso(&p,dt);
 p.pos.x += p.vitesse;
//p.pos.x = p.dx;
if (p.direction==1) //p.acceleration-=0.005;
//movePerso(&p,dt);
 //p.pos.x = p.dx;
p.pos.x -= p.vitesse;
if (p.direction==2) //p.acceleration+=0.01;
//movePerso(&p,dt);
//p.pos.x = p.dx;
p.pos.x += (2*p.vitesse);
if (p.direction==3)// p.acceleration-=0.01;
//movePerso(&p,dt);
//p.pos.x = p.dx;
 p.pos.x -= (2*p.vitesse);
if (left==1) {
    
    p.direction=1;
    p.vitesse=5;

    }
if (right==1)
{
    p.direction=0;
    p.vitesse=5;

} 
if (r==1)
{
    p.direction=2;
    p.vitesse=5;
    p.acceleration+=0.5;

} 
if (l==1)
{
    p.direction=3;
    p.vitesse=5;
    p.acceleration+=0.5;
}

deplacerPerso(&p,dt);


if ((up==1)&&( p.pos.y ==400 )) saut(&p,dt);
if (p.direction==0) p.pos.x += p.vitesse;
if (p.direction==1) p.pos.x -= p.vitesse;
if (p.direction==2) p.pos.x += p.dx;
if (p.direction==3) p.pos.x -= p.dx;

if (freinage==1)  p.acceleration-=1;

p.acceleration-=0.1;
if (p.acceleration<0) p.acceleration=0;

/*if (left==0 && right==0 && l==0 && r==0)
{
    p.vitesse=0;
  //p.vitesse==0; p.acceleration==0;
//movePerso(&p,dt);
//p.pos.x += p.dx;
}*/

if(v.val >-1)
{
afficher_vie(v,ecran);

afficherPerso(&p,ecran);
animerPerso(&p);
afficher_score(&s,ecran,sc);
printf("%d",v.val);
}


else
{
SDL_BlitSurface(pa,NULL,ecran,&pa_pos);
SDL_Flip(ecran);

}

 p.pos.y += p.vitesseV;
p.vitesseV += GRAVITY ;
if (p.pos.y>400)
{
    p.pos.y=400;
    p.vitesseV=0;
}

dt= SDL_GetTicks() - t_prev;

SDL_Flip(ecran);
SDL_Delay(70);

}        

}
