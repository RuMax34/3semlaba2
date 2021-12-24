#pragma once
#include <iostream>
#include <string>
#include "test_sorted_seq.h"
#include "test_sorts.h"
#include "test_BST.h"
#include "test_dictionary.h"
#include "test_sparce_vector.h"
#include "test_histogram.h"


void print_seq(Sequence<Tpair_for_dict<string, int>>* seq) {
    for (int i = 0; i < seq->GetLength(); i++) {
        cout << seq->Get(i).key << " - " << seq->Get(i).element << endl;
    }
}

class Search_often_sub {
private:
    Dictionary<string, int>* dict;
    int min, max;
    int max_count;
    string max_string;
public:
    Search_often_sub(Sequence<char>* seq, int min, int max,
        int (*cmp_for_dict)(Tpair_for_dict<string, int>, Tpair_for_dict<string, int>)) {
        dict = new Dictionary<string, int>(cmp_for_dict); // seq, min, max, compare for dict
        this->min = min;
        this->max = max;
        max_count = 0;
        for (int i = 0; i < seq->GetLength(); i++) {
            for (int j = min; i + j <= seq->GetLength() && j <= max; j++) {
                Sequence<char>* sub = seq->GetSubSequence(i, i + j);
                string sub_string = "fill";
                sub_string.clear();

                for (int i = 0; i < sub->GetLength(); i++) {
                    sub_string.append(1, sub->Get(i));
                }

                if (!dict->ContainsKey(sub_string)) {
                    int count = 1;
                    dict->Add(sub_string, count);
                    if (max_count < count) {
                        max_count = 1;
                        max_string = sub_string;
                    }

                }

                else {
                    int count = dict->Get(sub_string);
                    count++;
                    dict->Remove(sub_string);
                    dict->Add(sub_string, count);
                    if (max_count < count) {
                        max_count = count;
                        max_string = sub_string;
                    }
                }
            }
        }
    }

    Sequence<Tpair_for_dict<string, int>>* output_seq() {
        vector<Tpair_for_dict<string, int>>* vect = dict->LKP();
        ArraySequence<Tpair_for_dict<string, int>>* arr = new
            ArraySequence<Tpair_for_dict<string, int>>(dict->Count());
        Sequence<Tpair_for_dict<string, int>>* seq = arr;
        for (size_t i = 0; i < vect->size(); i++) {
            seq->Set(i, vect->at(i));
        }
        vect->clear();
        return seq;
    }

    ~Search_often_sub() {
        delete dict;
    }

    int Get(string sub) {
        return dict->Get(sub);
    }

    Sequence<Tpair_for_dict<string, int>>* Get_max() {
         vector<Tpair_for_dict<string, int>>* vect = dict->LKP();
         ArraySequence<Tpair_for_dict<string, int>>* arr = new
             ArraySequence<Tpair_for_dict<string, int>>;
         for (size_t i = 0; i < vect->size(); i++) {
             if (vect->at(i).element == max_count) {
                 arr->Append(vect->at(i));
             }
         }
         vect->clear();
         return arr;
    }

    int Get_max_count() {
        return max_count;
    }

    void print() {
        this->dict->Print();
    }
};