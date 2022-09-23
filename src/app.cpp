#include <GL/glut.h>
#include <unistd.h>
#include "Line.h"
//Variables globales
float radio = 20;
int xG=50, yG=250;


 void dibujaCirculo(){
    puntoMedio(xG,yG,xG-20,yG);
    puntoMedio(xG,yG,xG+20,yG);
    puntoMedio(xG,yG,xG,yG+20);
    puntoMedio(xG,yG,xG,yG-20);
    puntoMedio(xG,yG,xG+20,yG+20);
    puntoMedio(xG,yG,xG-20,yG-20);
    puntoMedio(xG,yG,xG+20,yG-20);
    puntoMedio(xG,yG,xG-20,yG+20);
}

void display()
{
    //codigo para dibujar objetos
    glClear(GL_COLOR_BUFFER_BIT);
    dibujaCirculo();

    //codigo para act. variables control
    if(xG > 499)
        xG=0;
    else
        xG+=10;
    glFlush();
    usleep(1);
}


void init()
{
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 499, 0, 499);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500); /* ventana 500x500 pixeles */
    glutInitWindowPosition(0,0); /* coloca la ventana de despliegue en esq. sup. izq */
    glutCreateWindow("Movimiento"); /* título de la ventana*/
    init(); /* fija o establece los atributos */
    glutDisplayFunc(display); /*llama a la funcion display cuando se abre la ventana */
    glutIdleFunc(display);
    glutMainLoop(); /* entra a un ciclo de evento */
}
