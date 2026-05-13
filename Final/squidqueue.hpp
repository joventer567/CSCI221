#ifndef SQUIDQUEUE_HPP
#define SQUIDQUEUE_HPP
#include "squid.hpp"
#define MAX_SIZE 5

class SquidQueue {
  private:
    int front;
    int back;
    int count;
    Squid arr[MAX_SIZE];

  public:
    SquidQueue();
    ~SquidQueue();
    bool enqueue(const Squid& val);
    Squid dequeue();
    bool isEmpty();
    bool isFull();
    void printArray();
    int size();
    Squid head();
};

#endif