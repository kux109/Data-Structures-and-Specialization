#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::vector;

struct Item
{
  int value;
  int weight;
};

bool greaterAvFirst(Item a,Item b)
{
  return (a.value*b.weight)>(b.value*a.weight);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  
  double answer = 0.0;
  int n = values.size();
  Item arr[n];
  
  for(int i=0;i<n;i++)
    arr[i] = {values[i],weights[i]};
  
  std::sort(arr,arr+n,greaterAvFirst);

  for(int i=0;i<n && capacity>0;i++)
  {
    if(arr[i].weight<=capacity)
    {
      answer += arr[i].value;
      capacity -= arr[i].weight;
    }
    else
    {
      double tmp = (double)arr[i].value/(double)arr[i].weight;
      answer += tmp * capacity;
      capacity = 0;
    }

  }

  return answer;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << std::fixed << optimal_value << std::endl;
  return 0;
}
