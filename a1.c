#include<stdio.h>
int c[10][10],p[10];
int find(int x){
    while(p[x]) x=p[x];
    return x;
}
int main(){
    int n,i,j,k=1,u,v,min,a,b,cost=0;
    printf("Enter the n value:");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    printf("Edge in MST:\n");
    while(k<n){
        min=999;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(c[i][j]<min){
                    min=c[i][j];
                    a=u=i;
                    b=v=j;
                }
                u=find(u);
                v=find(v);
                if(u!=v){
                    p[v]=u;
                    printf("%d -> %d\n",a,b);
                    cost+=min;
                    k++;
                }
                c[a][b]=c[b][a]=999;
    }
    printf("Minimum cost=%d",cost);
    return 0;
}
