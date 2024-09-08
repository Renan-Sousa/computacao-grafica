#include <GL/glut.h>
#include <math.h>

// cc -o casa casaV2.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;


GLfloat cor_ceu_1 = 104.0/255.0;
GLfloat cor_ceu_2 = 196.0/255.0;
GLfloat cor_ceu_3 = 249.0/255.0;

GLfloat cor_grama_1 = 34.0/255.0;
GLfloat cor_grama_2 = 175.0/255.0;
GLfloat cor_grama_3 = 24.0/255.0; 

//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() 
{
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void desenhaTriangulo() 
{
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

//Desenha um círculo de raio 1 centrado na origem
void desenhaCirculo() 
{
    glBegin(GL_POLYGON); 
        for (int i = 0; i < 360; i++) {
            glVertex2f(cos(i), sin(i));
        }
    glEnd();
}

//Faz o cisalhamento de um objeto em relação ao eixo X
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewX(GLfloat angle) 
{
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };
    glMultMatrixf(m);
}

//Faz o cisalhamento de um objeto em relação ao eixo Y
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewY(GLfloat angle) 
{
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(m);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    /* Aqui entra todo o seu código da casa 2D.
    Vocês só pode usar as funções de desenho:
        desenhaQuadrado, desenhaTriangulo, desenhaCirculo
    as transformações geométricas:
        glTranslatef, glRotatef, glScalef, skewX, skewY
    e as funções de cor:
        glColor3f
    Não desenhe nenhuma primitiva utilizando glBegin/glEnd diretamente aqui. */

    
    //FUNDO    
    glPushMatrix();
    glColor3f(cor_ceu_1, cor_ceu_2, cor_ceu_3);
    glTranslatef(0, 175, 0);
    glScalef(1000, 273.5, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(cor_grama_1, cor_grama_2, cor_grama_3);
    glTranslatef(0, 20, 0);
    glScalef(1000, 100, 1);
    desenhaQuadrado();
    glPopMatrix();
    
    //Parede frente
    glPushMatrix();
    glColor3f(0.82, 0.075, 0.0167);
    glTranslatef(120, 90, 1);
    glScalef(90, 90, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Porta
    glPushMatrix();
    glColor3f(0.31, 0.129, 0.012);
    glTranslatef(120, 75, 1);
    glScalef(35, 60, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Maçaneta
    glPushMatrix();
    glColor3f(0.82, 0.631, 0.012);
    glTranslatef(132.5, 75, 1);
    glScalef(2, 2, 1);
    desenhaCirculo();
    glPopMatrix();
// 0.82, 0.075, 0.0167
    //Parede lateral
    glPushMatrix();
    glColor3f(0.82, 0.094, 0.039);
    glTranslatef(245, 90, 1);
    glScalef(160, 90, 1);
    desenhaQuadrado();
    glPopMatrix();

    /* TELHADO */
    glPushMatrix();
    glColor3f(0.82, 0.075, 0.0167);
    glTranslatef(120, 160, 0);
    glScalef(90, 50, 1);
    desenhaTriangulo();
    glPopMatrix();

    //Telhado lateral
    glPushMatrix();
    glColor3f(0.071, 0.067,0.067);
    glTranslatef(222.50, 160, 0);
    skewX(-45*3.141596/180.0f);
    glScalef(170, 50, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.071, 0.067,0.067);
    glTranslatef(95, 160, 0);
    skewX(42*3.141596/180.0f);
    glScalef(10, 50, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Chamine Baixo
    glPushMatrix();
    glColor3f(0.129,0.129,0.118);
    glTranslatef(240, 190, 0);
    glScalef(18, 30, 1);
    desenhaQuadrado();
    glPopMatrix();
    
    //Chamine Cima
    glPushMatrix();
    glColor3f(0.129,0.129,0.118);
    glTranslatef(240, 200, 0);
    glScalef(28, 10, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Janela 1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(215, 90, 0);  
    glScalef(35, 35, 1);
    desenhaQuadrado();
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(0.949,0.882,0.424);
    glTranslatef(215, 90, 0);  
    glScalef(33, 33, 1);
    desenhaQuadrado();
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(215, 90, 0);  
    glScalef(35, 1, 1);
    desenhaQuadrado();
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(215, 90, 0);  
    glScalef(1, 35, 1);
    desenhaQuadrado();
    glPopMatrix(); 
    
    //Janela 2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(275, 90, 0);  
    glScalef(35, 35, 0);
    desenhaQuadrado();
    glPopMatrix(); 
    
    glPushMatrix();
    glColor3f(0.949,0.882,0.424);
    glTranslatef(275, 90, 0);  
    glScalef(33, 33, 0);
    desenhaQuadrado();
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(275, 90, 0);  
    glScalef(35, 1, 1);
    desenhaQuadrado();
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(275, 90, 0);  
    glScalef(1, 35, 1);
    desenhaQuadrado();
    glPopMatrix(); 

    //Janela redonda
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(120, 155, 1);
    glScalef(9, 9, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.949,0.882,0.424);
    glTranslatef(120, 155, 1);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(120, 155, 1);
    glScalef(18, 1, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(120, 155, 1);
    glScalef(1, 18, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Fumaça1
    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(250, 220, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(255, 217, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(260, 225, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(260, 220, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(252, 225, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    //Fumaça2
    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(297, 240, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(305, 240, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(300, 230, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(310, 232, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();
    glPushMatrix();

    glColor3f(0.49, 0.49, 0.455);
    glTranslatef(290, 235, 0);
    glScalef(8, 8, 1);
    desenhaCirculo();
    glPopMatrix();

    //Executa os comandos OpenGL
    glutSwapBuffers();
}

//Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    // Se a largura da janela, em pixels, for menor que a altura, a largura da viewport é fixada em 250 e a altura é escalada para o necessário
    if (w <= h)  {
        windowHeight = 250.0f*h/w;
        windowWidth = 250.0f;
    }
    else  {
    // Se a altura da janela, em pixels, for menor que a largura, a altura da viewport é fixada em 250 e a largura é escalada para o necessário
        windowWidth = 250.0f*w/h;
        windowHeight = 250.0f;
    }

    // As dimensões da janela vão de (0.0, 0.0) até (windowWidth, windowHeight), essas são as coordenadas da tela
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(650,400);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Casa V2");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    return 0;
}