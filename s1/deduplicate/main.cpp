#include <vector>
#include "./Headers/printVector.h"
#include "./Headers/split.h"
#include "./Headers/isNumber.h"
using namespace std;

vector<string> removeAdjDup(vector<string>& vec){
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] != vec[i + 1]) continue;

    vector<string>::iterator ite = vec.begin() + i;
    vec.erase(ite);
    i--;
  }

  return vec;
}




int main() {
  vector<string> aa = {"12", "22", "32", "32", "32", "22"};

  removeAdjDup(aa);
  printVector(aa);
  return 0;
}

