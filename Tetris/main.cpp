#include <iostream>
#include <GL/glut.h>

#define TIMER_ID 0
#define TIMER_INTERVAL 50
#define DELTA_TIME 10

#include "MatrixFigureT.h"
#include "MatrixFigureCube.h"
#include "TetrisMatrix.h"
#include "TetrisVisual.h"

using namespace std;

/*
    TO DO :
     - IMPLEMENTIRAJ SINGLTON ZA TETRIS MATRIX
     - IMPLEMENTIRAJ SINGLTON ZA MATRIX FIGURE
*/

TetrisMatrix matrix;
TetrisVisual tetris;
MatrixFigure* figure;

int animation_ongoing;
int delta_time;
bool max_speed;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);

	animation_ongoing = 0;
    delta_time = DELTA_TIME;
    max_speed = false;

    figure = new MatrixFigureCube(matrix, tetris);
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

void on_timer(int value){
    if(value!=TIMER_ID)
      return;

    if( max_speed )
        delta_time = 0;

    if( delta_time-- == 0 )
    {
        if( ! figure->move_down() )
            {
                delete figure;
                figure = new MatrixFigureCube(matrix, tetris);
                max_speed = false;
            }

        delta_time = DELTA_TIME;
    }

    glutPostRedisplay();
    if(animation_ongoing)
      glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
  }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    figure->draw();
    tetris.draw();

	glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
    case 'p' : case 'P' :
        if(!animation_ongoing)
        {
          animation_ongoing = 1;
          glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        } else
            animation_ongoing = 0;
        break;
    case 27:
        exit(0); // Exit the application if 'Esc' key is pressed
	}
}

void special(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP:
		    figure->rotate_figure(); break;
		case GLUT_KEY_DOWN :
            max_speed = true;
                break;
        case GLUT_KEY_LEFT :
            figure->move_left(); break;
        case GLUT_KEY_RIGHT:
            figure->move_right(); break;
        }
}

void animate() {
	glutPostRedisplay();
}

int main(int argc, char * argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutCreateWindow (argv[0]);

    init();

    glutKeyboardFunc    (keyboard);
    glutDisplayFunc     (display );
    glutReshapeFunc     (reshape );
    glutSpecialFunc     (special );
    glutIdleFunc        (animate );

    glutMainLoop();

    return 0;
}
