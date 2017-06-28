// Задача 1 .Сортування.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// -------------------------------------------------------------------------
//Buble Sort
vector<int> buble(vector<int> &massive)
{
	bool WasSwapped = true;
	for (int i = 0;i < size(massive) && WasSwapped;i++)
	{
		WasSwapped = false;
		for (int j = 0;j < size(massive)-i-1;j++)
			if (massive[j]>massive[j + 1])
			{
				WasSwapped = true;
				swap(massive[j], massive[j + 1]);
			}
	}
	return massive;
}
//----------------------------------------------------------------------------
//Insertion Sort

vector<int> insertion(vector<int>massive)
{
	int i, j;
		for ( i = 0; i < size(massive); i++) {  
			int a = massive[i];

			//the search space of the element in the finished sequence
			for (j = i - 1; j >= 0 && massive[j] > a; j--)

				massive[j + 1] = massive[j];  	// move the element to the right until  reach
								// insertion of the element
				massive[j +1] = a;
			
		}
			return massive;
	}


//-----------------------------------------------------------------------------
//Sorting option (Select Sort)

vector<int> select(vector<int>massive)
{
	long i, j, k;
	int x;

	for (i = 0; i < size(massive); i++) {   	// i - number of the step
		k = i; x = massive[i];

		for (j = i + 1; j < size(massive); j++)	// finding minimal element
			if (massive[j] < x) {
				k = j; x = massive[j];	        // k - index of the minimal element
			}

		massive[k] = massive[i]; massive[i] = x;   	// swap minimal and i element
	}
	return massive;
}

//------------------------------------------------------------------------------
//Quick Sort
void quickSort(vector<int> &massive, int start,int n) {
	// Input - massiv massive[], massive[n] - the last element.

	int i =start, j = n -1; 		
	int  p;

	p = massive[(start+n)/2];		// midle element

						// procedure division
	do {
		while (massive[i] < p) i++;
		while (massive[j] > p) j--;

		if (i <= j) {
			swap(massive[i], massive[j]);
			i++; j--;
		}
	} while (i <= j);


	//recursive calls, if you have something to sort
	 if (j >start) quickSort(massive, start,j);
	if (n > i) quickSort( massive,i, n);
}

//--------------------------------------------------------
//Merge Sort

vector <int> merge(vector <int> a, vector <int> b)
{
	vector<int> result;
	int count1 = 0;//for а
	int count2 = 0;//for b
	while (count1!=size(a)|| count2!=size(b))
	{	if (count1 == a.size())
		{
			result.push_back ( b[count2]);
			count2++;
			continue;
		}
		if (count2 == b.size())
		{
			result.push_back( a[count1]);
			count1++;
			continue;
		}
		//if size of our vectors!=0
		if (a[count1] <= b[count2])
		{
			result.push_back( a[count1]);
			count1++;
		}
		else
		{
			result.push_back( b[count2]);
			count2++;
		}
	}
	return result;
}

vector<int> merge_sort(vector <int> a)
{
	if (a.size() <= 1)
		return a;
	vector<int> b, c;
	b.assign(a.begin(), a.end() - (a.size() / 2));
	c.assign(a.end() - (a.size() / 2), a.end());
	return merge(merge_sort(b), merge_sort(c));
}
//---------------------------------------------------------
//HeapSort

void downHeap(vector<int> &massive, int k,int n) {
  //  the procedure of sifting the next item 
 // Procedure: a[k+1]...a[n] - pyramid 
// Post: a[k]...a[n] -heap
	int new_elem;
	int child;
	new_elem = massive[k];

	while (k<=n/2) {  		// while massive[k] has children 
		child = 2 * (k);
		//  choose the biggest son
		if (child < n && massive[child] <massive[child + 1])
			child++;
		if (new_elem >= massive[child]) break; // there is no necessary to swap son and father
				massive[k] = massive[child]; 	// swap son and father 
		k = child;
	}
	massive[k] = new_elem;
}
void heapSort(vector<int> &massive, int size) {
	int i;

	// build heap
	for (i = size / 2 ; i >= 0; i--) downHeap(massive, i, size-1 );

	// now a[0]...a[size-1] heap 

	for (i = size-1 ; i > 0; i--) {
		// swap first and last elements
		swap(massive[0],massive[i]);

		// restoring the pyramidal a[0]...a[i-1] 
		downHeap(massive, 0, i-1);
	}
}

//----------------------------------------------------------
//RadixSort

/*#include <queue>

int getMax(vector<int>mas, int n)
{
	int a, b = -15648;
	for (int i = 0;i < n;i++)
		if (b < mas[i])
			b = mas[i];
	a = 1;
	while (b != 0) {
		a++;
		b /= 10;
	}
	return a;
}



void Bubble_SortExp(vector<int> &arr, int exp)
{
	vector<int> b[10];
	for (int i = 0; i < arr.size(); ++i)
		b[arr[i] % (int)pow(10, exp)].push_back(arr[i]);

	for (int i = 0, k=0; i < 10; ++i) {
		for (int j = 0; j < b[i].size(); ++j)
			arr[k++] = b[i][j];
	}

/*	vector<queue<int>> temp(9);
	for (int i = 0;i < arr.size();i++) {
		temp[arr[i] % pow(10, exp) / pow(10, exp - 1)].push(arr[i]);
	}
	for (int i = 0;i < arr.size();i++)
		arr[i]=temp
}
vector <int>RadixSort(vector<int>massive,int n)
{

		// Find the maximum number to know number of digits
		int m = getMax(massive, n);

		// Do bubble sort for every digit.
		for (int exp = 1; exp < m; exp++)
			Bubble_SortExp(massive, exp);
		return massive;
}*/


void radixsort(vector<int> &massive, int n)
{
	vector<int> buckets[2];
	for (int i = 0; i < 32; i++) {
		for  (int j = 0; j < size(massive); j++)
			buckets[(massive[j] >> i) & 1].push_back(massive[j]);
		for (int j=0 , k=0; j < 2; j++) { 
			for (int f = 0; f < buckets[j].size(); f++)
				massive[k++] = buckets[j][f];
			buckets[j].clear();
		}
	}
}


//----------------------------------------------------------
vector <int> read(vector<int>massive)
{
	ifstream in("1.3.txt");
	if (!in.is_open())
	{
		cout << "File could not be opened!\n";
		system("pause");
		exit(1);
	}
	int a;
	while (in >> a)
		massive.push_back(a);
	return massive;
}

void write(vector<int> massive)
{
	vector <int> m1 = massive;
	cout << "Bublt sort :\n";
	m1 = buble(massive);
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	cout << "Insertion sort:\n";
	m1 = insertion(massive);
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	m1 = select(massive);
	cout << "Select sort:\n";
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	cout << "Quick sort:\n";
	m1 = massive;
	quickSort(m1, 0, size(m1));
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	cout << "Merge sort:\n";
	m1 = merge_sort(massive);
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	cout << "Heap sort:\n";
	m1 = massive;
	heapSort(m1, size(m1));
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
	cout << "Radix sort:\n";
	m1 = massive;
	radixsort(m1, size(m1));
	for (int i = 0;i < massive.size();i++)
		cout << m1[i] << " ";
	cout << endl;
}


int main()
{
	vector<int> massive=read(massive);
	write(massive);
	system("pause");
    return 0;
}

