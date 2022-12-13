#include <iostream>

using namespace std;

void binarySearchTreeApps();
void binarySearchTree();

int main() {

    binarySearchTreeApps();

}

void binarySearchTreeApps() {
    int num;

    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Binary Search Tree Implementation.\n\t0: Exit." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            binarySearchTree();
            break;
        default:
            break;
        }

        if (!(num <= 1 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

class Tree {
public:
    int data;
    Tree* left;
    Tree* right;
    Tree() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    Tree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Tree() {
        delete left;
        delete right;
    }
    Tree* insert(Tree*, int);
    void inorder(Tree*);
    void preorder(Tree*);
    void postorder(Tree*);
    Tree* search(Tree*, int);
    Tree* deleteNode(Tree*, int);
    Tree* treeMinData(Tree*);
    bool isBalanced(Tree*, int*);
};

Tree* Tree::insert(Tree* root, int data) {
    if (root == NULL) {
        return new Tree(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

void Tree::inorder(Tree* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Tree::preorder(Tree* root) {
    cout << root->data << " ";
    if (root->left != NULL)
        preorder(root->left);
    if (root->right != NULL)
        preorder(root->right);
}

void Tree::postorder(Tree* root) {
    if (root->left != NULL)
        postorder(root->left);
    if (root->right != NULL)
        postorder(root->right);
    cout << root->data << " ";
}

Tree* Tree::search(Tree* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

Tree* Tree::treeMinData(Tree* root) {
    Tree* p = root;
    while (p && p->left != NULL)
        p = p->left;
    return p;
}

Tree* Tree::deleteNode(Tree* root, int data) {
    if (root == NULL)
        return root;
    if (root->data > data)
        root->left = deleteNode(root->left, data);
    else if (root->data < data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL) {
            Tree* temp = root->right;
            return temp;
        }
        else if (root->right == NULL) {
            Tree* temp = root->left;
            return temp;
        }
        Tree* temp = treeMinData(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool Tree::isBalanced(Tree* root, int* height) {
    if (root == NULL)
        return true;

    int lh = 0, rh = 0;
    if (!(isBalanced(root->left, &lh)))
        return false;
    if (!(isBalanced(root->right, &rh)))
        return false;

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else 
        return false;
}

void binarySearchTree() {

    Tree* tree = NULL;
    Tree a;

    tree = a.insert(tree, 5);
    a.insert(tree, 3);
    a.insert(tree, 1);
    a.insert(tree, 2);
    a.insert(tree, 4);

    tree->inorder(tree);
    cout << endl;
    tree->preorder(tree);
    cout << endl;
    tree->postorder(tree);
    cout << endl;
  
    cout << tree->search(tree, 3)->data << endl;
    cout << tree->treeMinData(tree)->data << endl;

    tree = tree->deleteNode(tree, 1);
    tree->inorder(tree);
    cout << endl;

    int height = 0;
    if (tree->isBalanced(tree, &height))
        cout << "Balanced" << endl;
    else 
        cout << "Not Balanced" << endl;
}