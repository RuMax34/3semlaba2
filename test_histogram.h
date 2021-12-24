#pragma once
#include "Histogram.h"
#include <cassert>
#include <string>
#include "test_dictionary.h"

struct Person {
    string name;
    string second_name;
    int age;
    string country;
};

int Get_int_value(Person human) {
    return human.age;
}

int compare_int_int_pairs(Tpair_for_dict<int, int> a,
    Tpair_for_dict<int, int> b);



void test_1_Get_amount_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 12, "rf" };
    Person dad1{ "ivan", "diman", 22, "rf" };
    Person dad2{ "ivan", "diman", 3, "rf" };
    Person dad3{ "ivan", "diman", 5, "rf" };
    Person dad4{ "ivan", "diman", 12, "rf" };
    Person dad5{ "ivan", "diman", 51, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    assert(test->Get_amount(dad1) == 1);
    assert(test->Get_amount(dad0) == 2);
}

void test_2_Get_amount_int_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 12, "rf" };
    Person dad1{ "ivan", "diman", 22, "rf" };
    Person dad2{ "ivan", "diman", 3, "rf" };
    Person dad3{ "ivan", "diman", 5, "rf" };
    Person dad4{ "ivan", "diman", 12, "rf" };
    Person dad5{ "ivan", "diman", 51, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    assert(test->Get_amount_int(12) == 2);
    assert(test->Get_amount_int(3) == 1);
}

void test_3_even_partition_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 12, "rf" };
    Person dad1{ "ivan", "diman", 22, "rf" };
    Person dad2{ "ivan", "diman", 2, "rf" };
    Person dad3{ "ivan", "diman", 5, "rf" };
    Person dad4{ "ivan", "diman", 12, "rf" };
    Person dad5{ "ivan", "diman", 51, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    Dictionary<int, int>* dict = test->even_partition(2, 51, 7);
    assert(dict->Get(2) == 1);
    assert(dict->Get(9) == 1);
    assert(dict->Get(16) == 2);
    assert(dict->Get(23) == 1);
    assert(dict->Get(30) == 0);
    assert(dict->Get(37) == 0);
    assert(dict->Get(44) == 0);
    assert(dict->Get(51) == 1);
    assert(dict->Count() == 8);
}

void test_4_even_partition_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 11, "rf" };
    Person dad1{ "ivan", "diman", 11, "rf" };
    Person dad2{ "ivan", "diman", 11, "rf" };
    Person dad3{ "ivan", "diman", 13, "rf" };
    Person dad4{ "ivan", "diman", 11, "rf" };
    Person dad5{ "ivan", "diman", 11, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    Dictionary<int, int>* dict = test->even_partition(10, 18, 2);
    assert(dict->Get(12) == 5);
    assert(dict->Get(14) == 1);
    assert(dict->Get(16) == 0);
    assert(dict->Get(18) == 0);
}

void test_5_even_partition_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 0, "rf" };
    Person dad1{ "ivan", "diman", 10, "rf" };
    Person dad2{ "ivan", "diman", 20, "rf" };
    Person dad3{ "ivan", "diman", 30, "rf" };
    Person dad4{ "ivan", "diman", 40, "rf" };
    Person dad5{ "ivan", "diman", 50, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    Dictionary<int, int>* dict = test->even_partition(0, 40, 10);
    assert(dict->Get(0) == 1);
    assert(dict->Get(10) == 1);
    assert(dict->Get(20) == 1);
    assert(dict->Get(30) == 1);
    assert(dict->Get(40) == 1);
    assert(dict->Count() == 5);
}

void test_6_uneven_partition_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 13, "rf" };
    Person dad1{ "ivan", "diman", 22, "rf" };
    Person dad2{ "ivan", "diman", 2, "rf" };
    Person dad3{ "ivan", "diman", 5, "rf" };
    Person dad4{ "ivan", "diman", 12, "rf" };
    Person dad5{ "ivan", "diman", 51, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    ArraySequence<int> arr;
    arr.InsertAt(0, 0);
    arr.InsertAt(4, 1);
    arr.InsertAt(12, 2);
    arr.InsertAt(17, 3);
    arr.InsertAt(38, 4);
    arr.InsertAt(51, 5);
    Sequence<int>* seq = &arr;
    Dictionary<int, int>* dict = test->uneven_partition(seq);
    assert(dict->Get(4) == 1);
    assert(dict->Get(12) == 2);
    assert(dict->Get(17) == 1);
    assert(dict->Get(38) == 1);
    assert(dict->Get(51) == 1);
    assert(dict->Count() == 5);
}

void test_7_uneven_partition_histogram() {
    Histogram<Person>* test = new Histogram<Person>(Get_int_value, compare_int_int_pairs);
    Person dad0{ "ivan", "diman", 0, "rf" };
    Person dad1{ "ivan", "diman", 10, "rf" };
    Person dad2{ "ivan", "diman", 20, "rf" };
    Person dad3{ "ivan", "diman", 30, "rf" };
    Person dad4{ "ivan", "diman", 40, "rf" };
    Person dad5{ "ivan", "diman", 60, "rf" };
    Person dad6{ "ivan", "diman", 70, "rf" };
    Person dad7{ "ivan", "diman", 80, "rf" };
    test->Add(dad0);
    test->Add(dad1);
    test->Add(dad2);
    test->Add(dad3);
    test->Add(dad4);
    test->Add(dad5);
    test->Add(dad6);
    test->Add(dad7);
    ArraySequence<int> arr;
    arr.InsertAt(0, 0);
    arr.InsertAt(5, 1);
    arr.InsertAt(16, 2);
    arr.InsertAt(38, 3);
    arr.InsertAt(58, 4);
    arr.InsertAt(91, 5);
    Sequence<int>* seq = &arr;
    Dictionary<int, int>* dict = test->uneven_partition(seq);
    assert(dict->Get(5) == 1);
    assert(dict->Get(16) == 1);
    assert(dict->Get(38) == 2);
    assert(dict->Get(58) == 1);
    assert(dict->Get(91) == 3);
    assert(dict->Count() == 5);
}

void TEST_ALL_HISTOGRAM() {
    test_1_Get_amount_histogram();
    test_2_Get_amount_int_histogram();
    test_3_even_partition_histogram();
    test_4_even_partition_histogram();
    test_5_even_partition_histogram();
    test_6_uneven_partition_histogram();
    test_7_uneven_partition_histogram();
}