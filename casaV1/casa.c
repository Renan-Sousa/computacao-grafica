/* X compile line: cc -o simple simple.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm */

#include <GL/glut.h>
#include <math.h>

void
reshape(int w, int h)
{
  glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
  glMatrixMode(GL_PROJECTION);  /* Start modifying the projection matrix. */
  glLoadIdentity();             /* Reset project matrix. */
  glOrtho(0, w, 0, h, -1, 1);   /* Map abstract coords directly to window coords. */
  glScalef(1, -1, 1);           /* Invert Y axis so increasing Y goes down. */
  glTranslatef(0, -h, 0);       /* Shift origin up to upper-left corner. */
}  

float paredesF1 = 0.204;
float paredesF2 = 0.439;
float paredesF3 = 0.729;
 
void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
    glColor3f(1,1,1); 
    glVertex2i(0, 0);
    glColor3f(1,1,1); 
    glVertex2i(0, 1000);
    glColor3f(1,1,1);  
    glVertex2i(1000, 1000);
    glColor3f(1,1,1);
    glVertex2i(1000, 0);
  glEnd();

//frente 
  glBegin(GL_QUADS);
    glColor3f(paredesF1, paredesF2, paredesF3); 
    glVertex2i(0, 600);
    glColor3f(paredesF1, paredesF2, paredesF3); 
    glVertex2i(400, 600);
    glColor3f(paredesF1, paredesF2, paredesF3);  
    glVertex2i(400, 1000);
    glColor3f(paredesF1, paredesF2, paredesF3);
    glVertex2i(0, 1000);
  glEnd();

// triangulo
  glBegin(GL_TRIANGLES);
    glColor3f(paredesF1, paredesF2, paredesF3);
    glVertex2i(0, 600);
    glColor3f(paredesF1, paredesF2, paredesF3); 
    glVertex2i(400, 600);
    glColor3f(paredesF1, paredesF2, paredesF3);  
    glVertex2i(200, 400);
  glEnd();

// parede lateral
  glBegin(GL_QUADS);
    glColor3f(0.227,0.459,0.741);  /* blue */
    glVertex2i(400, 600);
    glColor3f(0.227,0.459,0.741);  /* ? */
    glVertex2i(1000, 600);
    glColor3f(0.227,0.459,0.741);  /* green */
    glVertex2i(1000, 1000);
    glColor3f(0.227,0.459,0.741);  /* red */
    glVertex2i(400, 1000);
  glEnd();

//telhado
/*
R: 0.169
G: 0.165
B: 0.165
*/
  glBegin(GL_QUADS);
    glColor3f(0.169, 0.165, 0.165);  /* blue */
    glVertex2i(200, 400);
    glColor3f(0.169, 0.165, 0.165);  /* ? */
    glVertex2i(400, 600);
    glColor3f(0.169, 0.165, 0.165);  /* green */
    glVertex2i(1000, 600);
    glColor3f(0.169, 0.165, 0.165);  /* red */
    glVertex2i(800, 400);
  glEnd();

// chamine
  glBegin(GL_QUADS);
    glColor3f(0.380, 0.376, 0.369);  /* blue */
    glVertex2i(350, 400);
    glColor3f(0.380, 0.376, 0.369);  /* ... */
    glVertex2i(450, 400);
    glColor3f(0.380, 0.376, 0.369);  /* green */
    glVertex2i(450, 300);
    glColor3f(0.380, 0.376, 0.369);  /* red */
    glVertex2i(350, 300);
  glEnd();

// porta
  glBegin(GL_QUADS);
    glColor3f(0.251, 0.094, 0.012);  /* blue */
    glVertex2i(110, 1000);
    glColor3f(0.251, 0.094, 0.012);  /* ... */
    glVertex2i(290, 1000);
    glColor3f(0.251, 0.094, 0.012);  /* green */
    glVertex2i(290, 700);
    glColor3f(0.251, 0.094, 0.012);  /* red */
    glVertex2i(110, 700);
  glEnd();

