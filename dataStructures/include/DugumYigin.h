#ifndef DugumYigin_hpp
#define DugumYigin_hpp

#include <iostream>
using namespace std;

class DugumYigin
{
public:
    DugumYigin(int veri);
    ~DugumYigin();
    int veri;
    DugumYigin* sonraki;
};
#endif