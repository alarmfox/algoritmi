#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int brute_force_solution (const vector<int>& input);
int sum (const vector<int>& input, int start, int end);

int main() {
    vector<int> input1 = { -1,-3,4,2 };
    vector<int> input2 = { -1,2,-5,7 };
    int res;

    res = brute_force_solution(input1);
    assert(res == 6);
    res = brute_force_solution(input2);
    assert(res == 7);

}

int brute_force_solution(const vector<int>& input) {

    int max = 0, tmp;
    for (int i = 0; i < input.size(); ++i) {
        for (int j = i; j < input.size(); ++j ){
            tmp = sum(input, i, j);
            if (max < tmp){
                max = tmp;
            }
        }
    }

    return max;
}

int sum(const vector<int>& input, int start, int end) {
    int tmp = 0;
    for (int i = start; i <= end; ++i) {
        tmp += input[i];
    }

    return tmp;
}