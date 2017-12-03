#include <stdio.h>

int MaxSubseqSum1(int A[],int N);
int MaxSubseqSum2(int A[],int N);
int MaxSubseqSum4(int A[],int N);
int Max3(int A,int B,int C);
int DivideAndConquer(int List[], int left, int right);
int MaxSubseqSum3(int List[],int N);

 
int main(){
    int n,i,Max,Array[100005];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }
    Max=MaxSubseqSum3(Array,n);
    printf("%d\n",Max);
    return 1;
}

int MaxSubseqSum1(int A[],int N){
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            ThisSum=0;
            for(k=i;k<j;k++){
                ThisSum+=A[k];
            }
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubseqSum2(int A[],int N){
    int ThisSum,MaxSum=0;
    int i,j;
    for(i=0;i<N;i++){
        ThisSum=0;
        for(j=i;j<N;j++){
            ThisSum+=A[j];
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}    

int MaxSubseqSum4(int A[],int N){
    int ThisSum, MaxSum;
    int i;
    ThisSum=MaxSum=0;
    for(i=0;i<N;i++){
        ThisSum+=A[i];
        if(ThisSum>MaxSum){
            ThisSum=MaxSum;
        }else if(ThisSum<0){
            ThisSum=0;
        }
    }
    return MaxSum;
}

int Max3(int A,int B,int C){
    return A>B?A>C?A:C:B>C?B:C;
}

int DivideAndConquer(int List[], int left, int right){
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;

    int LeftBorderSum,RightBorderSum;
    int center,i,j;
    //递归结束条件，当left==right时，只有一个子项，返回这个子项
    if(left==right){
        if(List[left]>0)return List[left];
        else return 0;
    }

    center=(left+right)/2;
    MaxLeftSum=DivideAndConquer(List,left,center);
    MaxRightSum=DivideAndConquer(List,center+1,right);

    MaxLeftBorderSum=0;LeftBorderSum=0;
    for(i=center;i>=left;i--){
        LeftBorderSum+=List[i];
        if(LeftBorderSum>MaxLeftBorderSum){
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    MaxRightBorderSum=0;RightBorderSum=0;
    for(j=center+1;j<right;j++){
        RightBorderSum+=List[j];
        if(RightBorderSum>MaxRightBorderSum){
            MaxRightBorderSum = RightBorderSum;
        }
    }
    
    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubseqSum3(int List[],int N){
    return DivideAndConquer(List,0,N-1);
}
