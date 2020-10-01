/*Given are two arrays having ranges in the form of array1[i] to array2[i]. We have to find the max occurance of an element
 in these ranges.
 Test Case-
 3
 2 1 3
 5 3 9
 thus ranges are 2-5,1-3,3-9(inclusive of both end elements)
 Output-3
*/
import java.util.*;
public class Main
{
   public static void main(String arg[])
   {
   	Scanner scan=new Scanner(System.in);
   	int s=scan.nextInt();  //size of left and right array
    int arr1[]=new int[s];
    int arr2[]=new int[s];
    for(int l=0;l<s;l++)
    	arr1[l]=scan.nextInt();
    for(int l=0;l<s;l++)
    	arr2[l]=scan.nextInt();
    int range=max(arr2,1);        // get max element from 2nd array
    int arr3[]=new int[range+2]; //very imp step..one extra space is taken here
   
    int i=0;
    for(i=0;i<s;i++)
    {
    	arr3[arr1[i]]++;    //index where left array starts is turned 1 and the index where r array finish + 1 is turned -1
    	arr3[arr2[i]+1]--;
    }
    
    int prev=0;
    for(i=0;i<range+2;i++)
    {
    	arr3[i]=arr3[i]+prev; //every element is added to the element on its previous index. 
    	prev=arr3[i];
    }
   
    System.out.println(max(arr3,0)); //max occurance of element is returned
   }
   
   public static int max(int arr[],int key)
   {
   	int max=-1;
   	int i=0,index=0;
   	for(int x:arr)
   	{
      if(x>max)
      {
          max=x;
          index=i;
      }
      i++;
   	}
   	if(key==1)
   	 return max;
   	else
   	 return index ;
   }
}