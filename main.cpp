#include <iostream>
#include <fstream>
#include "Sayi.h"
using namespace std;

int main() {

    string line;
    ifstream read("sayilar.txt");

    Sayi *sayi = new Sayi();



    if (read.is_open())
    {
        getline(read, line);
        cout << line << endl;
        for (int i = 0; i < line.length(); ++i)
        {    Basamak *basamak = new Basamak();

            if (line[i] != ' ')
            {
                basamak->Add(line[i]);
                sayi->Add(basamak);
                cout << line[i] << endl;
                cout << sayi->SayiHead->BasamakHead->Data << endl;
            }
            else if (line[i] == ' ')
            {
                cout << "else if e girdi" << endl;
                //basamak = new Basamak();


            }
            else
            {
                cout << "main else eklerken hatalar var" << endl;
            }
        }
        read.close();
    }
    else
    {
        cout << "Unable to open file";
    }




    return 0;
}
