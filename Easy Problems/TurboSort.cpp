#include <iostream>
using namespace std;
void Merge(int a[],int start,int middle,int end)
{
   //subarray 1 a1[start,mid]
   //subarray 2 a2[mid+1,end]
   //merge it back;
   int sizeSA1=middle-start+1;
   int sizeSA2=end-middle;
   
   auto *leftArray=new int[sizeSA1];
   auto *rightArray=new int[sizeSA2];
   
   //copying the left array and right array
   for(int i=0;i<sizeSA1;i++)
   {
        leftArray[i]=a[start+i];
   }
   for(int j=0;j<sizeSA2;j++)
   {
        rightArray[j]=a[middle+j+1];
   }
   //Merging into a new array(i<middle+1;j<=end;i++;j++;)
   int k=start;
  
   int i=0;
   int j=0;
   while(i<sizeSA1&&j<sizeSA2)
   {
        if(leftArray[i]<=rightArray[j])
        {
             a[k]=leftArray[i];
             i++;
        }
       else
       {
            a[k]=rightArray[j];
            j++;
       }
       k++;
   }
   
       while(i<sizeSA1)
       {
            a[k]=leftArray[i];
            k++;
            i++;
       }
   
       while(j<sizeSA2)
       {
            a[k]=rightArray[j];
            k++;
            j++;
       }
   
}

void MergeSort(int a[],int start,int end)
{
     if(end>start)
     {
          int middle=start+(end-start)/2;
          MergeSort(a,start,middle);
          MergeSort(a,middle+1,end);
          Merge(a,start,middle,end);
     }
}

int main() {
	// your code goes
	int n ;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	     cin>>a[i];
	}
	MergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
	     cout<<a[i]<<endl;
	}
	
	return 0;
}
