#include <SDL2/SDL.h>
#include <GL/gl.h>

#define MY_WIN_WIDTH 250
#define MY_WIN_HEIGHT 250
#define MY_WIN_POS_X 100
#define MY_WIN_POS_Y 100
#define MY_WIN_TITLE "hello"

void display(void) {
    //clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();

    /* don't wait!
     * start processing buffered OpenGL routines
     */
    glFlush();

}

void init(void) {
    /* Initialize SDL */
    SDL_Init(SDL_INIT_EVERYTHING);

    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setAttrib(void) {

    // 2.1 is part of the modern versions of OpenGL, but most video cards whould be able to run it
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Turn on double buffering with a 24bit Z buffer.
    // You may need to change this to 16 or 32 for your system
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

int main()
{

    init();
    setAttrib();

    SDL_Window* win;
    win = SDL_CreateWindow(MY_WIN_TITLE, MY_WIN_POS_X, MY_WIN_POS_Y, MY_WIN_WIDTH, MY_WIN_HEIGHT, SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(win);

    display();

    SDL_GL_SwapWindow(win);

    SDL_Delay(5000);

    return 0;
}
