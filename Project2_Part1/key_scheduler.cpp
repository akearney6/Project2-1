#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    char first_bit = sub_key[0];

    for (int i = 0; i < sub_key.length() - 1; i++) {
        sub_key[i] = sub_key[i + 1];  
    }
   
    sub_key[sub_key.length() - 1] = first_bit;

    return sub_key;
} 

vector<string> key_gen(string key){
    vector<string> sub_keys;
    string permuted_key;

    int shift_schedule[16] = {1, 1, 2, 2, 2, 2, 2, 2,
                              1, 2, 2, 2, 2, 2, 2, 1};

    for (int i = 0; i < 56; i++) {
        permuted_key += key[PC1[i] - 1];
    }

    string left_half;
    string right_half;

    for (int i = 0; i < 28; i++) {
        left_half += permuted_key[i];      
        right_half += permuted_key[i + 28]; 
    }

    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < shift_schedule[i]; j++) {
            left_half = shift_left(left_half);
            right_half = shift_left(right_half);
        }

        string combined = left_half + right_half;

        string sub_key = "";
        for (int k = 0; k < 48; k++) {
            sub_key += combined[PC2[k] - 1];
        }

        sub_keys.push_back(sub_key);
    }
    return sub_keys;
}
