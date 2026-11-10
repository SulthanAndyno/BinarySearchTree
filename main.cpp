
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int info;
    Node* left;
    Node* right;
};

// Membuat node baru
Node* createNode(int data) {
    Node* baru = new Node;

    baru->info = data;
    baru->left = NULL;
    baru->right = NULL;

    return baru;
}

// Insert data ke BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->info) {
        root->left = insert(root->left, data);
    }
    else if (data > root->info) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
    }
}

// Search data
bool search(Node* root, int cari) {
    if (root == NULL) {
        return false;
    }

    if (root->info == cari) {
        return true;
    }

    if (cari < root->info) {
        return search(root->left, cari);
    }

    return search(root->right, cari);
}

int main() {
    Node* root = NULL;
    int data, cari;

    // Input data
    int angka[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++) {
        root = insert(root, angka[i]);
    }

    // Menampilkan traversal
    cout << "=== BINARY SEARCH TREE ===" << endl;

    cout << "Inorder   : ";
    inorder(root);

    cout << "\nPreorder  : ";
    preorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    // Searching
    cout << "\n\nMasukkan angka yang dicari: ";
    cin >> cari;

    if (search(root, cari)) {
        cout << "Data ditemukan!";
    }
    else {
        cout << "Data tidak ditemukan!";
    }

    return 0;
}
