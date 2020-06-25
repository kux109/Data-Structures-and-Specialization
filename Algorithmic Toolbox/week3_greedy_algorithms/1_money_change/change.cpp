#include <iostream>

int get_change(int m) 
{
	/*
	int count=0;
	int left=0;

	count=m/10;
	left=m%10;

	count=count+left/5;
	left=left%5;

	count=count+left;

	return count;  
	*/

	return ( (m/10) + ((m%10)/5) + ((m%10)%5) );

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
