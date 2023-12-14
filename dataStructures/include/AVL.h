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
	//DugumAVL* sil(int veri, DugumAVL* aktif);
	void ekle(int veri);
	//void sil(int veri);
	//int yukseklik();
	int dengesizlikYonu(DugumAVL* aktif);
	DugumAVL* solaDondur(DugumAVL* dugum);
	DugumAVL* sagaDondur(DugumAVL* dugum);
	int minDeger(DugumAVL* aktif);
	void postOrder(DugumAVL* index);
	int yukseklik(DugumAVL* aktifDugum);
	DugumAVL* ekle(int veri, DugumAVL* aktifDugum);
	int maxDeger(DugumAVL* aktif);
	static int SatirSayisi(string path);
    void sil(DugumAVL* root);
    static void yazdir(AVL** dizi, int satirSayisi);
    static int enKucukDegeriBul(AVL** dizi, int satirSayisi, int enKucuk, int silinecek);
    static int enBuyukDegeriBul(AVL** dizi, int satirSayisi, int enBuyuk, int silinecek);
    static void avlYiginTemizleVePostOrder(AVL** dizi, int satirSayisi);
    static void YazdirSonAVL(int index, AVL** dizi);

    DugumAVL* root;
	int AVLToplamDugumDeger;
	Yigin* AVLYigin;
	char ascii;
};
#endif