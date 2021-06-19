// Gosha_2sem_exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
class matrix
{
private:
    std::vector<int>v;
    int n,m;
public:
    matrix(int a = 1, int b = 1) : n(a),m(b)
    {
        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                v.push_back(0);
            }
        }
    }
    matrix(const matrix& A) : n(A.n), m(A.m)
    {
        for (int i = 0; i < A.v.size(); ++i)
        {
            v.push_back(A.v[i]);
        }
    }
    matrix(const matrix& A,int c) : n(A.n), m(A.m)
    {
        for (int i = 0; i < A.v.size(); ++i)
        {
            v.push_back(A.v[i]+c);
        }
    }
    int getsize() const
    {
        return v.size();
    }
    int operator[] (int i) const
    {
        return v[i];
    }
    int getn() const
    {
        return n;
    }
    int getm() const
    {
        return m;
    }
    ~matrix()
    {
        for (int i = 0; i < v.size(); ++i)
            v[i] = 0;
        n = 0;
        m = 0;
    }
};

std::ostream& operator<<(std::ostream& out, const matrix& X) {
    std::cout << X.getn() << " " << X.getm() << std::endl;
    for (int i = 0; i < X.getsize(); ++i)
    {
        std::cout << X[i] <<" ";
        if (i == X.getm() - 1) std::cout << std::endl;
    }
    std::cout << std::endl;
    return out;
}

int main()
{
    matrix A(2, 3);
    matrix B(A, 10);
    matrix C(B, -2);
    std::cout << B << std::endl;
    std::cout << C;
}