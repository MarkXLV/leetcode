class MyCircularQueue {
private:
    vector<int> queue;
    int size;
    int front;
    int rear;
    int capacity;

public:
    MyCircularQueue(int k) {
        queue = vector<int>(k);
        size = 0;
        front = 0;
        rear = -1;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[front];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};