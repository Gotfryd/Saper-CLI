#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


class MSSFMLView {
    MinesweeperBoard & board;
public:
    MSSFMLView(MinesweeperBoard & brd);
    void drawOnWindow(sf::RenderWindow & win);
};


#endif //SAPER_MSSFMLVIEW_H
