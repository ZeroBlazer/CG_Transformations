#include <GL/glut.h>
#include <vector>
#include <iostream>

using namespace std;

GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f;

GLint ancho, alto;

int hazPerspectiva = 0;

// Polygon mypol;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(hazPerspectiva)
        gluPerspective(60.0f, (GLfloat)width/(GLfloat)height,1.0f,20.0f);
    else
        glOrtho(-4, 4, -4, 4, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}

// void drawPolygon() {
//     glColor3f(1.0f, 0.0f, 0.0f);
//     for(int i = 0; i < mypol.size(); ++i) {
        
//     }
// }

void drawCube(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //cara frontal
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        glVertex3f(-2.0f, -1.0f, 1.0f);
        glVertex3f( 2.0f, -1.0f, 1.0f);
        glVertex3f( 2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS); //cara trasera
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f( 1.0f, 0.0f, -1.0f);
        glVertex3f( 1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        glVertex3f(-2.0f, -1.0f, -1.0f);
        glVertex3f( 2.0f, -1.0f, -1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);
        glVertex3f( 2.0f, 0.0f, -1.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); //cara lateral izq
        glVertex3f(-2.0f, -1.0f, -1.0f);
        glVertex3f(-2.0f, -1.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);

        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS); //cara lateral dcha
        glVertex3f( 2.0f, 0.0f, 1.0f);
        glVertex3f( 2.0f, 0.0f, -1.0f);
        glVertex3f( 2.0f, -1.0f, -1.0f);
        glVertex3f( 2.0f, -1.0f, 1.0f);

        glVertex3f( 1.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, 0.0f, -1.0f);
        glVertex3f( 1.0f, 1.0f, -1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //cara arriba
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);

        glVertex3f(2.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); //cara abajo
        glVertex3f( 2.0f, -1.0f, -1.0f);
        glVertex3f( 2.0f, -1.0f, 1.0f);
        glVertex3f(-2.0f, -1.0f, 1.0f);
        glVertex3f(-2.0f, -1.0f, -1.0f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
    drawCube();

    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);
    glTranslatef(3.0f, 0.0f, 0.0f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireSphere(0.5f, 8, 8);
    
    glFlush();
    glutSwapBuffers();
    
    anguloCuboX+=0.1f;
    anguloCuboY+=0.1f;
    anguloEsfera+=0.2f;
}

void init()
{
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 640;
    alto = 640;
}

void idle()
{
    display();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) 
    {
        case 'p':
        case 'P':
            hazPerspectiva=1;
            reshape(ancho,alto);
            break;
        case 'o':
        case 'O':
            hazPerspectiva=0;
            reshape(ancho,alto);
            break;
        case 27: // escape
            exit(0);
            break;
    }
}

void mouse(int button, int state, int x, int y) {
    int b;
    switch(button) {
        case GLUT_LEFT_BUTTON:   break;
        case GLUT_MIDDLE_BUTTON: break;
        case GLUT_RIGHT_BUTTON:  break;
    }

    // if(mouse_status & MB_PRESSED(b) && GLUT_UP == state) {
    //     mouse_status |= MB_CLICKED(b);
    // }
    // if(!(mouse_status & MB_PRESSED(b)) && GLUT_DOWN == state) {
    //     mouse_status = (mouse_status & ~(0L | MB_CLICKED(b))) | MB_PRESSED(b);
    // }
    
    // if( GLUT_UP == state && GLUT_LEFT_BUTTON == button )
    // {
    //     polys.back().push_back( glm::vec2( x, y ) );
    //     glutPostRedisplay();
    // }
    // if( GLUT_UP == state && GLUT_RIGHT_BUTTON == button )
    // {
    //     polys.back().push_back( polys.back().front() );
    //     polys.push_back( Poly() );
    //     glutPostRedisplay();
    // }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    // mypol.addVertex(12, 10);
    // mypol.addVertex(2, 100);
    // mypol.addVertex(52, 18);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Polygon");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}