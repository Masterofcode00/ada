#include <stdio.h>
#define INF 999
int prim(int c[10][10], int n, int s) {
    int v[10] = {0}, d[10], sum = 0, min, u;
    for (int i = 0; i < n; i++) d[i] = c[s][i];
    v[s] = 1;
    for (int i = 0; i < n - 1; i++) {
        min = INF;
        for (int j = 0; j < n; j++) {
            if (!v[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        v[u] = 1;
        sum += min;
        for (int j = 0; j < n; j++) {
            if (!v[j] && c[u][j] < d[j]) d[j] = c[u][j];
        }
    }
    return sum;
}
int main() {
    int c[10][10], n, s;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter graph matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter source node : ");
    scanf("%d", &s);
    printf("\nTotal Cost = %d\n", prim(c, n, s));
    return 0;
}