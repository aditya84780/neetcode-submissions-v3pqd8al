class Solution {
public:
    vector<int> heightDom;
    bool isISmaller(int i, int j) {
        if (heightDom[i] < heightDom[j]) {
            return true;
        }
        if (heightDom[i] > heightDom[j]) {
            return false;
        }
        return isISmaller(i+1, j-1);
    }
    int maxArea(vector<int>& heights) {
        int maxWater = 0, n = heights.size();
        for (auto v: heights) {
            heightDom.push_back(v);
        }
        int i = 0, j = n-1;
        while(i<j) {
            maxWater = max(maxWater, ((j-i)*min(heights[i], heights[j])));
            if (isISmaller(i,j)) {
                i++;
            } else {
                j--;
            }
        }
        return maxWater;
    }
};
