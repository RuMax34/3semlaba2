#pragma once
#include <cassert>
#include "BST.h"

void test_is_empty_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    assert(!a->is_empty());
}

void test_is_empty_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    assert(a->is_empty());
}

void test_check_count() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(22);
    assert(a->check_count() == 2);
}

void test_insert_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    assert(a->what_in_root() == 13);
}

void test_insert_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(22);
    assert(a->what_in_node(a->tree_max()) == 22);
}

void test_insert_3() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(22);
    a->insert(23);
    a->insert(22);
    a->insert(22);
    a->insert(13);
    a->insert(23);
    assert(a->check_count() == 3);
}

void test_delete_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->delete_item(13);
    assert(a->is_empty() == 1);
}

void test_max() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    assert(a->what_in_node(a->tree_max()) == 25);
}

void test_min() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    assert(a->what_in_node(a->tree_min()) == 5);
}

void test_delete_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(22);
    a->insert(7);
    a->delete_item(7);
    assert(a->check_count() == 2);
    assert(a->what_in_node(a->tree_min()) == 13);
}

void test_search_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    assert(a->what_in_node(a->search(13)) == 13);
    assert(a->what_in_root() == 13);
}

void test_search_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(22);
    a->insert(7);
    assert(a->what_in_node(a->search(22)) == 22);
}

void test_KLP() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 13 , 7 , 5 , 10 , 22 , 17 , 25 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->KLP())[i] == exp[i]);
    }
}

void test_KPL() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 13 , 22 , 25 , 17 , 7 , 10 , 5 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->KPL())[i] == exp[i]);
    }
}

void test_LKP() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 5 , 7 , 10 , 13 , 17 , 22 , 25 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->LKP())[i] == exp[i]);
    }
}

void test_LPK() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 5 , 10 , 7 , 17 , 25 , 22 , 13 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->LPK())[i] == exp[i]);
    }
}

void test_PLK() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 25 , 17 , 22 , 10 , 5 , 7 , 13 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->PLK())[i] == exp[i]);
    }
}

void test_PKL() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    vector <int> exp = { 25 , 22 , 17 , 13 , 10 , 7 , 5 };
    for (int i = 0; i < a->check_count(); i++) {
        assert((*a->PKL())[i] == exp[i]);
    }
}

void test_vhozhdenie_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    assert(b->is_empty());
    assert(a->find_subtree(b));
}

void test_vhozhdenie_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b->insert(13);
    b->insert(7);
    b->insert(22);
    assert(a->find_subtree(b));
}
void test_vhozhdenie_3() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b->insert(13);
    b->insert(22);
    b->insert(7);
    b->insert(25);
    assert(a->find_subtree(b));
}

void test_vhozhdenie_4() {
    BST<int>* a = new BST<int>(compare_int_for_BST);

    BST<int>* b = new BST<int>(compare_int_for_BST);
    b->insert(13);
    b->insert(22);
    b->insert(17);
    b->insert(25);
    assert(!a->find_subtree(b));
}

void test_vhozhdenie_5() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b->insert(13);
    b->insert(22);
    b->insert(17);
    b->insert(25); //25
    b->insert(7);
    b->insert(5);
    b->insert(10);
    assert(a->find_subtree(b));
}

void test_izvlechenie_1() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b = a->eject(a->search(22));
    assert(a->check_count() == 7);
    assert(b->check_count() == 3);
    assert(b->what_in_root() == 22);
    assert((*b->KLP())[0] == 22);
    assert((*b->KLP())[1] == 17);
    assert((*b->KLP())[2] == 25);
}

void test_izvlechenie_2() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b = a->eject(a->search(17));
    assert(a->check_count() == 7);
    assert(b->check_count() == 1);
    assert(b->what_in_root() == 17);
}

void test_izvlechenie_3() {
    BST<int>* a = new BST<int>(compare_int_for_BST);
    a->insert(13);
    a->insert(7);
    a->insert(22);
    a->insert(5);
    a->insert(10);
    a->insert(17);
    a->insert(25);
    BST<int>* b = new BST<int>(compare_int_for_BST);
    b = a->eject(a->search(13));
    assert(a->check_count() == 7);
    assert(b->check_count() == 7);
    for (int i = 0; i < 7; i++) {
        assert((*a->KLP())[i] == (*b->KLP())[i]);
    }
    for (int i = 0; i < 7; i++) {
        assert((*a->LKP())[i] == (*b->LKP())[i]);
    }
    for (int i = 0; i < 7; i++) {
        assert((*a->PKL())[i] == (*b->PKL())[i]);
    }
}

void TEST_ALL_BST() {
    test_check_count();
    test_delete_1();
    test_delete_2();
    test_min();
    test_max();
    test_insert_1();
    test_insert_2();
    test_insert_3();
    test_is_empty_1();
    test_is_empty_2();
    test_izvlechenie_1();
    test_izvlechenie_2();
    test_izvlechenie_3();
    test_vhozhdenie_1();
    test_vhozhdenie_2();
    test_vhozhdenie_3();
    test_vhozhdenie_4();
    test_vhozhdenie_5();
    test_KLP();
    test_KPL();
    test_PKL();
    test_PLK();
    test_LKP();
    test_LPK();
    test_search_1();
    test_search_2();
}


