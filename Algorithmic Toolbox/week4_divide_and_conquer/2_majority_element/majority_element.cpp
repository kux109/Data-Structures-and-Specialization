#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int majority_element(vector<int> a, int n)
{
	
	int count=1;
	int temp=a[0];
	
	for(int i=1;i<n;i++)
	{
		if(temp == a[i])
		{
			count++;
		}
		else
		{
			count=1;
			temp=a[i];
		}
	}
	
	if(count>(n/2))
	{
		return 1;
	}
	return 0;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << majority_element(a,n) << '\n';
}
