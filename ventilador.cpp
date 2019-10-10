#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

// Leonardo Almeida de Araújo

GLdouble rotacao = 0;
GLdouble helice = 0;
GLdouble helice2 = 90;

int velRotacao = 3;
int velHelice = 8;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);
		
	glPushMatrix();
	glRotatef(rotacao, 0,1,0);
	
	// Helice 1
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0,0,6);
	glRotatef(helice2,0,0,1);
	glScalef(4,45,0);
	glutWireCube(1);
	glPopMatrix();
	
	// Helice 2
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0,0,6);
	glRotatef(helice,0,0,1);
	glScalef(4,45,0);
	glutWireCube(1);
	glPopMatrix();

	// Motor
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glutWireCube(10);
	glPopMatrix();
	
	// Encaixe
	glColor3f(1.0f,0.0f,1.0f);
	glPushMatrix();
	glTranslatef(0,0,6);
	glRotatef(helice, 0,0,1);
	glutWireSphere(4, 20, 20);
	glPopMatrix();
	
	glPopMatrix();
	
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0,-20,0);
	glScalef(5,40,5);
	glutWireCube(1);
	glPopMatrix();
	
	glutSwapBuffers();
}

void configView(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glViewport(0, 0, 800, 600);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, 800/600.0, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h) {
	if (h == 0)
	h = 1;
}

void teclado(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		helice += velRotacao;
		helice2 += velRotacao;
		break;
	case GLUT_KEY_DOWN:
		helice -= velRotacao;
		helice2 -= velRotacao;
		break;
	case GLUT_KEY_LEFT:
		rotacao += velHelice;
		break;
	case GLUT_KEY_RIGHT:
		rotacao -= velHelice;
		break;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
		case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(teclado);
	configView();
	glutMainLoop();
	return 0;
}