#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int data[MAX], priority[MAX];
int size =0;

void enqueue(int val, int prio) {
    if (size >= MAX) {
        printf("Queue Overflow\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && priority[i] < prio) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }
    data[i + 1] = val;  
    priority[i + 1] = prio;
    size++;
}

void dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }
    for (int j= 0; j < size - 1; j++) {
        data[j] = data[j + 1];
        priority[j] = priority[j + 1];
    }
    size--;
}

void peek(){
    if(size == 0){
        printf("Queue is empty\n");
        return;
    }
    printf("value: %d, priority: %d\n", data[0], priority[0]);
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", data[i], priority[i]);
    }
}
int main() {
    int choice, value, prio;
    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &prio);
                enqueue(value, prio);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}
