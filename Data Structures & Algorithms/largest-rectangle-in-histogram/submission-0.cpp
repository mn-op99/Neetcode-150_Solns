class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i=0; i<heights.size(); ++i){
            int hI = heights[i];
            int j=i;
            while(j>=0 && heights[j]>=heights[i]){
                j--;
            }
            j++;
            int k=i;
            while(k<heights.size() && heights[k]>=heights[i]){
                k++;
            }
            k--;
            maxArea = max(maxArea, (k-j+1)*heights[i]);
        }
        return maxArea;
    }
};