// janelas
  glBegin(GL_QUADS);
    glColor3f(0,0,0); 
    glVertex2i(497, 722);
    glColor3f(0,0,0); 
    glVertex2i(497, 878);
    glColor3f(0,0,0);  
    glVertex2i(653, 878);
    glColor3f(0,0,0);  
    glVertex2i(653, 722);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0.847, 0.894, 0.914); 
    glVertex2i(500, 725);
    glColor3f(0.847, 0.894, 0.914); 
    glVertex2i(500, 875);
    glColor3f(0.847, 0.894, 0.914);  
    glVertex2i(650, 875);
    glColor3f(0.847, 0.894, 0.914);  
    glVertex2i(650, 725);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0,0,0); 
    glVertex2i(747, 722);
    glColor3f(0,0,0); 
    glVertex2i(747, 878);
    glColor3f(0,0,0);  
    glVertex2i(903, 878);
    glColor3f(0,0,0);  
    glVertex2i(903, 722);
  glEnd();

  glBegin(GL_QUADS);
    glColor3f(0.847, 0.894, 0.914); 
    glVertex2i(750, 725);
    glColor3f(0.847, 0.894, 0.914); 
    glVertex2i(750, 875);
    glColor3f(0.847, 0.894, 0.914);  
    glVertex2i(900, 875);
    glColor3f(0.847, 0.894, 0.914);  
    glVertex2i(900, 725);
  glEnd();

float theta;
// Maçaneta
  glBegin(GL_POLYGON);
    glColor3f(0.831,0.686,0.216);
    float raioXM = 10.0;
    float raioYM = 10.0; 
    for (int i = 0; i < 360; i++)
    {
      theta=i*3.141592/180;
      glVertex2f(260+raioXM*cos(theta),850+raioYM*sin(theta));
    }
  glEnd();

//Janela circular
  glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    float raioXJ = 58.0;
    float raioYJ = 58.0;  
    for (int i = 0; i < 360; i++)
    {
      theta=i*3.141592/180;
      glVertex2f(200+raioXJ*cos(theta),550+raioYJ*sin(theta));
    }
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(0.847, 0.894, 0.914);
    raioXJ = 55.0;
    raioYJ = 55.0;  
    for (int i = 0; i < 360; i++)
    {
      theta=i*3.141592/180;
      glVertex2f(200+raioXJ*cos(theta),550+raioYJ*sin(theta));
    }
  glEnd();

///////////////////////////////////////////////////////////////////////////////
// fumaça
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        float raioXN = 30.0;
        float raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(400+raioXN*cos(theta),250+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(430+raioXN*cos(theta),240+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(420+raioXN*cos(theta),210+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(400+raioXN*cos(theta),220+raioYN*sin(theta));
        }
    glEnd();
    //////////////////////////////////////////////////////////////////////
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(580+raioXN*cos(theta),170+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(560+raioXN*cos(theta),160+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(570+raioXN*cos(theta),140+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(590+raioXN*cos(theta),140+raioYN*sin(theta));
        }
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.518, 0.533, 0.518);
        raioXN = 30.0;
        raioYN = 30.0;  
        for (int i = 0; i < 360; i++)
        {
        theta=i*3.141592/180;
        glVertex2f(600+raioXN*cos(theta),160+raioYN*sin(theta));
        }
    glEnd();
///////////////////////////////////////////////////////////////////////////////////
//Detalhes
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(500, 798.5);
        glColor3f(0,0,0); 
        glVertex2i(500, 801.5);
        glColor3f(0,0,0);  
        glVertex2i(650, 801.5);
        glColor3f(0,0,0);  
        glVertex2i(650, 798.5);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(750, 798.5);
        glColor3f(0,0,0); 
        glVertex2i(750, 801.5);
        glColor3f(0,0,0);  
        glVertex2i(900, 801.5);
        glColor3f(0,0,0);  
        glVertex2i(900, 798.5);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(823.5, 725);
        glColor3f(0,0,0); 
        glVertex2i(823.5, 875);
        glColor3f(0,0,0);  
        glVertex2i(826.5, 875);
        glColor3f(0,0,0);  
        glVertex2i(826.5, 725);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(573.5, 725);
        glColor3f(0,0,0); 
        glVertex2i(573.5, 875);
        glColor3f(0,0,0);  
        glVertex2i(576.5, 875);
        glColor3f(0,0,0);  
        glVertex2i(576.5, 725);
    glEnd();

    ////////////////////////////////////////
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(198.5, 495);
        glColor3f(0,0,0); 
        glVertex2i(201.5, 495);
        glColor3f(0,0,0);  
        glVertex2i(201.5, 605);
        glColor3f(0,0,0);  
        glVertex2i(198.5, 605);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0,0,0); 
        glVertex2i(145, 548.5);
        glColor3f(0,0,0); 
        glVertex2i(145, 551.5);
        glColor3f(0,0,0);  
        glVertex2i(255, 551.5);
        glColor3f(0,0,0);  
        glVertex2i(255, 548.5);
    glEnd();
  glFlush();  /* Single buffered, so needs a flush. */
}

void
meuTeclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
    }
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Uma casa muito engracada");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(meuTeclado);
  glutMainLoop();
  return 0;      
}
