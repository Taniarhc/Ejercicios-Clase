//Semestre 2017 - 2
//************************************************************//
//*************** Practica 2**********//
//************** Alumna: Heredia Córdova Tania Rocío**//
//*************	Visual Studio 2017										******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview


//Poner aqui codigo ha dibujar

glBegin(GL_QUADS);
//glPointSize(20.0f);
//C
glColor3f(0.1, 1, 0.7);
glVertex3f(-8.0f, -2.0f, -1.0f);
glVertex3f(-5.5f, -2.0f, -1.0f);
glVertex3f(-5.5f, -1.5f, -1.0f);
glVertex3f(-8.0f, -1.5f, -1.0f);

glVertex3f(-8.0f, -1.5f, -1.0f);
glVertex3f(-7.5f, -1.5f, -1.0f);
glVertex3f(-7.5f, 1.5f, -1.0f);
glVertex3f(-8.0f, 1.5f, -1.0);

glVertex3f(-8.0f, 1.5f, -1.0f);
glVertex3f(-5.5f, 1.5f, -1.0f);
glVertex3f(-5.5f, 2.0f, -1.0f);
glVertex3f(-8.0f, 2.0f, -1.0f);

//G
glColor3f(0.2, 0.2, 1.0);
glVertex3f(-4.5f, -2.0f, -1.0f);
glVertex3f(-2.0f, -2.0f, -1.0f);
glVertex3f(-2.0f, -1.5f, -1.0f);
glVertex3f(-4.5f, -1.5f, -1.0f);

glVertex3f(-4.5f, -1.5f, -1.0f);
glVertex3f(-4.0f, -1.5f, -1.0f);
glVertex3f(-4.0f, 1.5f, -1.0f);
glVertex3f(-4.5f, 1.5f, -1.0);

glVertex3f(-4.5f, 1.5f, -1.0f);
glVertex3f(-2.0f, 1.5f, -1.0f);
glVertex3f(-2.0f, 2.0f, -1.0f);
glVertex3f(-4.5f, 2.0f, -1.0f);

glVertex3f(-2.5f, -1.5f, -1.0f);
glVertex3f(-2.0f, -1.5f, -1.0f);
glVertex3f(-2.0f, -0.8f, -1.0f);
glVertex3f(-2.5f, -0.8f, -1.0f);

glVertex3f(-3.5f, -0.8f, -1.0f);
glVertex3f(-2.0f, -0.8f, -1.0f);
glVertex3f(-2.0f, -0.3f, -1.0f);
glVertex3f(-3.5f, -0.3f, -1.0f);

//T
glColor3f(1, 0.1, 0.8);
glVertex3f(-1.0f, 1.5f, -1.0f);
glVertex3f(1.5f, 1.5f, -1.0f);
glVertex3f(1.5f, 2.0f, -1.0f);
glVertex3f(-1.0f, 2.0f, -1.0f);

glVertex3f(0.0f, -2.0f, -1.0f);
glVertex3f(0.5f, -2.0f, -1.0f);
glVertex3f(0.5f, 1.5f, -1.0f);
glVertex3f(0.0f, 1.5f, -1.0f);

//H
glColor3f(1, 1, 0);
glVertex3f(2.5f, -2.0f, -1.0f);
glVertex3f(3.0f, -2.0f, -1.0f);
glVertex3f(3.0f, 2.0f, -1.0f);
glVertex3f(2.5f, 2.0f, -1.0f);

glVertex3f(4.5f, -2.0f, -1.0f);
glVertex3f(5.0f, -2.0f, -1.0f);
glVertex3f(5.0f, 2.0f, -1.0f);
glVertex3f(4.5f, 2.0f, -1.0f);

glVertex3f(3.0f, -0.25f, -1.0f);
glVertex3f(4.5f, -0.25f, -1.0f);
glVertex3f(4.5f, 0.25f, -1.0f);
glVertex3f(3.0f, 0.25f, -1.0f);



glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

