#include <iostream>
#include "fstream"
#include "string"
#include "sstream"
#include "SayilarListesi.h"
#include "Dugum.h"
#include "Sayi.h"
#include "Basamak.h"
using namespace std;

int main()
{
    SayilarListesi *sl = new SayilarListesi();
    Sayi *s = new Sayi();
    Dugum *d = new Dugum(s);
    Basamak *b = new Basamak(0);

    string line;

    ifstream read("Sayilar.txt");
    if (read.is_open())
    {

        /*cout << line.substr(1, 2) << endl;
        int deneme = stoi(line.substr(1, 2));
        ss.str(line);
        b = new Basamak(deneme);
        s->Ekle(b);

        d = new Dugum(s);
        sl->Ekle(d);*/

        /*cout << line.substr(4, 5) << endl;
        a = stoi(line.substr(4, 5));
        ss.str(line);
        b = new Basamak(a);
        s->Ekle(b);
        d = new Dugum(s);
        sl->Ekle(d);*/


        /*while (std::getline(ss, sayi, ' ')) {
            cout << "Sayi: " << sayi << endl;

            for (char basamak : sayi) {
                int basamakSayi = basamak - '0';
                std::cout << "Basamak: " << basamakSayi << std::endl;
                cout << typeid(basamakSayi).name() << endl;
                *//*b = new Basamak(basamakSayi);
                s->Ekle(b);*//*
            }
            *//*d = new Dugum(s);
            sl->Ekle(d);*//*
        }*/

        /*while (ss >> sayi) {
            std::cout << "Sayi: " << sayi << std::endl;

            for (char basamak : sayi) {
                int basamakSayi = basamak - '0';
                std::cout << "Basamak: " << basamakSayi << std::endl;
                b = new Basamak(basamakSayi);
                s->Ekle(b);
            }

        }*/


        /*for (int i = 0; i < 5; ++i)
        {
            b = new Basamak(i);
            s->Ekle(b);
        }*/
    }
    else
    {
        cout << "Dosya acilamadi" << endl;
    }


    getline(read, line);
    cout << line << endl;
    read.close();




    for (int i = 0; i < 5; ++i)
    {
        b = new Basamak(i);
        s->Ekle(b);

    }
    d = new Dugum(s);
    sl->Ekle(d);


    //TAM OLARAK BURASI HATA VERİYOR
    /*char bbbc = line[0];
    int a = int(bbbc) - 48;
    b = new Basamak(a);
    s->Ekle(b);
    bbbc = line[1];
    a = int(bbbc) - 48;
    b = new Basamak(a);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);*/


    /*int a = line[0] - '0';
    cout << line[0] << endl;
    cout << a << endl;
    cout << sizeof(a) << endl;
    cout << &a << endl;

    s = new Sayi();
    b = new Basamak(a);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);*/


    s = new Sayi();
    int a;
    for (int i = 0; i < 2; ++i)
    {
        a = line[i] - '0';
        b = new Basamak(a);
        s->Ekle(b);
    }
    d = new Dugum(s);
    sl->Ekle(d);


    s = new Sayi();
    b = new Basamak(9);
    s->Ekle(b);
    b = new Basamak(9);
    s->Ekle(b);
    b = new Basamak(9);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);

    s = new Sayi();
    b = new Basamak(6);
    s->Ekle(b);
    b = new Basamak(6);
    s->Ekle(b);
    b = new Basamak(6);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);


    s = new Sayi();
    b = new Basamak(1);
    s->Ekle(b);
    b = new Basamak(2);
    s->Ekle(b);
    b = new Basamak(3);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);


    s = new Sayi();
    b = new Basamak(1);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);

    s = new Sayi();
    b = new Basamak(1);
    s->Ekle(b);
    d = new Dugum(s);
    sl->Ekle(d);



    s = new Sayi();
    b = new Basamak(5);
    s->Ekle(b);
    b = new Basamak(6);
    s->Ekle(b);
    b = new Basamak(7);
    s->Ekle(b);
    b = new Basamak(8);
    s->Ekle(b);
    b = new Basamak(9);
    s->Ekle(b);

    d = new Dugum(s);
    sl->Ekle(d);

    s = new Sayi();
    b = new Basamak(9);
    s->Ekle(b);
    b = new Basamak(8);
    s->Ekle(b);
    b = new Basamak(7);
    s->Ekle(b);
    b = new Basamak(6);
    s->Ekle(b);


    d = new Dugum(s);
    sl->Ekle(d);



    s = new Sayi();
    b = new Basamak(9);
    s->Ekle(b);
    b = new Basamak(8);
    s->Ekle(b);
    b = new Basamak(7);
    s->Ekle(b);
    b = new Basamak(6);
    s->Ekle(b);

    d = new Dugum(s);
    sl->Ekle(d);

    sl->Yazdir();
    delete sl;

    return 0;
}
