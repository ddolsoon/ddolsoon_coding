#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    vector<string> input_names;

    string name;
    while (cin >> name) {
        input_names.push_back(name);
    }

    sort(input_names.begin(), input_names.end());

    vector<string> best_names;
    int best_cnt = 1;
    int cnt = 1;
    best_names.push_back(input_names[0]);

    for (int i = 1; i < input_names.size(); i++) {

        if (input_names[i] == input_names[i - 1]) {
            cnt += 1;
        } else {
            cnt = 1;
        }

        if (best_cnt < cnt) {
            best_cnt = cnt;
            best_names.clear();
            best_names.push_back(input_names[i]);
        } else if (best_cnt == cnt) {
            best_names.push_back(input_names[i]);
        }


    }

    for (int i = 0; i < best_names.size(); i++) {
        cout << best_names[i] << '\n';
    }


    return 0;
}