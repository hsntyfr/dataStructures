#include "AVL.h"
#include "Yigin.h"
#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>

using namespace std;

AVL::AVL()
{
    root = 0;
    AVLToplamDugumDeger = 0;
    AVLYigin = new Yigin();
}
AVL::~AVL()
{
    
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

void AVL::postOrder() {
    postOrder(0);
}


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
    else//aradığımız düğümü bulduk
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

    if (denge > 1) //sol tarafta dengesizlik
    {
        //sol sol dengesizliği
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
    else if (denge < -1)//sag tarafta dengesizlik
    {
        //sağ sağ durumu
        if (dengesizlikYonu(aktif->sag) <= 0)
        {
            return solaDondur(aktif);
        }
        //sağ sol durumu
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

