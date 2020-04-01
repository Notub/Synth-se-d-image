#include "actions.h"
#include <math.h>
#include <stdbool.h>

extern GLfloat xrot;   
extern GLfloat yrot; 

//pour la souris
extern unsigned int blend;
extern unsigned int light;

extern GLfloat look;
extern GLfloat lookh;

extern GLfloat aileGPingu;
extern GLfloat aileDPingu;
extern GLfloat xPingu;
extern GLfloat yPingu;
extern GLfloat corpsPingu;
extern GLfloat ailesEnMarcheD;
extern GLfloat ailesEnMarcheG;
extern GLboolean mouvement;



void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    switch (key) {
    case ESCAPE: 
	exit(1);
	break; 

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_A:
      if(aileGPingu<80){
       aileGPingu+=2;
       }
      break;
    case TOUCHE_MAJ_A:
      if(aileGPingu>20){
       aileGPingu-=2;
       }
      break;    
    case TOUCHE_MIN_E:
       if(aileDPingu<80){
       aileDPingu+=2;
       }
      break;
    case TOUCHE_MAJ_E:
      if(aileDPingu>20){
       aileDPingu-=2;
       }
      break;
    case TOUCHE_MIN_R:
      if(aileGPingu<80){
       aileGPingu+=2;
       }
      if(aileDPingu<80){
       aileDPingu+=2;
       }
      break;
    case TOUCHE_MAJ_R:
      if(aileGPingu>20){
       aileGPingu-=2;
       }
      if(aileDPingu>20){
       aileDPingu-=2;
       }
      break;

//DEPLACEMENT
    case TOUCHE_MIN_Z:


	if(((xPingu+0.1*sin(corpsPingu*(3.1415/180)))<=29)&&((xPingu+0.1*sin(corpsPingu*(3.1415/180)))>=-29))		//Vérification hors-zone
       xPingu+=0.1*sin(corpsPingu*(3.1415/180));
	if(((yPingu+0.1*cos(corpsPingu*(3.1415/180)))<=29)&&((yPingu+0.1*cos(corpsPingu*(3.1415/180)))>=-29))		//Vérification hors-zone
       yPingu+=0.1*cos(corpsPingu*(3.1415/180));


	//mouvement d'ailes de marche
       if(ailesEnMarcheD>=30)
	mouvement=0;
       else if(ailesEnMarcheD<=-30)
	mouvement=1;
       if (mouvement){
	ailesEnMarcheD+=2;
	ailesEnMarcheG-=2;
	}
       else{
	ailesEnMarcheD-=2;
	ailesEnMarcheG+=2;
	}
      break;
    case TOUCHE_MAJ_Z:


	if(((xPingu-0.1*sin(corpsPingu*(3.1415/180)))<=29)&&((xPingu-0.1*sin(corpsPingu*(3.1415/180)))>=-29))		//Vérification hors-zone
       xPingu-=0.1*sin(corpsPingu*(3.1415/180));
	if(((yPingu-0.1*cos(corpsPingu*(3.1415/180)))<=29)&&((yPingu-0.1*cos(corpsPingu*(3.1415/180)))>=-29))		//Vérification hors-zone
       yPingu-=0.1*cos(corpsPingu*(3.1415/180));


	//mouvement d'ailes de marche
       if(ailesEnMarcheD<=-30)
	mouvement=0;
       else if(ailesEnMarcheD>=30)
	mouvement=1;
       if (mouvement){
	ailesEnMarcheD-=2;
	ailesEnMarcheG+=2;
	}
       else{
	ailesEnMarcheD+=2;
	ailesEnMarcheG-=2;
	}
      break;

    case TOUCHE_MIN_S:
       corpsPingu+=2;
      break;
    case TOUCHE_MAJ_S:
       corpsPingu-=2;
      
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;
    }	
}

//Pour la souris

bool mouseLeftDown;
bool mouseRightDown;
float mouseX, mouseY;
float cameraAngleX;
float cameraAngleY;


void mouseCB(int button, int state, int x, int y)
{
        mouseX = x;
        mouseY = y;

        if (button == GLUT_LEFT_BUTTON)
        {
                if (state == GLUT_DOWN)
                {
                        mouseLeftDown = true;
			
                }
                else
                {
                        if (state == GLUT_UP)
                        {
                                mouseLeftDown = false;
                                
                        }
                }
                        
        }

        else if (button == GLUT_RIGHT_BUTTON)
        {
                if (state == GLUT_DOWN)
                {
                        mouseRightDown = true;
                }
                else if (state == GLUT_UP)
                        mouseRightDown = false;
        }
}



void mouseMotionCB(int x, int y)
{
        if (mouseLeftDown)
        {
                look += (x - mouseX)/4;
                lookh += (y - mouseY)/4;
                mouseX = x;
                mouseY = y;
        }
}

