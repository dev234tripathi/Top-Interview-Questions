/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

//java Solution : 
/**

dp(i, j) represents whether s(i ... j) can form a palindromic substring, 
dp(i, j) is true when s(i) equals to s(j) and s(i+1 ... j-1) is a palindromic substring. 
When we found a palindrome, check if it's the longest one. Time complexity O(n^2).
DP Solution:

public String longestPalindrome(String s) {
  int n = s.length();
  String res = null;
    
  boolean[][] dp = new boolean[n][n];
    
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);
            
      if (dp[i][j] && (res == null || j - i + 1 > res.length())) {
        res = s.substring(i, j + 1);
      }
    }
  }
    
  return res;
}
*/

//cpp Solution : Not DP 
 string longestPalindrome(string s) {
     int sLen = s.length(), maxLen = 0, maxStart = 0;
        int i = 0, l = 0, r = 0, len = 0;
        while(i<=sLen-maxLen/2)
        {
            l = r = i;
            while(r<sLen-1 && s[r+1]==s[r]){ r++;}
            i = r+1;
            while(l>0 && r<sLen-1 && s[r+1]==s[l-1]){ l--, r++;}
            len = r-l+1;
            if(maxLen < len) maxLen = len, maxStart = l;
        }
        return s.substr(maxStart, maxLen);    }
    
};