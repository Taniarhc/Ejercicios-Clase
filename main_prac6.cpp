//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumna: Heredia Córdova Tania Rocío*********************************//
//*************	Practica 6						******//
//*************	Visual Studio 2017									******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int luna1t=0;
int luna1m = 0;
int luna2m = 0;
int luna1j = 0;
int luna2j = 0;
int luna3j = 0;
int anillos1 = 0;
int anillos2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara

	glPushMatrix();//Sistema solar	
		
		glPushMatrix();
			glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glutSolidSphere(1.9,12,12);  //Draw Sun (radio,H,V);
		glPopMatrix();
		glPushMatrix();//Mercurio
			glRotatef(sol * 2, 0, 1, 0);//traslacion
			glTranslatef(3.2,0,0);
			glRotatef(mercurio,0,1,0);//rotación
			glColor3f(0.5,0.5,0.5);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();
		glPushMatrix();//Venus
			glRotatef(sol * 1.5, 0, 1, 0);//traslacion
			glTranslatef(4.7, 0, 0);
			glRotatef(venus, 0, 1, 0);//rotación
			glColor3f(0.8, 0.4, 0.2);
			glutSolidSphere(0.5, 8, 8);
		glPopMatrix();
		glPushMatrix();//tierra
			glRotatef(sol * 1.3, 0, 1, 0);//traslacion
			glTranslatef(6.4, 0, 0);
			glRotatef(tierra, 0, 1, 0);//rotación
			glColor3f(0.5, 0.6, 0.3);
			glutSolidSphere(0.7, 8, 8);
			glPushMatrix();//Luna1T
				glRotatef(tierra * 0.6, 0, 1, 0);//traslacion
				glTranslatef(1.5, 0, 0);
				glRotatef(luna1t, 0, 1, 0);//rotación
				glColor3f(0.5, 0.7, 0.7);
				glutSolidSphere(0.15, 8, 8);
			glPopMatrix();
			glPopMatrix();
		glPushMatrix();//marte
			glRotatef(sol * 2.2, 0, 1, 0);//traslacion
			glTranslatef(7.8, 0, 0);
			glRotatef(marte, 0, 1, 0);//rotación
			glColor3f(1, 0.0, 0.0);
			glutSolidSphere(0.4, 8, 8);
				glPushMatrix();//Luna1M
					glRotatef(marte * 1.5, 0, 1, 0);//traslacion
					glTranslatef(1.3, 0, 0);
					glRotatef(luna1m, 0, 1, 0);//rotación
					glColor3f(0.6, 0.7, 0.6);
					glutSolidSphere(0.2, 8, 8);
				glPopMatrix();
				glPushMatrix();//Luna2M
				glRotatef(marte * 1.1, 0, 1, 0);//traslacion
				glTranslatef(1.2, 0, 0);
				glRotatef(luna2m, 0, 1, 0);//rotación
				glColor3f(0.6, 0.5, 0.6);
				glutSolidSphere(0.1, 8, 8);
				glPopMatrix();
		glPopMatrix();
		glPushMatrix();//jupiter
			glRotatef(sol * 1.7, 0, 1, 0);//traslacion
			glTranslatef(9.8, 0, 0);
			glRotatef(jupiter, 0, 1, 0);//rotación
			glColor3f(0.7, 0.8, 0.9);
			glutSolidSphere(1, 8, 8);
			glPushMatrix();//Luna1j
				glRotatef(jupiter * 1.5, 0, 1, 0);//traslacion
				glTranslatef(1.1, 0, 0);
				glRotatef(luna1j, 0, 1, 0);//rotación
				glColor3f(0.4, 0.5, 0.6);
				glutSolidSphere(0.1, 8, 8);
			glPopMatrix();
			glPushMatrix();//Luna2j
				glRotatef(jupiter * 1.7, 0, 1, 0);//traslacion
				glTranslatef(1.4, 0, 0);
				glRotatef(luna2j, 0, 1, 0);//rotación
				glColor3f(0.4, 0.5, 0.8);
				glutSolidSphere(0.3, 8, 8);
			glPopMatrix();
			glPushMatrix();//Luna3j
				glRotatef(jupiter * 1.2, 0, 1, 0);//traslacion
				glTranslatef(1.6, 0, 0);
				glRotatef(luna3j, 0, 1, 0);//rotación
				glColor3f(0.5, 0.2, 0.8);
				glutSolidSphere(0.2, 8, 8);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//saturno
			glRotatef(sol * 0.8, 0, 1, 0);//traslacion
			glTranslatef(11.7, 0, 0);
			glRotatef(saturno, 0, 1, 0);//rotación
			glColor3f(0.9, 1.0, 0.9);
			glutSolidSphere(0.9, 8, 8);
			glPushMatrix();//saturno
			glRotatef(anillos1, 0, 1, 0);//rotación
			glColor3f(0.6, 0.8, 0.3);
			glRotatef(60, 1, 0, 0);
			glScalef(1, 0.1, 1);
			glutSolidTorus(1.2, 1.4, 5, 5);
			glPopMatrix();
			glPushMatrix();//saturno
			glRotatef(anillos2, 0, 1, 0);//rotación
			glColor3f(0.8, 0.8, 0.5);
			glTranslatef(0, -0.2, 0);
			glRotatef(60, 1, 0, 0);
			glScalef(1, 0.1,1);
			glutSolidTorus(1.4, 1.6, 5, 5);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//urano
			glRotatef(sol * 2.5, 0, 1, 0);//traslacion
			glTranslatef(13.5, 0, 0);
			glRotatef(urano, 0, 1, 0);//rotación
			glColor3f(0.3, 0.9, 1.0);
			glutSolidSphere(0.8, 8, 8);
		glPopMatrix(); 
	glPopMatrix();
	
	
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		mercurio = (mercurio - 1) % 360;
		venus = (venus - 1) % 360;
		tierra = (tierra - 1) % 360;
		marte = (marte - 1) % 360;
		jupiter = (jupiter - 1) % 360;
		saturno = (saturno - 1) % 360;
		urano = (urano - 1) % 360;
		luna1t = (luna1t - 1) % 360;
		luna1m = (luna1m - 1) % 360;
		luna2m = (luna2m - 1) % 360;
		luna1j = (luna1j - 1) % 360;
		luna2j = (luna2j - 1) % 360;
		luna3j = (luna3j - 1) % 360;
		anillos1 = (anillos1 - 1) % 360;
		anillos2 = (anillos2 - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}