#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} queue;

// Tạo hàng đợi
queue *createqueue(int capacity) {
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q) {
        printf("Khong the cap phat bo nho cho queue\n");
        return NULL;
    }

    q->arr = (int *)malloc(sizeof(int) * capacity);
    if (!q->arr) {
        printf("Khong the cap phat mang cho queue\n");
        free(q);
        return NULL;
    }

    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}

int isempty(queue *q) {
    return q->rear < q->front;
}

void enqueue(queue *q, int item) {
    if (q->rear == q->capacity - 1) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = item;
}


int dequeue(queue *q) {
    if (isempty(q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    return value;
}

void printQueue(queue *q) {
    if (isempty(q)) {
        printf("Hang doi rong\n");
        return;
    }

    printf("Cac phan tu trong hang doi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


void inputMany(queue *q) {
    int n;
    do {
        printf("Nhap so phan tu muon them: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("So luong khong hop le\n");
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(q, value);
    }
}

int main() {
    int capacity;
    printf("Nhap suc chua cua hang doi: ");
    scanf("%d", &capacity);

    if (capacity <= 0) {
        printf("Suc chua khong hop le\n");
        return 1;
    }

    queue *q = createqueue(capacity);
    if (!q) return 1;

    if (isempty(q)) {
        printf("Hang doi ban dau rong\n");
    }

    inputMany(q);

    printQueue(q);

    int removed = dequeue(q);
    if (removed != -1) {
        printf("Phan tu duoc lay ra: %d\n", removed);
    }

    printQueue(q);

    free(q->arr);
    free(q);

    return 0;
}
