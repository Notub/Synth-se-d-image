// gcc main.c actions.c axes.c init.c lumiere.c switch_blend.c  switch_light.c VM_init.c -lm -lGL -lGLU -lglut -o test


#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <GL/glu.h>
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 
GLfloat look = 180.0f;
GLfloat lookh=50;
GLfloat lookeloi=10; 


GLfloat corpsPingu=0.0f;
GLfloat corpsMumble=0.0f;
GLfloat corpsNageur=0.0f;
GLfloat aileDPingu=20.0f;
GLfloat aileGPingu=20.0f;
GLfloat ailesEnMarcheD=0.0f;
GLfloat ailesEnMarcheG=0.0f;
GLboolean mouvement=1;
GLfloat xPingu=0.0f;
GLfloat yPingu=0.0f;
GLfloat xMumble=0.0f;
GLfloat yMumble=0.0f;
GLfloat aileDMumble=20.0f;
GLfloat aileGMumble=20.0f;
GLfloat ailesMacronD=30.0f;
GLfloat ailesMacronG=30.0f;
GLfloat xNageur=0.0f;
GLfloat yNageur=0.0f;
GLfloat aileDNageur=20.0f;
GLfloat aileGNageur=20.0f;
GLboolean mouvementAilesMumble=1;
GLboolean mouvementAilesNageur=1;

void patte(int angl){
	glPushMatrix();
	{
		glRotatef(angl,0,1,0);
		glColor3f(255.0f/255.0f,128.0f/155.0f,0.0f/155.0f);
		GLUquadric* patte = gluNewQuadric();
		gluCylinder(patte,0.05,0.15,0.5,3,10);
	}
	glPopMatrix();
}

void oeil(){
	glColor3f(1,1,1);
	glutSolidSphere(0.05f,20,10);
	glTranslatef(0.0,0.01,0.045);
	glColor3f(0.2,0.2,0.2);
	glutSolidSphere(0.02f,20,10);
}

void yeux(){
	glPushMatrix();
	{
		glTranslatef(0.15,0.13,0.2);
		oeil();
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-0.15,0.13,0.2);
		oeil();
	}
	glPopMatrix();
}


