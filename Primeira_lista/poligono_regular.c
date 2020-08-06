#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>

int numLados = 3;

void desenhaMinhaCena()
{
	float t, aux = 0;

	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glLineWidth(3.0f);

	glColor3f(0.0, 0.5, 0.5);

	t = (2 * (M_PI) / numLados);
	aux = t;

	glBegin(GL_POLYGON);

		for(int i = 1; i <= numLados; i ++)
		{
			glVertex2f(20 + (10 * cos(t) ), 20 + (10 * sin(t) ) ) ;
			t += aux;
		}

    glEnd();

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
	glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);

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

		case 45:
			if(numLados > 3)
				numLados --;

			glutPostRedisplay();
			break;

		case 43:
			numLados ++;

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

	glutCreateWindow("Poligono regular");

	glutDisplayFunc(desenhaMinhaCena);
	glutReshapeFunc(redimensionada);
	glutKeyboardFunc(teclaPressionada);

	setup();

	glutMainLoop();
	return 0;
}