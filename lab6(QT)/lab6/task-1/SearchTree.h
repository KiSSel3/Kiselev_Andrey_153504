#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <iostream>
#include <QString>

template<typename T>
class TreeNode {
public:
    int key;
    T data;

    int height = 1;
    TreeNode<T>* right = nullptr;
    TreeNode<T>* left = nullptr;

    TreeNode(int Key, T Data = T()) {
        key = Key;
        data = Data;
    }
};

template <typename T>
class SearchTree {
public:
    TreeNode<T>* insert(TreeNode<T>* treeNode, int key, T data){
        if(!treeNode){
            return new TreeNode<T>(key, data);
        }

        if (key > treeNode->key){
            treeNode->right = insert(treeNode->right, key, data);
        }
        else {
            treeNode->left = insert(treeNode->left, key, data);
        }

        return balance(treeNode);
    }

    int getHeight(TreeNode<T>* treeNode){
        return (treeNode) ? treeNode->height : 0;
    }

    void heightChange(TreeNode<T>* treeNode){
        int heightLeft = getHeight(treeNode->left);
        int heigthRight = getHeight(treeNode->right);

        treeNode->height = ((heightLeft > heigthRight) ? heightLeft : heigthRight) + 1;
    }

    TreeNode<T>* rotateLeft(TreeNode<T>* treeNode) {
        TreeNode<T>* buff = treeNode->right;
        treeNode->right = buff->left;
        buff->left = treeNode;

        heightChange(buff);
        heightChange(treeNode);

        return buff;
    }

    TreeNode<T>* rotateRight(TreeNode<T>* treeNode){
        TreeNode<T>* buff = treeNode->left;
        treeNode->left = buff->right;
        buff->right = treeNode;

        heightChange(buff);
        heightChange(treeNode);

        return buff;
    }


    int bFactor(TreeNode<T>* treeNode){
        return getHeight(treeNode->right) - getHeight(treeNode->left);
    }

    TreeNode<T>* balance(TreeNode<T>* treeNode){
        heightChange(treeNode);

        if(bFactor(treeNode) == 2){
            if(bFactor(treeNode->right) < 0){
                treeNode->right = rotateRight(treeNode->right);
            }

            return rotateLeft(treeNode);
        }

        if(bFactor(treeNode) == -2){
            if(bFactor(treeNode->left) > 0){
                treeNode->left = rotateLeft(treeNode->left);
            }

            return rotateRight(treeNode);
        }

        return treeNode;
    }

    TreeNode<T>* getTreeNodeByKey(TreeNode<T>* treeNode, int Key){
        if (!treeNode){
            return 0;
        }
        if(treeNode->key > Key){
            return getTreeNodeByKey(treeNode->left,Key);
        }
        else if (treeNode->key < Key){
            return getTreeNodeByKey(treeNode->right,Key);
        }
        else {
            return treeNode;
        }
    }

    TreeNode<T>* remove(TreeNode<T>* treeNode, int Key){
        if(!treeNode){
            return treeNode;
        }
        if(Key < treeNode->key){
            treeNode->left = remove(treeNode->left,Key);
        }
        else if(Key > treeNode->key){
            treeNode->right = remove(treeNode->right,Key);
        }
        else {
            TreeNode<T>* leftNode = treeNode->left;
            TreeNode<T>* rightNode = treeNode->right;

            delete treeNode;

            if (!rightNode){
                return leftNode;
            }

            TreeNode<T>* min = getMin(rightNode);
            min->right = removeMin(rightNode);
            min->left = leftNode;

            return balance(min);
        }

        return balance(treeNode);

    }

    TreeNode<T>* getMin(TreeNode<T>* treeNode) {
        if(treeNode->left){
            return getMin(treeNode->left);
        }

        return treeNode;
    }

    TreeNode<T>* removeMax(TreeNode<T>* treeNode) {
        if(treeNode->right){
            return treeNode->right = removeMax(treeNode->right);
        }

        return nullptr;
    }

    TreeNode<T>* removeMin(TreeNode<T>* treeNode){
        if(!treeNode->left){
            return treeNode->right;
        }

        treeNode->left = removeMin(treeNode->left);
        return balance(treeNode);
    }

    void add(std::pair<int,QString> element) {
        /*if(!root){
            root = insert(root,element.first, element.second);
        }
        else{
            insert(root,element.first, element.second);
        }*/
        root = insert(root,element.first, element.second);
    }

    TreeNode<T>* root = nullptr;
};



#endif // SEARCHTREE_H
