#include <iostream>
#include <vector>
#include <memory>
#include <stack>

template<class T>
struct DefaultComparator {
 public:
    bool operator()(const T &l, const T &r) const {
        return l < r;
    }
};

template<class Value, class Position, class Comparator = DefaultComparator<Value> >
class AVLTree {
 public:
    void add(const Value &value, Position &pos) {
        root_ = add_aux(value, pos, root_);
    }

    void erase(const Value &value) {
        root_ = erase_aux(root_, value);
    }
    
    explicit AVLTree(Comparator comp = Comparator()) : 
        root_(nullptr), 
        count_(0), 
        comp_(comp) {}

    ~AVLTree() {
        root_.reset();
    }

 private:
    struct TreeNode {
        explicit TreeNode(Value value) : 
            value_(value), 
            height_(1), 
            position_(1) {}
        TreeNode(const Value &value, const Position &position) :
            value_(value), 
            height_(1), 
            position_(position), 
            left_(nullptr), 
            right_(nullptr) {}

        Value value_;
        uint8_t height_;
        Position position_;

        std::shared_ptr<TreeNode> left_;
        std::shared_ptr<TreeNode> right_;
    };

    std::shared_ptr<TreeNode> root_;
    size_t count_;
    Comparator comp_;

    std::shared_ptr<TreeNode> add_aux(const Value &value, Position &position, std::shared_ptr<TreeNode> node) {
        if (!node) {
            count_++;
            return std::make_shared<TreeNode>(value);
        }
        node->position_++;

        if (comp_(value, node->value_)) {
            position += get_position(node->right_) + 1;
            node->left_ = add_aux(value, position, node->left_);
        } else {
            node->right_ = add_aux(value, position, node->right_);
        }
        return balance(node);
    }

    std::shared_ptr<TreeNode> erase_aux(std::shared_ptr<TreeNode> current_node, Position position) {
        if (current_node == nullptr) {
            return nullptr;
        }
        if (position >= current_node->position_) {
            return current_node;
        }

        int current = 0;
        std::stack<std::shared_ptr<TreeNode> > nodes;

        while (true) {
            int nodes_right = get_position(current_node->right_);
            if (position - current > nodes_right) {
                nodes.push(current_node);
                current_node = current_node->left_;
                current += nodes_right + 1;
            } else if (position - current < nodes_right) {
                if (current_node->right_ != nullptr) {
                    nodes.push(current_node);
                    current_node = current_node->right_;
                } else {
                    break;
                }
            } else {
                std::shared_ptr<TreeNode> cur_left = current_node->left_;
                std::shared_ptr<TreeNode> cur_right = current_node->right_;
                int cur_value = current_node->value_;

                current_node.reset();

                if (cur_right == nullptr) {
                    if (cur_left == nullptr) {
                        if (!nodes.empty()) {
                            current_node = nodes.top();
                            nodes.pop();
                            if (current_node->value_ > cur_value) {
                                current_node->left_ = nullptr;
                            } else {
                                current_node->right_ = nullptr;
                            }
                            current_node->position_--;
                        } else {
                            return nullptr;
                        }
                    } else {
                        current_node = cur_left;
                    }
                } else {
                    std::shared_ptr<TreeNode> min;
                    std::shared_ptr<TreeNode> tree = find_erase_min(cur_right, min);
                    min->left_ = cur_left;
                    min->right_ = tree;
                    fix_position(min);
                    current_node = balance(min);
                }
                break;
            }
        }
        return fix_positions(nodes, current_node);
    }

    std::shared_ptr<TreeNode> find_erase_min(std::shared_ptr<TreeNode> node, std::shared_ptr<TreeNode> &min) {
        if (!node->left_) {
            min = node;
            return node->right_;
        }
        node->left_ = find_erase_min(node->left_, min);
        node->position_--;
        return balance(node);
    }

    uint8_t get_height(std::shared_ptr<TreeNode> node) {
        if (!node) {
            return 0;
        }
        return node->height_;
    }

    void fix_height(std::shared_ptr<TreeNode> node) {
        if (!node) {
            return;
        }
        node->height_ = std::max(get_height(node->left_), get_height(node->right_)) + 1;
    }

    int get_position(std::shared_ptr<TreeNode> node) {
        if (node == nullptr) {
            return 0;
        }
        return node->position_;
    }

    void fix_position(std::shared_ptr<TreeNode> node) {
        int left_h = get_position(node->left_);
        int right_h = get_position(node->right_);

        node->position_ = left_h + right_h + 1;
    }

    std::shared_ptr<TreeNode> fix_positions(std::stack<std::shared_ptr<TreeNode> > &nodes, std::shared_ptr<TreeNode> current_node) {
        while (!nodes.empty()) {
            std::shared_ptr<TreeNode> node = nodes.top();
            node->position_--;

            if (node->value_ > current_node->value_) {
                node->left_ = current_node;
            } else {
                node->right_ = current_node;
            }
            current_node = balance(node);
            nodes.pop();
        }
        return current_node;
    }

    int factor_b(std::shared_ptr<TreeNode> node) {
        return get_height(node->right_) - get_height(node->left_);
    }

    std::shared_ptr<TreeNode> balance(std::shared_ptr<TreeNode> node) {
        fix_height(node);

        int factor = factor_b(node);
        if (factor == 2) {
            if (factor_b(node->right_) < 0) {
                node->right_ = rotate_right(node->right_);
            }
            return rotate_left(node);
        } else if (factor == -2) {
            if (factor_b(node->left_) > 0) {
                node->left_ = rotate_left(node->left_);
            }
            return rotate_right(node);
        }
        return node;
    }

    std::shared_ptr<TreeNode> rotate_left(std::shared_ptr<TreeNode> node_p) {
        std::shared_ptr<TreeNode> node_q = node_p->right_;
        node_p->right_ = node_q->left_;
        node_q->left_ = node_p;
        fix_position(node_p);
        fix_position(node_q);
        fix_height(node_p);
        fix_height(node_q);
        return node_q;
    }

    std::shared_ptr<TreeNode> rotate_right(std::shared_ptr<TreeNode> node_p) {
        std::shared_ptr<TreeNode> node_q = node_p->left_;
        node_p->left_ = node_q->right_;
        node_q->right_ = node_p;
        fix_position(node_p);
        fix_position(node_q);
        fix_height(node_p);
        fix_height(node_q);
        return node_q;
    }
};

int main() {
    AVLTree<int, int> tree;
    std::vector<int> result;
    int amount, command, value, position;
    
    std::cin >> amount;
    for (size_t i = 0; i < amount; i++) {
        std::cin >> command;
        if (command == 1) {
            position = 0;
            std::cin >> value;
            tree.add(value, position);
            std::cout << position << std::endl;
        } 
        if (command == 2) {
            std::cin >> value;
            tree.erase(value);
        }
    }
    return 0;
}