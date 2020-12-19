#include <iostream>
#include <stdarg.h>
using namespace std;
int even_count(int n, ...)
{
	int cnt=0;
	for(int* ptr=&n;n>0;n--)if(*(ptr)%2==0)cnt++;
	return cnt;
}
double srednee(int n, ...)
{
	double sum=0.0;
	int cnt=0;
	double arg=n;
	va_list args;
	va_start(args,n);
	do
	{
		sum+=arg;
		arg=va_arg(args,int);
		cnt++;
	}while(arg!=-1);
	va_end(args);
	return sum/cnt;
}
int main()
{
	cout << "even_counter(7,1,2,3,4,3,2,1) = " << even_count(7, 1, 2, 3, 4, 3, 2, 1) << "\n";
	cout << "srednee(4, 5, 1, 3, 0, 6, 3, -1) = " << srednee(4, 5, 1, 3, 0, 6, 3, -1) << "\n";
}
