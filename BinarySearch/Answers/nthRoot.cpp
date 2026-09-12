#include <iostream>
using namespace std;
int nthRoot(int n, int m) {
    // Code here
    if (m == 1 || m == 0) {
        return m;
    }
    if (n == 0 || n == 1) {
        return m;
    }
    int left = 1;
    int right = (m / 2) + 1;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        // cout<<mid<<endl;
        long long calc = 1;
        for (int i = 0; i < n; i++) {
            calc = calc * mid;
            if (calc > m) {
                break;
            }
        }
        if (calc == m) {
            // cout<<mid<<endl;
            answer = mid;
            break;
        } else if (calc < m) {
            left = mid + 1;
        } else if (calc > m) {
            right = mid - 1;
        }
    }
    return answer;
}
int main() {
    int ans = nthRoot(3, 27);
    cout << ans << endl;
    return 0;
}