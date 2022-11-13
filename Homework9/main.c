#include <stdio.h>
#include "avlTree.h"

int main() {
    Node* root = NULL;
    //root = insert(root, 10, "w");
    root = insert(root, 9, "g");
    root = insert(root, 5, "j");
    root = insert(root, 10, "k");
    root = insert(root, 0, "h");
    root = insert(root, 6, "h");
    root = insert(root, 11, "k");
    root = insert(root, -1, "p");
    root = insert(root, 1, "j");
    root = insert(root, 2, "i");
    //root->right = newNode(30, "WW");
    //root->right->right = newNode(40, "GG");
    //root->left->left = newNode(5, "GG");
    //root = leftRotate(root);
    delete(root, 10);
    printf("%d ");
    printf("%d", height(root->left));
    printf("%d", height(root->right));
    return 0;
}
