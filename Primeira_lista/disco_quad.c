#include <GL/glew.h>
#include <GL/freeglut.h>

char estado_Triang = -1;

void desenhaTriangulo()
{
	glColor3f(0.0, 0.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glLineWidth(1.5f);

	glBegin(GL_TRIANGLE_STRIP);

		glVertex2f(20, 20);
		glVertex2f(60, 10);
		glVertex2f(10, 10);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

		glVertex2f(60, 10);
		glVertex2f(50, 20);
		glVertex2f(60, 60);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

		glVertex2f(60, 60);
		glVertex2f(50, 50);
		glVertex2f(10, 60);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

		glVertex2f(10, 60);
		glVertex2f(20, 50);
		glVertex2f(10, 10);

	glEnd();
}

void desenhaQuadrado()
{
	glLineWidth(2.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(0.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

		glVertex2f(10, 10);
		glVertex2f(60, 10);
		glVertex2f(60, 60);
		glVertex2f(10, 60);

	glEnd();

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);

		glVertex2f(20, 20);
		glVertex2f(50, 20);
		glVertex2f(50, 50);
		glVertex2f(20, 50);

    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glColor3f(0.0, 0.5, 0.5);

	glBegin(GL_POLYGON);

		glVertex2f(10, 10);
		glVertex2f(60, 10);
		glVertex2f(60, 60);
		glVertex2f(10, 60);

	glEnd();

	glColor3f(0.0, 0.5, 0.5);

	glBegin(GL_POLYGON);

		glVertex2f(20, 20);
		glVertex2f(50, 20);
		glVertex2f(50, 50);
		glVertex2f(20, 50);

    glEnd();
}

void desenhaMinhaCena()
{
	glClear(GL_COLOR_BUFFER_BIT);

	desenhaQuadrado();

	if(estado_Triang == 1)
		desenhaTriangulo();

	glFlush();
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
	glOrtho(0.0, 70.0, 0.0, 70.0, -1.0, 1.0);

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

		case 'c':
		case 'C':
			estado_Triang *= -1;
			glutPostRedisplay();
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

	glutCreateWindow("Discos quadrados");

	glutDisplayFunc(desenhaMinhaCena);
	glutReshapeFunc(redimensionada);
	glutKeyboardFunc(teclaPressionada);

	setup();

	glutMainLoop();
	return 0;
}