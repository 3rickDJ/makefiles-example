#include <GL/glut.h>
#include <unistd.h>
//Variables globales
float radio = 20;
int xG=50, yG=250;

//Funcion para dibujar un pixel dadas las coordenadas
void dibujarPixel(int ix, int iy)
{
  glBegin(GL_POINTS);
    glVertex2i(ix, iy);
  glEnd();
}

//Recibe las coordenadas de los puntos
    /*
    1er parametro: x1
    2do parametro: y1
    3er parametro: x2
    4to parametro: y2
    */
void puntoMedio(int x1,int y1,int x2,int y2)
{
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;
  //Diferencial en X (Distancia)
  dx = x2 - x1;
  //Diferencial en Y (Distancia)
  dy = y2 - y1;

  //Si la diferencial de x2 - x1 es menor que 0, la diferencial tomara su valor en positivo
  if(dx < 0) dx = -dx;
  //Si la diferencial de y2 - y1 es menor que 0, la diferencial tomara su valor en positivo
  if(dy < 0) dy = -dy;
  incx = 1; //el incremento en x se supone que sera de 1
  //Si el punto 2 en su coordenada x esta a la izquierda del punto 1 en su coordenada x sera decremento en -1
  if(x2 < x1) incx = -1;
  incy = 1; //el incremento en y se supone que sera de 1
  //Si el punto 2 en su coordenada y esta a la izquierda del punto 1 en su coordenada y sera decremento en -1
  if(y2 < y1) incy = -1;

  //Se comenzara a graficar desde el punto 1 (x1,y1)
  x=x1;
  y=y1;

  //Si la distancia entre entre los puntos X's es mayor a la distancia entre los puntos Y's
  if(dx > dy) //Caso 1
    {
      dibujarPixel(x,y); //Se pinta un pixel (vertice en la coordenadas de (x1,y1))
      /*El primer punto medio a ser considerado sera (Xinicial+1, Yinicial +(1/2))*/
      /*Despejando de la formula F(Xinicial + 1, Yinicial +(1/2)) se tiene dy - (dx/2)
      pero para eliminar valores flotantes se multiplica todo por 2*/
      e = 2*dy - dx;
      /*Se obtienen las posibles soluciones
      Enew = Eold + Incremento, donde el Incrento sera
      2*dy si Eold <0
      2*(dy-dx) Si Eold >0*/
      inc1 = 2*(dy -dx);
      inc2 = 2*dy;
      //Lo valores solo se necesitan calcular una vez, ya que el incremento sera el mismo.
      for(i = 0; i < dx; i++)
      {
          //Se opta por dibujar el pixel en el punto medio superior si la recta queda exactamente en el punto medio
         if(e >= 0)
         {
            y += incy;
            e += inc1;
         }
         else e += inc2;
         /*La siguiente coordenada X a ser dibujada sera definida ya sea 1 o -1
         dependiendo la posicion de punto 2 en el eje X */
         x += incx;
         dibujarPixel(x,y);
      }
   }
   else //Si la distancia entre entre los puntos X's es menor a la distancia entre los puntos Y's
   {
      dibujarPixel(x,y);//Se pinta un pixel (vertice en la coordenadas de (x1,y1))
      e = 2*dx - dy;
      inc1 = 2*( dx - dy);
      inc2 = 2*dx;
      for(i = 0; i < dy; i++)
      {
        if(e >= 0)
        {
           x += incx;
           e += inc1;
        }
        else e += inc2;
        /*La siguiente coordenada Y a ser dibujada sera definida ya sea 1 o -1
         dependiendo la posicion de punto 2 en el eje Y */
        y += incy;
        dibujarPixel(x,y);
    }
  }
 }

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
