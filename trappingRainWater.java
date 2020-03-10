/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

//cpp Solution :

/** 
  int trap(vector<int>& height) {
      int l=0,r=height.size()-1,water=0,level=0;
        while(l<r)
        {
            int lower = height[height[l]<height[r]?l++:r--];
            level = max(lower,level);
            water += (level-lower);
        }
        return water;
    }
	*/

//java Solution : 

class Solution {
    public int trap(int[] height) {
        if (height == null || height.length < 2) return 0;
        
        Stack<Integer> stack = new Stack<>();
        int water = 0, i = 0;
        while (i < height.length) {
            if (stack.isEmpty() || height[i] <= height[stack.peek()]) {
                stack.push(i++);
            } else {
                int pre = stack.pop();
                if (!stack.isEmpty()) {
                    // find the smaller height between the two sides
                    int minHeight = Math.min(height[stack.peek()], height[i]);
                    // calculate the area
                    water += (minHeight - height[pre]) * (i - stack.peek() - 1);
                }
            }
        }
        return water;
    }
}