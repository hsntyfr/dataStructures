#include <iostream>
#include <fstream>
#include "Basamak.h"
#include "Sayi.h"
#include "Node.h"

using namespace std;

int main()
{
    string line;
    ifstream read("sayilar.txt");
    Basamak* basamak = new Basamak();
    Sayi* sayi = new Sayi();

    if (read.is_open())
    {
        getline(read, line);
        cout << line << endl;
        for (int i = 0; i < line.length(); ++i)
        {
            /*if (line[i] != ' ')
            {
                basamak->Add(line[i]);
            }
            else
            {
                basamak = new Basamak();
                sayi->Add(basamak);
            }*/
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }







    return 0;
}