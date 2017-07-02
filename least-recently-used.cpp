/*
Choice of data structures

Queue - We should maintain a Queue (double ended queue), in which the most recently used pages (items) are in the front, and the least recently used pages are in the rear. This would allow to remove the least recently used item in O(1) time.

Doubly Linked List - We should implement our Queue using a doubly linked list (instead of arrays), which would allow us to apply shifting operations in O(1) time. (like, when we need to shift a page to the front of the queue)

HashMap - We should hash the key values to the location where the page is stored. This would allow get operation in O(1) time.


*/

#include <iostream>
#include <map>

using namespace std;

class Node {
public:
  int key, value;
  Node *prev, *next;
  
  Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {} // Constructor list

};

class DoublyLinkedList {

  Node *front, *rear;
  
  bool isEmpty() {
      return rear == NULL;
  }

public:
  
  DoublyLinkedList(): front(NULL), rear(NULL) {}
  
  Node* add_page_to_head(int key, int value) { // Note the Node *
      
      Node *page = new Node(key, value);
      // if there is no front && no rear then it is first head node
      if(!front && !rear) {
          front = rear = page;
      }
      else {
      	  // We're adding new page to front of queue.		
	      // imagine queue as: [0][1]...[n-1] where 0 is front and n-1 is end
	      page->next = front;	      
	      front->prev = page;	      
	      front = page;
      }
      return page;
  }

  void move_page_to_head(Node *page) {
      // if page is already at front
      if(page==front) {
          return;
      }
      // if page is at rear (end)
      if(page == rear) {
          rear = rear->prev;
          rear->next = NULL;
      }
      // if page is somewhere in between
      else {
      	  // Imagine: [prevOfPage]-->[Page]-->[nextOfPage]
      	  // where prevOfPage, Page, nextOfPage are arbitrary positional names
      	  // [prevOfPage] -> next => [nextOfPage]
          page->prev->next = page->next;  
          // [nextOfPage] -> prev => [prevOfPage]
          page->next->prev = page->prev;
      }

      page->next = front;
      page->prev = NULL;
      front->prev = page;
      front = page;
  }

  void remove_rear_page() {
  	  // safety check
      if(isEmpty()) {
          return;
      }
      // if only one page
      if(front == rear) {
          delete rear;
          front = rear = NULL;
      }
      // there are more than one page (cache size > 1)
      else {
      	  // assigning address of current rear to new variable for deleting
          Node *temp = rear;
          // updating rear variable with previous of rear as new rear
          rear = rear->prev;
          rear->next = NULL;
          delete temp;
      }
  }
  Node* get_rear_page() {
      return rear;
  }
  
};

class LRUCache{
  int capacity, size;
  DoublyLinkedList *pageList;
  map<int, Node*> pageMap;

  public:
    LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;
		pageList = new DoublyLinkedList();
		pageMap = map<int, Node*>();
    }

    int get(int key) {
    	// if finding reached to end value it means key not found
    	// Page Miss
        if(pageMap.find(key)==pageMap.end()) {
          return -1;
        }
        // Page Hit
        // pageMap[key] gets Node*
        int val = pageMap[key]->value;

        // move the page to front
        pageList->move_page_to_head(pageMap[key]);
        return val;
    }

    void put(int key, int value) {
      if(pageMap.find(key)!=pageMap.end()) {
          // if key already present, update value and move page to head
          pageMap[key]->value = value;
          pageList->move_page_to_head(pageMap[key]);
          return;
      }

        if(size == capacity) {
          // remove rear page
          int k = pageList->get_rear_page()->key;
          pageMap.erase(k);
          pageList->remove_rear_page();
          size--;
        }

        // add new page to head to Queue
        Node *page = pageList->add_page_to_head(key, value);
        size++;
        pageMap[key] = page;
    }

	~LRUCache() {
		map<int, Node*>::iterator i1;
		for(i1=pageMap.begin();i1!=pageMap.end();i1++) {
			delete i1->second;
		}
		delete pageList;
	}
};

int main() {
	LRUCache cache(2);  // cache capacity 2
	// cache.put(key, value) where value shows age of page
	cache.put(2,2);
	cout << cache.get(2) << endl;
	cout << cache.get(1) << endl;
	cache.put(1,1);
	cache.put(1,5);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	cache.put(8,8);
	cout << cache.get(1) << endl;
	cout << cache.get(8) << endl;

}