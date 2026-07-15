#include <stdio.h>
int s[20],x[20],n,d;
void subset(int sum,int k,int rem){
    x[k]=1;
    if(sum+s[k]==d){
        for(int i=1;i<=k;i++)
            if(x[i]) printf("%d ",s[i]);
        printf("\n");
    }
    else if(sum+s[k]+s[k+1]<=d)
        subset(sum+s[k],k+1,rem-s[k]);
    if(sum+rem-s[k]>=d && sum+s[k+1]<=d){
        x[k]=0;
        subset(sum,k+1,rem-s[k]);
    }}
int main(){
    int sum=0;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter set (sorted): ");
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        sum+=s[i];
    }
    printf("Enter required sum: ");
    scanf("%d",&d);
    if(sum<d || s[1]>d)
        printf("No subset possible");
    else
        subset(0,1,sum);
    return 0;
}