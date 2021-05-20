#include <conio.h>
#include <windows.h>
#include <C:\Users\YOLO\Documents\Zamora Dev. C++\Dev-Cpp\include\GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
//Librerias
using namespace std;
//definimos la svariables parra usar elm algoritmo dda
	int x_1, y_1, x_2, y_2, Pasos;
	int dy, dx;

		int steps = 1;
		int xinc, yinc;
		int Pendiente;
		//DDA funcion que crea la imagen
		//descricpion geometrica de la imagen se va us
		void algoritmoDDA()//contiene
		{
		//P

	Pendiente = (dy * 1.0) + (dx * 1.0);
		Pasos = max(dy, dx);
		glClear(GL_COLOR_BUFFER_BIT); //Con esta funcion el color de la ventana
		glColor3f(1,1,1);//Establecer color de objeto
		glLoadIdentity();

		//Plano Cartesiano
		glLineWidth(5.0);
		glColor3f(0.0471,  0.7176, 0.949); //sky blue
		glBegin(GL_LINES);
		        glVertex2d(-20, 0);
		        glVertex2d(20, 0);
                glVertex2d(0, 20);
                glVertex2d(0, -20);
			glEnd();

  //lineas cuadriculadas
  glLineWidth (2.0);
  glColor3f(0, 2, 1);
  glBegin(GL_LINES);

        for(int j = 21; j > -20; j--){ //Lineas horizontales
            glVertex2f(-20, j + 0.5);
            glVertex2f(20, j + 0.5);
		}
		for(int j = 21; j > -20; j--)//Lineas verticales
		{
         glVertex2f( j + 0.5 , -20);
            glVertex2f( j + 0.5, 20);

			}
		glEnd();

		glPointSize(18); //Se define el tamaño del pixel
		glBegin(GL_POINTS); //GL_POINTS es el tipo de primitiva grefica que se
		        glColor3f(1.0, 1.0, 0.0);
		        glVertex3f(0.0f, 0.0f, 0.0f);//El origen
		        glColor3f(4, 0.788, 0.41);


				int x = x_1;
				int y = y_1;

            	dy = y_2 - y_1;
				dx = x_2 - x_1;
				int p = (2 * dy) - dx;
		for(int i = x; i <= x_2 ; i++){

	    if(dx > dy){
		steps = dx;

	}else{
    steps = dy;
	}
			xinc = dx/ steps;
			yinc = dy/ steps;

            float xi = x_1 * 1.0;
	        float yi = y_1 * 1.0;

            glVertex2d( round (x), round (y));
             x++;
	    	if(p < 0){
			p = p + 2 * dy;
		}else{

            p = p + (2 * dy) - (2 * dx);
			 y++;
		
			printf( " %d\n", x );

        printf (" %d\n" ,y );
        //printf( "\n" );
        printf (" %d\n" ,dy );

        printf( " %d\n", dx );

        printf (" %d\n" ,dy );

        printf (" %d\n" ,xinc );

        printf (" %d\n" ,yinc );


	}
	
	
}
			
		 glEnd();
        glLineWidth(0.000001);
           glVertex2d(x_1 * 1.0, y_1 * 1.0);
            glVertex2d(x_2 * 1.0, y_2 * 1.0);

		glEnd();
		glFlush(); //Procesa todas las subrutinas de opneGl

			}
		void Init(){
			glClearColor(1, 1,1, 0); //Color de pantalla en blanco
		}

		void reshape(int width, int height)
		{
			glViewport(0, 0, width, height);
			glMatrixMode(GL_PROJECTION);//Tipo de proyeccion
			glLoadIdentity(); //Asignar la matriz identidad como de proyecto
			glOrtho (-20, 20, -20, 20, -1, 1);//SSe debe de usar una proyeccion or
			//objeto definidos dentro de este rango, se mostraran en la pantalla
			glMatrixMode(GL_MODELVIEW);
		}

		int main(int argc, char * argv[]){
            system ("color e8");
		//  Leer  los punto inicial y final de la recta a graficar
		cout << "HOLA!!! favor de ingresar los valores correspondientes :) " << endl ;
		cout << "Ingrese X1: " ; cin >> x_1;
		cout << "Ingrese Y1: " ; cin >> y_1;
		cout << "Ingrese X2: " ; cin >> x_2;
		cout << "Ingrese Y2: " ; cin >> y_2;

		glutInit(&argc, argv); //Realizar inclinacion el clut
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//NUMERO DE BUFFERS
		glutInitWindowSize(800, 800);//establece la altura y la anchura del pixel
		glutCreateWindow("Algoritmo DDA"); //Crea un aventana de visualizacion
		Init();//Ejecuta el procedimiento de inicialización
		glutDisplayFunc(algoritmoDDA);//Asigna la imagen a la ventana de visualizacion
		//especifica que va a contener la bventana de visualizacion
		//envia los graficos a la ventana de vis
		glutReshapeFunc(reshape);//Cambio de tamaño de la ventana actual
		glutMainLoop();//Con esta funcion las ventanas  que hayan creado
		//muestra los graficos iniciales y los pones en un bucle infinito
		//Muestra todo y espera
		
		return 0;
}
