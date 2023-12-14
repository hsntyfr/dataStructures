#ifndef AVL_hpp
#define AVL_hpp
#include<iostream>
#include "DugumAVL.h"
#include "Yigin.h"

using namespace std;

class AVL
{
public:
	AVL();
	~AVL();
	void Ekle(int veri);
	int DengesizlikYonu(DugumAVL* aktif);
	DugumAVL* SolaDondur(DugumAVL* dugum);
	DugumAVL* SagaDondur(DugumAVL* dugum);
	int MinDeger(DugumAVL* aktif);
	void PostOrder(DugumAVL* index);
	int Yukseklik(DugumAVL* aktifDugum);
	DugumAVL* Ekle(int veri, DugumAVL* aktifDugum);
	int MaxDeger(DugumAVL* aktif);
	static int SatirSayisi(string path);
    void Sil(DugumAVL* root);
    static void Yazdir(AVL** dizi, int satirSayisi);
    static int EnKucukDegeriBul(AVL** dizi, int satirSayisi, int enKucuk, int silinecek);
    static int EnBuyukDegeriBul(AVL** dizi, int satirSayisi, int enBuyuk, int silinecek);
    static void AVLYiginTemizleVePostOrder(AVL** dizi, int satirSayisi);
    static void YazdirSonAVL(int index, AVL** dizi);
    static void AVLOlustur(AVL** &dizi, string path);

    DugumAVL* Root;
	int AVLToplamDugumDeger;
	Yigin* AVLYigin;
	char ascii;
};
#endif