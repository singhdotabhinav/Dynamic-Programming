

import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		
		Scanner scn = new Scanner(System.in);
		
		int n =scn.nextInt();
		
		int[] arr= new int[n];
		
		for(int i=0;i<arr.length;i++){
		    arr[i]=scn.nextInt();
		}
		
		Integer[] t= new Integer[n+1];
		
		t[n]=0;
		
		for(int i=n-1;i>=0;i--){
		    if(arr[i]>0){
		        int min=Integer.MAX_VALUE;
		        for(int j=1 ; j<=arr[i]  && i+j<t.length ; j++){
		            
		            if(t[i+j]!=null){
		                
		                min=Math.min(min,t[i+j]);
		            }
		        }
		        if(min!=Integer.MAX_VALUE){
		            t[i]=min+1;
		        }
		    }
		}
		System.out.println(t[0]);
		
	}
}
