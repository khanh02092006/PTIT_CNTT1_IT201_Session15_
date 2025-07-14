#include <stdio.h>
#define MAX 100

typedef  struct
{
    int data;
    int front; // chi số phần tử đầu mảng
    int rear;// chỉ số phần t cuối mảng
    int capacity;// ố phần tử tối đa
}queue;
// tạo hàng đợi
void initQueue(queue* q)
{
    q->front = 0;
    q->rear = 0;
    q->capacity = MAX;

}

int main(void)
{
    queue q;
    initQueue(&q);
    printf(" hàng đợi khởi tạo");
    printf("front=%d\n", q.front);
    printf("rear=%d\n", q.rear);
    printf("capacity=%d\n", q.capacity);
    return 0;
}