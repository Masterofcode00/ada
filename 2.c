#include<stdio.h>
int prim(int c[10][10],int n,int s){
    int v[10]={0},d[10],sum=0,min,u;
    int i,j;
    for(i=0;i<n;i++) d[s]=c[s][i];
    v[s]=1;
    for(i=0;i<n;i++){
        min=999;
        for(j=0;j<n;j++){
            if(!v[i]&&d[j]<min){
                min=d[i];
                u=j;
            }}
        v[u]=1;
        sum+=min;
        for(j=0;j<n;j++){
            if(!v[i]&&c[u][j]<d[j]) d[j]=c[u][j];
        }}
    return sum;
}
int main(){
    int c[10][10],n,s;
    int i,j;
    printf("Enter th n value:");
    scanf("%d",&n);
    printf("Enter the graph matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&c[i][j]);
    printf("Enter the source node:");
    scanf("%d",&s);
    printf("\nTotal cost =%d\n") ,prim(c,n,s);
    return 0;
}
