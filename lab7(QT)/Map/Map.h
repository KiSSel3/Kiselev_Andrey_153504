#ifndef MAP_H
#define MAP_H
#include <utility>
#include <list>

template<typename K, typename V>
class map{
    using value_type = std::pair<const K, V>;
private:
    struct Node{
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;

        int height;
        value_type kv;

        Node() = default;

        Node(const value_type &value, int height) : kv(value), height(height){}
        Node(Node *left, Node *right, Node *parent, int height, const value_type &kv)
            :left(left), right(right), parent(parent), height(height), kv(kv){}

        int getBFactor(){
            int lheight = left ? left->height : 0;
            int rheight = right ? right->height : 0;

            return rheight - lheight;
        }

        void updateHeight(){
            int lheight = left ? left->height : 0;
            int rheight = right ? right->height : 0;

            height = ((lheight > rheight) ? lheight : rheight) + 1;
        }

        Node *rotateRight(){
            Node *p = this;
            Node *q = p->left;

            p->left = q->right;
            if(p->left)
                p->left->parent = p;

            q->parent = p->parent;

            q->right = p;

            if(p->parent->right == p){
                p->parent->right = q;
            }
            else{
                p->parent->left = q;
            }

            p->parent = q;

            p->updateHeight();
            q->updateHeight();

            return q;
        }
        Node *rotateLeft(){
            Node *q = this;
            Node *p = q->right;

            q->right = p->left;
            if(q->right)
                q->right->parent = q;

            p->parent = q->parent;

            p->left = q;

            if(q->parent->right == q){
                q->parent->right = p;
            }
            else{
                q->parent->left = p;
            }

            q->parent = p;

            q->updateHeight();
            p->updateHeight();

            return p;
        }

        Node *balance(){
            updateHeight();
            if(getBFactor() == 2){
                if(right->getBFactor() < 0){
                    right = right->rotateRight();
                }
                return rotateLeft();
            }
            else if(getBFactor() == -2){
                if(left->getBFactor() > 0){
                    left = left->rotateLeft();
                }
                return rotateRight();
            }

            return this;
        }


        Node *addNode(Node *node){
            if(node->kv.first < kv.first){
                if(left){
                    left = left->addNode(node);
                }
                else{
                    left = node;
                    left->parent = this;
                }
            }
            else if(node->kv.first > kv.first){
                if(right){
                    right = right->addNode(node);
                }
                else{
                    right = node;
                    right->parent = this;
                }
            }
            else{
                delete node;
            }

            return balance();
        }

        static Node *deleteNode(Node *node, const K &key){
            if(!node)
                return node;

            if(key < node->kv.first){
                node->left = deleteNode(node->left, key);
            }
            else if(key > node->kv.first){
                node->right = deleteNode(node->right, key);
            }
            else{
                if(!node->left && !node->right){
                    delete node;
                    return nullptr;
                }
                else if(!node->left){
                    Node *temp = node->right;
                    node->right->parent = node->parent;

                    delete node;

                    return temp;
                }
                else if(!node->right){
                    Node *temp = node->left;
                    node->left->parent = node->parent;

                    delete node;

                    return temp;
                }
                else{
                    Node *temp = node->right;
                    while(temp->left)
                        temp = temp->left;

                    const_cast<K&>(node->kv.first) = temp->kv.first;
                    node->kv.second = temp->kv.second;

                    node->right = deleteNode(node->right, temp->kv.first);
                }
            }

            return node->balance();
        }

        static Node *find(Node *node, const K &key){
            if(!node){
                return nullptr;
            }
            else if(node->kv.first > key){
                return find(node->left, key);
            }
            else if(node->kv.first < key){
                return find(node->right, key);
            }
            else{
                return node;
            }
        }
    };

    Node *m_begin;
    Node *m_fakeNode; // end

public:
    struct iterator{
        friend class map;
    private:
        Node *ptr;

        Node *leftMost(Node *node){
            if(node == nullptr){
                return nullptr;
            }
            while(node->left != nullptr){
                node = node->left;
            }

            return node;
        }

        Node *rightMost(Node *node){
            if(node == nullptr){
                return nullptr;
            }
            while(node->right != nullptr){
                node = node->right;
            }

            return node;
        }

        Node* next(Node* node)
        {


            // возращаемый самый левый элемент правого поддерева если таковое имеется
            if (node->right != nullptr)
                return leftMost(node->right);


            Node* parent = node->parent;
            if (parent == nullptr)
                return nullptr;

            if (node == parent->left)
                return parent;




            while (parent != nullptr && node != parent->left)
            {
                node = parent;
                parent = node->parent;
            }



            return parent;
        }

        Node *prev(Node *node){


            if(node->left != nullptr)
                return rightMost(node->left);

            Node *parent = node->parent;
            if(parent == nullptr)
                return nullptr;

            if(node == parent->right)
                return parent;



            while(parent != nullptr || node != parent->right){
                node = parent;
                parent = node->parent;
            }



            return parent;
        }

    public:
        iterator() = default;
        iterator(Node *ptr) : ptr(ptr){}

        value_type &operator*(){
            return ptr->kv;
        }

        value_type *operator->(){
            return &ptr->kv;
        }

        iterator &operator++(){
            ptr = next(ptr);
            return *this;
        }
        iterator &operator--(){
            ptr = prev(ptr);
            return *this;
        }

        friend bool operator==(const iterator &lhs, const iterator &rhs){
            return lhs.ptr == rhs.ptr;
        }
        friend bool operator!=(const iterator &lhs, const iterator &rhs){
            return lhs.ptr != rhs.ptr;
        }
    };


    map(){
        m_fakeNode = new Node;
        m_fakeNode->left = m_fakeNode;
        m_fakeNode->parent = m_fakeNode;

        m_begin = m_fakeNode;
    }

    void insert(const value_type &value){
        if(m_fakeNode->left == m_fakeNode){
            m_fakeNode->left = new Node(value, 1);
            m_fakeNode->left->parent = m_fakeNode;

            m_begin = m_fakeNode->left;

            m_fakeNode->parent = m_begin;
            m_begin->left = m_fakeNode;
        }
        else{
            m_begin->left = nullptr;
            m_fakeNode->parent = nullptr;

            auto temp = new Node(value, 1);
            m_fakeNode->left = m_fakeNode->left->addNode(temp);
            if(m_begin->kv.first > value.first){
                m_begin = temp;
            }

            m_begin->left = m_fakeNode;
            m_fakeNode->parent = m_begin;
        }
    }

    void erase(const K &key){
        m_begin->left = nullptr;
        m_fakeNode->parent = nullptr;

        m_fakeNode->left = Node::deleteNode(m_fakeNode->left, key);
        if(!m_fakeNode->left){
            m_begin = m_fakeNode;
        }
        else if(key == m_begin->kv.first){ // перещитываем начальную ноду
            auto temp = m_fakeNode;
            while(temp->left){
                temp = temp->left;
            }
            m_begin = temp;
        }

        m_begin->left = m_fakeNode;
        m_fakeNode->parent = m_begin;
    }

    iterator find(const K &key){
        m_begin->left = nullptr;
        m_fakeNode->parent = nullptr;

        Node *f = Node::find(m_fakeNode->left, key);

        m_begin->left = m_fakeNode;
        m_fakeNode->parent = m_begin;

        if(!f){
            return m_fakeNode;
        }
        else{
            return f;
        }

        m_begin->left = m_fakeNode;
        m_fakeNode->parent = m_begin;
    }

    iterator begin(){
        return m_begin;
    }

    iterator end(){
        return m_fakeNode;
    }
};
#endif // MAP_H
