#include <iostream>
#include "SayilarListesi.h"
using namespace std;

int main()
{
    Basamak *b = new Basamak(3);
    Sayi *s = new Sayi();
    SayilarListesi *sl = new SayilarListesi();
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

    Dugum *d = new Dugum(s);
    sl->Ekle(d);

    s = new Sayi();
    b = new Basamak(10);
    s->Ekle(b);
    b = new Basamak(11);
    s->Ekle(b);
    b = new Basamak(12);
    s->Ekle(b);
    b = new Basamak(13);
    s->Ekle(b);
    b = new Basamak(14);
    s->Ekle(b);

    Dugum *d2 = new Dugum(s);
    sl->Ekle(d2);

    delete sl;

    return 0;
}
