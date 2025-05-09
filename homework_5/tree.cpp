#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node class
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertBST(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->data)
            node->left = insertBST(node->left, val);
        else
            node->right = insertBST(node->right, val);
        return node;
    }

    void inorder(TreeNode* node, vector<int>& elements) {
        if (!node) return;
        inorder(node->left, elements);
        elements.push_back(node->data);
        inorder(node->right, elements);
    }

    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void destroyTree(TreeNode* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void printTree(TreeNode* node, int depth = 0, string prefix = "") {
        if (!node) return;

        if (node->right)
            printTree(node->right, depth + 1, prefix + "        ");

        cout << prefix;
        if (depth > 0)
            cout << (prefix.back() == '/' ? "/" : "\\") << "──── ";
        cout << node->data << endl;

        if (node->left)
            printTree(node->left, depth + 1, prefix + "        ");
    }

    bool isValid(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal)
            return false;
        return isValid(node->left, minVal, node->data) &&
               isValid(node->right, node->data, maxVal);
    }

public:
    BinaryTree(): root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(int val) {
        root = insertBST(root, val);
    }

    void printInorder() {
        vector<int> elements;
        inorder(root, elements);
        for (int val : elements)
            cout << val << " ";
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }

    void printTree() {
        printTree(root);
    }

    void printPostorderIterative() {
        if (!root) return;

        stack<TreeNode*> stk;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (!stk.empty() || current) {
            if (current) {
                stk.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = stk.top();
                if (peekNode->right && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    cout << peekNode->data << " ";
                    lastVisited = peekNode;
                    stk.pop();
                }
            }
        }
        cout << endl;
    }

    int findKthSmallest(int k) {
        vector<int> elements;
        inorder(root, elements);
        if (k < 1 || k > elements.size())
            throw out_of_range("k is out of bounds");
        return elements[k - 1];
    }

    bool isValidBST() {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

};

int main() {
    BinaryTree tree;
    vector<int> values = {20, 10, 30, 5, 15, 25, 35};

    cout << "Values inserted into BST: ";
    for (int val : values) {
        tree.insert(val);
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    tree.printInorder();

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    try {
        int kth = tree.findKthSmallest(k);
        cout << "The " << k << "th smallest element is: " << kth << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    cout << "The tree is " << (tree.isValidBST() ? "a valid BST." : "not a valid BST.") << endl;

    return 0;
}
