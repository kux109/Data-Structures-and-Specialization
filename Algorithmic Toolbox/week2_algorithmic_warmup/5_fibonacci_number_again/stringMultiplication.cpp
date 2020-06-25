#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiplication(string inp1,string inp2)
{
	int cap = inp1.size()+inp2.size()+1;
	
	int n,m,i,j,k,last=0,i_n,j_n,summ,carry;
	
	string a,b;

	if (inp1.size() > inp2.size())
	{
		a = inp1;
		b = inp2;
	}
	else
	{
		a = inp2;
		b = inp1;
	}
	
	n = a.size();
	m = b.size();
	
	vector<int> v(cap,0);

	for(j=m-1;j>-1;j--)
	{
		j_n = b[j]-'0';
		k = last;
		carry = 0;
		for(i=n-1;i>-1;i--)
		{
			i_n = a[i]-'0';
			summ  = (v[k] + carry + i_n*j_n)%10;
			carry = (v[k] + carry + i_n*j_n)/10;
			v[k++] = summ; 
		}
		if (carry!=0)
			v[k++] = v[k]+carry;
		last++;
	}

	string ans = "";
	while(v.back()==0)
		v.pop_back();

	for(int l=v.size()-1;l>-1;l--)
		ans.push_back('0'+v[l]);

	return ans;



}

int main()
{
	string inp1,inp2;
	cin >> inp1 >> inp2;
	cout << multiplication(inp1,inp2) << endl;
}