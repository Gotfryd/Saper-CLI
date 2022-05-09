#include "MSBoardTextView.h"
#include <iostream>
using namespace std;




MSBoardTextView::MSBoardTextView(MinesweeperBoard &board): planszaX(board) {
}

//wyswietlanie planszy
void MSBoardTextView::display() {

    int height = MSBoardTextView::planszaX.getBoardHeight();
    int width = MSBoardTextView::planszaX.getBoardWidth();

    for(int wys=0; wys<height; ++wys){
        for(int szer=0; szer<width; ++szer){
            cout << "[";
            cout << planszaX.getFieldInfo(szer,wys);
            cout << "]";
        }
        cout << endl;
    }
}

