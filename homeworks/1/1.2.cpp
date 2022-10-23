#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define DEBUG 1

int* solution(const vector<int>& input) {
    vector<pair<int, int>> appoggio;

    int* results = new int[input.size()];

    for (int i = 0; i < input.size(); ++i) {
        appoggio.push_back({
            i, input[i]
            });
    }

    stable_sort(appoggio.begin(), appoggio.end(), [](pair<int, int> first, pair<int, int> second) {
        return first.second < second.second;
        });

    int index, value, tmp, offset;
    for (int i = 0; i < appoggio.size(); ++i) {
        value = appoggio[i].second;

        if (appoggio.size() - 1 != i) {
            offset = 0;
            tmp = appoggio[i + 1].second;

            while (value == tmp) {
                if (tmp == value) {
                    offset += 1;
                    tmp = appoggio[i + offset + 1].second;
                }
            }
        }

        // 4 5 5 6 7 9
        // 5 6 4 5 7 9
        if (offset >= 1) {
            for (int j = 0; j < offset + 1; ++j) {
                index = appoggio[i + j].first;
                results[index] = offset + i;
            }

        }
        else {
            index = appoggio[i + offset].first;
            results[index] = offset + i;

        }
        i += offset;

    }
    return results;
}

int main() {

    vector<int> input = { 5, 6, 4, 5, 7, 9 };
    int* results = solution(input);

    // for (int i = 0; i < input.size(); ++i) {
    //     cout<<results[i]<<endl;
    // }
    // cout<<endl;

    // delete []results;

    input = { -6,3,2,4,6,-5,8 };


    // 0 3 2 4 5 1 6
    results = solution(input);

    for (int i = 0; i < input.size(); ++i) {
        cout << results[i] << endl;
    }
    cout << endl;

    delete[]results;
}