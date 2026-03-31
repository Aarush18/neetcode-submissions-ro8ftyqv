class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin() , arr.end());
    }
    
    double findMedian() {
    int n = arr.size();
        if (n % 2 == 1) {
            return arr[n / 2];
        } else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
