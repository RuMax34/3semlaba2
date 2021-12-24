#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class BST {
private:
    struct node {
        T data;
        node* left;
        node* right;
    };
    node* root;
    int count;
    int (*cmp)(T, T);
    void destroy_tree(node* branch) {
        if (branch != nullptr) {
            destroy_tree(branch->left);
            destroy_tree(branch->right);
            delete branch;
        }
    }

    void insert_help(node* branch, T item) {
        node* cur = branch;
        if (!this->cmp(cur->data, item) && !this->cmp(item, cur->data)) {
            this->count--;
            return;
        }
        else if (this->cmp(cur->data, item)) {
            if (cur->left != nullptr) {
                insert_help(cur->left, item);
            }
            else {
                cur->left = new node;
                cur->left->data = item;
                cur->left->left = nullptr;
                cur->left->right = nullptr;
            }
        }
        else if (this->cmp(item,cur->data)) {
            if (cur->right != nullptr) {
                insert_help(cur->right, item);
            }
            else {
                cur->right = new node;
                cur->right->data = item;
                cur->right->left = nullptr;
                cur->right->right = nullptr;
            }
        }
    }

    node* search_help(T item, node* cur) {
        node* branch = cur;
        if (branch != nullptr) {
            if (!this->cmp(cur->data, item) && !this->cmp(item, cur->data))
                return branch;
            else if (this->cmp(branch->data, item))
                return search_help(item, branch->left);
            else
                return search_help(item, branch->right);
        }
        else
            return nullptr;
    }

    void print_help(node* cur) {
        node* tmp = cur;
        if (tmp != nullptr) {
            if (tmp->left)
                print_help(tmp->left);
            cout << tmp->data << " ";
            if (tmp->right)
                print_help(tmp->right);
        }
        else
            return;
    }

    node* tree_min_help(node* cur) {
        node* min = cur;
        while (min->left) {
            min = min->left;
        }
        return min;
    }

    node* tree_max_help(node* cur) {
        node* max = cur;
        while (max->right) {
            max = max->right;
        }
        return max;
    }

    node* delete_help(T item, node* branch) {
        if (!branch) {
            return nullptr;
        }
        if (this->cmp(branch->data, item)) {
            branch->left = delete_help(item, branch->left);
        }
        else if (this->cmp(item,branch->data)) {
            branch->right = delete_help(item, branch->right);
        }

        else {
            if (branch->left == nullptr && branch->right == nullptr) {
                delete branch;
                branch = nullptr;
                return branch;
            }
            else if (branch->left == nullptr) {
                node* tmp = branch;
                branch = branch->right;
                delete tmp;
                return branch;
            }
            else if (branch->right == nullptr) {
                node *tmp = branch;
                branch = branch->left;
                delete tmp;
                return branch;
            }
            else {
                node* tmp = tree_min_help(branch->right);
                branch->data = tmp->data;
                branch->right = delete_help(tmp->data, branch->right);
            }
        }
        return branch;
    }

    vector<T>* KLP_help(node* branch, vector<T>* vect) {
        node* tmp = branch;
        if (tmp) {
            vect->push_back(branch->data);
            KLP_help(branch->left, vect);
            KLP_help(branch->right, vect);
        }
        return vect;
    }

    BST<T>* KLP_for_eject(node* cur, BST<T>* tree) {
        node* tmp = cur;
        if (tmp) {
            tree->insert(cur->data);
            KLP_for_eject(cur->left, tree);
            KLP_for_eject(cur->right, tree);
        }
        return tree;
    }

    vector<T>* KPL_help(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            vect->push_back(branch->data);
            KPL_help(branch->right, vect);
            KPL_help(branch->left, vect);
        }
        return vect;
    }

    vector<T>* LKP_help(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            LKP_help(branch->left, vect);
            vect->push_back(branch->data);
            LKP_help(branch->right, vect);
        }
        return vect;
    }

    vector<T>* PKL_help(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            PKL_help(branch->right, vect);
            vect->push_back(branch->data);
            PKL_help(branch->left, vect);
        }
        return vect;
    }

    vector<T>* LPK_help(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            LPK_help(branch->left, vect);
            LPK_help(branch->right, vect);
            vect->push_back(branch->data);
        }
        return vect;
    }

    vector<T>* PLK_help(node* branch, vector<T>* vect) {
        node* tmp = branch; // KLP
        if (tmp) {
            PLK_help(branch->right, vect);
            PLK_help(branch->left, vect);
            vect->push_back(branch->data);
        }
        return vect;
    }

    bool find_subtree_help(node* cur1, node* cur2) {
        if (cur2 == nullptr)
            return 1;
        return (!this->cmp(cur1->data, cur2->data) && !this->cmp(cur2->data, cur1->data)) &&
            find_subtree_help(cur1->left, cur2->left) &&
            find_subtree_help(cur1->right, cur2->right);
    }

public:
    BST(int (*cmp) (T, T)) {
        this->root = nullptr;
        this->count = 0;
        this->cmp = cmp;
    };

    ~BST() {
        destroy_tree(this->root);
    };

    bool is_empty() {
        if (this->root == nullptr)
            return 1;
        return 0;
    }

    T what_in_root() {
        return this->root->data;
    }

    node* tree_max() {
        return tree_max_help(this->root);
    }

    node* tree_min() {
        return tree_min_help(this->root);
    }

    vector <T>* KLP() {
        vector<T>* cur = new vector<T>;
        return KLP_help(this->root, cur);
    }

    vector <T>* KPL() {
        vector <T>* cur = new vector <T>;
        return KPL_help(this->root, cur);
    }

    vector <T>* LKP() {
        vector <T>* cur = new vector <T>;
        return LKP_help(this->root, cur);
    }

    vector <T>* PKL() {
        vector <T>* cur = new vector <T>;
        return PKL_help(this->root, cur);
    }

    vector <T>* PLK() {
        vector <T>* cur = new vector <T>;
        return PLK_help(this->root, cur);
    }
    vector <T>* LPK() {
        vector <T>* cur = new vector <T>;
        return LPK_help(this->root, cur);
    }

    void insert(T item) {
        this->count++;
        if (this->root != nullptr)
            insert_help(this->root, item);
        else {
            this->root = new node;
            this->root->data = item;
            this->root->right = nullptr;
            this->root->left = nullptr;
        }
    }

    void clear_tree() {
        destroy_tree(this->root);
        this->root = nullptr;
        this->count = 0;
    }

    node* search(T item) {
        return search_help(item, this->root);
    }

    void delete_item(T item) {
        if (search(item)) {
            this->count--;
        }
        this->root = delete_help(item, this->root);
    }

    int check_count() {
        return this->count;
    }

    bool find_subtree(BST<T>* little_tree) {
        if (is_empty()) {
            return 0;
        }
        if (little_tree->is_empty()) {
            return 1;
        }
        node* cur1 = little_tree->search(little_tree->what_in_root());
        if (!cur1)
            return 0;
        if (find_subtree_help(this->root, cur1)) {
            return 1;
        }
        return 0;
    }

    void print() {
        print_help(this->root);
        cout << endl;
    }

    BST<T>* eject(node* cur) {
        BST<T>* new_tree = new BST<T>(this->cmp);
        return KLP_for_eject(cur, new_tree);
    }
    T what_in_node(node* cur) {
        return cur->data;
    }
};

int compare_int_for_BST(int a, int b) {
    if (a > b)
        return 1;
    return 0;
}