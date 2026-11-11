class Solution {
    string exp(int l, int r, string s){
        int i = l;
        int j = r;

        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();++i){
            string e = exp(i,i+1,s);
            if(e.size() > ans.size())
                ans = e;

            string o = exp(i,i,s);
            if(o.size() > ans.size())
                ans = o;
        }
        return ans;
    }
};