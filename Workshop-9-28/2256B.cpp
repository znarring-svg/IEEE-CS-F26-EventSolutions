#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int res = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {

                bool valid = true;

                // Current values for even/odd positions
                int even = i;
                int odd = j;

                for (int u = 0; u < n; u++) {
                    int expected;

                    if (u % 2 == 0)
                        expected = even;
                    else
                        expected = odd;

                    if (s[u] != '?' && s[u] - '0' != expected) {
                        valid = false;
                        break;
                    }

                    // flip val for next step
                    if (u % 2 == 0)
                        even = 1 - even;
                    else
                        odd = 1 - odd;
                }

                if (valid)
                    res++;
            }
        }

        cout << res << '\n';
    }
}
