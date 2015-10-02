#include <iostream>
#include <GL/glut.h>

#include "MatrixFigureT.h"
#include "TetrisMatrix.h"

using namespace std;

/*
    TO DO :
     - IMPLEMENTIRAJ SINGLTON ZA TETRIS MATRIX
     - IMPLEMENTIRAJ SINGLTON ZA MATRIX FIGURE
*/

TetrisMatrix matrix;
MatrixFigureT figure(matrix);

GLfloat mat_ambient[] = {0.5, 0.5, 0.5, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_position[] = {10.0, 10.0, 10.0, 0.0};
GLfloat model_ambient[] = {1.0, 0.5, 0.5, 1.0};

void setupMaterials() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}

void changeColour(GLfloat r, GLfloat g, GLfloat b, GLfloat A) {
	model_ambient[0] = r;
	model_ambient[1] = g;
	model_ambient[2] = b;
	model_ambient[3] = A;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	setupMaterials();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h) {
	GLfloat fAspect;
	if(h==0) h=1;

	glViewport(0,0,w,h);

	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, fAspect, 0.5, 100.0);
	glTranslatef(0,0,-1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void) {
	int slices = 30;
	int stacks = 30;
	float radius = 0.2;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        changeColour(0.0, 0.0, 1.0, 1.0);
        glTranslatef(0.0, 0.0, 0.1);
        glutSolidSphere(radius, slices, stacks);
    glPopMatrix();

	glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
    case 'a' : case 'A' :
        cout << "proba za a" << endl; break;
    case 27:
        exit(0); // Exit the application if 'Esc' key is pressed
	}
}

void special(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
		    figure.move(MatrixFigure::UP); break;
		case GLUT_KEY_DOWN :
            figure.move(MatrixFigure::DOWN); break;
        case GLUT_KEY_LEFT :
            figure.move(MatrixFigure::LEFT); break;
        case GLUT_KEY_RIGHT:
            figure.move(MatrixFigure::RIGHT); break;
        }
}

void animate() {
	glutPostRedisplay();
}

int main(int argc, char * argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutCreateWindow (argv[0]);   init();

    glutKeyboardFunc    (keyboard);
    glutDisplayFunc     (display );
    glutReshapeFunc     (reshape );
    glutSpecialFunc     (special );
    glutIdleFunc        (animate );

    glutMainLoop();

    return 0;
}
