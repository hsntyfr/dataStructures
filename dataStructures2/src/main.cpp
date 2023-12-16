#include <iostream>
#include "AVL.h"
#include "Yigin.h"

using namespace std;

int main()
{
    string path = "src/Veri.txt";
    int silinecek = 0;
    int enBuyuk = 0;
    int enKucuk = 99999;
    int sayac = 0;

    int satirSayisi = AVL::SatirSayisi(path);
    AVL** dizi = new AVL * [satirSayisi];
    AVL::AVLOlustur(dizi, path);

    while (true)
    {
        silinecek = AVL::EnKucukDegeriBul(dizi, satirSayisi, enKucuk, silinecek);
        dizi[silinecek]->AVLYigin->Cikar();
        if (dizi[silinecek]->AVLYigin->Getir() == -1)
        {
            dizi[silinecek]->Sil(dizi[silinecek]->Root);
            dizi[silinecek]->Root = NULL;
            sayac++;
            AVL::Yazdir(dizi, satirSayisi);
            AVL::AVLYiginTemizleVePostOrder(dizi, satirSayisi);
            if (sayac + 1 == satirSayisi)
            {
                int i = 0;
                while (dizi[i]->Root == NULL)
                {
                    i++;
                }
                AVL::YazdirSonAVL(i, dizi);
                break;
            }
            continue;
        }
        silinecek = AVL::EnBuyukDegeriBul(dizi, satirSayisi, enBuyuk, silinecek);
        dizi[silinecek]->AVLYigin->Cikar();
        if (dizi[silinecek]->AVLYigin->Getir() == -1)
        {
            dizi[silinecek]->Sil(dizi[silinecek]->Root);
            dizi[silinecek]->Root = NULL;
            sayac++;
            AVL::Yazdir(dizi, satirSayisi);
            AVL::AVLYiginTemizleVePostOrder(dizi, satirSayisi);
        }
        if (sayac + 1 == satirSayisi)
        {
            int i = 0;
            while (dizi[i]->Root == NULL)
            {
                i++;
            }
            AVL::YazdirSonAVL(i, dizi);
            break;
        }
    }
    for (int i = 0; i < satirSayisi; i++)
    {
        dizi[i]->AVLYigin->Temizle();
        delete dizi[i]->AVLYigin;
        delete dizi[i]->Root;
        delete dizi[i];
    }
    delete[] dizi;

    return 0;
}


