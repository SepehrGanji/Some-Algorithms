#include <iostream>

using namespace std;

struct Item {
  int value;
  Item* next = nullptr;
};

class LinkedList {
public:
  Item* head;

  void insert_at(int item, int index) {
    Item *new_item = new Item();
    new_item->value = item;
    if(head == nullptr || index == 0) {
      if(head != nullptr) {
        new_item->next = head;
      }
      head = new_item;
    } else {
      Item* current = head;
      while(index-- > 1 && current->next != nullptr) {
        current = current -> next;
      }
      new_item->next = current->next;
      current->next = new_item;
    }
  }

  void delete_at(int index) {
    if(index == 0) {
      Item* old = head;
      head = head->next;
      delete[] old;
      return;
    }
    Item* current = head;
    while(index-- > 1 && current->next != nullptr) {
      current = current -> next;
    }
    Item* old = current->next;
    current->next = old->next;
    delete[] old;
  }

  void print() {
    Item* current = head->next;
    cout << head->value;
    while(current != nullptr) {
      cout << " --> " << current->value;
      current = current->next;
    }
    cout << endl;
  }

};

int main() {
  LinkedList ll;
  while (1) {
    cout << "---------------------" << endl;
    cout << "What do you want to do?" << endl;
    cout << "1) Print the list" << endl;
    cout << "2) Add item to the list" << endl;
    cout << "3) Remove item from the list" << endl;
    cout << "0) Exit the program" << endl;

    int n;
    cin >> n;
    if(n == 0) break;
    else if(n == 1) ll.print();
    else if(n == 2) {
      cout << "Please insert item and its index" << endl;
      int item, idx;
      cin >> item >> idx;
      ll.insert_at(item, idx);
    } else if(n == 3) {
      cout << "Please enter the index" << endl;
      int idx;
      cin >> idx;
      ll.delete_at(idx);
    }
  }

  return 0;
}
