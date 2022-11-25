#include<iostream>
#include <vector>

const int solution(const int x) {
    int pairs[x+1];
    pairs[0] = pairs[1] = 1;
 
    for (int i=2; i<=x; i++)
       pairs[i] = pairs[i-1] + (i-1)*pairs[i-2];
 
    return pairs[x];
               
}
 
int main() {
    std::vector<int> inputs = {3, 4, 5};
    for (const int input : inputs) {
      std::cout << solution(input) << std::endl;
    }


}