#include "lumiere.h"
void lumiere() {
  GLfloat LightAmbient[] = { 1.0f, 0.75f, 0.7f, 0.75f };
  GLfloat LightDiffuse[] = { 0.0f, 0.9f, 0.9f, 1.0f };
  GLfloat LightSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
  GLfloat LightPosition[] = { 0.0f, 5.0f, 25.0f, 1.0f };
  GLfloat LightDirection[] = { 0.0f, 1.0f, 1.0f, 1.0f };

  glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);
  glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);
  glEnable(GL_LIGHT1);
}


