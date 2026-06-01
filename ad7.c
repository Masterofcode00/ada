#include <stdio.h>
int main() {
    int n, m, w[20], p[20], i, j, cw = 0;
    float r[20], profit = 0;
    printf("Enter n and capacity: ");
    scanf("%d%d", &n, &m);
    printf("Enter weights:\n");
    for(i=0;i<n;i++) scanf("%d",&w[i]);
    printf("Enter profits:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&p[i]);
        r[i] = (float)p[i]/w[i];
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(r[i] < r[j]) {
                float t=r[i]; r[i]=r[j]; r[j]=t;
                int x=w[i]; w[i]=w[j]; w[j]=x;
                x=p[i]; p[i]=p[j]; p[j]=x;
            }
    for(i=0;i<n;i++) {
        if(cw + w[i] <= m) {
            cw += w[i];
            profit += p[i];
        } else {
            profit += (m-cw) * r[i];
            break;
        }
    }

    printf("Max Profit = %.2f", profit);
    return 0;
}