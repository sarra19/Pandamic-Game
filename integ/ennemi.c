#include "ennemi.h"

void init_Ennemi (Ennemi *E){
    int i,j;
    char chemin[100];
    E->pos.x=600;
    E->pos.y=300;
    E->directionX=0; 
    E->directionY=0;
    E->frame=0;

    for ( i = 0; i < 2; i++)
{
  for ( j=0 ; j < 4; j++)
  {
    sprintf(chemin,"imgs/%d/%d.png",i,j);
    E->images[i][j]=IMG_Load(chemin);
  }
  
}
E->posmin.x=300;
E->posmax.y=300;
E->posmax.x=800;
E->posmin.y=240;

}

void afficher_Ennemi (Ennemi *E,SDL_Surface *screen)
{
  SDL_BlitSurface(E->images[E->directionX][E->frame],NULL,screen,&E->pos);
}


void animation (Ennemi *E){
      E->frame++;
  if (E->frame > 3)
  {
    E->frame = 0;
  }  
}

void deplacer(Ennemi *E)
    {
    if (E->pos.y < E->posmin.y)
    {
        E->directionY = 0;
    }else if (E->pos.y > E->posmax.y)
    {
        E->directionY = 1;
      
    }




    if (E->pos.x < E->posmin.x)
    {
        E->directionX = 0;
    }else if (E->pos.x > E->posmax.x)
    {
        E->directionX = 1;
      
    }


    
    if (E->directionX == 0)
    {
        E->pos.x+=15;
    }
    if (E->directionX == 1)
    {
        E->pos.x-=15;
    }  
    if (E->directionY == 0)
    {
        E->pos.y+=5;
    }
    if (E->directionY == 1)
    {
        E->pos.y-=5;
    }  
}





int collision (SDL_Rect E,SDL_Rect p){
    int collision;
    if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.y) < E.y) || (p.y > (E.y + E.y)))
    {
        collision = 0;
    }
    else
    {
        collision = 1;
    }
    
    return collision;
}

