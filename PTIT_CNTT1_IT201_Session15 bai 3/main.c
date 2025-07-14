#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int capacity;
} queue;

// Khoi tao hang doi
void initQueue(queue* q) {
    q->front = 0;
    q->rear = -1;
    q->capacity = MAX;
}

// Them phan tu vao hang doi
void add(queue* q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Hang doi da day!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("Da them %d vao hang doi.\n", value);
}

// Kiem tra hang doi rong
int isEmpty(queue* q) {
    return q->rear < q->front;
}

// Nhap nhieu phan tu vao hang doi
void inputMany(queue* q) {
    int n;
    do {
        printf("Nhap so phan tu muon them vao hang doi: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Khong hop le! Nhap lai.\n");
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        add(q, value);
    }
}

// In cac phan tu trong hang doi
void printQueue(queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(void) {
    queue q;
    initQueue(&q);

    printf("Ban dau: ");
    if (isEmpty(&q)) {
        printf("Hang doi rong.\n");
    } else {
        printf("Hang doi co phan tu.\n");
    }

    inputMany(&q);

    if (isEmpty(&q)) {
        printf("Sau khi them: Hang doi rong.\n");
    } else {
        printf("Sau khi them: Hang doi co phan tu.\n");
    }

    printQueue(&q);

    return 0;
}
