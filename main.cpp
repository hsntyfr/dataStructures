#include <iostream>
#include <fstream>
#include "Sayi.h"
using namespace std;

int main() {

    string line;
    ifstream read("sayilar.txt");

    Sayi *sayi = new Sayi();
    Sayi *original = sayi;

    if (read.is_open())
    {
        getline(read, line);
        cout << line << endl;

        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i] != ' ')
            {
                cout << sayi << endl;
                cout << "basamak eklendi" << endl;
                cout << i << endl;
                sayi->Add(i);
            }
            else if (line[i] == ' ')
            {
                cout << "yeni sayıya geçildi" << endl;
                sayi->Next = new Sayi();
                sayi = sayi->Next;
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

    sayi = original;
    sayi->Delete(sayi);
    return 0;
}
