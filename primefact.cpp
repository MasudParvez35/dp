#include<bits/stdc++.h>
using namespace std;
vector <int> vec(int n) {
    vector <int> v;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
        {
            v.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if (n > 1) v.push_back(n);
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector <int> v = vec(n);
    for (auto i : v) cout << i << " ";
}
