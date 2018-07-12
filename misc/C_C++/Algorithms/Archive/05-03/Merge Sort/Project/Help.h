void quick_sort2(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	if(last - first >= 2)
	{
		int mid = (first + last) / 2;

		if(v[first] < v[mid])
		{
			if(v[mid] < v[last])
				swap(v[mid],v[last]);
			else if(v[last] < v[first])
				swap(v[first],v[last]);
		}
		else
		{
			if(v[first] < v[last])
				swap(v[first],v[last]);
			else if(v[last] < v[mid])
				swap(v[mid],v[last]);
		}

	}
	int i = partition(v, first, last);
	quick_sort2(v, first, i-1);
	quick_sort2(v, i+1, last);
}

////////////////////////////////////
//	Merge Sort with 3 part division
////////////////////////////////////
void tri_merge(SortVector& v, int first, int mid1, int mid2, int last)
{
	for(int i = first; i <= last; i++)
		aux[i] = v[i];

	int p1 = first, p2 = mid1 + 1, p3 = mid2 + 1;
	for(int pos = first; pos <= last; pos++)
	{
		if(p1 > mid1)
		{
			if(p2 > mid2)
				v[pos] = aux[p3++];
			else if(p3 > last)
				v[pos] = aux[p2++];
			else if(aux[p2] <= aux[p3])
				v[pos] = aux[p2++];
			else
				v[pos] = aux[p3++];
		}
		else if(p2 > mid2)
		{
			if(p3 > last)
				v[pos] = aux[p1++];
			else if(aux[p1] <= aux[p3])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p3++];
		}
		else if(p3 > last)
		{
			if(aux[p1] <= aux[p2])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p2++];
		}
		else if(aux[p1] <= aux[p2])
		{
			if(aux[p1] <= aux[p3])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p3++];
		}
		else if(aux[p2] <= aux[p3])
			v[pos] = aux[p2++];
		else
			v[pos] = aux[p3++];
	}
}
void tri_merge_sort(SortVector& v, int first, int last)
{
	if(first == last)		//Size == 1
		return;
	
	if(last - first <= 1)	//Size == 2
	{
		if(v[last] < v[first])
			swap(v[first],v[last]);
		return;
	}
	int mid1 = (2*first + last) / 3;
	int mid2 = (first + 2*last) / 3;
	tri_merge_sort(v, first, mid1);
	tri_merge_sort(v, mid1+1, mid2);
	tri_merge_sort(v, mid2+1, last);
	tri_merge(v, first, mid1, mid2, last);
}