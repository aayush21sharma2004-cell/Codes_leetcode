class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

       unordered_map<int,int> count;
       
       for(int i=0; i<arr.size(); i++) {
        count[arr[i]]++;
       } 
       
       unordered_set<int> uniqueFreq;
       for(auto i:count) {
        uniqueFreq.insert(i.second);   
       }
       if(count.size() == uniqueFreq.size()) {
        return true;
       }
    return false;
    }

};