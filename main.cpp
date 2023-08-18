#include<iostream>
#include <conio.h>

using namespace std;

enum eDirection{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dira;
bool gameOver;
void setup();
void Draw();
void Input();
void Logic();
void Logic2();
const int width = 20;
const int height = 20;
int x,y,fruitX, fruitY, score;
int tailx[100], taily[100];
int ntail;

int main(){
    char choice;
    cout << "\n\t-------------------------------\n";
    cout << "\t\t Snake in C++\n";
    cout << "\t-------------------------------\n\n";
    cout << "Please Ender Game Difficulty: \n\n";
    cout << "PLay Hard Mode for Press : x\n\n";
    cout << "PLay Easy Mode for Press: z\n\n";
    cin >> choice;
    switch(choice)
    {
        case 'x':
            setup();
            while(!gameOver)
            {
                Draw();
                Input();
                Logic2();
                _sleep(30);
            }
            break;

        case 'z':
            setup();
            while(!gameOver)
            {
                Draw();
                Input();
                Logic();
                _sleep(30);
            }

        default:
            cout << "Invalid!! PLease sellect correct Option!";
            break;
    }

    getch();
    return 0;
}

void setup(){
    gameOver = false;
    dira = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}

void Draw(){
    system("cls");
    cout << "\n\t\t     :SNAKE GAME:\n";
    cout << "\t\t";
    for (int i = 0; i < width - 8; i++){
        cout << "||";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "\t\t||";
            }
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "*";
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                    if(tailx[k] == j && taily[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
                cout << "||";
        }
        cout << endl;
    }
    cout << "\t\t";
    for (int i = 0; i < width - 8; i ++)
    {
        cout << "||";
    }
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dira = LEFT;
                break;
            case 'd':
                dira = RIGHT;
                break;
            case 'w':
                dira = UP;
                break;
            case 's':
                dira = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

//Easy Modu
void Logic()
{
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X, prev2Y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dira)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    for (int i = 0; i < ntail; i++)
    {
        if (tailx[i] == x && taily[i] == y)
        {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        ntail++;
    }
}

//Hard Mode
void Logic2()
{
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X, prev2Y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dira)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }
    if (x>= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    for (int i = 0; 9 < ntail; i ++)
    {
        if (tailx[i] == x && taily[i] == y)
        {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        ntail++;
    }

}

