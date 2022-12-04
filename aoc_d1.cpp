#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string myText;
    ifstream MyReadFile("aoc_d1.txt");

    int elf = 0;
    int theElf = 0;
    int secondElf = 0;
    int thirdElf = 0;
    int maxCalory = 0;
    int secondCalory = 0;
    int thirdCalory = 0;
    int runningCalory = 0;
    int i = 0;

    while (getline (MyReadFile, myText)) {
        if (myText == "")
        {
            if (runningCalory > maxCalory)
            {
                if (maxCalory > secondCalory)
                {
                    if (secondCalory > thirdCalory)
                    {
                        thirdCalory = secondCalory;
                        thirdElf = secondElf;
                    }

                    secondCalory = maxCalory;
                    secondElf = theElf;
                }
                else if (maxCalory > thirdCalory)
                {
                    thirdCalory = maxCalory;
                    thirdElf = theElf;
                }

                maxCalory = runningCalory;
                theElf = elf;
            }
            else if (runningCalory > secondCalory)
            {
                if (secondCalory > thirdCalory)
                {
                    thirdCalory = secondCalory;
                    thirdElf = secondElf;
                }

                secondCalory = runningCalory;
                secondElf = elf;
            }
            else if (runningCalory > thirdCalory)
            {
                thirdCalory = runningCalory;
                thirdElf = elf;
            }

            // cout << elf << " " << runningCalory <<endl;
            // cout << runningCalory <<endl;

            elf++;
            runningCalory = 0;
            continue;
        }

        std::istringstream ( myText ) >> i;
        runningCalory += i;
    }

    MyReadFile.close();

    // cout << "The elf is: " << theElf << endl;
    // cout << "Calory count: " << maxCalory << endl;

    cout << theElf << " " << maxCalory <<endl;
    cout << secondElf << " " << secondCalory <<endl;
    cout << thirdElf << " " << thirdCalory <<endl;
    cout << maxCalory + secondCalory + thirdCalory <<endl;
}