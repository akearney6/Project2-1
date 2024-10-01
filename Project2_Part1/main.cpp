#include "DES.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // please do not write code in this file
  // you only need to implement the shift_left and key_gen functions in the key_scheduler.cpp
  string key = hexToBinary("02FFA374EB55F57B");
  string output;
  vector<string> sub_keys = key_gen(key);
  for (int i = 0; i < sub_keys.size(); i++) {
    cout << sub_keys[i] << endl;
  }
}
