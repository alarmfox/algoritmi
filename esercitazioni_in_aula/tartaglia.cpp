#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

const vector<int> solution(const int k);

#define DEBUG 0

int main() {
    const int n = 5;

    const auto res = solution(n);

    for (auto elem: res) {
        cout << elem << ' ';
    }
}

const vector<int> solution(const int n) {
    int tartaglia[n][n];

    tartaglia[0][0] = 1;

    for (int i = 1; i < n; ++i) {
        tartaglia[0][i] = 0;
    }

    for (int i = 1; i<n; ++i){
        tartaglia[i][0] = 1;
        for (int j = 1; j < n; ++j) {
            tartaglia[i][j] = tartaglia[i-1][j-1] + tartaglia[i-1][j];
        }
    }

    if (DEBUG) {
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j<n; ++j) {
                cout << tartaglia[i][j] << ' ';
            }
            cout << endl;
        }
    }

    vector<int> res;

    for (int i = 0; i < n; ++i) {
        res.push_back(tartaglia[n-1][i]);
    }
    return res;
}

