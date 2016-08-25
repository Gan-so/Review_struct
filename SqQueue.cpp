#include<stdio.h>

#define MaxSize 5

typedef int Elemtype;

typedef struct{
	Elemtype data[MaxSize];
	int front,rear;
}SqQueue;

//��������
void InitQueue(SqQueue &Q);//��ʼ��
bool IsEmpty(SqQueue Q);//�п�
bool EnQueue(SqQueue &Q,Elemtype x);//���
bool DeQueue(SqQueue &Q,Elemtype &x);//����
void PrQueue(SqQueue Q);


void main(){
	int x;
	SqQueue Q;
	InitQueue(Q);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
	for(int i=0;i<7;i++)EnQueue(Q,i);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
	PrQueue(Q);
	DeQueue(Q,x);
	PrQueue(Q);
	for( i=0;i<7;i++)DeQueue(Q,x);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
}

void PrQueue(SqQueue Q){
	if(IsEmpty(Q))return;
	printf("����Ϊ:",Q.front,Q.rear);

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
	if((Q.rear+1)%MaxSize==Q.front)return false;//����
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	printf("����Ԫ��%d\n",x);
	return true;
}

bool DeQueue(SqQueue &Q,Elemtype &x){
	if(Q.rear==Q.front)return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	printf("ɾ����ͷԪ��%d\n",x);
	return true;
}