/*
https://leetcode.com/problems/moving-average-from-data-stream/
*/

class MovingAverage {
private :
    int size ;
    queue<int> q;
    double avg = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int sizei) {
        size = sizei;
    }
    
    double next(int val) {
        if(q.size() == size){
                avg = (avg*size - q.front() + val)/size;
                q.pop();
                q.push(val);
            } 
            else{
                q.push(val);
                avg = (avg*(q.size() -1) + val)/q.size();
            }
            return avg ;
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
