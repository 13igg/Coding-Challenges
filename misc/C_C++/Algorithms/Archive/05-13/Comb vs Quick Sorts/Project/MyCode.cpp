//Sorting
#include <iostream>
#include "SortVector.h"
#include <algorithm>
using namespace std;

int partition(SortVector& a, int first, int last) {
  int pivot = a[first];
  int lastS1 = first;
  int firstUnknown = first + 1;
  while (firstUnknown <= last) {
    if (a[firstUnknown] < pivot) {
      lastS1++;
      std::swap(a[firstUnknown], a[lastS1]);
    }
    firstUnknown++;
  }
  std::swap(a[first], a[lastS1]);
  return lastS1;
}


void quicksort1(SortVector& a, int first, int last) {
  if (first < last) {
    int pivotIndex = partition(a, first, last);
    quicksort1(a, first, pivotIndex - 1);
    quicksort1(a, pivotIndex + 1, last);
  }
}

void quicksort(SortVector& a) {
  quicksort1(a, 0, a.size() - 1);
}

void bubblesort(SortVector& a) {
  for (;;) {
    bool swapped = false;
    for (int i = 0; i < a.size() - 1; i++) {
      int j = i + 1;
      if (a[i] > a[j]) {
        std::swap(a[i], a[j]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}
int newGap(int gap) {
  gap = (gap * 10) / 13;
  if (gap == 9 || gap == 10)
    gap = 11;
  if (gap < 1)
    gap = 1;
  return gap;
}

void combsort(SortVector& a) {
  int gap = a.size();
  for (;;) {
    gap = newGap(gap);
    bool swapped = false;
    for (int i = 0; i < a.size() - gap; i++) {
      int j = i + gap;
      if (a[i] > a[j]) {
        std::swap(a[i], a[j]);
        swapped = true;
      }
    }
    if (gap == 1 && !swapped)
      break;
  }
}
int my_partition(SortVector& v, int first, int last)
{
	int pivot = v[last];
	int left = first - 1;
	int right = last;
	while(true)
	{
		while(v[++left] <  pivot);
		while(v[--right] > pivot)
			if(right == first)
				break;
		if(left >= right)
			break;
		swap(v[left], v[right]);
	}
	swap(v[left], v[last]);
	return left;
}
void my_quick_sort1(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	int i = my_partition(v, first, last);
	my_quick_sort1(v, first, i-1);
	my_quick_sort1(v, i+1, last);
}
void my_quicksort(SortVector& a) 
{
  my_quick_sort1(a, 0, a.size() - 1);
}





int main()
{
	srand(time(NULL));

	SortVector v(10000000);
	SortVector w(v);
	w = v; w.sort( quicksort, "Quick Sort ");
	w = v; w.sort( my_quicksort, "My Quick Sort ");
	w = v; w.sort( combsort, "Comb Sort ");
	//w = v; w.sort( bubblesort, "Bubble Sort ");

	int end;
	w = v;
	begin_timer();
	sort(w.begin(), w.end());
	end = end_timer();
	cout << end << endl;

	system("pause");
	return 0;
}



