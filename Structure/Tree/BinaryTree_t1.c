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

int get_height(Node *root)
{
    int left_height = 0;
    int right_height = 0;
    if (root == NULL)
        return 0;
    left_height = get_height(root->left);
    right_height = get_height(root->right);

    if (left_height > right_height)
        return (1 + left_height);
    else
        return (1 + right_height);
}

int get_node_count(Node *root)
{
    int count = 0;
    if (root != NULL)
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    return count;
}

int get_leaf_count(Node *root)
{
    int count = 0;
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int degree(Node *root)
//특정 노드의 자식 수만 반환
{
    if (root == NULL) return 0;

    int degree = 0;

    if (root->left) degree++;
    if (root->right) degree++;
    return degree;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return 0;
}