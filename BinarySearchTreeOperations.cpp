#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to search for a value in the BST
    bool search(int value) const {
        return searchRecursive(root, value);
    }

    // Function to perform an in-order traversal of the BST
    void inOrderTraversal() const {
        inOrderTraversalRecursive(root);
    }

    // Function to delete a value from the BST
    void remove(int value) {
        root = removeRecursive(root, value);
    }

private:
    // Helper function to recursively insert a value into the BST
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Helper function to recursively search for a value in the BST
    bool searchRecursive(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    // Helper function to perform an in-order traversal of the BST
    void inOrderTraversalRecursive(TreeNode* node) const {
        if (node != nullptr) {
            inOrderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inOrderTraversalRecursive(node->right);
        }
    }

    // Helper function to recursively remove a value from the BST
    TreeNode* removeRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = removeRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = removeRecursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* minRightSubtree = findMin(node->right);
            node->data = minRightSubtree->data;
            node->right = removeRecursive(node->right, minRightSubtree->data);
        }

        return node;
    }

    // Helper function to find the node with the minimum value in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal of the BST: ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    int searchValue = 40;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    int deleteValue = 30;
    bst.remove(deleteValue);
    std::cout << "In-order traversal after deleting " << deleteValue << ": ";
    bst.inOrderTraversal();
    std::cout << std::endl;

    return 0;
}
