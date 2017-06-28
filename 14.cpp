// 14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
void siftDown(int *numbers, int root, int bottom) {
	int done, maxChild, temp;
	done = 0;
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild]) {
			temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}
void heapSort(int *numbers, int array_size) {
	int i, temp;
	for (i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	for (i = array_size - 1; i >= 1; i--) {
		temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}
int main() {
	int a[10];
	for (int i = 0;i < 10;i++)
		a[i] = rand() % 20 - 10;
	for (int i = 0;i < 10;i++)
		printf("%d ", a[i]);
	printf("\n");
	heapSort(a, 10);
	for (int i = 0;i < 10;i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}