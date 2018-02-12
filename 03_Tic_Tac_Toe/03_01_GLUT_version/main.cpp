/************/
/* main.cpp */
/************/

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define MY_WIN_WIDTH 200
#define MY_WIN_HEIGHT 200
#define MY_WIN_POS_X 100
#define MY_WIN_POS_Y 100
#define MY_WIN_TITLE "Tic-Tac-Toe"

#define PLAYER_X 'X'
#define PLAYER_O 'O'

/*
 * This is ta GameBoard Tiles Structure.
 * Every classic Tic-Tac-Toe has a 3x3 board.
 * The win objective is for a player to score
 * 3 of his symbol horrizondal or vertical or diagonal.
 */
struct Tiles {
    float X_min;
    float Y_min;

    float X_max;
    float Y_max;

    char ID;
    bool isFree;
    bool isDraw;
};

/*
 * Global Variables
 */
Tiles tiles[9]; //Tiles
bool O_turn = true; //Check whose turn is
float width; //keep the current width of the window
float height; //keep the current height of the window
const float DEG2RAD = 3.14159265/180; //transform DEGREE to RAD
bool winGame = false; //set the winGame bool value
bool drawGame = false; //set the drawGame bool value
char winPlayer = '\0'; //set win Player symbol

/*
 * Set the values for a tile
 */
Tiles setTiles(float x_min, float y_min, float x_max, float y_max, bool freeState, bool drawState, char id = '\0') {
    Tiles t;

    t.X_min = x_min;
    t.Y_min = y_min;
    t.X_max = x_max;
    t.Y_max = y_max;
    t.isFree = freeState;
    t.isDraw = drawState;
    t.ID = id;

    return t;
}

/*
 * Initialize the starting tiles values. When the game needs to be restart this function must be called
 *
 *  6 | 7 | 8
 * ---|---|---
 *  3 | 4 | 5
 * ---|---|---
 *  0 | 1 | 2
 */
void initializeTiles(void) {
    tiles[0] = setTiles(0.0, 0.0, 1.0, 1.0, true, false);
    tiles[1] = setTiles(1.0, 0.0, 2.0, 1.0, true, false);
    tiles[2] = setTiles(2.0, 0.0, 3.0, 1.0, true, false);

    tiles[3] = setTiles(0.0, 1.0, 1.0, 2.0, true, false);
    tiles[4] = setTiles(1.0, 1.0, 2.0, 2.0, true, false);
    tiles[5] = setTiles(2.0, 1.0, 3.0, 2.0, true, false);

    tiles[6] = setTiles(0.0, 2.0, 1.0, 3.0, true, false);
    tiles[7] = setTiles(1.0, 2.0, 2.0, 3.0, true, false);
    tiles[8] = setTiles(2.0, 2.0, 3.0, 3.0, true, false);

}

/*
 * The init(void) function.
 * This function runs when the program start and set the
 * default clearing values.
 */
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
}

/*
 * The reshape(int w, int h) function.
 * This function runs when the window is reshaped.
 */
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 3.0, 0.0, 3.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    width = w;
    height = h;
}

void grid(void) {
    glLineWidth(5.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 1.0, 0.0);
        glVertex3f(3.0, 1.0, 0.0);

        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(3.0, 2.0, 0.0);

        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(1.0, 3.0, 0.0);

        glVertex3f(2.0, 0.0, 0.0);
        glVertex3f(2.0, 3.0, 0.0);
    glEnd();
}

/*
 * draw the symbol for X player.
 */
void drawX(float x_min, float y_min, float x_max, float y_max) {
    glLineWidth(3.0);
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(x_min + 0.2, y_min + 0.2, 0.0);
        glVertex3f(x_max - 0.2, y_max - 0.2, 0.0);

        glVertex3f(x_min + 0.2, y_max - 0.2, 0.0);
        glVertex3f(x_max - 0.2, y_min + 0.2, 0.0);
    glEnd();
}

/*
 * draw the symbol for O player.
 */
