#include "Game.h"
#include "AiGame.h"
using namespace std;
int main()
{
    int choice;
    cout << "welcome player !!" << endl;
    cout << "1 - play with friend" << endl;
    cout << "2 - play with your computer" << endl;
    cin >> choice;
    if (choice == 1) {
        Game play;
        int size;
        cout << "what is the size of the borad do you want ?" << endl;
        cin >> size;
        play.run(size);
    }
    if (choice == 2) {
        AiGame play1;
        play1.run(5);
    }
   
}