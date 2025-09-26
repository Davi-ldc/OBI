#include <iostream>
#include <vector>
using namespace std;
#define int long long
/*

f(x) = ax + b
h(x) = cx + d

AX + B = CX + D
AX-CX = D-B
X(A-C)=D-B
X = (D-B)/(A-C)

X1 <= X <= X2

X1 <= (D-B)/(A-C) <= X2
(A-C)*X1 <= D-B <= (A-C)*X2

*/
int N, X1, X2;

bool val(int A, int B, int C, int D) {
    if (A == C) {
        return false;
    }

    //aura
    int ac = (A - C);
    int db = (D - B);

    if (ac > 0) {
        return (ac * X1 <= db && db <= ac * X2);
    } else {
        return (ac * X2 <= db && db <= ac * X1);
    }
}

int32_t main() {
    cin >> N >> X1 >> X2;

    vector<pair<int, int>> f(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        f[i] = {a, b};
    }

    int r = 0;
    //pra cada reta
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (val(f[i].first, f[i].second, f[j].first, f[j].second)) {
                r++;
            }
        }
    }

    cout << r << endl;

    return 0;
}