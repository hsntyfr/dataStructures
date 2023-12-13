#include "AVL.h"
#include "Yigin.h"
#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

AVL::AVL()
{
    root = 0;
    AVLToplamDugumDeger = 0;
    AVLYigin = new Yigin();
}
AVL::~AVL()
{
    //cout << "avl silindi" << endl;
}
void AVL::sil(DugumAVL* root)
{
    if (root == nullptr)
    {
        return;
    }

    sil(root->sol);
    sil(root->sag);

    delete root;
}
bool AVL::varmi(int veri)
{
    return varmi(veri, root);
}
void AVL::ekle(int eklenecek)
{
    root = ekle(eklenecek, root);
}
void AVL::sil(int veri)
{
    root = sil(veri, root);
}
int AVL::yukseklik()
{
    return yukseklik(root);
}

//void AVL::postOrder() {
//    postOrder(0);
//}


void AVL::postOrder(DugumAVL* aktif)
{
    if (aktif)
    {

        postOrder(aktif->sol);
        postOrder(aktif->sag);
            
        if (aktif->sag == NULL && aktif->sol == NULL)
        {
            //cout <<"yaprakta" << aktif->veri << "  ";
            AVLYigin->ekle(aktif->veri);

        }
        else
        {
            //cout << "dugumde"<< aktif->veri << "  ";
           
            AVLToplamDugumDeger += aktif->veri;

        }
    }
}

int AVL::yukseklik(DugumAVL* aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(yukseklik(aktifDugum->sol),
            yukseklik(aktifDugum->sag));
    }
    return -1;
}
DugumAVL* AVL::ekle(int veri, DugumAVL* aktifDugum)
{
    if (aktifDugum == 0)
        return new DugumAVL(veri);

    else if (aktifDugum->veri < veri && !varmi(veri))
    {
        aktifDugum->sag = ekle(veri, aktifDugum->sag);
        if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1)
        {
            if (veri > aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);

            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum = solaDondur(aktifDugum);
            }
        }
    }
    else if (aktifDugum->veri > veri && !varmi(veri))
    {
        aktifDugum->sol = ekle(veri, aktifDugum->sol);
        if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
        {

            if (veri < aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum = sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
DugumAVL* AVL::solaDondur(DugumAVL* buyukEbeveyn)
{
    DugumAVL* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
DugumAVL* AVL::sagaDondur(DugumAVL* buyukEbeveyn)
{
    DugumAVL* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int AVL::maxDeger(DugumAVL* aktif)
{
    if (aktif->sag)
        return maxDeger(aktif->sag);

    return aktif->veri;
}
bool AVL::varmi(int aranan, DugumAVL* aktif)
{
    if (aktif->veri < aranan)
    {
        if (aktif->sag)
            return varmi(aranan, aktif->sag);
        else
            return 0;
    }
    else if (aktif->veri > aranan)
    {
        if (aktif->sol)
            return varmi(aranan, aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}
DugumAVL* AVL::sil(int veri, DugumAVL* aktif)
{
    if (aktif == 0)
        return 0;

    if (veri < aktif->veri)
    {
        aktif->sol = sil(veri, aktif->sol);
    }
    else if (veri > aktif->veri)
    {
        aktif->sag = sil(veri, aktif->sag);
    }
    else
    {
        if (aktif->sol == 0 && aktif->sag == 0)
        {
            delete aktif;
            aktif = 0;
        }
        else if (aktif->sol == 0)
        {
            DugumAVL* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if (aktif->sag == 0)
        {
            DugumAVL* sil = aktif->sol;
            *aktif = *aktif->sol;
            delete sil;
        }
        else
        {
            aktif->veri = minDeger(aktif->sag);
            sil(aktif->veri, aktif->sag);
        }


    }


    int denge = dengesizlikYonu(aktif);

    if (denge > 1)
    {
        if (dengesizlikYonu(aktif->sol) >= 0)
        {
            return sagaDondur(aktif);
        }
        //sol sag durumu
        if (dengesizlikYonu(aktif->sol) < 0)
        {
            aktif->sol = solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }
    else if (denge < -1)
    {
        if (dengesizlikYonu(aktif->sag) <= 0)
        {
            return solaDondur(aktif);
        }
        if (dengesizlikYonu(aktif->sag) > 0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }
    return aktif;
}


int AVL::dengesizlikYonu(DugumAVL* aktif)
{
    if (aktif == 0)
        return 0;
    return yukseklik(aktif->sol) - yukseklik(aktif->sag);
}

int AVL::minDeger(DugumAVL* aktif)
{
    if (aktif->sol)
        return maxDeger(aktif->sol);

    return aktif->veri;
}

int AVL::SatirSayisi(string path)
{
    int satirSayisi = 0;
    string satir;
    ifstream dosyaOku("src/Sayilar.txt");
    while (std::getline(dosyaOku, satir))
    {
        satirSayisi++;
    }
    dosyaOku.close();
    return satirSayisi;

}

void AVL::yazdir(AVL** dizi, int satirSayisi) {
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->root != NULL) {
            cout << dizi[i]->ascii;
        }
    }
}

int AVL::enKucukDegeriBul(AVL** dizi, int satirSayisi, int enKucuk = 99999, int silinecek = 0)
{
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL) {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }
    }
    return silinecek;
}

int AVL::enBuyukDegeriBul(AVL** dizi, int satirSayisi, int enBuyuk = 0, int silinecek = 0)
{
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->AVLYigin->getir() > enBuyuk && dizi[i]->root != NULL) {
            enBuyuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }
    }
    return silinecek;
}

void AVL::avlYiginTemizleVePostOrder(AVL** dizi, int satirSayisi)
{
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->root != NULL) {
            dizi[i]->AVLYigin->temizle();
            dizi[i]->postOrder(dizi[i]->root);
        }
    }
}

void AVL::YazdirSonAVL(int index, AVL** dizi)
{
    if (dizi[index]->root != NULL)
    {
        /*cout << "==============================" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "|     " << "Son Karakter : " << dizi[index]->ascii << setw(8) << "|" <<endl;
        cout << "|     " << "AVL No       : " << setw(3) << index + 1 << "     |" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "==============================" << endl;*/

        std::cout << std::setw(30) << "" << std::endl;
        std::cout << "|                            |\n";
        std::cout << "|    Son Karakter  :  " << std::setw(7) << dizi[index]->ascii << "    |\n";
        std::cout << "|    AVL No             :  " << std::setw(3) << index + 1 << "    |\n";
        std::cout << "|                            |\n";
        std::cout << "|                            |\n";
        std::cout << std::setw(30) << "" << std::endl;

    }
}
