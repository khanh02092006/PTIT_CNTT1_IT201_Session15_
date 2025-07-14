#include <stdio.h>
#define MAX 100
typedef  struct
{
    int data[MAX];
    int front;
    int rear;
    int capacity;
}queue;
 void initialize(queue *q)
 {
     q->front = 0;
     q->rear = -1;
     q->capacity = MAX;
 }
void add(queue *q, int value)
 {
     if (q->rear>=q->capacity)
     {
         printf(" ầng doi day , khong them vao dc");
         return;
     }
     q->rear++;
     q->data[q->rear] = value;
     printf(" da them %d vao hang doi :", value);
 }

int main(void)
{
    queue q;
     initialize(&q);
     printf(" nhap 5 phan tu vao hang doi\n");
     for (int i = 0; i < 5; i++)
     {
         int mun;
         do
         {
             printf(" nhap phan tu thu %d",i+1);
             scanf("%d", &mun);
             if (mun<=0 )
             {
                 printf(" khong hop le");

             }
         } while (mun<=0);
         add(&q, mun);
     }
    return 0;
}