class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());

        string a = strs[0];

        if(strs.size() == 1){
            return a;
        }

        string b = strs[strs.size() - 1];

        int i = 0 ;
        int j = 0 ;

        string op = "";

        while(i < a.size() || j < b.size()){
            if(a[i] == b[j]){
                op+=a[i];
            }else if(a[i] != b[j]){
                break;
            }
            i++;
            j++;
        }

        return op;
    }
};