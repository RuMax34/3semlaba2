#pragma once
#include "SortedSequence.h"
#include <cassert>
using namespace std;

int compare_int_for_sorted_seq(int a, int b) {   // сравнение интв
    if (a > b)
        return 1;
    return 0;
}

void test_1_length_sorted() {
    ArraySequence<int> arr_seq;
    Sequence<int>* seq = &arr_seq;
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(0 == sorted->GetLength());
}

void test_2_length_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(5 == sorted->GetLength());
}

void test_3_empty_sorted() {
    ArraySequence<int> arr_seq;
    Sequence<int>* seq = &arr_seq;
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(sorted->is_empty());
}

void test_4_empty_sorted() {
    ArraySequence<int> arr_seq(8);
    Sequence<int>* seq = &arr_seq;
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(!sorted->is_empty());
}

void test_5_get_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 5; i++) {
        seq->Set(i, 134 - i);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(132 == sorted->Get(2));
}

void test_6_get_sorted() {
    ArraySequence<int> arr_seq(2);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 2; i++) {
        seq->Set(i, 1343 - i);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(1342 == sorted->Get(0));
}

void test_7_GetFirst_sorted() {
    ArraySequence<int> arr_seq(4);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 4; i++) {
        seq->Set(i, 150 + i);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(150 == sorted->GetFirst());
}

void test_8_GetFirst_sorted() {
    ArraySequence<int> arr_seq(4);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 4; i++) {
        seq->Set(i, 150 - i);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(147 == sorted->GetFirst());
}

void test_9_GetLast_sorted() {
    ArraySequence<int> arr_seq(6);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 6; i++) {
        seq->Set(i, 11);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(11 == sorted->GetLast());
}

void test_10_GetLast_sorted() {
    ArraySequence<int> arr_seq(6);
    Sequence<int>* seq = &arr_seq;
    for (int i = 0; i < 6; i++) {
        seq->Set(i, 11 + 7 * i);
    }
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(46 == sorted->GetLast());
}

void test_11_IndexOf_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 133);
    seq->Set(1, 1323);
    seq->Set(2, 433);
    seq->Set(3, 4433);
    seq->Set(4, -133);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(-1 == sorted->IndexOf(13));
    assert(2 == sorted->IndexOf(433));
}

void test_12_GetSubSequence_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 533);
    seq->Set(2, 19);            // 0, 19, 42 , 432, 533
    seq->Set(3, 432);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    SortedSequence<int>* SortedSubSeq = sorted->GetSubSequence(2, 4);
    assert(SortedSubSeq->Get(1) == 432);
    assert(sorted->GetSubSequence(2, 4)->GetLength() == 2);
}

void test_13_GetSubSequence_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 533);
    seq->Set(2, 19);          // 0 , 19 ,42 , 432, 533
    seq->Set(3, 432);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    assert(sorted->GetSubSequence(2, 3)->Get(0) == 42);
    assert(sorted->GetSubSequence(2, 3)->GetLength() == 1);
}

void test_14_add_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 533);
    seq->Set(2, 19);    // 0, 19 , 42, 432, 533
    seq->Set(3, 432);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(13);       // 0, 13, 19, 42, 432, 533
    assert(sorted->GetLength() == 6);
    assert(sorted->Get(0) == 0);
    assert(sorted->Get(1) == 13);
    assert(sorted->Get(2) == 19);
    assert(sorted->Get(3) == 42);
    assert(sorted->Get(4) == 432);
    assert(sorted->Get(5) == 533);
}

void test_15_add_sorted() {
    ArraySequence<int> arr_seq(1);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(15);
    assert(sorted->GetLength() == 2);
    assert(sorted->Get(0) == 15);
    assert(sorted->Get(1) == 42);
}

void test_16_add_sorted() {
    ArraySequence<int> arr_seq;
    Sequence<int>* seq = &arr_seq;
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(13);
    assert(sorted->GetLength() == 1);
    assert(sorted->GetFirst() == 13);
}

void test_17_add_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 43);
    seq->Set(2, 42);
    seq->Set(3, 41);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(41);
    assert(sorted->GetLength() == 6);
    assert(sorted->Get(0) == 0);
    assert(sorted->Get(1) == 41);
    assert(sorted->Get(2) == 41);
    assert(sorted->Get(3) == 42);
    assert(sorted->Get(4) == 42);
    assert(sorted->Get(5) == 43);
}

void test_18_add_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 43);
    seq->Set(2, 42);
    seq->Set(3, 41);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(42);
    assert(sorted->GetLength() == 6);
    assert(sorted->Get(0) == 0);
    assert(sorted->Get(1) == 41);
    assert(sorted->Get(2) == 42);
    assert(sorted->Get(3) == 42);
    assert(sorted->Get(4) == 42);
    assert(sorted->Get(5) == 43);
}

void test_19_add_sorted() {
    ArraySequence<int> arr_seq(5);
    Sequence<int>* seq = &arr_seq;
    seq->Set(0, 42);
    seq->Set(1, 533);
    seq->Set(2, 19);    // 0, 19 , 42, 432, 533
    seq->Set(3, 432);
    seq->Set(4, 0);
    SortedSequence<int> sorted_from_seq(bubble_sort, seq, compare_int_for_sorted_seq);
    SortedSequence<int>* sorted = &sorted_from_seq;
    sorted->Add(-13);       // 0, 13, 19, 42, 432, 533
    assert(sorted->GetLength() == 6);
    assert(sorted->Get(0) == -13);
    assert(sorted->Get(1) == 0);
    assert(sorted->Get(2) == 19);
    assert(sorted->Get(3) == 42);
    assert(sorted->Get(4) == 432);
    assert(sorted->Get(5) == 533);
}

void TEST_ALL_SORTED_SEQ() {
    test_1_length_sorted();
    test_2_length_sorted();
    test_3_empty_sorted();
    test_4_empty_sorted();
    test_5_get_sorted();
    test_6_get_sorted();
    test_7_GetFirst_sorted();
    test_8_GetFirst_sorted();
    test_9_GetLast_sorted();
    test_10_GetLast_sorted();
    test_11_IndexOf_sorted();
    test_12_GetSubSequence_sorted();
    test_13_GetSubSequence_sorted();
    test_14_add_sorted();
    test_15_add_sorted();
    test_16_add_sorted();
    test_17_add_sorted();
    test_18_add_sorted();
    test_19_add_sorted();
}
