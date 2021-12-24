#pragma once
#include "Search_often_sub.h"
#include <cassert>

int compare_string_int(Tpair_for_dict<string, int> a, Tpair_for_dict<string, int> b) {
    if (a.key > b.key)
        return 1;
    return 0;
}

void test_1_search_often_sub() {
    ArraySequence<char> arr;
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('a');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('c');
    arr.Append('a');

    Sequence<char>* seq;
    seq = &arr;

    Search_often_sub testing(seq, 2, 3, compare_string_int);
    assert(testing.Get_max_count() == 3);
    assert(testing.output_seq()->GetLength() == 15);
    assert(testing.Get_max()->Get(0).key == "ab");
    assert(testing.Get_max()->Get(1).key == "ca");
}

void test_2_search_often_sub() {
    ArraySequence<char> arr;
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('a');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('c');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');

    Sequence<char>* seq;
    seq = &arr;

    Search_often_sub testing(seq, 3, 4, compare_string_int);
    assert(testing.Get_max_count() == 3);
    assert(testing.output_seq()->GetLength() == 21);
    assert(testing.Get_max()->Get(0).key == "abc");
}

void test_3_search_often_sub() {
    ArraySequence<char> arr;
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('a');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('c');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('c');
    arr.Append('a');

    Sequence<char>* seq;
    seq = &arr;

    Search_often_sub testing(seq, 1, 5, compare_string_int);
    assert(testing.Get_max_count() == 10);
    assert(testing.Get_max()->Get(0).key == "a");
    assert(testing.output_seq()->GetLength() == 52);
}

void TEST_ALL_SEARCH_OFTEN_SUB() {
    test_1_search_often_sub();
    test_2_search_often_sub();
    test_3_search_often_sub();
}