void drawO(float x_min, float y_min, float x_max, float y_max) {

    glLineWidth(2.0);
    glColor3f(0.0, 0.0, 0.5);
    float x_circle = x_min + (x_max-x_min)/2;
    float y_circle = y_min + (y_max-y_min)/2;
    glBegin(GL_LINE_LOOP);

       for (int i=0; i < 360; i++)
       {
          float degInRad = i*DEG2RAD;
          glVertex2f(x_circle + cos(degInRad)*0.4, y_circle + sin(degInRad)*0.4);
       }

       glEnd();
}

/*
 * Check if three char values are the same.
 */
bool checkSameChar(char c1, char c2, char c3) {
    if ((c1 != '\0' || c2 != '\0' || c3 != '\0') && c1 == c2 && c2 == c3) {
        winPlayer = c1;
        return true;
    }
    return false;
}

/*
 * Check if someone Winned
 */
bool checkWinCondition(void) {
    if(checkSameChar(tiles[0].ID, tiles[1].ID, tiles[2].ID) || checkSameChar(tiles[0].ID, tiles[3].ID, tiles[6].ID)
            || checkSameChar(tiles[0].ID, tiles[4].ID, tiles[8].ID) || checkSameChar(tiles[1].ID, tiles[4].ID, tiles[7].ID)
            || checkSameChar(tiles[2].ID, tiles[5].ID, tiles[8].ID) || checkSameChar(tiles[2].ID, tiles[4].ID, tiles[6].ID)
            || checkSameChar(tiles[3].ID, tiles[4].ID, tiles[5].ID) || checkSameChar(tiles[6].ID, tiles[7].ID, tiles[8].ID))
        return true;
    return false;
}

/*
 * Check if game is Drawn
 */
bool checkDrawCondition(void) {
    int counter = 0;
    for(int i = 0; i < 9; i++) {
        if(!tiles[i].isFree) {
            counter++;
        }
    }
    if(counter == 9)
        return true;
    return false;
}

/*
 * The display(void) function.
 * This function draw the graphics to screen.
 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    grid();

    for(int i = 0; i < 9; i++) {
        if(tiles[i].isDraw) {
            if(tiles[i].ID == PLAYER_O) {
                drawO(tiles[i].X_min, tiles[i].Y_min, tiles[i].X_max, tiles[i].Y_max);
            } else if(tiles[i].ID == PLAYER_X) {
                drawX(tiles[i].X_min, tiles[i].Y_min, tiles[i].X_max, tiles[i].Y_max);
            }
        }
    }

    glutSwapBuffers();

    if(winGame) {
        std::cout << "The player " << winPlayer << " won the game" << std::endl;
    } else if(drawGame) {
        std::cout << "The game is draw! Well done to both of you!"<< std::endl;
    }

}

/*
 * Initialize GLUT window features.
 */
void initializeGL(void) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(MY_WIN_WIDTH, MY_WIN_HEIGHT);
    glutInitWindowPosition(MY_WIN_POS_X, MY_WIN_POS_Y);
    glutCreateWindow(MY_WIN_TITLE);
}

/*
 * Check if a number is between a min and a max value.
 */
bool NumBetweenEqual(float num, float min, float max) {
    if(min <= num && max >= num)
        return true;
    return false;
}

/*
 * Check which tiles must be drawn and set tiles symbol.
 */
void checkTile(float x, float y) {
    for(int i = 0; i < 9; i++) {
        if(NumBetweenEqual(x*3.0, tiles[i].X_min, tiles[i].X_max) && NumBetweenEqual(3-y*3.0, tiles[i].Y_min, tiles[i].Y_max)) {
            if(tiles[i].isFree) {
                tiles[i].isFree = false;
                tiles[i].isDraw = true;
                if(O_turn) {
                    tiles[i].ID = PLAYER_O;
                    O_turn = false;
                } else {
                    tiles[i].ID = PLAYER_X;
                    O_turn = true;
                }
            }
            winGame = checkWinCondition();
            if(!winGame)
                drawGame = checkDrawCondition();
            glutPostRedisplay();
            break;
        }
    }
}

/*
 * Check mouse input events.
 */
void mouse(int button, int state, int x, int y) {
    switch(button) {
    case GLUT_LEFT_BUTTON: {
        if(state == GLUT_DOWN)
            if(!winGame && !drawGame)
                checkTile((float)x/width, (float)y/height);
        break;
    } default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    initializeGL();
    initializeTiles();

    init();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
