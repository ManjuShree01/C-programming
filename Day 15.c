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
