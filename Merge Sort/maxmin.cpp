#include <iostream>
using namespace std;

int max2, min2;
int a[100];
void maxmin(int i, int j)
{
 int max1, min1, mid;
 if(i==j)
 {
  max2 = min2 = a[i];
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    max2 = a[j];
    min2 = a[i];
   }
   else
   {
    max2 = a[i];
    min2 = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   maxmin(i, mid);
   max1 = max2; min1 = min2;
   maxmin(mid+1, j);
   if(max2 <max1)
    max2 = max1;
   if(min2 > min1)
    min2 = min1;
  }
 }
}
int main ()
{
 int i, num;
 cout<<"Enter the number of elements in array: ";
 cin>>num;
 cout<<"Enter the numbers :"<<endl;;
 for (i=1;i<=num;i++)
  cin>>a[i];

cout<<"\nAccepted array is: "<<endl;
    for(int i=1; i<=num; i++)
    {
        cout<<a[i]<<" ";
    }

 max2 = a[0];
 min2 = a[0];
 maxmin(1, num);
 cout<<"\n\nMinimum element in an array : "<<min2<<endl;
 cout<<"Maximum element in an array : "<<max2<<endl;
 return 0;
}