#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int win_id;
double camera_x = 5.0;
double camera_y = 1.5;
double camera_z = 5.0;


//Aqui se capturam as teclas comuns (letras, números e ESC, por exemplo)
void myKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 'D': 
    case 'd':
      camera_z = camera_z + 0.5;
      gluLookAt(camera_x, camera_y, camera_z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
    case 'A': 
    case 'a':
      camera_z = camera_z - 0.5;
      gluLookAt(camera_x, camera_y, camera_z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
    case 27:
     glutDestroyWindow(win_id);
     exit(0);
     break;
  }
  glutPostRedisplay();
}

//Aqui se capturam as teclas especiais (Alt, Control, Shift, F1, F2, etc.)
void myKeyboardSpecial(int key, int x, int y ) {
  switch ( key ) {
    case GLUT_KEY_UP:                   // Quando a seta para cima é teclada...
      glutFullScreen ( );               // Vá para o modo tela cheia...
      break;
    case GLUT_KEY_DOWN:                 // Quando a seta para baixo for teclada...
      glutReshapeWindow ( 640, 480 );   // Vá para modo em janela de 640 por 480
      break;
    default:
      printf("Você apertou a tecla especial código: %d\n", key);  // ...para ajudar você a debugar...       
      break;
  }
}

// Função callback chamada para gerenciar eventos do mouse
void myMouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {
      float r, g, b;
      r = (double)rand() / (double)RAND_MAX;
      g = (double)rand() / (double)RAND_MAX;
      b = (double)rand() / (double)RAND_MAX;
      glColor3f(r,g,b);
      printf("%.2f, %.2f, %.2f\n", r, g, b);
    }
  glutPostRedisplay();
}

void init(void) 
{
  // Define a cor de fundo da janela de visualização como preto
  glClearColor (0.0, 0.0, 0.0, 0.0);
  // Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
  glShadeModel (GL_SMOOTH);
  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);

  //Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

  // Passa os parâmetros definidos acima para a OpenGL
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Habilita a luz ambiente, a luz zero e o depth buffer
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  //Primeira cor, para depois mudarmos com os eventos
  glColor3f(0.5, 1.0, 0.5);
}

void display(void)
{
  // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  // Entra no modo de definição de matriz de visualização
  glMatrixMode(GL_MODELVIEW);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a posição da câmera, para onde ela aponta e qual o vetor UP
  gluLookAt(camera_x, camera_y, camera_z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  

  //Parede
  glPushMatrix();
  glColor3f(0.82, 0.075, 0.0167);
  glTranslatef(0.0, 14.7, 0.0);
  glRotatef(45, 0.0, 0.0, 0.5);
  glScalef(21.35, 21.35, 60);
  glutSolidCube(1.0);
  glPopMatrix();  
  
  glPushMatrix();
  glColor3f(0.82, 0.075, 0.0167);
  glScalef(30,30,60);
  glutSolidCube(1.0);
  glPopMatrix(); 

  //Telhado
  glPushMatrix();
  glColor3f(0.302, 0.294, 0.29);
  glTranslatef(-7.6, 22.5, 0.0);
  glRotatef(45, 0.0, 0.0, 0.5);
  glScalef(21.9, 0.5, 63);
  glutSolidCube(1.0);
  glPopMatrix();  

  glPushMatrix();
  glColor3f(0.302, 0.294, 0.29);
  glTranslatef(7.6, 22.5, 0.0);
  glRotatef(-45, 0.0, 0.0, 0.5);
  glScalef(22, 0.5, 63);
  glutSolidCube(1.0);
  glPopMatrix();  

  //Porta 
  glPushMatrix();
  glColor3f(0.459, 0.188, 0.0);
  glTranslatef(0.0, -5.0, 29.7);
  glScalef(10,20,1);
  glutSolidCube(1.0);
  glPopMatrix(); 

  //Janela direita
  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.52, 0.0, -12.0);
  glScalef(1, 10, 13);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.6, 0.0, -12.0);
  glScalef(1, 10, 0.5);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.6, 0.0, -12.0);
  glScalef(1, 0.5, 13);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.824,0.949,0.949);
  glTranslatef(14.55, 0.0, -12.0);
  glScalef(1, 9, 12);
  glutSolidCube(1.0);
  glPopMatrix(); 

  //Janela esquerda  
  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.52, 0.0, 12.0);
  glScalef(1, 10, 13);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.6, 0.0, 12.0);
  glScalef(1, 10, 0.5);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.31, 0.129, 0.012);
  glTranslatef(14.6, 0.0, 12.0);
  glScalef(1, 0.5, 13);
  glutSolidCube(1.0);
  glPopMatrix(); 

  glPushMatrix();
  glColor3f(0.824,0.949,0.949);
  glTranslatef(14.55, 0.0, 12.0);
  glScalef(1, 9, 12);
  glutSolidCube(1.0);
  glPopMatrix(); 

  //Bola
  glPushMatrix();
  glColor3f(0.82, 0.631, 0.012);
  glTranslatef(3.5, -5.0, 32);
  glutSolidSphere(0.5, 10.0, 10.0);
  glPopMatrix(); 

  //Chaminé
  glPushMatrix();
  glColor3f(0.212, 0.204, 0.2);
  glTranslatef(10.0, 18, -2.0);
  glScalef(4, 20, 4);
  glutSolidCube(1.0);
  glPopMatrix();  

  // Executa os comandos OpenGL, e depois troca os buffers de vídeo
  glFlush();
}

void reshape (int w, int h)
{
  // Define o viewport como o tamanho da janela
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  // Entra no modo de definição de matriz de projeção
  glMatrixMode (GL_PROJECTION);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a projeção ortogonal
  if (w <= h)
    // Se a largura for menor que a altura, a projeção é feita para manter a proporção da janela
    glOrtho (-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
  else
    // Se a altura for menor que a largura, a projeção é feita para manter a proporção da janela
    glOrtho (-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);
   
}

int main(int argc, char** argv)
{
  // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
  glutInit(&argc, argv);
  // Inicializa o display, indicando que usará:
  // - um buffer de imagem (single buffer);
  // - buffer de profundidade;
  // - padrão de cores RGB)
  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  // Especifica as dimensões da janela de exibição
  glutInitWindowSize (500, 500); 
  // Especifica a posição inicial da janela de exibição
  glutInitWindowPosition (100, 100);
  // Cria a janela de exibição
  win_id = glutCreateWindow (argv[0]);
  // Chama a função init
  init ();
  // Estabelece a função "display" como a função callback de exibição.
  glutDisplayFunc(display); 
  // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
  glutReshapeFunc(reshape);
  // Estabelece a função "keyboard" como a função callback de evento de teclado.
  glutKeyboardFunc(myKeyboard);
  // Estabelece a função "keyboardSpecial" como a função callback de evento de teclado especial.
  glutSpecialFunc(myKeyboardSpecial);
  // Estabelece a função "mouse" como a função callback de evento de mouse.
  glutMouseFunc(myMouse);
  // Entra no loop de eventos, não retorna
  glutMainLoop();
  return 0;
}