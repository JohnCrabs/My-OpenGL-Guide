/************/
/* main.cpp */
/************/

#include <GL/gl.h>
#include <GL/glut.h>

#define drawOneLine(x1, y1, x2, y2) glBegin(GL_LINES); \
    glVertex2f((x1), (y1)); glVertex2f((x2), (y2)); glEnd();

#define MY_WIN_WIDTH 400
#define MY_WIN_HEIGHT 150
#define MY_WIN_POS_X 100
#define MY_WIN_POS_Y 100
#define MY_WIN_TITLE "Lines"

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400.0, 0.0, 150.0, -1.0, 1.0);
}

void display(void) {
    glClear((GL_COLOR_BUFFER_BIT));

    /* select white for all lines */
    glColor3f(1.0, 1.0, 1.0);


    glEnable(GL_LINE_STIPPLE);
    /* int 1st row, 3 lines, each with a different stipple */
    glLineWidth(1.0);
    glLineStipple(1, 0x0101); /* dotted */
    drawOneLine(50.0, 125.0, 150.0, 125.0);
    glLineStipple(1, 0x00FF); /* dashed */
    drawOneLine(150.0, 125.0, 250.0, 125.0);
    glLineStipple(1, 0x1C47); /* dash/dot/dash */
    drawOneLine(250.0, 125.0, 350.0, 125.0);

    /* int 2nd row, 3 wide lines, each with a different stipple */
    glLineWidth(5.0);
    glLineStipple(1, 0x0101); /* dotted */
    drawOneLine(50.0, 100.0, 150.0, 100.0);
    glLineStipple(1, 0x00FF); /* dashed */
    drawOneLine(150.0, 100.0, 250.0, 100.0);
    glLineStipple(1, 0x1C47); /* dash/dot/dash */
    drawOneLine(250.0, 100.0, 350.0, 100.0);

    /* int 3rd row, 6 lines, with dash/dot/dash stipple */
    /* as part of a single connected line strip */
    glLineWidth(1.0);
    glLineStipple(1, 0x1C47); /* dash/dot/dash */
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i < 7; i++)
        glVertex2f(50.0 + ((GLfloat) i * 50.0), 75.0);
    glEnd();

    /* int 4th row, 6 independent lines, with same stipple */
    /* as part of a single connected line strip */
    for(int i = 0; i < 6; i++) {
        drawOneLine(50.0 + ((GLfloat) i * 50.0), 50.0,
                    50.0 + ((GLfloat) (i+1) * 50.0), 50.0);
    }
    /* in the 5th row, 1 line, with dash/dot/dash stipple */
    /* and a stipple repeat factor of 5 */
    glLineStipple(5, 0x1c47); /* dash/dot/dash */
    drawOneLine(50.0, 25.0, 350.0, 25.0);

    glDisable(GL_LINE_STIPPLE);
    glFlush();
}

void initializeGL(void) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(MY_WIN_WIDTH, MY_WIN_HEIGHT);
    glutInitWindowPosition(MY_WIN_POS_X, MY_WIN_POS_Y);
    glutCreateWindow(MY_WIN_TITLE);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    initializeGL();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
