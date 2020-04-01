#ifndef __ACTIONS
#define __ACTIONS

/* ascii codes for various special keys */

#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>

#include "touches.h"
#include "switch_blend.h"
#include "switch_light.h"
#include <stdlib.h>

void touche_pressee(unsigned char key, int x, int y);

//sourie
void mouseCB(int button, int state, int x, int y);
void mouseMotionCB(int x, int y);
#endif
