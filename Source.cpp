#include <bits/stdc++.h>
#include <cstdlib>
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
int digits(int n)
{
	int k=0;
	while(n>0)
	{
		n/=10;
		k++;
	}
	return k;
}
int main()
{
	srand(time(NULL));
	int n=5,m=6; 
	int d=0;
	int arr[n][m]; 
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)arr[i][j]=rand()%10000;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			d=6-digits(arr[i][j]);
			cout << arr[i][j];
			for (;d>0;d--)cout << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			d=6-digits(arr[i][j]);
			if(j!=0)for (;d>0;d--)cout << " ";
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
