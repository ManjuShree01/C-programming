//Linear search
#include <stdio.h>
int search(int a[],int key,int size)
{
  for(int i=0;i<size;i++)
 {
    if(key==a[i])
      return i;
 }
 return -1;
}
int main()
{
  int key,size;
  printf("Enter number of products: ");
  scanf("%d",&size);
  int a[size];
  printf("Enter product prices: ");
  for(int i=0;i<size;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter price to be searched: ");
  scanf("%d",&key);
  int val=search(a,key,size);
  if(val==-1)printf("Price not available");
  else printf("Price available");
  return 0;
}

//Binary search
#include <stdio.h>
int binary(int a[],int n,int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
}
int main() {
    int a[]={1,2,3,4,5,6};
    int n=6,key=4;
    int res=binary(a,n,key);
    if(res!=-1)
    {
        printf("Element is found at index %d",res);
    }
    else
        printf("Element is not found");
    return 0;
}
