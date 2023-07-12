#include <iostream>
#include <conio.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 17;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //Koordynaty weza
int nTail;

enum eDirection {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
}; // Kontrole

eDirection dir;

void Setup(){
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height /2;
    fruitX = rand() % width; // Ustawia owoc w randomowym miejscu na mapie
    fruitY = rand() % height;
}

void Draw(){
    system("cls");
    for (int i = 0; i < width; i++){
        cout << "☐";
        cout << endl;
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0)
                cout << "☐"; //Sciany
            if (i == y && j == x)
                cout << "⊗"; // Ogon weza
            else if (i == fruitY && j == fruitY)
                cout << "☢";
            else {
            bool print = false;
            for (int k = 0; k < nTail; k++){
                if (tailX[k] == j && tailY[k] == 1){
                    cout << "*";
                    print = true;
                }
            }
            if (!print) cout << "";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++){
        cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;
    }
}

void Input(){
    if(_kbhit()){
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void alghoritm(){

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
