
https://www.youtube.com/watch?v=A6mOASLl2Dg&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=2&ab_channel=Pepcoding





import java.util.Scanner; 
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner scn = new Scanner(System.in);
	    int n = scn.nextInt();
	    int cp=countPairs(n, new int[n+1]);
	    System.out.println(cp);
	}
	
	public static int countPairs(int n, int[] t){
	    
	    if(n==0||n==1){
	        return 1;
	    }else if(n<0){
	       return 0; 
	    }
	    if(t[n]!=0){
	        return t[n];
	    }
	    int nm1=countPairs(n-1,t);
	    int nm2=countPairs(n-2,t);
	    int nm3=countPairs(n-3,t);
	    int cp=nm1+nm2+nm3;
	    t[n]=cp;
	    return t[n];
	    
	}
}
