#include<iostream>
#include <vector>

const int solution(const int n) {
    int pairs[n+1];
    pairs[0] = pairs[1] = 1;
 
    for (int i=2; i<=n; i++)
       pairs[i] = pairs[i-1] + (i-1)*pairs[i-2];
 
    return pairs[n];
               
}
 
int main() {
    const std::vector<int> inputs = {3, 4, 5};
    for (const int input : inputs) {
      std::cout << solution(input) << std::endl;
    }
}