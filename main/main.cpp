#include "../src/functions.h"
#include <iostream>
using namespace std;

int main() {
    int x;
    while(true){
        printLogo();
        cout << "- Escolha uma opção: \n\n";
        cout << "\t 1) INICIAR\n" << "\t 2) PONTUAÇÕES\n" << "\t 3) SAIR\n";

        cin >> x;
        switch(x){
            case 1: {
                start();
                break;
            }
            case 2: {
                loadScore("../data/score/score.bin");
                break;
            }
            case 3: {
                cleanScreen();
                return 0;
            }
            default: cout << "\n---Opção Inválida!---\n\n";
        }
    }
}