
https://www.youtube.com/watch?v=uNqoQ0sNZCM&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=3&frags=wn&ab_channel=Pepcoding

import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n= scn.nextInt();
		int[] arr = new int[n];
		
		for(int i=0;i<n;i++){
		    arr[i]=scn.nextInt();
		}
		
		int[] t= new int[n+1];
		t[n]=1;
		for(int i=n-1;i>=0;i--){
		    for(int j=1;j<=arr[i] && i+j<t.length;j++){
		        t[i]+=t[i+j];
		    }
		}
		
		System.out.println(t[0]);
	}
}
