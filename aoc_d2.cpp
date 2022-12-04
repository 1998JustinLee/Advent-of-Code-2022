#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

char XtoA(char move)
{
    if (move == 'X')
    {
        return 'A';
    }
    else if (move == 'Y')
    {
        return 'B';
    }
    else if (move == 'Z')
    {
        return 'C';
    }
}

int WinLoseDraw(char elf, char my)
{
    if (elf == my)
    {
        return 3;
    }

    if (my == 'A' && elf == 'C')
    {
        return 6;
    }
    else if (my == 'A')
    {
        return 0;
    }

    if (my == 'B' && elf == 'A')
    {
        return 6;
    }
    else if (my == 'B')
    {
        return 0;
    }

    if (my == 'C' && elf == 'B')
    {
        return 6;
    }
    else if (my == 'C')
    {
        return 0;
    }
}

int MoveScore(char move)
{
    if (move == 'A')
    {

        return 1;
    }
    else if (move == 'B')
    {
        return 2;
    }
    else if (move == 'C')
    {
        return 3;
    }

    return 0;
}

int WhatDo(char outcome)
{
    if (outcome == 'X')
    {
        return 0;
    }
    else if (outcome == 'Y')
    {
        return 3;
    }
    else if (outcome == 'Z')
    {
        return 6;
    }
}

int final(char elfmove, int whatdo)
{
    if (whatdo == 3)
    {
        return MoveScore(elfmove);
    }

    if (elfmove == 'A')
    {
        if (whatdo == 0)
        {
            return MoveScore('C');
        }
        else if (whatdo == 6)
        {
            return MoveScore('B');
        }
    }
    else if (elfmove == 'B')
    {
        if (whatdo == 0)
        {
            return MoveScore('A');
        }
        else if (whatdo == 6)
        {
            return MoveScore('C');
        }
    }
    else if (elfmove == 'C')
    {
        if (whatdo == 0)
        {
            return MoveScore('B');
        }
        else if (whatdo == 6)
        {
            return MoveScore('A');
        }
    }
}

int main()
{
    string myText;
    ifstream MyReadFile("aoc_d2.txt");

    int score = 0;

    while (getline (MyReadFile, myText)) {
        // Part 1
        char elfMove = myText[0];
        char myMove = XtoA(myText[2]);
        score += WinLoseDraw(elfMove, myMove) + MoveScore(myMove);

        // Part 2
        // char elfMove = myText[0];
        // char whatDo = myText[2];
        // cout <<WhatDo(whatDo) << " " << final(elfMove, WhatDo(whatDo))<< endl;

        // score += WhatDo(whatDo);
        // score += final(elfMove, WhatDo(whatDo));
    }

    cout << score << endl;

    MyReadFile.close();
}