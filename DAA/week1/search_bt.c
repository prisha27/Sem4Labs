#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;

};

struct node *create(struct node *root,int val) {
    if(root==NULL)
    {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->left=nn->right=NULL;
    return nn;
}
if(val<root->data)
    root->left=create(root->left,val);
if(val>root->data)
    root->right=create(root->right,val);

return root;

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
struct node*search(struct node *root, int se) {
    if (root == NULL)
        return NULL;

    if(se==root->data)
        return root;
    if(se<root->data)
        return search(root->left,se);
    else 
    return search(root->right, se);

}




int main()
{

    struct node*root=NULL;
    int x,se;
    do {
        printf("\nEnter data (-1 to stop\n): ");
        scanf("%d", &x);
            root = create(root, x);
    } while (x != -1);

    printf("the inorder is:\n");
    inorder(root);

     printf("\nEnter a value to search: ");
    scanf("%d", &se);

    struct node* result = search(root, se);

    if (result != NULL)
        printf("\n%d found in the BST.", se);
    else
        printf("\n%d not found in the BST.", se);

   return 0;
}