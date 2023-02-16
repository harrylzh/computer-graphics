#include <windows.h>
#include <GL/glut.h> // (or others, depending on the system in use)
#include <stdio.h>

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

    glMatrixMode(GL_PROJECTION); // Set projection parameters.
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);//��ά����ϵ
}

//�滭�ص�����
void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
    glColor3f(0.0, 0.4, 0.2); // Set line segment color to green.

    glBegin(GL_LINES);
    // glVertex2i(180, 15); // Specify line-segment geometry.
    // glVertex2i(10, 145);

    glVertex2i(0, 0); // Specify line-segment geometry.
    glVertex2i(200, 150);
    glEnd();

    glFlush(); // Process all OpenGL routines as quickly as possible.
}

int main(int argc, char **argv)
{
    // glut��ʼ��
    glutInit(&argc, argv);                         // Initialize GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode.
    glutInitWindowPosition(50, 100);               // ������ʼλ�� �� ��
    glutInitWindowSize(400, 300);                  // ���� �� ��
    glutCreateWindow("An Example OpenGL Program"); // Create display window.

    errorCheck();
    init();                       // Execute initialization procedure. �����������ʼ��
    
    glutDisplayFunc(lineSegment); // Send graphics to display window. �������ʾ
    glutMainLoop();               // Display everything and wait.
}
