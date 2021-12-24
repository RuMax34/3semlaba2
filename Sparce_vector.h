#pragma once
#include "Dictionary.h"

template <class T>
class Sparce_vector {
private:
    Dictionary<int, T>* dict;
    int size;
public:
    Sparce_vector(T* vector, int size,
        int (*cmp)(Tpair_for_dict<int, T>, Tpair_for_dict<int, T>)) {
        dict = new Dictionary<int, T>(cmp);
        for (int i = 0; i < size; i++) {
            if (vector[i] != 0) {
                dict->Add(i, vector[i]);
            }
        }
        this->size = size;
    }

    ~Sparce_vector() {
        delete dict;
    }

    T* Get_sparce_vector() {
        T* get_vector = new T[size];
        for (int i = 0; i < size; i++) {
            if (dict->ContainsKey(i))
                get_vector[i] = dict->Get(i);
            else
                get_vector[i] = 0;
        }
        return get_vector;
    }

    int Get_size() {
        return size;
    }

    Dictionary<int, T>* Get_dictionary() {
        return this->dict;
    }

    void Print() {
        dict->Print();
    }

};

