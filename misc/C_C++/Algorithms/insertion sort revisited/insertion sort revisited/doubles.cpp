//Insertion Sort
#include <iostream>
#include "SortVector.h"
#include <algorithm>
using namespace std;

//Paired insertion sort
//Modify insertion_sort2 so that a pair of next elements are to be considered.
//Determine their positions, and then shift the other elements to make room.
//(The savings come when elements are shifts two spaces at once...)
void insertion_sort3(SortVector& v)
{
	int i;		//Started index of next value to be inserted
	int j;		//Index of values being shifted to the back

	int pos1;	//Index where next value will be inserted
	int pos2;	//Index where next value will be inserted
	int save1;
	int save2;	


	for(i = v.size(); i >= 0; i--)
	{
		save1 = v[i];
		save2 = v[i-1];
		if(save1 > save2)
		{	
			for(pos1 = i; pos1 > 0 && save1 < v[pos1-1]; pos1--);			
			for(pos2 = pos1; pos2 > 0 && save2 < v[pos2-1]; pos2--);
			for(j = i; j > pos1; j--)
				v[j] = v[j-2];
			v[pos1] = save1;	

			for(j = pos1; j > pos2; j--)
				v[j] = v[j-2];				
			v[pos2] = save2;
		}
		else
		{
		}

	}
}

int main()
{
	srand(time(NULL));

	int N = 100000, end;
	SortVector v(N);
	SortVector w(v);

	w = v;
	begin_timer();
	insertion_sort3(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "Paired Insertion Sort Time: " << end << endl;

	system("pause");
	return 0;
}



