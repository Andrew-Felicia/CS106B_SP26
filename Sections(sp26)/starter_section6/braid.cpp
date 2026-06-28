/*
 * CS106B Section Handout Test Harness: Section 6
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "vector.h"
using namespace std;

/*
 * Braid (Code Writing)
 * --------------------------------------------------------
 * Write a function braid that takes a linked list and weaves the 
 * reverse of that list into the original. (You will need to create 
 * new nodes.)
 */

void braid(Node*& front) {
    if (front == nullptr) return;

    // Build a reversed copy.
    Node* reverse = nullptr;

    for (Node* cur = front; cur != nullptr; cur = cur->next) {
        Node* node = new Node;
        node->data = cur->data;
        node->next = reverse;
        reverse = node;
    }

    // Weave the two lists.
    Node* p1 = front;
    Node* p2 = reverse;

    while (p1 != nullptr && p2 != nullptr) {
        Node* next1 = p1->next;
        Node* next2 = p2->next;

        p1->next = p2;
        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }
}

/* * * * * Provided Tests Below This Point * * * * */


PROVIDED_TEST("Simple Braided Example") {
    Node *list = createListFromVector({1, 4, 2});
    Node *braided = createListFromVector({1, 2, 4, 4, 2, 1});

    braid(list);
    EXPECT(listEqual(list, braided));

    freeList(list);
    freeList(braided);
}