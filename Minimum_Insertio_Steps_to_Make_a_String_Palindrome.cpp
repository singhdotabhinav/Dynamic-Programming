class Solution {
public:
    
    int LCS( string X, string Y, int m, int n ){

        int t[m+1][n+1];
        for(int i=0 ; i<=m ; i++ ){
            for(int j=0 ; j<=n ; j++){
                if(i==0 || j==0)
                    t[i][j]=0;
                else if (X[i - 1] == Y[j - 1])
                    t[i][j] = t[i - 1][j - 1] + 1;
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        return m - t[m][n];
    }
    
    
    int minInsertions(string s1) {
        
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        
        return LCS(s1,s2,s1.length(), s2.length());        
        
    }
};
