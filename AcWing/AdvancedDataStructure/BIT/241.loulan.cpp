#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2000010;
int a[N], t[N];

int n;

long long l[N], r[N]; // for A
long long ll[N], rr[N]; // for V

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) {
        t[i] += k;
    }
}

int ask(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
        sum += t[i];
    }

    return sum;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    long long resA = 0;
    long long resV = 0;

    for (int i = 1; i <= n; i++) {
        int y = a[i];
        l[i] = ask(y-1);
        ll[i] = ask(n) - ask(y);
        add(y, 1);
    }
    memset(t, 0, sizeof t);
    for (int i = n; i >= 1; i--) {
        int y = a[i];
        r[i] = ask(y-1);
        rr[i] = ask(n) - ask(y);
        add(y, 1);
    }
    for (int i = 1; i <= n; i++) {
        resA += l[i] * r[i];
        resV += ll[i] * rr[i];
    }

    cout << resV << " " << resA << endl;

    return 0;
}