void manchot(GLfloat aileD, GLfloat aileG, GLfloat ailesMacronEnMarcheD, GLfloat ailesMacronEnMarcheG){
	glPushMatrix();
	{
		glRotatef(-90,0,1,0);
		//corps
		glPushMatrix();
		{		//Blanc de la moitié inférieur du corps
			glTranslatef(0.1,0.05,0);
			glRotatef(-90,1,0,0);
			glColor3f(1,1,1);
			GLUquadric* basducorps = gluNewQuadric();
			gluCylinder(basducorps,0.25,0.45,1,100,10);
			GLUquadric* trouenbas = gluNewQuadric();
			gluCylinder(trouenbas,0.25,0,0,100,10);
		}
		glPopMatrix();
		glPushMatrix();
		{		//Noir du corps (fait avec une sphere allongée)
			glColor3f(0,0,0);
			glTranslatef(0,1,0);
			glScalef(1,2,1);
			glutSolidSphere(0.5f,10,10);

			glPushMatrix();
			{		//Blanc au dessus de la moitié du corps
				glTranslatef(0.1,0,0);
				glRotatef(-90,1,0,0);
				glColor3f(1,1,1);
				GLUquadric* hautdublanc = gluNewQuadric();
				gluCylinder(hautdublanc,0.45,0.3,0.25,100,10);
			}
			glPopMatrix();

			glPushMatrix();
			{		//Tête
				glColor3f(0,0,0);
				glTranslatef(0,0.5,0);
				glScalef(1,0.5,1);
				glutSolidSphere(0.3f,200,10);
				glPushMatrix();
				{
					glColor3f(0.2,0.2,0.2);
					glRotatef(90,0,1,0);
					GLUquadric* bec1 = gluNewQuadric();
					gluCylinder(bec1,0.1,0,0.7,100,10);
					glPushMatrix();
					{
						//Coloration orange pour l'entre-bec
						glScalef(1,0.1,1);
						glColor3f(255.0f/255.0f,128.0f/155.0f,0.0f/155.0f);
						GLUquadric* bec2 = gluNewQuadric();
						gluCylinder(bec2,0.12,0,0.7,100,10);
					}
					glPopMatrix();
					//Yeux
					yeux();
					
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		
		glPushMatrix();
		{
			glColor3f(0,0,0);
			glTranslatef(0,1.7,0);
			glPushMatrix();
			{		//Aile Droite
				glTranslatef(0,0,0.325);
				glRotatef(ailesMacronEnMarcheD,0,0,1);
				glRotatef(aileD,-1,0,0);
				glTranslatef(0,-0.7,0);
				glPushMatrix();
				{
					glScalef(0.5,1.4,0.2);
					glutSolidSphere(0.5f,20,10);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();
			{		//Aile Gauche
				glTranslatef(0,0,-0.325);
				glRotatef(ailesMacronEnMarcheG,0,0,1);
				glRotatef(aileG,1,0,0);
				glTranslatef(0,-0.7,0);
				glPushMatrix();
				{
					glScalef(0.5,1.4,0.2);
					glutSolidSphere(0.5f,20,10);
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		{
			glRotatef(90,0,1,0);
			patte(-30);
			patte(30);
		}
		glPopMatrix();
		
	}
	glPopMatrix();
}

GLvoid Modelisation()
{
	VM_init();

	gluLookAt(cos(look*M_PI/180)*lookeloi*cos(lookh*M_PI/180),sin(lookh*M_PI/180)*lookeloi, sin(look*M_PI/180)*lookeloi*cos(lookh*M_PI/180),0 , 0., 0., 0., 1., 0.);

//BANQUISE
	glTranslatef(0,-1.8,0);
	glPushMatrix();
	{
		glColor3f(102.0f/255.0f, 153.0f/255.0f, 153.0f/255.0f);
		GLUquadric* banquise = gluNewQuadric();
		glBegin(GL_POLYGON);
			glVertex3f(30,0,30);
			glVertex3f(-30,0,30);
			glVertex3f(-30,0,-30);
			glVertex3f(30,0,-30);
		glEnd();
	}
	glPopMatrix();

//PINGU
	glTranslatef(0,0.1,0);
	axes();
	glPushMatrix();
	{
		glTranslatef(xPingu,0,yPingu);
		glRotatef(corpsPingu,0,1,0);
		manchot(aileDPingu, aileGPingu, ailesEnMarcheD, ailesEnMarcheG);
	}
	glPopMatrix();

//MUMBLE (HAPPY FEET)
	glTranslatef(0,0,20);
	glPushMatrix();
	{	
		glTranslatef(xMumble,0,yMumble);
		glRotatef(corpsMumble,0,1,0);
		manchot(aileDMumble,aileGMumble,ailesMacronD,ailesMacronG);
		yMumble-=0.1*cos(corpsMumble*(3.1415/180));
		xMumble-=0.1*sin(corpsMumble*(3.1415/180));			//MoonWalk parce qu'il danse
	      	corpsMumble+=2;
		if(mouvementAilesMumble){
			aileDMumble+=2;
			aileGMumble+=2;
			if((aileDMumble>=80) && (aileGMumble>=80))
				mouvementAilesMumble=0;
		}
		else{
			aileDMumble-=2;
			aileGMumble-=2;
			if((aileDMumble<=20) && (aileGMumble<=20))
				mouvementAilesMumble=1;
		}
	}
	glPopMatrix();

//MANCHOT QUI NAGE (Il nage dans l'air)

	glTranslatef(0,5,-40);
	glPushMatrix();
	{	
		glTranslatef(xNageur,0,yNageur);
		glRotatef(corpsNageur,0,1,0);
		glPushMatrix();
		{
			glRotatef(90,1,0,0);	
			glPushMatrix();
				{
					glRotatef(-90,0,1,0);					//Changement par rapport à la fonction manchot
					//corps
					glPushMatrix();
					{		//Blanc de la moitié inférieur du corps
						glTranslatef(0.1,0.05,0);
						glRotatef(-90,1,0,0);
						glColor3f(1,1,1);
						GLUquadric* basducorps = gluNewQuadric();
						gluCylinder(basducorps,0.25,0.45,1,100,10);
						GLUquadric* trouenbas = gluNewQuadric();
						gluCylinder(trouenbas,0.25,0,0,100,10);
					}
					glPopMatrix();
					glPushMatrix();
					{		//Noir du corps (fait avec une sphere allongée)
						glColor3f(0,0,0);
						glTranslatef(0,1,0);
						glScalef(1,2,1);
						glutSolidSphere(0.5f,10,10);

						glPushMatrix();
						{		//Blanc au dessus de la moitié du corps
							glTranslatef(0.1,0,0);
							glRotatef(-90,1,0,0);
							glColor3f(1,1,1);
							GLUquadric* hautdublanc = gluNewQuadric();
							gluCylinder(hautdublanc,0.45,0.3,0.25,100,10);
						}
						glPopMatrix();

						glPushMatrix();
						{		//Tête
							glColor3f(0,0,0);
							glTranslatef(0,0.5,0);
							glScalef(1,0.5,1);
							glutSolidSphere(0.3f,200,10);
							glPushMatrix();
							{
								glColor3f(0.2,0.2,0.2);
								glRotatef(90,0,1,0);				//Changement par rapport à la fonction manchot
								glRotatef(90,-1,0,0);
								GLUquadric* bec1 = gluNewQuadric();
								gluCylinder(bec1,0.1,0,0.7,100,10);
								glPushMatrix();
								{
									//Coloration orange pour l'entre-bec
									glScalef(1,0.1,1);
									glColor3f(255.0f/255.0f,128.0f/155.0f,0.0f/155.0f);
									GLUquadric* bec2 = gluNewQuadric();
									gluCylinder(bec2,0.12,0,0.7,100,10);
								}
								glPopMatrix();
								//Yeux
								yeux();
					
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
		
					glPushMatrix();
					{
						glColor3f(0,0,0);
						glTranslatef(0,1.7,0);
						glPushMatrix();
						{		//Aile Droite
							glTranslatef(0,0,0.325);
							glRotatef(aileDNageur,-1,0,0);
							glTranslatef(0,-0.7,0);
							glPushMatrix();
							{
								glRotatef(90,0,1,0);				//Changement par rapport à la fonction manchot
								glScalef(0.5,1.4,0.2);
								glutSolidSphere(0.5f,20,10);
							}
							glPopMatrix();
						}
						glPopMatrix();
						glPushMatrix();
						{		//Aile Gauche
							glTranslatef(0,0,-0.325);
							glRotatef(aileGNageur,1,0,0);
							glTranslatef(0,-0.7,0);
							glPushMatrix();
							{
								glRotatef(90,0,1,0);				//Changement par rapport à la fonction manchot
								glScalef(0.5,1.4,0.2);
								glutSolidSphere(0.5f,20,10);
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
					glPopMatrix();
					glPushMatrix();
					{
						glRotatef(90,0,1,0);
						patte(-30);
						patte(30);
					}
					glPopMatrix();
		
				}
				glPopMatrix();
		}
		glPopMatrix();
		yNageur+=0.1*cos(corpsNageur*(3.1415/180));
		xNageur+=0.1*sin(corpsNageur*(3.1415/180));
	      	corpsNageur+=2;
		if(mouvementAilesNageur){
			aileDNageur+=2;
			aileGNageur+=2;
			if((aileDNageur>=80) && (aileGNageur>=80))
				mouvementAilesNageur=0;
		}
		else{
			aileDNageur-=2;
			aileGNageur-=2;
			if((aileDNageur<=20) && (aileGNageur<=20))
				mouvementAilesNageur=1;
		}
	}
	glPopMatrix();


	glutSwapBuffers();
}

int main(int argc, char **argv) 
{
	return notre_init(argc, argv, &Modelisation);
}
