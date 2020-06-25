#include <iostream>
#include <string>
using namespace std;

string addition(string inp1,string inp2)
{
	string ans = "";
	string tmp;
	int carry = 0;
	int summ;

	int i=inp1.size()-1;
	int j=inp2.size()-1;

	while(i>-1 && j>-1)
	{
		summ  = (carry + (inp1[i]-'0') + (inp2[j]-'0'))%10;
		carry = (carry + (inp1[i]-'0') + (inp2[j]-'0'))/10;
		tmp = "";
		tmp.push_back('0'+summ);
		ans = tmp + ans;
		i--; j--;
	}

	while(i>-1)
	{
		summ  = (carry + (inp1[i]-'0'))%10;
		carry = (carry + (inp1[i]-'0'))/10;
		tmp = "";
		tmp.push_back('0'+summ);
		ans = tmp + ans;
		i--; 
	}

	while(j>-1)
	{
		summ  = (carry + (inp2[j]-'0'))%10;
		carry = (carry + (inp2[j]-'0'))/10;
		tmp = "";
		tmp.push_back('0'+summ);
		ans = tmp + ans;
		j--; 
	}

	if (carry!=0)
	{
		tmp = "";
		tmp.push_back('0'+carry);
		ans = tmp + ans;
	}

	return ans;
}


int main()
{
	string inp1,inp2;
	cin >> inp1 >> inp2;
	cout << addition(inp1,inp2) << endl;
}