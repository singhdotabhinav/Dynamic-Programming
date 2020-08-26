//Leet code problem to min number of deletion made to make string one and string 1 as same


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
        return t[m][n];
    }
    int minDistance(string X, string Y) {
        
        int M=X.size();
        int N=Y.size();
        int sub_len=LCS( X, Y, M, N );
        //return (M - sub_len) + (N - sub_len)
        return (M+N-2*sub_len);
        
        
        
    }
};
