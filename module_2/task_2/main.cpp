#include <iostream>
#include <stack>

template <typename T>
struct DefaultComparator {
    bool operator()(const T& l, const T& r) const {
        return l < r;
    }
};

template<typename T, typename Comparator = DefaultComparator<T> >
class BinaryTree {
 private:
    struct TreeNode {
        T value;
        TreeNode *left;
        TreeNode *right;

        TreeNode(TreeNode *l, TreeNode *r, T val) : left(l), right(r), value(val) {}
    };

    Comparator comp;
    TreeNode *root;
    
 public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        std::stack<TreeNode*> stack;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top()->right;
            TreeNode *deleted = stack.top();
            stack.pop();
            delete deleted;
        }
    }

    void Insert(const T &value) {
        if (root == nullptr) {
            root = new TreeNode(nullptr, nullptr, value);
            return;
        }
        TreeNode *current = root;
        while (current != nullptr) {
            if (comp(value, current->value)) {
                if (current->left == nullptr) {
                    current->left = new TreeNode(nullptr, nullptr, value);
                    return;
                }
                current = current->left;
            }
            if (!comp(value, current->value)) {
                if (current->right == nullptr) {
                    current->right = new TreeNode(nullptr, nullptr, value);
                    return;
                }
                current = current->right;
            }
        }
    }

    void InOrderOutput() {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode *> stack;
        TreeNode *current = root;
    
        while (current != nullptr || !stack.empty()) {
            while (current !=  nullptr) {
                stack.push(current);
                current = current->left;
            }
    
            current = stack.top();
            stack.pop();
            std::cout << current->value << " ";
            current = current->right;
        }
    }
    
};

int main() {
    BinaryTree<int> tree;
    int nodeValue;
    size_t count;
    std::cin >> count;
    for (size_t i = 0; i < count; i++) {
        std::cin >> nodeValue;
        tree.Insert(nodeValue);
    }

    tree.InOrderOutput();
}