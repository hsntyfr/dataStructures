/**
* @file             main.cpp
* @description      Bu dosyada programın ana kodları yer alıyor
* @course           1-C
* @assignment       1
* @date             2.11.2023
* @author           Hasan Tayfur hasan.tayfur@ogr.sakarya.edu.tr
*/

#include <iostream>
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
    int secim = 0;
    string sayilar = sl->SayiOku("./src/Sayilar.txt");
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

    do
    {
        cout << "1. Tek basamaklari basa al" << endl;
        cout << "2. Basamaklari tersle" << endl;
        cout << "3. En buyuk cikar" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
            case 1:
                sl->TekBasaAl();
                break;

            case 2:
                sl->BasamaklariTersle();
                break;

            case 3:
                sl->EnBuyukCikar();
                break;

            case 4:
                delete sl;
                return 0;

            default:
                cout << "Hatali secim yaptiniz" << endl;
                break;
        }
    }
    while (secim != 4);

    delete sl;
    return 0;
}
