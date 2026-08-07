class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<int> v;
        for(auto i:count) {
            if(i.second>1) {
                v.push_back(i.first);
            }
        }
        return v;
    }
};