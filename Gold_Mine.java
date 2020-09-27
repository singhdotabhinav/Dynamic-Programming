//https://www.youtube.com/watch?v=hs0lilfJ7C0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=9&ab_channel=Pepcoding

class Solution {
    
    
    public int getMaximumGold(int[][] grid) {
        
        
        int[][] dp = new int[grid.length][grid[0].length];
        
        
        
        for( int j = grid[0].length-1 ; j>=0 ; j--){
            
            for( int i = grid.length-1 ; i>=0 ; i--){
                
                if( j==grid[0].length - 1){
                    
                    dp[i][j] = grid[i][j] ;
                    
                }else if(i == 0){
                    
                    dp[i][j] = grid[i][j] + Math.max( dp[i][j+1] , dp[i+1][j+1] );
                    
                }else if( i==grid.length-1){
                    
                    dp[i][j] = grid[i][j] + Math.max( dp[i][j+1] , dp[i-1][j+1] );
                    
                }else{
                    dp[i][j] = grid[i][j] + Math.max (dp[i][j + 1], Math.max(dp[i + 1][j + 1], dp[i - 1][j + 1]) );
                }
            }
        }
        
        int max = dp[0][0];
        for(int i=1 ; i<dp.length ; i++){
            if(dp[i][0]>max){
                max=dp[i][0];
            }
        }
        
        return max;
        
        
        
    }
}
