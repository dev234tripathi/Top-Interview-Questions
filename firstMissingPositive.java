/**
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

//java Solution :
//The idea is simple: put the positive integer n (n > 0 and n <= array.length) at index n - 1. 
//Then traverse the array, if nums[index] != index + 1, then we find the first miss positive number.

public int firstMissingPositive(int[] nums) {
	for(int i = 0; i < nums.length; i++) {
		while( nums[i] > 0 && nums[i] <= nums.length ) {
			int temp = nums[nums[i] - 1];
			if( temp == nums[i] ) // If nums[nums[i] - 1] equals nums[i], then we don't need to exchange them
				break;
			nums[nums[i] - 1] = nums[i];
			nums[i] = temp;
		}
	}
	for(int i = 0; i < nums.length; i++) 
		if( nums[i] != i + 1 )
			return i + 1;
	return nums.length + 1;
}


//cpp Solution :
/**
int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]<=nums.size())
            {
                int pos=nums[i]-1;
                if(nums[pos]!=nums[i])
                {
                    swap(nums[i],nums[pos]);
                    i--;
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
	
	*/