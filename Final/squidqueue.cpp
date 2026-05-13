
#include "squidqueue.hpp"
#include <iostream>

using namespace std;

SquidQueue::SquidQueue() {
  front = 0;
  count = 0;
  back = MAX_SIZE - 1;
  
}
SquidQueue::~SquidQueue() {

}

bool SquidQueue::enqueue(const Squid& val) {
if (isFull()) {
    return false;
}
else {
    back = (back + 1) % MAX_SIZE;
    arr[back] = val;
    count++;
    return true;
}
}
Squid SquidQueue::dequeue() {
if (isEmpty()) {
    cout << "No entry to dequeue." << endl;
    return Squid();
}
else {
    Squid rem_squid = arr[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return rem_squid;

}

}

bool SquidQueue::isEmpty() {
  if (count == 0) {
    return true;
  }
  else {
    return false;
  }
}

bool SquidQueue::isFull() {
  if (count == MAX_SIZE) {
    return true;
  }
  else {
    return false;
  }

}

void SquidQueue::printArray() {
  int current = front;
  if (isEmpty()) {
    return;
}
else {
  for (int i = 0; i < count; i++) {
    cout << current << endl;
    current = (current + 1) % MAX_SIZE;
  }
}

} 

int SquidQueue::size() {
  return count;
}

Squid SquidQueue::head() {
  return arr[front];
} 