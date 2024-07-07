#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
#include "update_score.h"
#include "vie.h"
#include "ennemi.h"


#define GRAVITY 20
int main()
{

TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen ;
screen=SDL_SetVideoMode (1000,667,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
Uint32 t_prev,dt;
SDL_WM_SetCaption("perso\t1",NULL);
score s;
Ennemi E;
int sc;
SDL_Event event;
perso p,p1;
SDL_Surface *back;
back=IMG_Load("background.png");
SDL_Surface* pa;
SDL_Rect pa_pos;
pa =IMG_Load("perdu.png");
pa_pos.x=200;
pa_pos.y=100;

int continuer=1;
int right=0,left=0,up=0,l=0,r=0,right1=0,left1=0,up1=0,l1=0,r1=0;
int vies;
vie v;
int freinage=0,freinage1=0;
initialiser_vie(&v);
init(&p);
init(&p1);

initialiser_score(sc,&s);
init_Ennemi(&E);
while(continuer)
{
    t_prev = SDL_GetTicks();
    SDL_BlitSurface(back,NULL,screen,NULL);
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
                case SDLK_q:
                    left1=1;
                break;
                case SDLK_RIGHT:                  
                       right=1;          
                break;
                case SDLK_d:                  
                       right1=1;          
                break;
                case SDLK_UP:
                    up=1;
                break; 
                case SDLK_z:
                    up1=1;
                break;  
                case SDLK_r:
                    r=1;
                break;
                case SDLK_e:
                    r1=1;
                break;
                case SDLK_l:
                    l=1;
                break;   
                case SDLK_a:
                    l1=1;
                break;  
                case SDLK_SPACE:
                    freinage=1;
                    break; 
                    case SDLK_b:
                    freinage1=1;
                    break;       
		/*case SDLK_v:
		gestion_vies(&v,&vies);
		break;*/

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
                    p.vitesse=0;
                break;
                case SDLK_RIGHT:
                    right=0;
                    p.vitesse=0;
                break;
                case SDLK_UP:
                    up=0;
                break;
                case SDLK_r:
                    r=0;
                    p.vitesse=0;
                break;
                case SDLK_l:
                    l=0;
                    p.vitesse=0;
                break; 
                case SDLK_SPACE:
                    freinage=0;
                    break; 

                 case SDLK_q:
                    left1=0;
                    p1.vitesse=0;
                break;
                case SDLK_d:
                    right1=0;
                    p1.vitesse=0;
                break;
                case SDLK_z:
                    up1=0;
                break;
                case SDLK_e:
                    r1=0;
                    p1.vitesse=0;
                break;
                case SDLK_a:
                    l1=0;
                    p1.vitesse=0;
                break; 
                case SDLK_b:
                    freinage1=0;
                    break;    
            }
        break;    
        }
    
    
    
    
    
    
    }


    if (left==1) {
    
    p.direction=1;
    p.vitesse=5;

    }
        if (left1==1) {
    
    p1.direction=1;
    p1.vitesse=5;

    }
if (right==1)
{
    p.direction=0;
    p.vitesse=5;

} 

if (right1==1)
{
    p1.direction=0;
    p1.vitesse=5;

} 
if (r==1)
{
    p.direction=2;
    p.vitesse=5;
    p.acceleration+=0.2;

} 
if (r1==1)
{
    p1.direction=2;
    p1.vitesse=5;
    p1.acceleration+=0.2;

} 

if (l==1)
{
    p.direction=3;
    p.vitesse=5;
    p.acceleration+=0.2;
}

if (l1==1)
{
    p1.direction=3;
    p1.vitesse=5;
    p1.acceleration+=0.2;
}

deplacerPerso(&p,dt);
deplacerPerso(&p1,dt);

if ((up==1)&&( p.pos.y ==400 )) saut(&p,dt);
if (p.direction==0) p.pos.x += p.vitesse;
if (p.direction==1) p.pos.x -= p.vitesse;
if (p.direction==2) p.pos.x += p.dx;
if (p.direction==3) p.pos.x -= p.dx;


if ((up1==1)&&( p1.pos.y ==400 )) saut(&p1,dt);
if (p1.direction==0) p1.pos.x += p1.vitesse;
if (p1.direction==1) p1.pos.x -= p1.vitesse;
if (p1.direction==2) p1.pos.x += p1.dx;
if (p1.direction==3) p1.pos.x -= p1.dx;


if (freinage==1)  p.acceleration-=1;
if (freinage1==1)  p1.acceleration-=1;

p1.acceleration-=0.1;
if (p1.acceleration<0) p1.acceleration=0;
/*if (left==0 && right==0 && l==0 && r==0)
{
    p.vitesse=0;
}*/
if (collision(E.pos,p.pos)==1)//ilyaa collision
	{
	gestion_vies(&v,&vies);	
	}
/*if (collision(E.pos,p.pos)==2)//ilyaa collision
	{
	update_score(&s);
	}*/
if (collision(E.pos,p1.pos)==1)//ilyaa collision
	{
	gestion_vies(&v,&vies);	
	}
/*if (collision(E.pos,p1.pos)==2)//ilyaa collision
	{
	update_score(&s);
	}*/

if(v.val >-1)
{
afficher_vie(v,screen);
//update_score(&s);
afficherPerso(&p,screen);
animerPerso(&p);
afficherPerso(&p1,screen);
animerPerso(&p1);
afficher_score(&s,screen,sc);
printf("%d",v.val);
afficher_Ennemi(&E,screen);
	//deplacerIA(&E,p.rect);
	animation(&E);
	deplacer(&E);
	
}


else
{
SDL_BlitSurface(pa,NULL,screen,&pa_pos);
SDL_Flip(screen);

}


dt= SDL_GetTicks() - t_prev;

 p.pos.y += p.vitesseV;
p.vitesseV += GRAVITY ;
if (p.pos.y>400)
{
    p.pos.y=400;
    p.vitesseV=0;
}


 p1.pos.y += p1.vitesseV;
p1.vitesseV += GRAVITY ;
if (p1.pos.y>400)
{
    p1.pos.y=400;
    p1.vitesseV=0;
}


SDL_Flip(screen);
SDL_Delay(70);



}        






























}
