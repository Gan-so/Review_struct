#include<stdio.h>
#include<stdlib.h>

#define MaxSize = 5

typedef int Elemtype;

typedef struct QNode{
	Elemtype data;
	struct QNode *next;//ָ��ṹ�����͵�ָ��
}QNode,*Queueptr;

typedef struct{
	Queueptr front,rear;
}LinkQueue;


void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,Elemtype x);
bool DeQueue(LinkQueue &Q,Elemtype &x);
void PrQueue(LinkQueue Q);

void main(){
	int x;
	LinkQueue Q;
	InitQueue(Q);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
	for(int i=0;i<7;i++)EnQueue(Q,i);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
	PrQueue(Q);
	DeQueue(Q,x);DeQueue(Q,x);DeQueue(Q,x);
	PrQueue(Q);
	for( i=0;i<7;i++)DeQueue(Q,x);
	printf("�����Ƿ�Ϊ�գ�%d\n",IsEmpty(Q));
	PrQueue(Q);
}

void PrQueue(LinkQueue Q){
	if(Q.rear==Q.front)return;
	QNode *s=Q.front->next;
	printf("����Ϊ��");
	while(s!=NULL){
	printf("%d,",s->data);
	s=s->next;
	}
	printf("\n");

}

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QNode *)malloc(sizeof(QNode));
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)return true;
	return false;
}

void EnQueue(LinkQueue &Q,Elemtype x){
	QNode *s;
	s=(QNode *)malloc(sizeof(QNode));
	s->data=x;s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	printf("����Ԫ��%d\n",x);
}

bool DeQueue(LinkQueue &Q,Elemtype &x){
	if(Q.front==Q.rear)return false;
	QNode *p=Q.front->next;
	x=p->data;
	Q.front->next=p->next;
	printf("ɾ��Ԫ��%d\n",x);
	if(Q.rear==p)
		Q.rear=Q.front;//�ж�������������
	free(p);
	return true;

}