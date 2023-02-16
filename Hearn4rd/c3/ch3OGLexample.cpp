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
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);//二维坐标系
}

//绘画回调函数
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
    // glut初始化
    glutInit(&argc, argv);                         // Initialize GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode.
    glutInitWindowPosition(50, 100);               // 窗口起始位置 左 上
    glutInitWindowSize(400, 300);                  // 窗口 宽 高
    glutCreateWindow("An Example OpenGL Program"); // Create display window.

    errorCheck();
    init();                       // Execute initialization procedure. 背景，坐标初始化
    
    glutDisplayFunc(lineSegment); // Send graphics to display window. 具体的显示
    glutMainLoop();               // Display everything and wait.
}
