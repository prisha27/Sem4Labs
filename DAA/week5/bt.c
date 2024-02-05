#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the Closest Common Ancestor in a Binary Tree
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    // If either n1 or n2 matches with the root's key, return the root
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    // Recur for the left and right subtrees
    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    // If both left and right subtrees have a CCA, then root is the CCA
    if (leftCCA != NULL && rightCCA != NULL) {
        return root;
    }

    // Otherwise, return the non-null CCA (either from left or right subtree)
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

int main() {
    // Construct the binary tree based on user input
    int rootData, n1, n2;

    printf("Enter the root value: ");
    scanf("%d", &rootData);
    struct Node* root = createNode(rootData);

    printf("Enter the left child value of %d (or -1 if none): ", rootData);
    scanf("%d", &n1);
    if (n1 != -1) {
        root->left = createNode(n1);
    }

    printf("Enter the right child value of %d (or -1 if none): ", rootData);
    scanf("%d", &n2);
    if (n2 != -1) {
        root->right = createNode(n2);
    }

    // Test cases
    printf("Enter the first node value to find CCA: ");
    scanf("%d", &n1);

    printf("Enter the second node value to find CCA: ");
    scanf("%d", &n2);

    struct Node* cca = findCCA(root, n1, n2);

    if (cca != NULL) {
        printf("CCA of %d and %d: %d\n", n1, n2, cca->data);
    } else {
        printf("One or both nodes not found in the tree.\n");
    }

    return 0;
}
