#ifndef SET_H
#define SET_H

#include <QPair>

template<typename T>
class MySet {
public:
    struct Node {
        QPair <T, T> pair;
        int height;
        Node *left;
        Node *right;

        Node() {}

        Node(T key) : pair(key, key), height(1), left(nullptr), right(nullptr) {}
    };

    MySet() : root(nullptr), sz(0) {}

    void insert_to_list(QList<Node *> &list, Node *node) {
        if (list.empty())
            list.push_back(node);
        else {
            auto it = list.begin();
            while (it != list.end() && (*it)->pair.first < node->pair.first) ++it;

            list.insert(it, node);
        }
    }

    void remove_from_list(QList<Node *> &list, Node *node) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == node) {

                list.erase(it);
                return;
            }
        }
    }

    ~MySet() {
        delete root;
    }

    void insert(T k) {
        root = insert(root, k);
    }

    void erase(T k) {
        root = erase(root, k);
    }

    bool empty() {
        return sz == 0;
    }

    int size() {
        return sz;
    }

    void clear() {
        deleteTree(root);
        root = nullptr;
        list.clear();
        sz = 0;
    }

    void deleteTree(Node *node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    class l_iterator {
    private:
        typename QList<Node *>::iterator it;

    public:
        l_iterator() {}

        l_iterator(typename QList<Node *>::iterator it) : it(it) {}

        l_iterator(const l_iterator &iter) : it(iter.it) {}

        l_iterator(Node *node) : it(node) {}

        l_iterator &operator=(const l_iterator &other) {
            it = other.it;
            return *this;
        }

        bool operator==(const l_iterator &other) {
            return it == other.it;
        }

        bool operator!=(const l_iterator &other) {
            return it != other.it;
        }

        l_iterator &operator++() {
            ++it;
            return *this;
        }

        l_iterator &operator--() {
            --it;
            return *this;
        }

        Node &operator*() {
            return *it;
        }

        Node *operator->() {
            return *it;
        }
    };

    l_iterator l_begin() {
        return l_iterator(list.begin());
    }

    l_iterator l_end() {
        return l_iterator(list.end());
    }

private:
    Node *root;
    QList<Node *> list;

public:
    int sz;

private:
    Node *insert(Node *head, T k) {
        if (!head) {
            ++sz;
            Node *temp = new Node(k);
            insert_to_list(list, temp);
            return temp;
        }
        if (k < head->pair.first)
            head->left = insert(head->left, k);
        else if (k > head->pair.first)
            head->right = insert(head->right, k);
        head->height = 1 + qMax(get_height(head->left), get_height(head->right));
        int dif = get_height(head->left) - get_height(head->right);
        if (dif > 1) {
            if (k < head->left->pair.first)
                return right_rotation(head);
            else {
                head->left = left_rotation(head->left);
                return right_rotation(head);
            }
        } else if (dif < -1) {
            if (k > head->right->pair.first)
                return left_rotation(head);
            else {
                head->right = right_rotation(head->right);
                return left_rotation(head);
            }
        }
        return head;
    }

    Node *erase(Node *head, const T key) {
        if (!head)
            return nullptr;
        if (key < head->pair.first)
            head->left = erase(head->left, key);
        else if (key > head->pair.first)
            head->right = erase(head->right, key);
        else {
            Node *r = head->right;
            if (!head->right) {
                Node *l = head->left;
                remove_from_list(list, head);
                //delete head;
                head = l;
            } else if (!head->left) {
                remove_from_list(list, head);
                //delete head;
                head = r;
            } else {
                while (r->left != nullptr)
                    r = r->left;
                head->pair.first = r->pair.first;
                head->pair.second = r->pair.second;
                head->right = erase(head->right, r->pair.first);
            }
        }
        if (!head)
            return head;
        head->height = 1 + qMax(get_height(head->left), get_height(head->right));
        int dif = get_height(head->left) - get_height(head->right);
        if (dif > 1) {
            if (get_height(head->left) >= get_height(head->right))
                return right_rotation(head);
            else {
                head->left = left_rotation(head->left);
                return right_rotation(head);
            }
        } else if (dif < -1) {
            if (get_height(head->right) >= get_height(head->left))
                return left_rotation(head);
            else {
                head->right = right_rotation(head->right);
                return left_rotation(head);
            }
        }
        return head;
    }

    Node *left_rotation(Node *head) {
        Node *newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + qMax(get_height(head->left), get_height(head->right));
        newhead->height = 1 + qMax(get_height(newhead->left), get_height(newhead->right));
        return newhead;
    }

    Node *right_rotation(Node *head) {
        Node *newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + qMax(get_height(head->left), get_height(head->right));
        newhead->height = 1 + qMax(get_height(newhead->left), get_height(newhead->right));
        return newhead;
    }

    int get_height(Node *head) {
        if (!head) return 0;
        return head->height;
    }
};

#endif // SET_H
