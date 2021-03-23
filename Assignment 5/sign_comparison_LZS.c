#include<stdio.h>

int signum(int x) {
    if (x > 0)return 1;
    else if (x < 0)return -1;
    else return 0;
}
int LZS(int Arr[], int n) {
    if(n == 0)return 0;
    int prevSign = 0, length = 1;
    for (int i = 1; i < n; i++) {
        int sign = signum(Arr[i] - Arr[i - 1]);
        if (sign != prevSign && sign != 0) {
            length++;
            prevSign = sign;
        }
    }
    return length;
}

int main() {

    int n;
    scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++)scanf("%d", &Arr[i]);
    printf("%d\n", LZS(Arr, n));
}
