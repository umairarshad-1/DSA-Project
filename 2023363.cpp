#include<iostream>
using namespace std;


struct BSTNode
{
    Medicine *medicine;
    BSTNode *left;
    BSTNode *right;
    int height;

    BSTNode(Medicine *medicine) : medicine(medicine), left(nullptr), right(nullptr), height(1) {}
};

// Class for AVL tree
class AVLTree
{
private:
    BSTNode *root;

    int height(BSTNode *node)
    {
        return node ? node->height : 0;
    }

    int balanceFactor(BSTNode *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    BSTNode *rotateRight(BSTNode *y)
    {
        BSTNode *x = y->left;
        BSTNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    BSTNode *rotateLeft(BSTNode *x)
    {
        BSTNode *y = x->right;
        BSTNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
}

BSTNode *insert(BSTNode *node, Medicine *medicine)
    {
        if (!node)
            return new BSTNode(medicine);

        if (medicine->name < node->medicine->name)
        {
            node->left = insert(node->left, medicine);
        }
        else if (medicine->name > node->medicine->name)
        {
            node->right = insert(node->right, medicine);
        }
        else
        {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = balanceFactor(node);

        if (balance > 1 && medicine->name < node->left->medicine->name)
        {
            return rotateRight(node);
        }

        if (balance < -1 && medicine->name > node->right->medicine->name)
        {
            return rotateLeft(node);
        }

        if (balance > 1 && medicine->name > node->left->medicine->name)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && medicine->name < node->right->medicine->name)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inOrderTraversal(BSTNode *node)
    {
        if (node)
        {
            inOrderTraversal(node->left);
            cout << left << setw(15) << node->medicine->name << setw(10) << node->medicine->price << setw(10) << node->medicine->quantity << endl;
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void addMedicine(Medicine *medicine)
    {
        root = insert(root, medicine);
    }

    void display()
    {
        cout << "\n\033[1;32mMedicine List (AVL Tree):\033[0m\n";
        cout << left << setw(15) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        cout << "--------------------------------------\n";
        inOrderTraversal(root);
    }
};
