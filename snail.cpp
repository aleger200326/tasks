#include<bits/stdc++.h>
int main()
{
	std::cout<<"Input m(rows) and n(columns):";
	int m,n;
	std::cin>>m>>n;
	int m1=m,n1=n;
	int a[m][n];
	int k=0,l=0,g=1;
	while(k<m&&l<n)
	{
		for(int i=l;i<n;++i)
		a[k][i]=g++;
		k++;
		for(int i=k;i<m;++i)
		a[i][n-1]=g++;
		n--;
		if(k<m)
		{
			for(int i=n-1;i>=l;--i)
			a[m-1][i]=g++;
			m--;
		}
		if(l<n)
		{
			for(int i=m-1;i>=k;--i)
			a[i][l]=g++;
			l++;
		}
	}
	int h=m1*n1,f=1;
	while(h>0)
	{
		f++;
		h/=10;
	}
	for(int i=0;i<m1;++i)
	{
		for(int j=0;j<n1;++j)
		std::cout<<std::setw(f)<<a[i][j];
		std::cout<<std::endl;
	}
}
