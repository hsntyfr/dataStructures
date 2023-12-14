#ifndef DugumYigin_hpp
#define DugumYigin_hpp
#include <iostream>

using namespace std;

class DugumYigin
{
public:
    DugumYigin(int veri);
    ~DugumYigin();
    int Veri;
    DugumYigin* Sonraki;
};
#endif