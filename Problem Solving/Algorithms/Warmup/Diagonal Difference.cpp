#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n, sum1 = 0, sum2 = 0;
    scanf("%d", &n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i ++) {
       for(int a_j = 0; a_j < n; a_j ++) {
          scanf("%d",&a[a_i][a_j]);
       }
    }
    for(int a_i = 0; a_i < n; a_i ++) {
          sum1 = sum1 + a[a_i][a_i];
    }
    for(int a_i = 0, a_j = n - 1; a_i < n, a_j >= 0; a_i ++, a_j --) {
          sum2 = sum2 + a[a_i][a_j];
    }
    int result;
    result = abs(sum1 - sum2);

    printf("%d", result);
    return 0;
}
