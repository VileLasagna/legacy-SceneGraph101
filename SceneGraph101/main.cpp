
#define _USE_MATH_DEFINES
#include <cmath>
#include "SceneTeapot.h"
#include <GL/glut.h>


SceneNode* Scene = 0;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(10,10,10,0,0,0,0,1,0);
	//glutSolidTeapot(3);
	Scene->Draw();
	Scene->DrawBox();


    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Hello");
    glutDisplayFunc(Draw);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
	//glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	//glFrontFace(GL_CW);
	//glLineWidth(5);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 1000.0); 

	Scene = new SceneComposite();
	SceneTeapot* TP = new SceneTeapot();
	TP->setTranslation(0,5,0);
	Scene->addChild(TP);
	TP = new SceneTeapot();
	TP->setTranslation(0,-5,0);
	Scene->addChild(TP);
	Scene->CascadeTransform();


    glutMainLoop();
}

