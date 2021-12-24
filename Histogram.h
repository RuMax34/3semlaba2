#pragma once
using namespace std;

template <class T>
class Histogram {
private:
    Dictionary<int, int>* dict;
    int (*Get_int_value)(T);
    int (*cmp)(Tpair_for_dict<int, int>, Tpair_for_dict<int, int>);
public:
    Histogram(int (*Get_int_value)(T),
        int (*cmp)(Tpair_for_dict<int, int>, Tpair_for_dict<int, int>)) {
        dict = new Dictionary<int, int>(cmp);
        this->cmp = cmp;
        this->Get_int_value = Get_int_value;
    }

    ~Histogram() {
        delete dict;
    }

    void Add(T human) {
        int int_value = Get_int_value(human);
        if (dict->ContainsKey(int_value)) {
            int amount = dict->Get(int_value);
            dict->Remove(int_value);
            amount++;
            dict->Add(int_value, amount);
        }
        else {
            dict->Add(int_value, 1);
        }
    }

    int Get_amount(T human) {
        int int_value = Get_int_value(human);
        if (dict->ContainsKey(int_value))
            return dict->Get(int_value);
        return 0;
    }

    int Get_amount_int(int value) {
        if (dict->ContainsKey(value))
            return dict->Get(value);
        return 0;
    }

    Dictionary<int, int>* even_partition(int min, int max, int range) {
        Dictionary<int, int>* even_dict = new Dictionary<int, int>(this->cmp);
        int j = min, summary_amount = 0;
        if (dict->ContainsKey(min))
            even_dict->Add(min, dict->Get(min));
        for (int i = min; i < max; i++) {
            if ((i - min) % range == 0) {
                if (dict->ContainsKey(i)) {
                    summary_amount += dict->Get(i);
                    //    dict->Remove(i);
                }
                even_dict->Add(j, summary_amount);
                j = j + range;
                summary_amount = 0;
            }
            else {
                if (dict->ContainsKey(i)) {
                    summary_amount += dict->Get(i);
                    //  dict->Remove(i);
                }
            }
        }
        if (dict->ContainsKey(max))
            summary_amount += dict->Get(max);
        even_dict->Add(max, summary_amount);
        return even_dict;
    }

    Dictionary<int, int>* uneven_partition(Sequence<int>* seq) {
        Dictionary<int, int>* uneven_dict = new Dictionary<int, int>(this->cmp);
        int summary_amount = 0;
        for (int i = seq->GetFirst(), j = 1; i < seq->GetLast(); i++) {
            if (i < seq->Get(j)) {
                if (dict->ContainsKey(i)) {
                    summary_amount += dict->Get(i);
                    //   dict->Remove(i);
                }
            }
            else {
                if (dict->ContainsKey(i)) {
                    summary_amount += dict->Get(i);
                    //   dict->Remove(i);
                }
                uneven_dict->Add(seq->Get(j), summary_amount);
                j++;
                summary_amount = 0;
            }
        }
        if (dict->ContainsKey(seq->GetLast()))
            summary_amount += dict->Get(seq->GetLast());
        uneven_dict->Add(seq->GetLast(), summary_amount);
        return uneven_dict;
    }
};
