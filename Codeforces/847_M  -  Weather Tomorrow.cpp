#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t1, t2;
    bool progression;

    while(cin >> n) {
        cin >> t1 >> t2;
        int d = t2 - t1;
        progression = true;
        t1 = t2;
        for(int i=3; i<=n; i++) {
            cin >> t2;
            if( (t2-t1) != d) progression = false;

            t1 = t2;
        }

        if(progression) cout << (t2 + d) << endl;
        else cout << t2 << endl;

    }

    return 0;
}
