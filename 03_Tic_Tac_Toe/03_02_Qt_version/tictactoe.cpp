/***************/
/* tictactoe.h */
/***************/

#include "tictactoe.h"
#include "GL/gl.h"

#include "math.h"

const float DEG2RAD = 3.14159265/180;

void Tile::setTile(float x_min, float y_min, float x_max, float y_max, char sym) {
    Xmin = x_min;
    Ymin = y_min;
    Xmax = x_max;
    Ymax = y_max;
    symbol = sym;
}

TicTacToe::TicTacToe(void)
{
    maxBoardWidth = 3.0;
    maxBoardHeight = 3.0;

    isWin = false;
    isDraw = false;
    O_plays = true;
}

/*
 * Reset the board tiles when the game needs to be called.
 *
 *  6 | 7 | 8
 * ---|---|---
 *  3 | 4 | 5
 * ---|---|---
 *  0 | 1 | 2
 *
 */
void TicTacToe::resetBoard(void) {

    /*
     * boardTiles[0].setTile(0.0, 0.0, 1.0, 1.0);
     * boardTiles[1].setTile(1.0, 0.0, 2.0, 1.0);
     * boardTiles[2].setTile(2.0, 0.0, 3.0, 1.0);
     *
     * boardTiles[3].setTile(0.0, 1.0, 1.0, 2.0);
     * boardTiles[4].setTile(1.0, 1.0, 2.0, 2.0);
     * boardTiles[5].setTile(2.0, 1.0, 3.0, 2.0);
     *
     * boardTiles[6].setTile(0.0, 2.0, 1.0, 3.0);
     * boardTiles[7].setTile(1.0, 2.0, 2.0, 3.0);
     * boardTiles[8].setTile(2.0, 2.0, 3.0, 3.0);
     */
    int index = 0;
    for(int y = 0; y < maxBoardHeight; y++)
        for(int x = 0; x < maxBoardWidth; x++)
            boardTiles[index++].setTile(x, y, x+1, y+1);

    isWin = false;
    isDraw = false;
    O_plays = true;
}

/*
 * Draw GameBoard Grid
 */
void TicTacToe::drawGrid(void) {
    glLineWidth(5.0);
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_LINES);
        for(int y = 1; y < maxBoardHeight; y++) {
            glVertex2f(0.0, y);
            glVertex2f(maxBoardWidth, y);
        }
        for(int x = 1; x < maxBoardWidth; x++) {
            glVertex2f(x, 0.0);
            glVertex2f(x, maxBoardHeight);
        }
    glEnd();
}

void TicTacToe::drawTiles(void) {
    for(int i = 0; i < maxBoardWidth*maxBoardHeight; i++) {
        if(boardTiles[i].Symbol() != DEFAULT_SYMBOL) {
            if(boardTiles[i].Symbol() == PLAYER_O)
                drawSymbolO(boardTiles[i].minX(), boardTiles[i].minY(), boardTiles[i].maxX(), boardTiles[i].maxY());
            else if(boardTiles[i].Symbol() == PLAYER_X)
                drawSymbolX(boardTiles[i].minX(), boardTiles[i].minY(), boardTiles[i].maxX(), boardTiles[i].maxY());
        }
    }
}

/*
 * Draw 'O' Symbol
 */
void TicTacToe::drawSymbolO(float x_min, float y_min, float x_max, float y_max) {
    glLineWidth(2.0);
    glColor3f(0.0, 0.0, 1.0);
    float x_circle= x_min + (x_max - x_min)/2;
    float y_circle= y_min + (y_max - y_min)/2;

    glBegin(GL_LINE_LOOP);
        for(int i = 0; i < 360; i++) {
            float degInRad = i * DEG2RAD;
            glVertex2f(x_circle + cos(degInRad) * 0.4, y_circle + sin(degInRad) * 0.4);

        }
    glEnd();
}

/*
 * Draw 'X' Symbol
 */
void TicTacToe::drawSymbolX(float x_min, float y_min, float x_max, float y_max) {
    glLineWidth(3.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(x_min + 0.2, y_min + 0.2);
        glVertex2f(x_max - 0.2, y_max - 0.2);

        glVertex2f(x_min + 0.2, y_max - 0.2);
        glVertex2f(x_max - 0.2, y_min + 0.2);
    glEnd();
}

/*
 * Check if three char values are the same.
 */
bool TicTacToe::checkSameChar(char c1, char c2, char c3) {
    if((c1 != DEFAULT_SYMBOL && c2 != DEFAULT_SYMBOL && c3 != DEFAULT_SYMBOL) && (c1 == c2 && c2 == c3)) {
        winPlayer = c1;
        return true;
    }
    return false;
}

/*
 * Check if the game has been won.
 */
bool TicTacToe::checkWinCondition(void) {
    if(checkSameChar(boardTiles[0].Symbol(), boardTiles[1].Symbol(), boardTiles[2].Symbol())
    || checkSameChar(boardTiles[0].Symbol(), boardTiles[4].Symbol(), boardTiles[8].Symbol())
    || checkSameChar(boardTiles[0].Symbol(), boardTiles[3].Symbol(), boardTiles[6].Symbol())
    || checkSameChar(boardTiles[1].Symbol(), boardTiles[4].Symbol(), boardTiles[7].Symbol())
    || checkSameChar(boardTiles[2].Symbol(), boardTiles[4].Symbol(), boardTiles[6].Symbol())
    || checkSameChar(boardTiles[3].Symbol(), boardTiles[4].Symbol(), boardTiles[5].Symbol())
    || checkSameChar(boardTiles[6].Symbol(), boardTiles[7].Symbol(), boardTiles[8].Symbol()))
        return true;
    return false;
}

/*
 * Check if the game has been drawn.
 */
bool TicTacToe::checkDrawCondition(void) {
    for(int i = 0; i < maxBoardWidth*maxBoardHeight; i++) {
        if(boardTiles[i].Symbol() == DEFAULT_SYMBOL) {
            return false;
        }
    }
    return true;
}

/*
 * Check if a Number is higher or equal than a min value and lower than a max value
 */
bool TicTacToe::numBetweenOrEgualToMin(float num, float min, float max) {
    if(min <= num && max > num)
        return true;
    return false;
}

/*
 * Check which Tile must be drawn and set tile symbol.
 */
void TicTacToe::checkTileToDraw(float x, float y) {
    for(int i = 0; i < maxBoardWidth*maxBoardHeight; i++) {
        if(numBetweenOrEgualToMin(x * 3.0, boardTiles[i].minX(), boardTiles[i].maxX())
                && numBetweenOrEgualToMin(y * 3.0, boardTiles[i].minY(), boardTiles[i].maxY())) {

            if(boardTiles[i].Symbol() == DEFAULT_SYMBOL) {
                if(O_plays) {
                    boardTiles[i].setSymbol(PLAYER_O);
                    O_plays = false;
                } else {
                    boardTiles[i].setSymbol(PLAYER_X);
                    O_plays = true;
                }
            }
            break;
        }
    }
    isWin = checkWinCondition();
    if(!isWin)
        isDraw = checkDrawCondition();
}
