#include <iostream>
using namespace std;

unsigned long long int fibonacci_fast(int n) 
{     
    unsigned long long int arr[n+1];

    arr[0]=0ull; // prev
    arr[1]=1ull; // curr
    for(int i=2;i<=n;i++)
    {
     	arr[i]=arr[i-1]+arr[i-2];
      // tmp = curr
      // curr = curr + prev
      // prev = tmp
    }
    return arr[n];
}


int main() 
{
  int n;
  cin >> n;
	
  cout << fibonacci_fast(n) << '\n';
   
  return 0;
}
