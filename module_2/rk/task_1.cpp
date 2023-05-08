#include <iostream>
#include <stack>
#include <vector>
#include <queue>

#define INT_MAX 10000

template <typename T>
struct DefaultComparator {
    bool operator()(const T& l, const T& r) const {
        return l < r;
    }
};

template<typename T>
struct TreeNode {
    T value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(TreeNode *l, TreeNode *r, T val) : left(l), right(r), value(val) {}
};

template<typename T, typename Comparator = DefaultComparator<T> >
class BinaryTree {
 private:

    Comparator comp;
    
 public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        std::stack<TreeNode<int>*> stack;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top()->right;
            TreeNode<int> *deleted = stack.top();
            stack.pop();
            delete deleted;
        }
    }

    TreeNode<int> *root;

    void Insert(const T &value) {
        if (root == nullptr) {
            root = new TreeNode<int>(nullptr, nullptr, value);
            return;
        }
        TreeNode<int> *current = root;
        while (current != nullptr) {
            if (comp(value, current->value)) {
                if (current->left == nullptr) {
                    current->left = new TreeNode<int>(nullptr, nullptr, value);
                    return;
                }
                current = current->left;
            }
            if (!comp(value, current->value)) {
                if (current->right == nullptr) {
                    current->right = new TreeNode<int>(nullptr, nullptr, value);
                    return;
                }
                current = current->right;
            }
        }
    }

    std::vector<int> InOrderOutput() {
        // if (root == nullptr) {
        //     return;
        // }
        std::stack<TreeNode<int> *> stack;
        TreeNode<int> *current = root;

        std::vector<int> output;
    
        while (current != nullptr || !stack.empty()) {
            while (current !=  nullptr) {
                stack.push(current);
                current = current->left;
            }
    
            current = stack.top();
            stack.pop();
            output.push_back(current->value);
            current = current->right;
        }
        return output;
    }
    

};

int MinPath(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }
    
    std::queue<std::pair<TreeNode<int>*, int>> q; 
    q.push({root, 1});
    
    int shortest = INT_MAX;
    
    while (!q.empty()) {
        TreeNode<int>* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (node->left == nullptr && node->right == nullptr) {
            shortest = std::min(shortest, depth); 
        }
        
        if (node->left != nullptr) {
            q.push({node->left, depth + 1}); 
        }
        
        if (node->right != nullptr) {
            q.push({node->right, depth + 1});
        }
    }
    
    return shortest;
}

int main() {
    BinaryTree<int> tree;
    int nodeValue;
    std::cin >> nodeValue;
    tree.Insert(nodeValue);
    while(std::cin >> nodeValue) {
        tree.Insert(nodeValue);
    }
    
    std::cout << MinPath(tree.root) << std::endl;
}