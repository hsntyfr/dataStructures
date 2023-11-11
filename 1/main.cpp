#include <iostream>
#include "fstream"
#include "string"
#include "SayilarListesi.h"

using namespace std;

int main()
{
    SayilarListesi *sl = new SayilarListesi();
    Sayi *s = new Sayi();
    Dugum *d = new Dugum(s);
    Basamak *b = new Basamak(0);
    int sayi;
    string sayilar;

    ifstream read("Sayilar.txt");
    if (read.is_open())
    {
        getline(read, sayilar);
    }
    else
    {
        cout << "Dosya acilamadi" << endl;
    }
    read.close();


    for (int i = 0; i < sayilar.length(); i++)
    {
        if (sayilar[i] != ' ')
        {
            sayi = sayilar[i] - '0';
            b = new Basamak(sayi);
            s->Ekle(b);
        }
        else if (sayilar[i] == ' ')
        {
            d = new Dugum(s);
            sl->Ekle(d);
            s = new Sayi();
        }
    }
    d = new Dugum(s);
    sl->Ekle(d);

    sl->Yazdir();

    sl->EnBuyukCikar();
    sl->EnBuyukCikar();
    sl->EnBuyukCikar();
    sl->EnBuyukCikar();
    sl->EnBuyukCikar();








    delete sl;
    return 0;
}