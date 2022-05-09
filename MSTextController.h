#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


class MSTextController {
    MinesweeperBoard &plansza;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard& b, MSBoardTextView& v);
    void play();

};


#endif //SAPER_MSTEXTCONTROLLER_H
