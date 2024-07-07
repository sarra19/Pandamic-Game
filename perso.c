#include "perso.h"


    void init(perso* p)
	{
        char chemin[20];
        int i;

//p->vitesse=5; 
//p->acceleration=0;


        
        for ( i = 0; i < 4; i++)
        {
            sprintf(chemin,"%d.png",i);
            p->sprites[i]=IMG_Load(chemin);
        }
        
        p->direction=0;
        p->pos.x=30;
        p->pos.y=300;


	p->posspritesheet.x=0;
        p->posspritesheet.y=0;
        p->posspritesheet.h=150;
        p->posspritesheet.w=100;
      
        p->vitesseV=0;
	p->vitesse=0;
//p->dx=0;
        
    }

    void afficherPerso(perso *p,SDL_Surface* ecran)
    {
        SDL_BlitSurface(p->sprites[p->direction],&p->posspritesheet,ecran,&p->pos);
    }

      
      
      
  /*     void deplacerPerso(perso *p)
{
	p->vitesse++;
	
	if (p->vitesse > 50)
	{
		p->vitesse = 50;
	}
	
}*/
      void deplacerPerso(perso *p,int dt)
{
	//double dx;
   // p->vitesse=5;
    p->dx= 0.5* p->acceleration * dt * dt + p->vitesse * dt ;//formule de vitesse

	
}


void animerPerso(perso *p){
    p->posspritesheet.x+=100;
    if (p->posspritesheet.x>590)
    {
        p->posspritesheet.x=0;
    }
    if (p->vitesse==0) //&& p->acceleration==0 )
    {
        p->posspritesheet.x=0;
    }
    
    
}

/*void saut(perso *p)
{
  p->vitesseV=-60; 

}*/
void saut(perso *p,int dt)
{
    p->vitesseV=-(1 * p->acceleration * dt * dt + 20* dt);
}

        
    



      
