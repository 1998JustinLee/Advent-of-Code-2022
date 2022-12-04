#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int convert(char c)
{
    int asd = (int)c;
    if (asd > 96)
    {
        return asd - 96;
    }
    else
    {
        return asd - 38;
    }
}

int main()
{
    string myText;
    ifstream MyReadFile("aoc_d3.txt");

    int priority = 0;

    // Pt1
    // while (getline (MyReadFile, myText)) {
    //     string comp1 = myText.substr(0, myText.length()/2);
    //     string comp2 = myText.substr(myText.length()/2, myText.length()/2);

    //     for (int i=0; i<comp1.length(); i++)
    //     {
    //         if (comp2.find(comp1[i]) != string::npos)
    //         {
    //             priority += convert(comp1[i]);
    //             break;
    //         }
    //     }


    // }
    // cout <<priority<<endl;

    // Pt2
    while (getline (MyReadFile, myText)) {
        string items = myText;
        string elf1 = myText;
        getline (MyReadFile, myText);
        items += myText;
        string elf2 = myText;
        getline (MyReadFile, myText);
        items += myText;
        string elf3 = myText;

        sort(items.begin(), items.end());
        // cout<<items<<endl;
        for(int i=0; i<items.length(); i++)
        {
            int j = i + 2;
            if (j < items.length())
            {
                if (items[i] == items[j])
                {
                    if (elf1.find(items[i]) != string::npos &&
                    elf2.find(items[i]) != string::npos &&
                    elf3.find(items[i]) != string::npos)
                    {
                        priority += convert(items[i]);
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }

    }

    cout <<priority<<endl;

    MyReadFile.close();
}