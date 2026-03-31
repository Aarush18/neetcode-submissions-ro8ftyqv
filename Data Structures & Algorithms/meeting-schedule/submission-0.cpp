class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        if(intervals.size() <= 1) return true;

        sort(intervals.begin(), intervals.end(), 
            [](Interval &a, Interval &b){
                return a.start < b.start;
            });

        int end = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < end){
                return false;
            } else {
                end = intervals[i].end;
            }
        }

        return true;
    }
};
