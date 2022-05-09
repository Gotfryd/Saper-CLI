#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H
enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };


struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};



class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    bool firstMove = true;
    GameState stanGry = RUNNING;
public:

    MinesweeperBoard();
    MinesweeperBoard(int wys, int szer, GameMode mode);
    void debug_display() const;
    void setMines(int wys, int szer, int ilosc_min);
    void setMinesDEBUG(int wys, int szer);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool isOnField(int x, int y) const;
    void moveMine(int x, int y, int wys, int szer);
    bool isRevealed(int x, int y) const;
    bool hasMine(int x, int y) const;
    char getFieldInfo(int x, int y) const;
    GameState getGameState() const;
    void winCond();
};

#endif //SAPER_MINESWEEPERBOARD_H