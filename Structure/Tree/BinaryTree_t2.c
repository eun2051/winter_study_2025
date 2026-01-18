#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
} Node;

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorder(Node *root)
{
    if (root == NULL) return ;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL) return ;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int height(Node *root)
{
    if (root == NULL) return 0;
    int left_h = 0;
    int right_h = 0;

    left_h = height(root->left);
    right_h = height(root->right);

    if (left_h > right_h)
        return 1 + left_h;
    else return 1 + right_h;
}

void levelorder(Node *root, int level)
{
    if (root == NULL) return ;
    if (level == 1) printf("%d ", root->data);
    else if (level > 1)
    {
        levelorder(root->left, level - 1);
        levelorder(root->right, level - 1);
    }
}

int main()
{
    int h = 0;
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    h = height(root);
    printf("height : %d\n", h);
    int i = 1;
    while (i <= h) {
        levelorder(root, i);
        i++;
    }
    printf("\n");
    printf("preorder : ");
    preorder(root);
    printf("\n");
    printf("inorder : ");
    inorder(root);
    printf("\n");
    printf("preorder : ");
    postorder(root);
    free(root);
}