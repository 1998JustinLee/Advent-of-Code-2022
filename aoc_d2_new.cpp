#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include <map>

std::map<string, int> asd =
{
    {"A X", 4},
    {"A Y", 8},
    {"A Z", 3},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 7},
    {"C Y", 2},
    {"C Z", 6},
};

std::map<string, int> asd2 =
{
    {"A X", 3},
    {"A Y", 4},
    {"A Z", 8},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 2},
    {"C Y", 6},
    {"C Z", 7},
};

int main()
{
    string myText;
    ifstream MyReadFile("aoc_d2.txt");

    int score = 0;

    while (getline (MyReadFile, myText)) {
        // Part 1
        // score += asd[myText];

        // Part 2
        // score += asd2[myText];

        /*
                  Me
        Elf   Win   Lose
        1 R | Y 2 | Z 3
        2 P | Z 3 | X 1
        3 S | X 1 | Y 2
               +1    -1
        */

        // Advanced Part 1
        // int elf = myText[0] - 65;
        // int me = myText[2] - 88;

        // for (int i = -1; i < 2; i++)
        // {
        //     if ((((elf + i) % 3) + 3) % 3 == me)
        //     {
        //         score += me + 1 + 3 + (i * 3);
        //         break;
        //     }
        // }

        // Advanced Part 2
        // int elf = myText[0] - 65;
        // int me = myText[2] - 89;
        // score += 3 + (3 * me) + ((((elf + me) % 3) + 3) % 3) + 1;
    }

    cout << score << endl;

    MyReadFile.close();
}