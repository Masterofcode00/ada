#include <stdio.h>
#define MAX 20
int main() {
    int n,w[MAX],p[MAX],x[MAX]={0},m,i,j,t,cw=0;
    float r[MAX],tp=0,temp;
    printf("Enter the number of objects: ");
    scanf("%d",&n);
    printf("Enter the objects' weights: ");
    for(i=0;i<n;i++) scanf("%d",&w[i]);
    printf("Enter the objects' profits: ");
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    printf("Enter the maximum capacity: ");
    scanf("%d",&m);
    for(i=0;i<n;i++) r[i]=(float)p[i]/w[i];
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(r[i]<r[j]){
                temp=r[i]; r[i]=r[j]; r[j]=temp;
                t=w[i]; w[i]=w[j]; w[j]=t;
                t=p[i]; p[i]=p[j]; p[j]=t;
            }
    for(i=0;i<n;i++){
        if(cw+w[i]<=m){
            x[i]=1;
            cw+=w[i];
            tp+=p[i];
        }else{
            tp+=(m-cw)*(float)p[i]/w[i];
            break;
        }}
    printf("\nOptimal solution for greedy method: %.1f",tp);
    printf("\nSolution vector for greedy method: ");
    for(i=0;i<n;i++)
        printf("%d ",x[i]);
    return 0;
}
