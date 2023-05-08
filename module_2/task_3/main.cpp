#include <iostream>
#include <vector>
#include <queue>

template<class T>
class BTree {
public:
	BTree( size_t _t ) : root( nullptr ), t( _t ) {}
	~BTree() { delete root; }

	void Insert( const T& key );
    void printByLevel() const;

private:
	struct Node {
		bool IsLeaf;
		std::vector<T> Keys;
		std::vector<Node*> Children;

		Node( bool isLeaf ) : IsLeaf( isLeaf ) {}
		~Node() { for( Node* child : Children ) { delete child; } }
	};
	Node* root;
	size_t t;

	bool isNodeFull( Node* node ) const { return node->Keys.size() == 2 * t - 1; }
	void insertNonFull( Node* node, const T& key );
	void splitChild( Node* node, size_t pos );
};

template<class T>
void BTree<T>::Insert( const T& key )
{
	if( root == nullptr ) {
		root = new Node( true );
	}

	if( isNodeFull( root ) ) {
		Node* newRoot = new Node( false );
		newRoot->Children.push_back( root );
		root = newRoot;
		splitChild( root, 0 );
	}

	insertNonFull( root, key );
}

template<class T>
void BTree<T>::insertNonFull(Node* node, const T& key) {
    size_t pos = node->Keys.size();
    if( node->IsLeaf ) {
        node->Keys.push_back( key );
        while( pos > 0 && key < node->Keys[pos - 1] ) {
            node->Keys[pos] = node->Keys[pos - 1];
            pos--;
        }
        node->Keys[pos] = key;
    } else {
        while( pos > 0 && key < node->Keys[pos - 1] ) {
            pos--;
        }
        if( isNodeFull( node->Children[pos] ) ) {
            splitChild( node, pos );
            if( key > node->Keys[pos] ) {
                pos++;
            }
        }
        insertNonFull( node->Children[pos], key );
    }
}

template<class T>
void BTree<T>::splitChild(Node* node, size_t pos) {
    Node* child = node->Children[pos];
    Node* newChild = new Node( child->IsLeaf );

    newChild->Keys.reserve( t - 1 );
    for( size_t i = 0; i < t - 1; i++ ) {
        newChild->Keys.push_back( child->Keys[t + i] );
    }
    child->Keys.erase( child->Keys.begin() + t - 1, child->Keys.end() );

    if( !child->IsLeaf ) {
        newChild->Children.reserve( t );
        for( size_t i = 0; i < t; i++ ) {
            newChild->Children.push_back( child->Children[t + i] );
        }
        child->Children.erase( child->Children.begin() + t, child->Children.end() );
    }

    node->Children.insert( node->Children.begin() + pos + 1, newChild );
    node->Keys.insert( node->Keys.begin() + pos, child->Keys[t - 1] );
}

template<class T>
void BTree<T>::printByLevel() const {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            Node* current = q.front();
            q.pop();
            for (T key : current->Keys) {
                std::cout << key << " ";
            }
            if (!current->IsLeaf) {
                for (Node* child : current->Children) {
                    if (child != nullptr) {
                        q.push(child);
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    size_t t;
    int value;
    std::cin >> t;
    BTree<int> tree(t);

    while (std::cin >> value) {
        tree.Insert(value);
    }
    
    tree.printByLevel();
    return 0;
}