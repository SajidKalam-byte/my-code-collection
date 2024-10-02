#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> powers(n);

    for (int i = 0; i < n; ++i) {
        cin >> powers[i];
    }

    sort(powers.begin(), powers.end(), greater<long long>());

    long long teamCaptain = 0;
    long long teamIronMan = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            teamCaptain += powers[i];
        } else {
            teamIronMan += powers[i];
        }
    }

    long long difference = teamCaptain - teamIronMan;
    cout << difference << endl;

    return 0;
}
