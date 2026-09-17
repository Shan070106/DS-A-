class Solution {

public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<int> preR(n2+1), curR(n2+1);
        
        for(int i=1;i<=n1;i++){
            
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    curR[j] = 1+preR[j-1];
                }
                else{
                    curR[j] = max(curR[j-1], preR[j]);
                }
            }
            preR = curR;
        }

        return (n1+n2)-2*preR[n2]; 
    }
};