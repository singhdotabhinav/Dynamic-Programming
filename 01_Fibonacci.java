https://www.youtube.com/watch?v=94dfRrDANRY&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&ab_channel=Pepcoding

import java.util.Scanner; 
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner scn = new Scanner(System.in);
	    int n = scn.nextInt();
	    int fibn=Fib(n,new int[n+1]);
	    System.out.println(fibn);
	}	
	public static int Fib(int n, int[] t){   
	    if(n==0||n==1)
	        return n;
	    if(t[n]!=0)
	        return t[n];
	    int fib1=Fib(n-1,t);
	    int fib2=Fib(n-2,t);
	    int fibn=fib1+fib2;
	    t[n]=fibn;
	    return t[n];
		// cute
	}	
}
