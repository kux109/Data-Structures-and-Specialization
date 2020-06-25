#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd(int a,int b)
{
	int p = (a>b)?a:b;
	int q = (a<b)?a:b;

	while(q!=0)
	{
		int temp=p;
		p=q;
		q=temp%p;
	}
	return p;

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
