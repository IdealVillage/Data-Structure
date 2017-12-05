#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct QNode{
	ElementType *data;
	int rear;
	int front;
	int MaxSize;
}*Queue;


Queue createQueue(int MaxSize);
bool isFull(Queue q);
bool isEmpty(Queue q);
bool AddQ(ElementType x,Queue q);
ElementType DeleteQ(Queue q);

int main(){
	Queue q=createQueue(100);
	AddQ(1,q);
	AddQ(2,q);
	AddQ(3,q);
	printf("%d",q->data[q->rear]); 
}

Queue createQueue(int MaxSize){
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
	q->front=q->rear=0;
	q->MaxSize=MaxSize;
	return q;
}

bool isFull(Queue q){
	return ((q->rear+1)%q->MaxSize==q->front);
}

bool isEmpty(Queue q){
	return (q->rear==q->front);
}

bool AddQ(ElementType x,Queue q){
	if(isFull(q)){
		printf("Full");
		return false;
	}else{
		q->rear=(q->rear+1)%q->MaxSize;
		q->data[q->rear]=x;
	}
}

ElementType DeleteQ(Queue q){
	if(isEmpty(q)){
		printf("empty");
		return -1;
	}else{
		q->front=(q->front+1)%q->MaxSize;
		return q->data[q->front];
	}
}










