class MovingAverage {
public:
    /** Initialize your data structure here. */
    int max_size;
    list<int> num_list;
    int sum;
    MovingAverage(int size) {
        max_size = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        num_list.push_back(val);
        if (num_list.size() > max_size) {
            sum -= num_list.front();
            num_list.pop_front();
        }
        return (float)sum / num_list.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */