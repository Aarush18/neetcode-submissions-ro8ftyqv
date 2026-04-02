class MyCircularQueue {
public:
    int cap;
    int l ;
    int r ;
    int currSize;

    vector<int> arr;
    MyCircularQueue(int k) {
        l = 0 ;
        r = -1 ;
        cap = k;
        currSize = 0 ;
        arr = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(currSize == cap){
            return false;
        }

        r = (r + 1) % cap;

        arr[r] = value;
        currSize++;

        return true;

    }
    
    bool deQueue() {
        if(currSize == 0){
            return false;
        }

        l = (l + 1) % cap;
        currSize--;

        return true;
    }
    
    int Front() {
        if(currSize == 0){
            return -1;
        }
        return arr[l];
    }
    
    int Rear() {
        if(currSize == 0){
            return -1;
        }

        return arr[r];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == cap;
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