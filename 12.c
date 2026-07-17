#include <stdio.h>
int b[10][10], n;
int safe(int r, int c){
    int i, j;
    for(i=0;i<c;i++)
        if(b[r][i]) return 0;
    for(i=r,j=c;i>=0&&j>=0;i--,j--)
        if(b[i][j]) return 0;
    for(i=r,j=c;i<n&&j>=0;i++,j--)
        if(b[i][j]) return 0;
    return 1;
}
int queen(int c){
    int i;
    if(c==n)return 1;
    for(i=0;i<n;i++){
        if(safe(i,c)){
            b[i][c]=1;
            if(queen(c+1)) return 1;
            b[i][c]=0;     
        }}
    return 0;
}
int main(){
    int i,j;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=0;
    if(queen(0)){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                printf("%c ", b[i][j] ? 'Q' : '#');
            printf("\n");
        }}
    else{
        printf("Solution does not exist");
    }
    return 0;
}
