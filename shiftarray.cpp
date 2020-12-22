
#include <iostream>


void reversArray(int A[], int n) {
    for (int left = 0, right = n - 1; left < right; ++left, --right) {
        int tmp = A[left]; A[left] = A[right]; A[right] = tmp;
    }
}


void shiftArray(int A[], int n, int k) {
    while (k < 0) {
        k += n;
    }
    while (k >= n) {
        k -= n;
    }
    if (k > 0) {
        reversArray(A, k);
        reversArray(A + k, n - k);
        reversArray(A, n);
    }

/*
    while (k > 0) {
        int tmp = A[0];
        for (int i = 0; i < n - 1; ++i) {
            A[i] = A[i + 1];
        }
        A[n - 1] = tmp;
        --k;
    }
*/
}

void printArray(const int A[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << A[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    int n = 10;
    int* M = new int[n];
    for (int i = 0; i < n; ++i)
        M[i] = i + 1;

    shiftArray(M, n, 7);
    printArray(M, n);
    
    const int C[] = { 1,2,3,4,5 };
    //shiftArray(C, sizeof(C) / sizeof(C[0]), 3);
    printArray(C, sizeof(C)/sizeof(C[0]));
    delete[] M;
    return 0;
}
