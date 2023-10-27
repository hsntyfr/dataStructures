#include <iostream>
#include <fstream>
#include "Sayi.h"
using namespace std;

int main() {

    string line;
    ifstream read("sayilar.txt");

    Sayi *sayi = new Sayi();
    Sayi *temp = sayi;
    sayi->Add(5);
    sayi->Add(6);
    cout << temp->BasamakHead->Data << endl;
    cout << temp->BasamakHead->Next->Data << endl;

    temp->Next = new Sayi();
    Sayi *temp2 = temp->Next;
    temp2->Add(7);
    temp2->Add(8);
    temp2->Add(9);
    temp2->Add(10);

    cout << temp2->BasamakHead->Data << endl;
    cout << temp2->BasamakHead->Next->Data << endl;
    cout << temp2->BasamakHead->Next->Next->Data << endl;
    cout << temp2->BasamakHead->Next->Next->Next->Data << endl;

    temp2->Next = new Sayi();
    Sayi *temp3 = temp2->Next;
    temp3->Add(11);
    cout << temp3->BasamakHead->Data << endl;






/*    if (read.is_open())
    {
        *//*getline(read, line);
        cout << line << endl;
        line.substr();
        int b = stoi(line);
        cout << b << endl;
        cout << line << endl;*//*

        for (int i = 0; i < line.length(); ++i)
        {


            if (line[i] != ' ')
            {
            }
            else if (line[i] == ' ')
            {

                cout << "else if eklerken hatalar var" << endl;
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

    sayi->Print();*/


    delete sayi;
    return 0;
}
