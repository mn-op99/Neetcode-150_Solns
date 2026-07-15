class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> deleted;
        priority_queue<int> pq;
        
        for(int i=0; i<k; ++i){
            pq.push(nums[i]);
        }

        vector<int> res;
        res.push_back(pq.top());
        for(int i=k; i<nums.size(); ++i){
            deleted[nums[i-k]]++;
            pq.push(nums[i]);

            while(deleted.find(pq.top())!=deleted.end()){
                deleted[pq.top()]--;
                pq.pop();
                if(deleted[pq.top()]==0)
                    deleted.erase(pq.top());
            }
            res.push_back(pq.top());
        }
        return res;
    }
};
