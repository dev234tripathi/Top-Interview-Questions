/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//cpp Solution :

vector<string> generateParenthesis(int n) {
       if (!n) {
            return {""};
        }
        vector<string> parens;
        for (int i = 0; i < n; i++) {
            for (string l : generateParenthesis(i)) {
                for (string r : generateParenthesis(n - 1 - i)) {
                    parens.push_back('(' + l + ')' + r);
                }
            }
        }
        return parens;
    }
	


/**

java Solution :
 public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<String>();
        backtrack(list, "", 0, 0, n);
        return list;
    }
    
    public void backtrack(List<String> list, String str, int open, int close, int max){
        
        if(str.length() == max*2){
            list.add(str);
            return;
        }
        
        if(open < max)
            backtrack(list, str+"(", open+1, close, max);
        if(close < open)
            backtrack(list, str+")", open, close+1, max);
    }
	
	
The idea here is to only add '(' and ')' that we know will guarantee us a solution (instead of adding 1 too many close). 
Once we add a '(' we will then discard it and try a ')' 
which can only close a valid '('. Each of these steps are recursively called.
*/