// Sean Szumlanski
// CS106B, Spring 2026
//
// bst.cpp
// =======
// Implementation of a few basic BST functions: traversal algorithms, insertion,
// and deallocation. Includes a test case that checks for memory leaks.

#include <iostream>
#include "console.h"
#include "MemoryDiagnostics.h"
#include "SimpleTest.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }

    TRACK_ALLOCATIONS_OF(Node);
};

void preorderHelper(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << " " << root->data;
    preorderHelper(root->left);
    preorderHelper(root->right);
}

void preorder(Node *root)
{
    cout << "preorder:";
    preorderHelper(root);
    cout << endl;
}

void postorderHelper(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderHelper(root->left);
    postorderHelper(root->right);
    cout << " " << root->data;
}

void postorder(Node *root)
{
    cout << "preorder:";
    postorderHelper(root);
    cout << endl;
}

void inorderHelper(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderHelper(root->left);
    cout << " " << root->data;
    inorderHelper(root->right);
}

void inorder(Node *root)
{
    cout << "inorder:";
    inorderHelper(root);
    cout << endl;
}

void bstInsert(Node*& root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return;
    }

    if (data <= root->data)
    {
        bstInsert(root->left, data);
    }
    else
    {
        bstInsert(root->right, data);
    }
}

void forestFire(Node*& root)
{
    if (root == nullptr)
    {
        return;
    }

    forestFire(root->left);
    forestFire(root->right);
    delete root;

    root = nullptr;
}

PROVIDED_TEST("fun with traversals + memleak check")
{
    //       50
    //      /  \
    //    30    55      preorder: 50 30 40 35 45 55
    //     \            postoder: 35 45 40 30 55 50
    //      40          inorder: 30 35 40 45 50 55
    //     /  \
    //    35  45

    Node *root = nullptr;
    bstInsert(root, 50);
    bstInsert(root, 30);
    bstInsert(root, 55);
    bstInsert(root, 40);
    bstInsert(root, 35);
    bstInsert(root, 45);

    preorder(root);
    postorder(root);
    inorder(root);

    // Comment out the following line to see how the testing framework
    // reports a memory leak.
    forestFire(root);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}
