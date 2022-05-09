#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
int main() {
    // sf::RenderWindow win{sf::VideoMode{1100, 800}, "MINESWEEPER"};
    MinesweeperBoard plansza(3, 3, DEBUG);
    // MSSFMLView view (plansza);
    MSBoardTextView view(plansza);
    MSTextController ctrl(plansza, view);
    ctrl.play();
    // plansza.toggleFlag(0,0);
    //  plansza.revealField(2,3);

    // while (win.isOpen())
    // {
//        // obsługa zdarzeń
//        //
//        win.clear();
//        view.drawOnWindow(win);   // wywołujemy funkcję draw i dostarczamy jej okno na którym ma odbyć sie rysowanie
//        win.display();
//     }
    return 0;
}