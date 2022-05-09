#include "MSTextController.h"

#include <iostream>
using namespace std;

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v): plansza(b), view(v){

}

void MSTextController::play(){
    int x, y, action;
    view.display();
    do{
        cout<<endl<<"Wprowadz 1 aby odkryc pole"<<endl;
        cout<<"Wprowadz 2 aby flagowac/odflagowac pole"<<endl;
        cout<<"Wybieram: ";
        cin>>action;
        cout<<"Podaj wspolrzedne x i y"<<endl;
        cin>>x>>y;
        switch(action)
        {
            case 1:
                plansza.revealField(x, y);
                view.display();
                break;
            case 2:
                plansza.toggleFlag(x, y);
                view.display();
                break;
            default:
                cout<<"Niepoprawny wybor. Mozliwe operacje: 1 i 2"<<endl;
                break;
        }
    }
    while (plansza.getGameState()==RUNNING);
    if(plansza.getGameState() == FINISHED_LOSS)
        cout << "Przegrales";
    if(plansza.getGameState() == FINISHED_WIN)
        cout << "Gratulacje, wygrales!";

}
