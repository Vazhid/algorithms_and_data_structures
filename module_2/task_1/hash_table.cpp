// Copyright 2023 Vazhid
#include<iostream>
#include<vector>
#include<string>

#define EMP "EMP"
#define KEY "KEY"
#define DEL "DEL"

struct StringHasher {
    size_t operator()(const std::string& str, size_t max) const {
        size_t hash = 0;
        for(const char& ch : str) {
            hash = (hash * 17 + ch) % max;
        }
        return hash;
    }
};

template<typename Hasher>
class HashTable {
 private:
    struct HashTableNode {
     public:
        std::string data_;
        std::string state_;

        explicit HashTableNode(const std::string& data) : data_(data), state_(KEY) {}  
        HashTableNode() : data_(""), state_(EMP) {}
    };

    std::vector<HashTableNode> table_;
    size_t keys_count_;
    Hasher hasher_;

    size_t probe(size_t hash, size_t i) {
        return (hash + i) % table_.size();
    }

    void grow() {
        std::vector<HashTableNode> old_table = std::move(table_);
        table_.resize(old_table.capacity() * 2);
        keys_count_ = 0;
        for (const HashTableNode& node: old_table) {
            if (node.state_ == KEY)
                add(node.data_);
        }
    }
    
 public:
    explicit HashTable() :
        table_(8),
        keys_count_(0) {}

    bool add(const std::string& data) {
        if (keys_count_ >= table_.size() * 0.75) {
            grow();
        }
        int first_deleted = -1;
        size_t index = hasher_(data, table_.size());
        for (size_t i = 0; i < table_.size(); i++) {
            index = probe(index, i);
            HashTableNode& node = table_[index];
            if (node.data_ == data && node.state_ == KEY) {
                return false;
            }
            if (node.state_ == DEL && first_deleted != -1) {
                first_deleted = index;
                continue;
            }
            if (node.state_ == EMP) {
                HashTableNode set_node(data);
                first_deleted == -1 ? table_[index] = set_node : table_[first_deleted] = set_node;
                ++keys_count_;
                return true;
            }   
        }
        return false;
    }

    bool has(const std::string& data) {
        size_t index = hasher_(data, table_.size());
        for (size_t i = 0; i < table_.size(); i++) {
            index = probe(index, i);
            HashTableNode& node = table_[index];
            if (node.data_ == data && node.state_ == KEY) {
                return true;
            }
            if (node.state_ == EMP) {
                return false;
            }
        }
        return false;
    }

    bool remove(const std::string& data) {
        size_t index = hasher_(data, table_.size());
        for (size_t i = 0; i < table_.size(); i++) {
            index = probe(index, i);
            HashTableNode node = table_[index];
            if (node.data_ == data && node.state_ == KEY) {
                table_[index].state_ = DEL;
                --keys_count_;
                return true;
            }
            if (node.state_ == EMP) {
                return false;
            }
        }
        return false;
    }


};

int main() {
    StringHasher hasher;
    HashTable<StringHasher> my_table;
    char operation_number;
    std::string my_data;
    while (std::cin >> operation_number >> my_data) {
        switch (operation_number) {
        case '+':
            std::cout
                << (my_table.add(my_data) ? "OK" : "FAIL")
                << std::endl;
            break;
        case '-':
            std::cout
                << (my_table.remove(my_data) ? "OK" : "FAIL")
                << std::endl;
            break;
        case '?':
            std::cout
            << (my_table.has(my_data) ? "OK" : "FAIL")
            << std::endl;
            break;
        }
    }
}