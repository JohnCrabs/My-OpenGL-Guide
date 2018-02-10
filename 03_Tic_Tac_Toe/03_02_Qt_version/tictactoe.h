#ifndef TICTACTOE_H
#define TICTACTOE_H

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define DEFAULT_SYMBOL '\0'

class Tile
{
public:
    void setTile(float x_min, float y_min, float x_max, float y_max, char sym = DEFAULT_SYMBOL);

    inline float minX(void) {return Xmin;}
    inline float minY(void) {return Ymin;}
    inline float maxX(void) {return Xmax;}
    inline float maxY(void) {return Ymax;}
    inline char Symbol(void) {return symbol;}
    inline void setSymbol(char sym) {symbol = sym;}

private:
    float Xmin; //minimum X tile coordinate
    float Ymin; //minimum Y tile coordinate
    float Xmax; //maximum X tile coordinate
    float Ymax; //maximum Y tile coordinate

    char symbol; //the symbol of the player 'O' or 'X' if not free or '\0' if free.
};

class TicTacToe
{
public:
    TicTacToe(void);

    void resetBoard(void);
    void drawGrid(void);
    void drawTiles(void);
    void drawSymbolX(float x_min, float y_min, float x_max, float y_max);
    void drawSymbolO(float x_min, float y_min, float x_max, float y_max);

    float boardWidth(void) {return maxBoardWidth;}
    float boardHeight(void) {return maxBoardHeight;}

    inline bool IsWin(void) {return isWin;}
    inline bool IsDraw(void) {return isDraw;}
    inline char WinPlayer(void) {return winPlayer;}

    void checkTileToDraw(float x, float y);

private:
    Tile boardTiles[9];

    float maxBoardWidth;
    float maxBoardHeight;

    bool isWin;
    bool isDraw;
    bool O_plays;

    char winPlayer;

    bool checkSameChar(char c1, char c2, char c3);
    bool checkWinCondition(void);
    bool checkDrawCondition(void);
    bool numBetweenOrEgualToMin(float num, float min, float max);
};

#endif // TICTACTOE_H
