/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

//cpp Solution : Sorting makes it easier


    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0)
            return "";
        string result = "";
        sort(begin(strs),end(strs));
        string start = strs[0];
        string end = strs[n-1];
        for(int i=0;i<start.length();i++)
        {
            if(start[i]==end[i])
            {
                result = result+start[i];
            }
            else
            {
                break;
            }
        }
        return result;
    }


//java Solution :

/**
public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String pre = strs[0];
    for (int i = 1; i < strs.length; i++)
        while(strs[i].indexOf(pre) != 0)
            pre = pre.substring(0,pre.length()-1);
    return pre;
}
*/
