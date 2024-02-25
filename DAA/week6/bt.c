#include<stdio.h>
#include<stdlib.h>
 
int ctr=0;
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create() {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data (-1 if you don't want to enter that child): ");
    scanf("%d", &x);
    nn->data = x;
    if (x == -1)
        return NULL;
    else {
        printf("Enter the left child %d: ", x);
        nn->left = create();

        printf("Enter the right child %d: ", x);
        nn->right = create();
    }
    return nn;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        printf("-> %d", root->data);
        inorder(root->right);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ht(struct node *root) {
    if (root == NULL)
        return 0;
    return (1 + max(ht(root->left), ht(root->right)));
}

int large(struct node *root) {
    if (root == NULL)
        return 0;
    int ll=large(root->left);
    int lr=large(root->right);

    return max(root->data,max(ll,lr));
}

int countNodes(struct node *root) {
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

int countleaf(struct node *root)
{
	if (root == NULL)
        return 0;
    countleaf(root->left);
    if(root->left==NULL && root->right==NULL)
    	ctr++;
    countleaf(root->right);
     

    return ctr;
}
void search(struct node *root, int se) {
    if (root == NULL)
        return;

    if (se == root->data) {
        printf("Element %d found\n", se);
        return;
    }

    search(root->left, se);
    search(root->right, se);
}

void freeMemory(struct node *root) {
    if (root == NULL)
        return;
    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}


int main() {
    struct node *root;
    root = create();
    printf("The inorder is:\n");
    inorder(root);
    int ch;

    do {
        printf("\nMenu\n1. Height\n2. Number of nodes\n 3. leaf nodes\n 4.search elements\n 0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Height is %d\n", ht(root));
                break;

            case 2:
                printf("Number of nodes is %d\n", countNodes(root));
                break;

             case 3:
                printf("Number of leaf nodes is %d\n", countleaf(root));
                break;

             case 4:
             	int s;
             	printf("enter number to be searched");
             	scanf("%d",&s);
             	search(root,s);

             case 5:
             	int l=large(root);
                printf("largest is %d\n", l);
                break;

      

            case 0:
                freeMemory(root);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while (ch != 0);

    return 0;
}