#include "RingBufferQueue.h"
#include "SimpleTest.h"
#include "error.h"

using namespace std;

const int defaultCapacity = 10;
/**
 * constructor.
 */
RBQueue::RBQueue() {
    _capacity = defaultCapacity;
    _elements = new int[_capacity];
    _numUsed = 0;
    _head = 0;

}

/**
 * destructor.
 */
RBQueue::~RBQueue() {
    delete[] _elements;

}

/**
 * add one element in the front, throw error if it's full.
 */
void RBQueue::enqueue(int elem) {
    if(isFull()) error("RBQ is full!");
    int tail = (_head + _numUsed) % _capacity;
    _elements[tail] = elem;
    _numUsed += 1;
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    if(isEmpty()) error("RBQ is empty!");
    int front = _elements[_head];
    _head = (_head + 1) % _capacity;
    _numUsed -= 1;
    return front;
}

/**
 * return the first element without removing it.
 */
int RBQueue::peek() {
    if(isEmpty()) error("RBQ is empty!");
    return _elements[_head];

}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {

    return _numUsed == 0;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {

    return _numUsed == _capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {

    return _numUsed;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {

    (void) queue;
    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout") {
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}
