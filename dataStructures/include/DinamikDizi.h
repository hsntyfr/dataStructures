#include "AVL.h"

class DinamikDizi
{
public:
	AVL **dizi;
	int kapasite;   
	int boyut;

	DinamikDizi();
	~DinamikDizi();
	void Ekle(AVL* agac);

	int geriDondur();



	
};