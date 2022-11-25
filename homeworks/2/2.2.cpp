#include<iostream>
 
const int solution(const int x) {
    if (x==0 || x==1) {
      return 1;
    } else {
        return solution(x-1) + (x-1)*solution(x-2);
    }
               
}
 
int main() {
    int x = 3;
    std::cout << solution(x) << std::endl;
    return 0;
}