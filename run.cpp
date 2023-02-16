#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
// #include <stdlib.h>
// #include <math.h>
#include <cstdlib>
#include <cmath>

using namespace std;

inline int xround (const float a)  { return int (a + 0.5); }
void lineDDA (int x0, int y0, int xEnd, int yEnd);

GLenum errorCheck()
{
    GLenum code;
    const GLubyte *string;

    code = glGetError();
    if (code != GL_NO_ERROR)
    {
        string = gluErrorString(code);
        fprintf(stderr, "OpenGL error: %s\n", string);
    }

    return code;
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
    glMatrixMode(GL_PROJECTION);      // Set projection parameters.
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void drawLine(GLdouble sX,GLdouble sY,GLdouble eX,GLdouble eY); // header

void drawLine(GLdouble sX,GLdouble sY,GLdouble eX,GLdouble eY)
{ // body
    glBegin(GL_LINES);
    // glVertex2i(180, 15); // Specify line-segment geometry.
    // glVertex2i(10, 145);
    glVertex2i(sX, sY); // Specify line-segment geometry.
    glVertex2i(eX, eY);
    glEnd();
}

void setPixel(GLdouble x,GLdouble y); // header

void setPixel(GLdouble x,GLdouble y)
{ // body
    glBegin(GL_POINTS);
    glVertex2d(x, y);    
    // glVertex2i(10, 10);    
    glEnd();
    
}

void drawSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
    glColor3f(0.0, 0.4, 0.2);     // Set line segment color to green.

    // drawLine(180,15,10,145);
    lineDDA(180,15,10,145);
    setPixel(20,20);
    setPixel(10,10);

    glFlush(); // Process all OpenGL routines as quickly as possible.
}

void glutInitWindow(); // header

void glutInitWindow()
{
    int width = 400;
    int height = 300;
    int x = 50;
    int y = 100;
    // body
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.

    glutInitWindowPosition(x, y);                  // Set top-left display-window position.
    glutInitWindowSize(width, height);             // Set display-window width and height.
    glutCreateWindow("An Example OpenGL Program"); // Create display window.
}





void lineDDA (int x0, int y0, int xEnd, int yEnd)
{
   int dx = xEnd - x0,  dy = yEnd - y0,  steps,  k;
   float xIncrement, yIncrement, x = x0, y = y0;

   if (fabs (dx) > fabs (dy))
      steps = fabs (dx);
   else
      steps = fabs (dy);
   xIncrement = float (dx) / float (steps);
   yIncrement = float (dy) / float (steps);

   setPixel (xround (x), xround (y));
   for (k = 0; k < steps; k++) {
      x += xIncrement;
      y += yIncrement;
      setPixel (xround (x), xround (y));
   }
}


int main(int argc, char **argv)
{
    cout << "hello world!" << endl;
    glutInit(&argc, argv);

    glutInitWindow();

    errorCheck();
    init(); // Execute initialization procedure.
    glutDisplayFunc(drawSegment);
    glutMainLoop();
    return 0;
}