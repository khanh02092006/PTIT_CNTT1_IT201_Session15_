#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;        // mảng động chứa phần tử
    int front;
    int rear;
    int capacity;
} Queue;

// Tạo queue động
Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Thêm 1 phần tử vào queue
void add(Queue* q, int value) {
    if (q->rear >= q->capacity - 1) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Da them %d vao hang doi\n", value);
}

// Kiểm tra queue rỗng
int isEmpty(Queue* q) {
    return q->rear < q->front;
}

// Nhập nhiều phần tử vào queue
void inputMany(Queue* q) {
    int n;
    do {
        printf("Nhap so phan tu muon them: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("So phan tu khong hop le\n");
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        add(q, value);
    }
}

// In các phần tử trong hàng đợi
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity;
    printf("Nhap suc chua cua hang doi: ");
    scanf("%d", &capacity);

    Queue* q = createQueue(capacity);

    if (isEmpty(q)) {
        printf("Hang doi ban dau rong\n");
    }

    inputMany(q);

    if (isEmpty(q)) {
        printf("Sau khi them: Hang doi rong\n");
    } else {
        printf("Sau khi them: Hang doi KHONG rong\n");
    }

    printQueue(q);

    // Giải phóng bộ nhớ
    free(q->arr);
    free(q);

    return 0;
}
