class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        bool flag=false;
        stack<pair<int, int>> st1, st2;
        int leftIdx=-1;
        for(int i=0; i<heights.size(); ++i){
            if(st1.empty()){
                st1.push({heights[i], i});
                maxArea = max(maxArea, heights[i]);
            }
            else{
                if(heights[i]<st1.top().first){
                    while(!st1.empty() && heights[i]<st1.top().first){
                        maxArea = max(maxArea, (i-st1.top().second + 1)*heights[i]);
                        leftIdx = st1.top().second;
                        st1.pop();
                    }
                    st1.push({heights[i], leftIdx});
                }
                else{
                    if(i<heights.size()-1){
                        if(heights[i+1]<heights[i]){
                            while(!st1.empty()){
                                maxArea = max(maxArea, (i-st1.top().second + 1)*st1.top().first);
                                st2.push(st1.top());
                                st1.pop();
                            }
                            while(!st2.empty()){
                                st1.push(st2.top());
                                st2.pop();
                            }
                        }
                        maxArea = max(maxArea, heights[i]);
                        st1.push({heights[i], i});
                    }
                    else{
                        maxArea = max(maxArea, heights[i]);
                        while(!st1.empty()){
                            maxArea = max(maxArea, (i-st1.top().second + 1)*st1.top().first);
                            st1.pop();
                        }
                    }
                }
            }
        }
        int lastIdx = heights.size()-1;
        while(!st1.empty()){
            maxArea = max(maxArea, (lastIdx - st1.top().second + 1)*st1.top().first);
            st1.pop();
        }
        return maxArea;
    }
};