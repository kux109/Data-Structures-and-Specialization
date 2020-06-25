#include <iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	long long p= (a>b)?a:b;
	long long q= (a<b)?a:b;

	while(q!=0)
	{
		long long tmp  = p;
		p = q;
		q = tmp%q;
	}

	return p;
}


long long lcm(long long a,long long b)
{
	long long l = (a*b)/gcd(a,b);
	return l;
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout<<lcm(a,b)<<endl;
  return 0;
}
