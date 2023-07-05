#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "Enter the number of elements: ";
  int n;
  cin >> n;

  cout << "Enter the array of elements:" << endl;
  int tmp;
  vector<int> vec;
  for(int i = 0 ; i < n ; i++) {
    cin >> tmp;
    vec.push_back(tmp);
  }

  // selection sort
  vector<int> sorted;
  while(vec.size() > 0){
    int el = vec.at(0);
    int idx = 0;
    for(int j = 0 ; j < vec.size() ; j++) {
      int new_el = vec.at(j);
      if(new_el < el) {
        el = new_el;
        idx = j;
      }
    }
    sorted.push_back(el);
    vec.erase(vec.begin() + idx);
  }

  for(int num: sorted) {
    cout << num << " ";
  }

  return 0;
}
