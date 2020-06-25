#include <iostream>
#define llu unsigned long long int
using namespace std;

llu get_fibonacci_huge_naive(llu n, llu m) {
    if (n <= 1)
        return n;

    llu previous = 0;
    llu current  = 1;

    for (llu i = 0; i < n - 1; ++i) {
        llu tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


int pisano_period(int m)
{
	int prev = 0ull;
	int curr = 1ull;
	int tmp;
	int count=0;
	do
	{
		tmp  = curr;
		curr = curr + prev;
		prev = tmp;
		curr = curr%m;
		prev = prev%m;
		count++;
	}
	while(prev!=0 || curr!=1);
	return count;
}

int get_fibonacci_huge_fast(llu n,int m)
{
	int pp = pisano_period(m);
	int N = (int)(n%pp);

	if (N==0 || N==1)
		return N;

	int prev = 0;
	int curr = 1;
	while(N>1)
	{
		int temp = curr;
		curr = prev + curr;
		prev = temp;
		N--;
	}
	
	return curr%m;
}

int main() {
    llu n;
    int m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    cout << pisano_period(m) << endl;
}
