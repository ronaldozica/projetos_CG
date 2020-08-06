#include <GL/glew.h>
#include <GL/freeglut.h>

void desenha_quadrado(int x, int y, float cor[])
{
	glColor3f(cor[0], cor[1], cor[2]);

	glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x + 30, y);
		glVertex2f(x + 30, y + 30);
		glVertex2f(x, y + 30);

	glEnd();

	glFlush();
}

void desenhaMinhaCena()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int x = 10, y = 10, i, j;
	float cor[3];

	cor[0] = 1.0;
	cor[1] = 0.0;
	cor[2] = 0.0;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.0;
	cor[1] = 1.0;
	cor[2] = 0.0;
	x = 50;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.0;
	cor[1] = 0.0;
	cor[2] = 1.0;
	x = 90;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.0;
	cor[1] = 0.0;
	cor[2] = 0.0;
	x = 10;
	y = 50;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.5;
	cor[1] = 0.0;
	cor[2] = 0.5;
	x = 50;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.5;
	cor[1] = 0.5;
	cor[2] = 0.0;
	x = 90;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.0;
	cor[1] = 0.5;
	cor[2] = 0.5;
	x = 10;
	y = 90;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.3;
	cor[1] = 0.5;
	cor[2] = 0.2;
	x = 50;
	desenha_quadrado(x, y, cor);

	cor[0] = 0.4;
	cor[1] = 0.8;
	cor[2] = 0.0;
	x = 90;
	desenha_quadrado(x, y, cor);
}

void setup()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void redimensionada(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 130.0, 0.0, 130.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void teclaPressionada(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(1, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);

	glutCreateWindow("Quadrados coloridos");

	glutDisplayFunc(desenhaMinhaCena);
	glutReshapeFunc(redimensionada);
	glutKeyboardFunc(teclaPressionada);

	setup();

	glutMainLoop();
	return 0;
}