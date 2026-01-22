#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} Tree;

Tree *createNode(int val)
{
    Tree *new = (Tree *)malloc(sizeof(Tree));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Tree *Insert(Tree *root, int val)
{
    if (root == NULL) {
        Tree *new = createNode(val);
        return new;
    }
    if (val > root->data) {
        root->right = Insert(root->right, val);
    } else if (val < root->data) {
        root->left = Insert(root->left, val);
    }
    return root;
}

Tree *Search(Tree *root, int val)
{
    if (root == NULL) return NULL;
    if (val > root->data) {
        root = Search(root->right, val);
    } else if (val < root->data) {
        root = Search(root->left, val);
    } else if (val == root->data) {
        return root;
    }
    return root;
}

Tree *Delete(Tree *root, int val)
{
    Tree *ptr = Search(root, val);
    if (ptr == NULL) {
        printf("not found\n");
        return root;
    }
    if (ptr->left == NULL && ptr->right == NULL) {
        free(ptr);
        return root;
    } else if (ptr->left == NULL || ptr->right == NULL) {
        if (ptr->left == NULL) {

        } else if (ptr->right == NULL) {

        }
    } else {
        Tree *curr = ptr;
        while (curr->left != NULL)
            curr = curr->left;
        ptr->data = curr->data;
        ptr->right = Delete(ptr->right, curr->data);
        return (ptr);
    }
}

void print_bst(Tree *root)
{
    if (root == NULL) return ;
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

int main() {
    Tree *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 60);

    Tree *s = Search(root, 10);
    if (s != NULL)
        printf("search : %d\n", s->data);
    else printf("not found\n");
    print_bst(root);
    printf("\n");

    Tree *d = Delete(root, 20);
    printf("delete : %d", d->data);
    print_bst(root);
    free(root);
    return 0;
}