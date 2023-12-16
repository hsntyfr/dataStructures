#include "AVL.h"
#include "Yigin.h"
#include<iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

AVL::AVL()
{
    Root = 0;
    AVLToplamDugumDeger = 0;
    AVLYigin = new Yigin();
}

AVL::~AVL()
{

}

void AVL::Sil(DugumAVL* root)
{
    if (root == nullptr)
    {
        return;
    }

    Sil(root->Sol);
    Sil(root->Sag);

    delete root;
}

void AVL::Ekle(int eklenecek)
{
    Root = Ekle(eklenecek, Root);
}

void AVL::PostOrder(DugumAVL* aktif)
{
    if (aktif)
    {
        PostOrder(aktif->Sol);
        PostOrder(aktif->Sag);
            
        if (aktif->Sag == NULL && aktif->Sol == NULL)
        {
            AVLYigin->Ekle(aktif->Veri);
        }
        else
        {
            AVLToplamDugumDeger += aktif->Veri;
        }
    }
}

int AVL::Yukseklik(DugumAVL* aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(Yukseklik(aktifDugum->Sol), Yukseklik(aktifDugum->Sag));
    }
    return -1;
}

DugumAVL* AVL::Ekle(int veri, DugumAVL* aktifDugum)
{
    if (aktifDugum == 0)
    {
        return new DugumAVL(veri);
    }
    else if (aktifDugum->Veri < veri)
    {
        aktifDugum->Sag = Ekle(veri, aktifDugum->Sag);
        if (Yukseklik(aktifDugum->Sag) - Yukseklik(aktifDugum->Sol) > 1)
        {
            if (veri > aktifDugum->Sag->Veri)
            {
                aktifDugum = SolaDondur(aktifDugum);
            }
            else
            {
                aktifDugum->Sag = SagaDondur(aktifDugum->Sag);
                aktifDugum = SolaDondur(aktifDugum);
            }
        }
    }
    else if (aktifDugum->Veri > veri)
    {
        aktifDugum->Sol = Ekle(veri, aktifDugum->Sol);
        if (Yukseklik(aktifDugum->Sol) - Yukseklik(aktifDugum->Sag) > 1)
        {
            if (veri < aktifDugum->Sol->Veri)
                aktifDugum = SagaDondur(aktifDugum);
            else
            {
                aktifDugum->Sol = SolaDondur(aktifDugum->Sol);
                aktifDugum = SagaDondur(aktifDugum);
            }
        }
    }
    return aktifDugum;
}

DugumAVL* AVL::SolaDondur(DugumAVL* buyukEbeveyn)
{
    DugumAVL* sagCocuk = buyukEbeveyn->Sag;
    buyukEbeveyn->Sag = sagCocuk->Sol;
    sagCocuk->Sol = buyukEbeveyn;
    return sagCocuk;
}

DugumAVL* AVL::SagaDondur(DugumAVL* buyukEbeveyn)
{
    DugumAVL* solCocuk = buyukEbeveyn->Sol;
    buyukEbeveyn->Sol = solCocuk->Sag;
    solCocuk->Sag = buyukEbeveyn;
    return solCocuk;
}

int AVL::MaxDeger(DugumAVL* aktif)
{
    if (aktif->Sag)
    {
        return MaxDeger(aktif->Sag);
    }
    return aktif->Veri;
}

int AVL::DengesizlikYonu(DugumAVL* aktif)
{
    if (aktif == 0)
    {
        return 0;
    }
    return Yukseklik(aktif->Sol) - Yukseklik(aktif->Sag);
}

int AVL::MinDeger(DugumAVL* aktif)
{
    if (aktif->Sol)
    {
        return MaxDeger(aktif->Sol);
    }
    return aktif->Veri;
}

int AVL::SatirSayisi(string path)
{
    int satirSayisi = 0;
    string satir;
    ifstream dosyaOku(path);
    while (std::getline(dosyaOku, satir))
    {
        satirSayisi++;
    }
    dosyaOku.close();
    return satirSayisi;
}

void AVL::Yazdir(AVL** dizi, int satirSayisi)
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->Root != NULL) {
            cout << dizi[i]->ascii;
        }
    }
}

int AVL::EnKucukDegeriBul(AVL** dizi, int satirSayisi, int enKucuk = 99999, int silinecek = 0)
{
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->AVLYigin->Getir() < enKucuk && dizi[i]->Root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->Getir();
            silinecek = i;
        }
    }
    return silinecek;
}

int AVL::EnBuyukDegeriBul(AVL** dizi, int satirSayisi, int enBuyuk = 0, int silinecek = 0)
{
    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->Getir() > enBuyuk && dizi[i]->Root != NULL)
        {
            enBuyuk = dizi[i]->AVLYigin->Getir();
            silinecek = i;
        }
    }
    return silinecek;
}

void AVL::AVLYiginTemizleVePostOrder(AVL** dizi, int satirSayisi)
{
    for (int i = 0; i < satirSayisi; i++) {
        if (dizi[i]->Root != NULL) {
            dizi[i]->AVLYigin->Temizle();
            dizi[i]->PostOrder(dizi[i]->Root);
        }
    }
}

void AVL::YazdirSonAVL(int index, AVL** dizi)
{
    cout << "\033[2J\033[1;1H";
    if (dizi[index]->Root != NULL)
    {
        cout << "==============================" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "|    Son Karakter  : " << dizi[index]->ascii << "       |" << endl;
        cout << "|    AVL No        : " << setw(8) << left << index + 1 << "|" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "==============================" << endl;
    }
}

void AVL::AVLOlustur(AVL** &dizi, string path)
{
    string satir = "";
    ifstream dosya(path);
    int index = 0;
    while (getline(dosya, satir))
    {
        istringstream iss(satir);
        int sayi;
        dizi[index] = new AVL();


        while (iss >> sayi)
        {
            dizi[index]->Ekle(sayi);
        }
        dizi[index]->PostOrder(dizi[index]->Root);

        int ascii = dizi[index]->AVLToplamDugumDeger % (90 - 65 + 1) + 65;
        dizi[index]->ascii = (char) ascii;
        cout << dizi[index]->ascii;
        index++;
    }
    dosya.close();
}
