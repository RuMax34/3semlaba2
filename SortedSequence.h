#pragma once
#include "my_sorts.h"
using namespace std;

template<class T>
class SortedSequence {
private:
    Sequence<T>* seq;
    int (*cmp)(T, T);
public:
    SortedSequence(Sequence<T>* (*sort)(Sequence<T>*, int (*)(T, T)),
        Sequence<T>* not_sorted, int (*cmp)(T, T)) {
        seq = sort(not_sorted, cmp);
        this->cmp = cmp;
    }

    ~SortedSequence() {
        seq = nullptr;
    }

    int GetLength() {
        return seq->GetLength();
    }

    bool is_empty() {
        if (!seq->GetLength())
            return 1;
        return 0;
    }

    T Get(int index) {
        return seq->Get(index);
    }

    T GetLast() {
        return seq->GetLast();
    }

    T GetFirst() {
        return seq->GetFirst();
    }

    bool Contain(T item) {
        for (int i = 0; i < seq->GetLength(); i++) {
            if (seq->Get(i) == item)
                return 1;
        }
        return 0;
    }

    int IndexOf(T item) {
        for (int i = 0; i < seq->GetLength(); i++) {
            if (seq->Get(i) == item)
                return i;
        }
        return -1;
    }

private:
    SortedSequence(Sequence<T>* seq, int (*cmp)(T,T)) {
        this->seq = seq;
        this->cmp = cmp;
    }
public:
    SortedSequence<T>* GetSubSequence(int start, int end) {
        Sequence<T>* SubSeq = seq->GetSubSequence(start, end);
        SortedSequence<T>* SortedSubSeq_ptr = new SortedSequence<T>(SubSeq, cmp);
        return SortedSubSeq_ptr;
    }


    void Add(T item) {
        int left = 0;
        int needed = -1;
        int right = seq->GetLength() - 1;
        while (left < right) {

            int mid =  left + (right - left) / 2;

            if (this->cmp(item, seq->Get(mid)))
                left = mid + 1;

            else if (this->cmp(seq->Get(mid), item))
                right = mid ;

            else {
                needed = mid;
                right = left - 1;
            }
        }
        if (needed == -1)
            seq->InsertAt(item, left);
        else
            seq->InsertAt(item, needed);
    }
   
   
    void print() {
        seq->print();
    }

};
