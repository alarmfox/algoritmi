#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int x, y, n;
    cin >> n;
    for (int i = 0; i < n;++i) {
        cin >> x;
        cin >> y;

        cabs(x, y);
    }

    return 0;
}

void cabs(int x, int y) {
    if (x < y) {
        cout << "FIRST";
    }
    else if (x > y) {
        cout << "SECOND";
    }
    else {
        cout << "ANY";
    }
    cout << endl;
}