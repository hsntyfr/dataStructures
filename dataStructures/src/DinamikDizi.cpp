#include "DinamikDizi.h"

DinamikDizi::DinamikDizi()
{
	dizi = NULL;
	kapasite = 0;
	boyut = 0;
}

DinamikDizi::~DinamikDizi()
{
    if (dizi != nullptr) {
        for (int i = 0; i < boyut; ++i)
        {
            delete dizi[i];
        }
        delete[] dizi;
    }
}

void DinamikDizi::Ekle(AVL* agac) 
{
    if (boyut >= kapasite)
    {
        int yeniKapasite;
        if (kapasite == 0)
        {
            yeniKapasite = 5;
        }
        else
        {
            yeniKapasite = kapasite * 2;
        }

        AVL **yeniDizi = new AVL *[yeniKapasite];

        for (int i = 0; i < boyut; ++i) {
            yeniDizi[i] = dizi[i];
        }

        delete[] dizi;
        dizi = yeniDizi;
        kapasite = yeniKapasite;
    }

    dizi[boyut] = agac;
    ++boyut;
}


int DinamikDizi::geriDondur()
{
    return boyut;
}