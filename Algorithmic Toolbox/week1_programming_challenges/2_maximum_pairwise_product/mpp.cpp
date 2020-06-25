#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

long long mpp(long long arr[],int n)
{
	sort(arr,arr+n);

	long long prod= arr[n-2]*arr[n-1];

	return prod;
}


int main()
{
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<mpp(arr,n);

	return 0;
}