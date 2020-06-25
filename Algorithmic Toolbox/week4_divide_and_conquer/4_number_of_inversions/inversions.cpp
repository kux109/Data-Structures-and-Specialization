#include <iostream>
#include <vector>
#define llu unsigned long long int
using std::vector;

llu merge(vector<int> &a,int l,int m,int r)
{
	int i = l;
	int j = m+1;
	int k = 0;
	llu count=0;
	
	int* tmp = new int[r-l+1];
	
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
		{
			tmp[k]=a[i];
			i++;
		}
		else
		{
			count += (m-i+1);
			tmp[k]=a[j];
			j++;
		}
		k++;		
	}
	while(i<=m)
	{
		tmp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		tmp[k]=a[j];
		j++;
		k++;
	}
	for(int x=0;x<=r-l;x++)
	{
		a[l+x]=tmp[x];
	}
	delete [] tmp;
	return count;
}

llu get_number_of_inversions(vector<int> &a,int l,int r)
{
	llu count=0;
	if(l<r)
	{
		int m=(l+r)/2;
		count += get_number_of_inversions(a,l,m);
		count += get_number_of_inversions(a,m+1,r);
		count += merge(a,l,m,r);
	}
	return count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << get_number_of_inversions(a,0, a.size()-1) << '\n';
}
