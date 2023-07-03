#include <iostream>

using namespace std;

int binary_search(int* array, int n, int a) {
  int lb = 0; // lower band
  int ub = n; // upper band
  while(lb + 1 < ub) {
    int i = lb + ((ub - lb) / 2);
    int b = array[i];
    if(a < b) {
      ub = i;
    } else if (a > b) {
      lb = i;
    } else {
      return i;
    }
  }

  return -1;
}

int main() {
  cout << "Enter the size of array:" << endl;
  int n;
  cin >> n;

  int* array = new int[n];
  cout << "Enter the (sorted) array:" << endl;
  for(int i = 0 ; i < n ; i++) {
    cin >> array[i];
  }

  cout << "Enter the element you are looking for:" << endl;
  int a;
  cin >> a;

  int result = binary_search(array, n, a);
  cout << "The result index is: " << result << endl;
  
  return 0;
}
