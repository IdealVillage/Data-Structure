#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 1024
typedef int ElementType;
typedef struct Node *List;
struct Node {
    ElementType Data[MAXSIZE];
    int Last;
};


List MakeEmpty();
int Insert(List L,ElementType X,int p);
int Delete(List L, int p);
int Find(List L,ElementType X);
    int main()
{
    List L=MakeEmpty();
	Insert(L,2,0);
	Insert(L,3,1);
    printf("当前最后一个元素：%d\n",L->Data[L->Last]);
	int position=Find(L,3);
	printf("要查找的元素的位置:%d\n",position);
    return 1;
}


List MakeEmpty()
{
    List L;
 
    L = (List)malloc(sizeof(struct Node));
    L->Last = -1;
 	
    return L;
}

int Find(List L,ElementType X){
	int i=0;
    while(i<=L->Last&&L->Data[i]!=X)
        i++;
    if(i>L->Last)return -2;
    else return i;
}

int Insert(List L,ElementType X,int p){
    int i;
    if(L->Last>MAXSIZE-1){
        printf("琛ㄦ弧");
        return 0;
    }
    if(p<0||p>L->Last+1){
        printf("浣嶇疆涓嶅悎娉�");
        return 0;
    }
    for(i=L->Last;i>=p;i--)
        L->Data[i+1]=L->Data[i];
    L->Data[p]=X;
    L->Last++;
    return 1;
}
int Delete(List L,int p){
    int i;
    if(p<0||p>L->Last){
        printf("浣嶇疆涓嶅悎娉�");
        return 0;
    }
    for(i=p+1;i<L->Last;i++){
        L->Data[i-1]=L->Data[i];
    }
    L->Last--;
    return 1;
}

















