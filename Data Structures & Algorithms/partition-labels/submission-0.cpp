class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char , int> mpp;

        for(int i = 0 ; i < s.size(); i++){
            mpp[s[i]] = i;
        }

        vector<int> output;
        int start = 0 ; 
        int end = 0 ;

        for(int i = 0 ; i < s.size(); i++){
            end = max(end , mpp[s[i]]);

            if(i == end){
                output.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return output;
    }
};
