/**
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/
 int reverse(int x) {
       long result = 0;
    while(x != 0)
    {
        result = result*10 + x % 10;
        x = x/10;
         if(result> INT_MAX)
                return 0;
            if(result<INT_MIN)
                return 0;
    }
        return result;
    }