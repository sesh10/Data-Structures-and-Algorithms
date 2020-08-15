#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct binary_tree_node
{
    int value;
    struct binary_tree_node * left;
    struct binary_tree_node * right;
};
typedef struct binary_tree_node binary_tree_node;

struct tree
{
    binary_tree_node * root;
    int size;
};
typedef struct tree tree;

tree * create_tree()
{
    tree * t = (tree *) malloc(sizeof(tree));
    t->root = NULL;
    t->size = 0;
    return t;
}

bool empty_tree(tree * t)
{
    return t->size == 0;
}

void insert_node(tree * t, int value)
{
    binary_tree_node * tn = (binary_tree_node *) malloc(sizeof(binary_tree_node));
    tn->left = tn->right = NULL;
    tn->value = value;
    if (empty_list(t))
    {
        t->root = tn;
        t->size++;
        return;
    }
    binary_tree_node * btn = t->root;
    while (true)
    {
        if (value < btn->value)
        {
            if (btn->left == NULL)
            {
                btn->left = tn;
                t->size++;
                return;
            }
            else
            {
                btn = btn->left;
            }
        }
        else if (value > btn->value)
        {
            if (btn->right == NULL)
            {
                btn->left = tn;
                return;
            }
            else
            {
                btn = btn->right;
            }
        }
        else
        {
            break;
        }         
    }
}

void print_tree(binary_tree_node * root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%d\t", root->value);
    print_tree(root->right);
}

int main()
{
    tree * t = create_tree();
    // perform operations
    return 0;
}
