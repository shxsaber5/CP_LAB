#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string N;
        cin >> N;

        reverse(N.begin(), N.end());

        int i = 0;

        while (i < N.size() && N[i] == '0')
            i++;

        if (i == N.size())
            cout << 0 << endl;
        else
            cout << N.substr(i) << endl;
    }

    return 0;
}
