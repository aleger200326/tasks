#include <iostream>

#define SORTSTAT
#include "sorters.h"

void RandomArray(int *M, int Len) {
	for (int i = 0; i < Len; ++i)
		M[i] = rand() % 9000 + 1000;
}

void SortedArray(int* M, int Len) {
	for (int i = 0; i < Len; ++i)
		M[i] = i+1;
}

void ReversedArray(int* M, int Len) {
	for (int i = 0; i < Len; ++i)
		M[i] = Len-i;
}

void NearlyReversedArray(int* M, int Len) {
	for (int i = 0; i < Len; ++i)
		M[i] = Len - i;
	for (int i = 0; i < Len / 2; i += 2)
		std::swap(M[i], M[i + 1]);
}

void QuickSortKillerArray(int* M, int Len) {
	for (int i = 0; i < Len; ++i) M[i] = i;
	for (int i = 2; i < Len; ++i) std::swap(M[i], M[i/2]);
}

void ConstArray(int* M, int Len) {
	for (int i = 0; i < Len; ++i) M[i] = 1;
}


void print(int* M, int Len, const char* str = "") {
	std::cout << str;
	for (int i = 0; i < Len; ++i)
		std::cout << ' ' << M[i];
	std::cout << std::endl;
}

bool isSorted(int* M, int Len) {
	for (int i = 1; i < Len; ++i)
		if (M[i] < M[i - 1])
			return false;
	return true;
}

void SortArray(  void (*sorter)(int *, int), int *A, int Len, const char *arrayname) {
	std::cout << "--- Array: " << arrayname << std::endl;
	if (Len < 25) print(A, Len, "Before: ");
	sorter(A, Len);
	if (!isSorted(A, Len))
		std::cout << "ERROR: Not sorted!" << std::endl;
	if (Len < 25) print(A, Len, "After: ");
}

void Tester(void (*sorter)(int*, int), const int *RandArray, int Len, const char *name) {
	std::cout << std::endl << "=========== Method: " << name << " =================" << std::endl;
	int* A = new int[Len];
	SortedArray(A, Len);
	SortArray(sorter, A, Len, "Sorted: ");

	ConstArray(A, Len);
	SortArray(sorter, A, Len, "Constants: ");

	ReversedArray(A, Len);
	SortArray(sorter, A, Len, "Reversed: ");
	
	NearlyReversedArray(A, Len);
	SortArray(sorter, A, Len, "Nearly reversed: ");

	QuickSortKillerArray(A, Len);
	SortArray(sorter, A, Len, "QuickSort Killer: ");

	for (int i = 0; i < Len; ++i) A[i] = RandArray[i];
	SortArray(sorter, A, Len, "Random: ");

	delete[] A;
}


int main()
{
	srand((unsigned int)time(NULL));
	int N;
	do {
		std::cout << "Array size: ";
		std::cin >> N;
	} while (N<1);
	int* M = new int[N];
	RandomArray(M, N);
	
	Tester(BubbleSort, M, N, "Bubble sorting");
	Tester(ChooseSort, M, N, "Choose sorting");
	Tester(InsertSort, M, N, "Insert sorting");
	Tester(InsertSortA, M, N, "Insert sorting (advanced)");
	//Tester(QuickSortR, M, N, "Quick sorting (recursive)");
	Tester(QuickSortS, M, N, "Quick sorting");
	Tester(MergeSort, M, N, "Merge sorting");
	Tester(MergeSortA, M, N, "Merge sorting (advanced)");
	Tester(HeapSort, M, N, "Heap sorting");

	delete[] M;
	return 0;
}
