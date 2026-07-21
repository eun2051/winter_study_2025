#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
} Node;

Node *createNode(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = val;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

void print_bst(Node *root)
{
    if (root == NULL) return ;
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

Node *bstInsert(Node *root, int val)
{
    if (root == NULL) {
        Node *new = createNode(val);
        return new;
    }
    if (val > root->data) {
        root->right = bstInsert(root->right, val);
    } else if (val < root->data) {
        root->left = bstInsert(root->left, val);
    }
    return root;
}

/*
Node *bstSearch(Node *root, int val)
{
    while (node != NULL) {
        if (val == root->data) return root;
        else if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
*/

Node *bstSearch(Node *root, int val)
{
    if (root == NULL) return (NULL);
    if (root->data == val) {
        printf("equal\n");
        return (root);
    }
    if (root->data > val) {
        return (bstSearch(root->left, val));
    } else {
        return (bstSearch(root->right, val));
    }
}

Node *bstDelete(Node *root, int val)
{
    if (root == NULL) return (NULL);
    if (val < root->data)
        root->left = bstDelete(root->left, val);
    else if (val > root->data)
        root->right = bstDelete(root->right, val);
    else {
        if (root->left == NULL) {
            Node *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        Node *curr = root;
        while (curr->left != NULL)
            curr = curr->left;
        root->data = curr->data;
        root->right = bstDelete(root->right, curr->data);
    }
    return root;
}

int main()
{
    Node *root = createNode(30);
    root->left = createNode(20);
    root->right = createNode(50);
    root->left->left = createNode(10);
    root->left->right = createNode(25);
    root->right->left = createNode(40);
    root->right->right = createNode(60);

    print_bst(root);
    printf("\n");
    root = bstInsert(root, 45);
    print_bst(root);
    printf("\n");

    Node *find = bstSearch(root, 10);
    if (find != NULL)
        printf("found : %d\n", find->data);
    else printf("not found\n");

    root = bstDelete(root, 10);
    print_bst(root);
    printf("\n");
    return 0;
}