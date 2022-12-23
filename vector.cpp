#include "OYVector.h"
#include "OYVector.cpp"

int main()
{
	OYVector <int> y(1);
	y.push_back(9);	
	y.push_back(51);
	y.push_back(1);
	cout << y << endl;
	y.erase(y.begin());
	cout << y;
	OYVector <int> y2(1);
	y2.push_back(9);
	y2.push_back(51);
	y2.push_back(1);
	//cout << (y < y2);
	/*for (size_t i = 0; i < y.Size(); i++)
	{
		cout << y[i] << endl;
	}*/


}
