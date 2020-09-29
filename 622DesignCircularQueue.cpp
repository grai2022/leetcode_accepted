/*
https://leetcode.com/problems/design-circular-queue/
*/

class MyCircularQueue {
private:
    vector<int> data;
    int p_start,p_end, size ;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
        p_start = -1, p_end = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty()){
            p_start = 0, p_end =0;
        }else{
            p_end = (p_end+1)%size ;
        }
        data[p_end] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        if(p_start == p_end && p_end != -1){
            p_start = -1, p_end =-1;
            return true;
        }
        p_start = (p_start+1)%size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return data[p_start];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return data[p_end];
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return p_start == -1 && p_end == -1 ;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        cout<< size;
        return size -1 == abs(p_start - p_end) || p_end - p_start == -1;
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
