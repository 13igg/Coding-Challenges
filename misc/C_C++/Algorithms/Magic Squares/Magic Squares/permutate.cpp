#include <iostream>
#include <algorithm>
using namespace std;

int malin()
{
	int a[4] = {1,2,3,4};

	while (true)
	{
		cout << a[0]<< " " << a[1] << " " << a[2] << " " << a[3] << endl;

		int y,q;
		for(y = 2; y >=0 && (a[y] > a[y+1]); y --);
		if(y == -1) break;
				
		for(q = 3; (a[q] < a[y]); q --);
	
		swap(a[y],a[q]);
		reverse(a+y+1,a+4);
	}
	system("pause");
	return 0;
}