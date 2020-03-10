/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

/**
java Solution :
 public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
	
	Time complexity : O(n)O(n). Single pass.

Space complexity : O(1)O(1). Constant space is used.

*/

//cpp Solution:

int maxArea(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int mx=0;
        int check=1,h;
        while(i<j)
        {
            int distance =(j-i);
            if(height[i]<height[j])
            {
                h = height[i];
            }
            else
            {
                h= height[j];
            }
            check = h*distance;
            mx = max(mx,check);
           while (height[i] <= h && i < j) i++;
            
           while (height[j] <= h && i < j) j--;
        }
        return mx;
    }