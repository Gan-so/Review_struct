#include<stdio.h>

#define MaxSize 5

typedef int Elemtype;

typedef struct{
	Elemtype data[MaxSize];
	int front,rear;
}SqQueue;

//函数声明
void InitQueue(SqQueue &Q);//初始化
bool IsEmpty(SqQueue Q);//判空
bool EnQueue(SqQueue &Q,Elemtype x);//入队
bool DeQueue(SqQueue &Q,Elemtype &x);//出队
void PrQueue(SqQueue Q);


void main(){
	int x;
	SqQueue Q;
	InitQueue(Q);
	printf("队列是否为空：%d\n",IsEmpty(Q));
	for(int i=0;i<7;i++)EnQueue(Q,i);
	printf("队列是否为空：%d\n",IsEmpty(Q));
	PrQueue(Q);
	DeQueue(Q,x);
	PrQueue(Q);
	for( i=0;i<7;i++)DeQueue(Q,x);
	printf("队列是否为空：%d\n",IsEmpty(Q));
}

void PrQueue(SqQueue Q){
	if(IsEmpty(Q))return;
	printf("队列为:",Q.front,Q.rear);

	int i=Q.front;
	
	while(Q.rear!=(i++)%MaxSize){
	printf("%d",Q.data[i-1]);
	}
	printf("\n");
}

void InitQueue(SqQueue &Q){
	Q.rear=Q.front=0;
}

bool IsEmpty(SqQueue Q){
	if(Q.rear==Q.front)return true;
	return false;
}

bool EnQueue(SqQueue &Q,Elemtype x){
	if((Q.rear+1)%MaxSize==Q.front)return false;//队满
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	printf("加入元素%d\n",x);
	return true;
}

bool DeQueue(SqQueue &Q,Elemtype &x){
	if(Q.rear==Q.front)return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	printf("删除队头元素%d\n",x);
	return true;
}