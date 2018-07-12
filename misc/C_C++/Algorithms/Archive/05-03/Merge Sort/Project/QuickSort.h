int partition(SortVector& v, int first, int last)
{
	int left = first - 1;
	int right = last;
	while(true)
	{
		while(v[++left] <  v[last]);
		while(v[--right] > v[last])
			if(right == first)
				break;
		if(left >= right)
			break;
		swap(v[left], v[right]);
	}
	swap(v[left], v[last]);
	return left;
}

void quick_sort(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	int i = partition(v, first, last);
	quick_sort(v, first, i-1);
	quick_sort(v, i+1, last);
}

//Quick Sort with simple median of three improvement
//Given at least three elements, 
//  find the median of the first, middle, and last elements,
//  and swap it into the last place to serve as the pivot.
void quick_sort1(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	if(last - first >= 2)
	{
		int mid = (first + last) / 2;

		if(v[first] < v[mid])
		{
			if(v[mid] > v[last])
				swap(v[mid], v[last]);
			else if(v[last] < v[first])
				swap(v[first], v[last]);
		}
		else
		{
			if(v[first] < v[last])
				swap(v[first],v[last]);
			else if(v[last] < v[mid])
				swap(v[mid], v[last]);
		}
	}
	int i = partition(v, first, last);
	quick_sort1(v, first, i-1);
	quick_sort1(v, i+1, last);
}
//Same as quick_sort1 except a more efficient pre-sort
void quick_sort2(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	if(last - first >= 2)
	{
		int mid = (first + last) / 2;

	}
	int i = partition(v, first, last);
	quick_sort2(v, first, i-1);
	quick_sort2(v, i+1, last);
}