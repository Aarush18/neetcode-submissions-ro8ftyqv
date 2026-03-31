class Solution {
private:
    void mergeSort(int left , int right , vector<int>& nums){
        if(left >= right){
            return;
        }

        int mid = left + (right - left)/2;

        mergeSort(left , mid , nums);
        mergeSort(mid + 1 ,right , nums);
        merge(left , mid , right , nums);

    }

    void merge(int left , int mid , int right , vector<int>& nums ){
        int n1 = mid - left + 1;
        int n2 = right - mid ;

        vector<int> l1(n1);
        vector<int> l2(n2);

        for(int i =0 ; i < n1; i++){
            l1[i] = nums[left + i];
        }

        for(int i = 0 ; i < n2 ; i++){
            l2[i] = nums[mid + 1 + i];
        }

        int i = 0 ; int j = 0 ;
        int k = left;

        while(i < n1 && j < n2){
            if(l1[i] <= l2[j]){
                nums[k] = l1[i];
                i++;
            }else{
                nums[k] = l2[j];
                j++;
            }

            k++;
        }

        while(i < n1){
            nums[k] = l1[i];
            i++;
            k++;
        }

        while(j < n2){
            nums[k] = l2[j];
            j++;
            k++;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0 , n - 1 , nums);
        return nums;
    }
};