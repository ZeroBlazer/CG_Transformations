#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "polygon.h"

static GLfloat spin = 0.0;
int width = 640,
    height = 480,
    m_act_x0 = 0,
    m_act_y0 = 0,
    m_act_xf = 0,
    m_act_yf = 0;

Polygon myPol;

enum Action {
    None,
    Scale,
    Rotate,
    Translate
};

Action myAction(None);

bool actionEnabled() {
    return myAction != None;
}

void performAction() {
    int dMx = m_act_xf - m_act_x0,
        dMy = m_act_y0 - m_act_yf;
    switch (myAction)
    {
    case Scale:
        myPol.scale(dMx*1.0/100, dMy*1.0/100);
        break;
    case Rotate:
        break;
    case Translate:
        myPol.translate(dMx, dMy);
        break;
    default:
        break;
    }
    cout << "dx: " << dMx << "\tdy: " << dMy << endl; 
}

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void drawPolygon(void) {
    if(!myPol.isClosed()) {
        float   p0_x = 0.0,
                p0_y = 0.0,
                pN_x = 0.0,
                pN_y = 0.0;
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
            auto it_end = myPol.vertices.end();
            for(auto it = myPol.vertices.begin(); it != it_end; ++it) {
                p0_x = it->x;
                p0_y = it->y;
                pN_x = (it+1)!=it_end?(it+1)->x:myPol.vertices.begin()->x;
                pN_y = (it+1)!=it_end?(it+1)->y:myPol.vertices.begin()->y;
                glVertex3f(p0_x*1.0, p0_y*1.0, 0.0f);
                glVertex3f(pN_x*1.0, pN_y*1.0, 0.0f);
            }
        glEnd();
   }
   else {
        float   p0_x = 0.0,
                p0_y = 0.0;
        glColor4f(0.7f, 0.7f, 1.0f, 0.9f);
        glBegin(GL_POLYGON);
            auto it_end = myPol.vertices.end();
            for(auto it = myPol.vertices.begin(); it != it_end; ++it) {
                p0_x = it->x;
                p0_y = it->y;
                glVertex3f(p0_x*1.0, p0_y*1.0, 0.0f);
            }
        glEnd();
   }
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   glPushMatrix();            
   glRotatef(spin, 0.0, 0.0, 1.0);
   drawPolygon();

   glPopMatrix();
   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
//    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//   glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
   glOrtho(-width/2.0, width/2.0, -height/2.0, height/2.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                if(!myPol.isClosed()) {
                    myPol.addVertex(x - width/2, height/2 - y);
                    break;
                }
                if(actionEnabled()) {
                    m_act_x0 = x;
                    m_act_y0 = y;
                    break;
                }
            }
            if(state == GLUT_UP && actionEnabled()) {
                m_act_xf = x;
                m_act_yf = y;
                performAction();
            }
            //  glutIdleFunc(spinDisplay);
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                myPol.close();
                // glutIdleFunc(NULL);
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                // glutIdleFunc(NULL);
         break;
      default:
         break;
   }
   glutPostRedisplay();
}

/* 
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */

void keyboard(unsigned char key, int x, int y)
{
    switch(key) 
    {
        case 'e':
        case 'E':
            if(myPol.isClosed()) {
                cout << "scaling!" << endl;
                myAction = Scale;
            }
            else
                cout << "Close the polygon by right-clicking the screen" << endl;
            break;
        case 'r':
        case 'R':
            if(myPol.isClosed()) {
                cout << "rotating!" << endl;
                myPol.rotate(1.5);
                myAction = Rotate;
            }
            else
                cout << "Close the polygon by right-clicking the screen" << endl;
            break;
        case 't':
        case 'T':
            if(myPol.isClosed()) {
                cout << "translating!" << endl;
                myAction = Translate;
            }
            else
                cout << "Close the polygon by right-clicking the screen" << endl;
            break;
        case 'w':
        case 'W':
            if(myPol.isClosed()) {
                myAction = None;
            }
            else
                cout << "Close the polygon by right-clicking the screen" << endl;
            break;
        case 27: // escape
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (width, height); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();

   return 0;
}