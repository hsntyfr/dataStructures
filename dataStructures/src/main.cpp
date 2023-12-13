#include <iostream>
#include "AVL.h"
#include "Yigin.h"
#include "DinamikDizi.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{   
    string satir = "";
    ifstream dosya("src/Sayilar.txt");
    int satirSayisi = AVL::SatirSayisi("src/Sayilar.txt");
    //cout << satirSayisi << endl;

    AVL** dizi = new AVL * [satirSayisi];
    int index = 0;
    while (getline(dosya, satir))
    {
        istringstream iss(satir);
        int sayi;
        dizi[index] = new AVL();


        while (iss >> sayi)
        {
            dizi[index]->ekle(sayi);
        }
        dizi[index]->postOrder(dizi[index]->root);

        int ascii1 = dizi[index]->AVLToplamDugumDeger % (90 - 65 + 1) + 65;
        dizi[index]->ascii = (char)ascii1;
        cout << dizi[index]->ascii;
        index++;
    }
    cout << endl;


    int silinecek = 0;
    int enBuyuk = 0;
    int enKucuk = 99999;
    int sayac = 0;
    int bitti = 0;

    while (true)
    {
        //kucuk sayi cikti
        for (int i = 0; i < satirSayisi; i++)
        {
            if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
            {
                enKucuk = dizi[i]->AVLYigin->getir();
                silinecek = i;
            }

        }
        //cout << enKucuk << endl;
        enKucuk = 99999;
        dizi[silinecek]->AVLYigin->cikar();
        //cikan sayi yiginin sonuysa o yiginin rootu silindi
        if (dizi[silinecek]->AVLYigin->getir() == -1)
        {
            dizi[silinecek]->root = NULL;
            sayac++;
            for (int i = 0; i < satirSayisi; i++)
            {
                if (dizi[i]->root != NULL)
                {
                    cout << dizi[i]->ascii;
                }
            }

            cout << endl;


            for (int i = 0; i < satirSayisi; i++)
            {
                if (dizi[i]->root != NULL)
                {
                    dizi[i]->AVLYigin = new Yigin();
                    dizi[i]->postOrder(dizi[i]->root);
                }
            }
            if (sayac + 1 == satirSayisi)
            {
                int i = 0;
                while (dizi[i]->root == NULL)
                {
                    i++;
                }
                cout << i << endl;
                return 0;
            }
            continue;
        }

        for (int i = 0; i < satirSayisi; i++)
        {
            if (dizi[i]->AVLYigin->getir() > enBuyuk && dizi[i]->root != NULL)
            {
                enBuyuk = dizi[i]->AVLYigin->getir();
                silinecek = i;
            }

        }
        //cout << enBuyuk << endl;
        enBuyuk = 0;
        dizi[silinecek]->AVLYigin->cikar();

        if (dizi[silinecek]->AVLYigin->getir() == -1)
        {
            dizi[silinecek]->root = NULL;
            sayac++;

            for (int i = 0; i < satirSayisi; i++)
            {
                if (dizi[i]->root != NULL)
                {
                    cout << dizi[i]->ascii;
                }
            }
            cout << endl;
            for (int i = 0; i < satirSayisi; i++)
            {
                if (dizi[i]->root != NULL)
                {
                    dizi[i]->AVLYigin = new Yigin();
                    dizi[i]->postOrder(dizi[i]->root);
                }
            }
        }
        if (sayac + 1 == satirSayisi)
        {
            int i = 0;
            while (dizi[i]->root == NULL)
            {
                i++;
            }
            cout << i << endl;
            return 0;
        }


    }

  
    

    /*for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enKucuk << endl;
    enKucuk = 99999;
    dizi[silinecek]->AVLYigin->cikar();
    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;

    }



    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() > enBuyuk && dizi[i]->root != NULL)
        {
            enBuyuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enBuyuk << endl;
    enBuyuk = 0;
    dizi[silinecek]->AVLYigin->cikar();

    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }

    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enKucuk << endl;
    enKucuk = 99999;
    dizi[silinecek]->AVLYigin->cikar();

    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }
 
    for (int i = 0; i < satirSayisi; i++)
    {


        if (dizi[i]->root != NULL)
        {
            cout << dizi[i]->ascii;
        }

    }

    for (int i = 0; i < satirSayisi; i++)
    {


        if (dizi[i]->root != NULL)
        {
            dizi[i]->AVLYigin = new Yigin();
            dizi[i]->postOrder(dizi[i]->root);
        }

    }



    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enKucuk << endl;
    enKucuk = 99999;
    dizi[silinecek]->AVLYigin->cikar();
    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }

    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() > enBuyuk && dizi[i]->root != NULL)
        {
            enBuyuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enBuyuk << endl;
    enBuyuk = 0;
    dizi[silinecek]->AVLYigin->cikar();

    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }
    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }

    }
    cout << enKucuk << endl;
    enKucuk = 99999;
    dizi[silinecek]->AVLYigin->cikar();
    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }

    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() > enBuyuk && dizi[i]->root != NULL)
        {
            enBuyuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }
    }
    cout << enBuyuk << endl;
    enBuyuk = 0;
    dizi[silinecek]->AVLYigin->cikar();

    if (dizi[silinecek]->AVLYigin->getir() == -1)
    {
        dizi[silinecek]->root = NULL;
        sayac++;
    }

    for (int i = 0; i < satirSayisi; i++)
    {
        if (dizi[i]->AVLYigin->getir() < enKucuk && dizi[i]->root != NULL)
        {
            enKucuk = dizi[i]->AVLYigin->getir();
            silinecek = i;
        }
    }
    

    if (sayac + 1 == satirSayisi)
    {
        for (int i = 0; i < satirSayisi; i++)
        {
            if (dizi[i]->root != NULL)
            {
                cout << dizi[i]->ascii;
            }
        }
        return 0;
    }


    dizi[0]->AVLYigin->cikar();
    cout << dizi[0]->AVLYigin->getir();
    cout << sayac;*/




























    //cout << dizi[1]->AVLYigin->getir();
    

    /*cout << dizi[0]->AVLYigin->getir();
    dizi[0]->AVLYigin->cikar();
    cout << dizi[0]->AVLYigin->getir();
    dizi[0]->AVLYigin->cikar();
    cout << dizi[0]->AVLYigin->getir();

    cout << dizi[2]->AVLYigin->getir();
    dizi[2]->AVLYigin->cikar();
    cout << dizi[2]->AVLYigin->getir();
    dizi[2]->AVLYigin->cikar();
    cout << dizi[2]->AVLYigin->getir();

    cout << endl;

    cout << dizi[1]->AVLYigin->getir();
    dizi[1]->AVLYigin->cikar();
    cout << dizi[1]->AVLYigin->getir();
    dizi[1]->AVLYigin->cikar();
    cout << dizi[1]->AVLYigin->getir();*/
    


    
    

   
    

    return 0;




}


