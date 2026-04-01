/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int findPeek(MountainArray & mountainArr , int target){
        int l = 0 ;
        int r = mountainArr.length() - 1;

        while(l < r){
            int mid = l + (r - l)/2;

            if(mountainArr.get(mid + 1) > mountainArr.get(mid)){
                l = mid + 1;
            }else{
                r = mid ;
             }
         }
        return l ;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        auto peekEl = findPeek(mountainArr , target);

        int l = 0 ;
        int r = peekEl;

        int minInd = 1e9;
        
        while(l <= r){
            auto mid = l + (r - l)/2;

            if(mountainArr.get(mid) == target){
                minInd = min(minInd , mid);
                break;
            }else if(mountainArr.get(mid) > target){
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        l = peekEl;
        r = mountainArr.length() - 1;

        while(l <= r){
            auto mid = l + (r - l)/2;

            if(mountainArr.get(mid) == target){
                minInd = min(minInd , mid);
                break;
            }
            else if(mountainArr.get(mid) > target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return minInd == 1e9 ? -1 : minInd;

    }
};