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
	DugumAVL* sil(int veri, DugumAVL* aktif);

	bool varmi(int veri);
	void ekle(int veri);
	void sil(int veri);
	int yukseklik();
	void postOrder();
	int dengesizlikYonu(DugumAVL* aktif);
	DugumAVL* solaDondur(DugumAVL* dugum);
	DugumAVL* sagaDondur(DugumAVL* dugum);
	int minDeger(DugumAVL* aktif);
	void postOrder(DugumAVL* index);
	int yukseklik(DugumAVL* aktifDugum);
	DugumAVL* ekle(int veri, DugumAVL* aktifDugum);
	bool varmi(int aranan, DugumAVL* aktif);
	int maxDeger(DugumAVL* aktif);

	DugumAVL* root;
	int AVLToplamDugumDeger;
	Yigin* AVLYigin;
};
#endif