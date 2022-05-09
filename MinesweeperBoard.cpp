#include <iostream>
#include <time.h>
#include "MinesweeperBoard.h"
using namespace std;

//konstruktor domyslny
MinesweeperBoard::MinesweeperBoard() {
    width = 10;
    height = 10;
    for (int wiersze = 0; wiersze < height; wiersze++)
    {
        for (int kolumny = 0; kolumny < width; kolumny++)
        {
            board[kolumny][wiersze].hasMine = false;
            board[kolumny][wiersze].hasFlag = false;
            board[kolumny][wiersze].isRevealed = false;
        }
    }

}
//konstruktor glowny

MinesweeperBoard::MinesweeperBoard(int wys, int szer, GameMode mode) {
    width = szer;
    height = wys;
    int ilosc_pol = width * height;
    for (int wiersze = 0; wiersze < height; wiersze++)
    {
        for (int kolumny = 0; kolumny < width; kolumny++)
        {
            board[kolumny][wiersze].hasMine = false;
            board[kolumny][wiersze].hasFlag = false;
            board[kolumny][wiersze].isRevealed = false;
        }
    }
    switch (mode) {
        case EASY:
            setMines(height, width, ilosc_pol*(1.0 / 10));
            break;
        case NORMAL:
            setMines(height, width, ilosc_pol*(2.0 / 10));
            break;
        case HARD:
            setMines(height, width, ilosc_pol*(3.0 / 10));
            break;
        case DEBUG:
            setMinesDEBUG(height, width);
            break;
        default:
            cout << "Wybierz tryb gry" << endl;
            break;
    }
}
void MinesweeperBoard::setMines(int wys, int szer, int ilosc_min) {
    srand(time(NULL));
    for (int i = 0; i < ilosc_min; i++) {
        int x = rand() % szer;
        int y = rand() % wys;
        while (board[x][y].hasMine == true) {
            x = rand() % szer;
            y = rand() % wys;
        }
        board[x][y].hasMine = true;
    }
}
void MinesweeperBoard::setMinesDEBUG(int wys, int szer) {
    for (int wiersze = 0; wiersze < wys; wiersze++)
    {
        for (int kolumny = 0; kolumny < szer; kolumny++)
        {
            if (kolumny == wiersze || wiersze == 0 || (kolumny == 0 && wiersze % 2 == 0))
                board[kolumny][wiersze].hasMine = true;
        }
    }
}
int MinesweeperBoard::getBoardWidth() const {
    return width;
}
int MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getMineCount() const {
    int miny = 0;
    for (int wiersze = 0; wiersze < height; wiersze++)
    {
        for (int kolumny = 0; kolumny < width; kolumny++)
        {
            if (board[kolumny][wiersze].hasMine == true)
                miny += 1;
        }
    }
    return miny;
}
int MinesweeperBoard::countMines(int x, int y) const {
    int ilosc_min = 0;
    if (board[x - 1][y - 1].hasMine == true)
        ilosc_min++;
    if (board[x][y - 1].hasMine == true)
        ilosc_min++;
    if (board[x + 1][y - 1].hasMine == true)
        ilosc_min++;
    if (board[x - 1][y].hasMine == true)
        ilosc_min++;
    if (board[x + 1][y].hasMine == true)
        ilosc_min++;
    if (board[x - 1][y + 1].hasMine == true)
        ilosc_min++;
    if (board[x][y + 1].hasMine == true)
        ilosc_min++;
    if (board[x + 1][y + 1].hasMine == true)
        ilosc_min++;
    return ilosc_min;
}
bool MinesweeperBoard::hasFlag(int x, int y) const {
    return board[x][y].hasFlag; //do testu
}
void MinesweeperBoard::toggleFlag(int x, int y) {
    if (board[x][y].isRevealed == false)
        board[x][y].hasFlag = !board[x][y].hasFlag;
    //do testu
}
void MinesweeperBoard::revealField(int x, int y) {
    if (board[x][y].isRevealed == false && board[x][y].hasFlag == false && isOnField(x,y)) {
        if (board[x][y].hasMine == false) {
            board[x][y].isRevealed = true;
            firstMove = false;
        }
        else
        {
            if (firstMove) {
                moveMine(x, y, height, width);
                board[x][y].isRevealed = true;
                firstMove = false;
            }
            else {
                board[x][y].isRevealed = true;
                stanGry = FINISHED_LOSS;
            }
        }
    }
}

bool  MinesweeperBoard::isOnField(int x, int y) const {
    if (x <= width && y <= height && x>=0 && y>=0)
        return true;
    else
        return false;
}

void MinesweeperBoard::moveMine(int x, int y, int wys, int szer) {
    srand(time(NULL));
    int tempx = x;
    int tempy = y;
    board[x][y].hasMine = false;
    x = rand() % szer;
    y = rand() % wys;
    while (board[x][y].hasMine == true && (x==tempx && y==tempy)) {
        x = rand() % szer;
        y = rand() % wys;
    }
    board[x][y].hasMine = true;
}

bool MinesweeperBoard::isRevealed(int x, int y) const {
    return board[x][y].isRevealed;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if (!isOnField(x, y))
        return '#';
    else if (board[x][y].isRevealed == false && board[x][y].hasFlag == true)
        return 'F';
    else if (board[x][y].isRevealed == false && board[x][y].hasFlag == false)
        return '_';
    else if (board[x][y].isRevealed == true && board[x][y].hasMine == true)
        return 'x';
    else if (board[x][y].isRevealed == true && countMines(x,y)==0)
        return ' ';
    else if (board[x][y].isRevealed == true && countMines(x,y) > 0)
        return countMines(x,y)+48;
    return 0;
}
GameState MinesweeperBoard::getGameState() const {
    return stanGry;
}

void MinesweeperBoard::winCond() {
    for (int wiersze = 0; wiersze < height; wiersze++) {
        for (int kolumny = 0; kolumny < width; kolumny++) {
            if (board[wiersze][kolumny].isRevealed == false && board[wiersze][kolumny].hasMine == false) {
                return;
            }
            if (board[wiersze][kolumny].hasMine == true && board[wiersze][kolumny].hasFlag == false) {
                    return;
            }
            if (board[wiersze][kolumny].hasFlag == true && board[wiersze][kolumny].hasMine == false) {
                    return;
            }
        }
    }
    stanGry = FINISHED_WIN;
//do testu
}
//wyswietlanie planszy debug_displayem
void MinesweeperBoard::debug_display() const {
    for (int wiersze = 0; wiersze < height; wiersze++)
    {
        for (int kolumny = 0; kolumny < width; kolumny++)
        {
            cout << "[";
            if (board[kolumny][wiersze].hasMine == true)
            {
                cout << "M";
            }
            else cout << ".";
            if (board[kolumny][wiersze].isRevealed == true)
            {
                cout << "o";
            }
            else cout << ".";
            if (board[kolumny][wiersze].hasFlag == true)
            {
                cout << "f";
            }
            else cout << ".";
            cout << "]";
            cout << " ";
        }
        cout << endl;
    }
}
