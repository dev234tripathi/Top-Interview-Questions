/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/



//java Solution: 
/**
* Find the median by traversing.
*
* Time complexity: O(m+n). Although the running time is similar, it is worse than the required O(log (m+n)).
* Space complexity: O(1).
*
* @param nums1 the first sorted arrays
* @param nums2 the second sorted arrays
* @return the median of the two sorted arrays
*/
/*
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int index1 = 0;
    int index2 = 0;
    int med1 = 0;
    int med2 = 0;
    for (int i=0; i<=(nums1.length+nums2.length)/2; i++) {
        med1 = med2;
        if (index1 == nums1.length) {
            med2 = nums2[index2];
            index2++;
        } else if (index2 == nums2.length) {
            med2 = nums1[index1];
            index1++;
        } else if (nums1[index1] < nums2[index2] ) {
            med2 = nums1[index1];
            index1++;
        }  else {
            med2 = nums2[index2];
            index2++;
        }
    }

    // the median is the average of two numbers
    if ((nums1.length+nums2.length)%2 == 0) {
        return (float)(med1+med2)/2;
    }

    return med2;
}*/


//cpp Solution:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (nums1.size()+nums2.size())/2;
        int i =0,j=0;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        if(nums1.size()+nums2.size()&1)
        {
            while(i+j!=n)
            {
                if(nums1[i]>nums2[j])
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
            return nums1[i]>nums2[j]?nums2[j]:nums1[i];
        }
        while((i+j)!=n-1)
        {
            if(nums1[i]>nums2[j])
                j++;
            else
                i++;
        }
        return ((nums1[i]>nums2[j]?nums2[j++]:nums1[i++])+(nums1[i]>nums2[j]?nums2[j]:nums1[i]))/2.0;
    }