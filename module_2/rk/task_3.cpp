// Copyright 2022 Vazhid
#include<iostream>
#include<vector>
#include<string>
#include<cassert>

struct StringHasher {
    unsigned int operator()(const std::string& str) const {
        unsigned int hash = 0;
        for (unsigned int i = 0; i < str.size(); ++i) {
            hash = hash * 11 + str[i];
        }
        return hash;
    }
};

template<class T, class H>
class HashTable {
 public:
    explicit HashTable(const H& hasher) :
        hasher_(hasher),
        table_(8, nullptr),
        keys_count_(0)
        {}

    HashTable(const HashTable&) = delete;
    HashTable(HashTable&&) = delete;

    HashTable& operator=(const HashTable&) = delete;
    HashTable& operator=(HashTable&&) = delete;

    ~HashTable();

    bool Has(const T& key, int color, int size) const;
    bool Add(const T& key, int color, int size);
    bool Delete(const T& key, int color, int size);

 private:
    struct HashTableNode {
        unsigned int hash;
        HashTableNode* next;
        T data; 
        std::string product_name;
        int color;
        int size;

        HashTableNode() : hash(0), next(nullptr) {}
        HashTableNode(
            const T& data,
            int color,
            int size,
            unsigned int hash,
            HashTableNode* next_node) :
            data(data), color(color), size(size), hash(hash), next(next_node) {}
    };

    H hasher_;
    std::vector<HashTableNode*> table_;
    unsigned int keys_count_;
    void growTable();
};

template<class T, class H>
HashTable<T, H>::~HashTable() {
    for (unsigned int i = 0; i < table_.size(); ++i) {
        HashTableNode* node = table_[i];
        while (node != nullptr) {
            HashTableNode* next_node = node->next;
            delete node;
            node = next_node;
        }
    }
}

template<class T, class H>
bool HashTable<T, H>::Has(const T& data, int color, int size) const {
    unsigned int hash = hasher_(data + std::to_string(color) + std::to_string(size)) % table_.size();
    HashTableNode* node = table_[hash];
    while (node != nullptr && node->data != data) {
        node = node->next;
    }
    return node != nullptr;
}

template<class T, class H>
bool  HashTable<T, H>::Add(const T& data, int color, int size) {
    if (keys_count_ > 3 * table_.size()) {
        growTable();
    }

    unsigned int abs_hash = hasher_(data + std::to_string(color) + std::to_string(size));
    unsigned int hash = abs_hash % table_.size();
    HashTableNode* node = table_[hash];
    while (node != nullptr && node->data != data && node->color != color && node->size != size)
        node = node->next;

    if (node != nullptr && node->data != data && node->color != color && node->size != size) {
        return false;
    }

    table_[hash] = new HashTableNode(data, color, size, abs_hash, table_[hash]);
    ++keys_count_;
    return true;
}

template<class T, class H>
bool HashTable<T, H>::Delete(const T& data, int color, int size) {
    unsigned int hash = hasher_(data + std::to_string(color) + std::to_string(size)) % table_.size();
    HashTableNode* node = table_[hash];
    HashTableNode* prev_node = nullptr;

    while (node != nullptr && node->data != data && node->color != color && node->size != size) {
        prev_node = node;
        node = node->next;
    }

    if (node == nullptr) {
        return false;
    }

    if (prev_node == nullptr) {
        table_[hash] = node->next;
    } else {
        prev_node->next = node->next;
    }

    delete node;
    --keys_count_;
    return true;
}

template<class T, class H>
void HashTable<T, H>::growTable() {
    std::vector<HashTableNode*> new_table(table_.size() * 2, nullptr);
    for (unsigned int i = 0; i < table_.size(); ++i) {
        HashTableNode* node = table_[i];
        while (node != nullptr) {
            HashTableNode* next_node = node->next;
            unsigned int new_hash = node->hash % new_table.size();
            node->next = new_table[new_hash];
            new_table[new_hash] = node;
            node = next_node;
        }
    }
    table_ = std::move(new_table);
}

int main() {
    StringHasher hasher;
    HashTable<std::string, StringHasher> my_table(hasher);
    char operation_number = 0;
    std::string my_data;
    int color;
    int size;
    while (std::cin >> operation_number >> my_data >> color >> size) {
        switch (operation_number) {
        case '+':
            std::cout
                << (my_table.Add(my_data, color, size) ? "OK" : "FAIL")
                << std::endl;
            break;
        case '-':
            std::cout
                << (my_table.Delete(my_data, color, size) ? "OK" : "FAIL")
                << std::endl;
            break;
        case '?':
            std::cout
            << (my_table.Has(my_data, color, size) ? "OK" : "FAIL")
            << std::endl;
            break;
        default:
            assert(false);
        }
    }
    return 0;
}
