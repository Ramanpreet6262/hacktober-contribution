/*
Given is an array of size n.We have to find the subarray having the largest sum
*/
import java.util.*;
class Main
{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int arr[]=new int[n],i=0;
		for(i=0;i<n;i++)
			arr[i]=scan.nextInt();
        int sum=arr[0],max=arr[0]; // initially first element is the largest sum
		for(i=1;i<n;i++)
		{
           if(arr[i]+sum>arr[i]) // if adding the previous sum to me(ith element) increases my value then i will consider joining the subarray
           {
           	sum=sum+arr[i];
           	max=max>sum ? max : sum;
           }
           else    // if adding the previous sum to me decreases my value then start a new sub array from me            
           {
           	sum=arr[i];
           	max=max>sum ? max : sum;  
           }
		}
		System.out.print(max);
	}
}