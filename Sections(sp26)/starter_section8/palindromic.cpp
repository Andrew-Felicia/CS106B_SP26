/*
 * CS106B Section Handout Test Harness: Section 8
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
#include "utility.h"
#include "error.h"
#include "stack.h"
using namespace std;


bool areMirror(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr || root2 == nullptr) {
        return root1 == root2;
    }

    if(root1->data != root2->data) return false;

    return areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
}

/*
 * Palindromic Trees (Code Writing)
 * --------------------------------------------------------
 * Write a function that accepts a reference to a pointer
 * to a TreeNode and determines if the (sub)tree rooted at
 * that node is its own mirror image. Return true if so,
 * false otherwise.
 *
 * For example, the following is a palindromic tree:
 *
 *                3
 *             /     \
 *           2         2
 *          / \       / \
 *         5  4      4   5
 *           / \    / \
 *          1   2  2   1
 *
 * In contrast, the following is not a palindromic tree:
 *
 *                3
 *             /     \
 *            1       1
 *           / \     / \
 *          1   2   1   2
 */

bool isPalindromicTree(TreeNode* root) {
    if(!root) return true;

    return areMirror(root->left, root->right);
}



PROVIDED_TEST("Simple set of test cases for isPalindromicTree function") {
    TreeNode *tree = nullptr;
    EXPECT(isPalindromicTree(tree));

    tree = createTreeFromVector({1});
    EXPECT(isPalindromicTree(tree));
    freeTree(tree);

    tree = createTreeFromVector({/* Level 1 */3, /* Level 2*/ 2, 2, /* Level 3 */ 5, 4, 4, 5, /* Level 4 */ EMPTY, EMPTY, 1, 2, 2, 1, EMPTY, EMPTY});
    EXPECT(isPalindromicTree(tree));
    freeTree(tree);

    tree = createTreeFromVector({/* Level 1 */3, /* Level 2*/ 1, 1, /* Level 3 */ 1, 2, 1, 2});
    EXPECT(!isPalindromicTree(tree));
    freeTree(tree);
}
