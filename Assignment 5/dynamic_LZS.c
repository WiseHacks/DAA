#include<stdio.h>
int max(int x, int y) {
    if (x > y)return x;
    return y;
}
int LZS(int Arr[], int n) {
    if(n == 0)return 0;
    int dp[n][2], result = 1;
    for (int i = 0; i < n; i++)dp[i][0] = 1, dp[i][1] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (Arr[j] < Arr[i]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            if (Arr[j] > Arr[i]) {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        result = max(result, max(dp[i][0], dp[i][1]));
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++)scanf("%d", &Arr[i]);
    printf("%d\n", LZS(Arr, n));
}
