class MyCircularQueue {
public:
    int K;
    deque<int>dq;
    MyCircularQueue(int k):K(k) {
        
    }
    
    bool enQueue(int value) {
        if(dq.size()<K)
        {
            dq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(dq.empty())return false;
        dq.pop_front();
        return true;
    }
    
    int Front() {
        if(dq.empty())return -1;
        return dq.front();
    }
    
    int Rear() {
        if(dq.empty())return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size()==K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */