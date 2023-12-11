#include <iostream>
#include "AVL.h"
#include "Yigin.h"
#include "DinamikDizi.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    AVL dizi[3];
    DinamikDizi *dizi1 = new DinamikDizi();

   
    
    ifstream dosya("src/Sayilar.txt");

    string satir = "";
    int index = 0;
    while (getline(dosya, satir)) 
    {
        istringstream iss(satir);
        int sayi;

        while (iss >> sayi)
        {
            dizi[index].ekle(sayi);
        }
        dizi[index].postOrder(dizi[index].root);
        int ascii = dizi[index].AVLToplamDugumDeger % (90 - 65 + 1) + 65;
        cout << (char)ascii;
        index++;
    }
    
    int silinecek = 0;
    int enBuyuk = 0;
    int enKucuk = 99999;
    int sayac = 0;

    cout << dizi[0].AVLYigin->getir();
    dizi[0].AVLYigin->cikar();
    cout << dizi[0].AVLYigin->getir();
    

   
    

    return 0;




}


