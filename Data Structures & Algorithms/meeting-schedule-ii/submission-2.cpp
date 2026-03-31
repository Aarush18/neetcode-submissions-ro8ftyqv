/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start(n , 0);
        vector<int> end(n , 0);

        for(int i = 0 ; i < intervals.size(); i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        map<int , int> events;

        for(int i = 0 ; i < n ; i++){
            events[start[i]]++;
            events[end[i]]--;
        }

        int overlaps = 0 ;
        int maxOverlaps = 0;

        for(auto& it : events){
            overlaps += it.second;
            if(overlaps > maxOverlaps){
                maxOverlaps = overlaps;
            }
        }

        return maxOverlaps;
    }
};
