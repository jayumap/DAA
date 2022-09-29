#include<iostream>
using namespace std;

int main()
{int a[2][2],b[2][2],c[2][2];
 int p,q,r,s,t,u,v,i,j;
 
 cout<<"Matrix Multiplication Strassen's methodt\n";
 cout<<"Enter the elements of 2x2 Matrix 1:\n";
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   cin>>a[i][j];
  }
 }
 cout<<"Enter the elements of 2x2 Matrix 2:\n";
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   cin>>b[i][j];
  }
 }
 
 cout<<"\nFirst matrix is:\n";
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   cout<<a[i][j]<<" ";
  }
  cout<<"\n";
 }
 cout<<"\nSecond matrix is\n";
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   cout<<b[i][j]<<" ";
  }
  cout<<"\n";
 }
 p= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
 q= (a[1][0]+a[1][1])*b[0][0];
 r= a[0][0]*(b[0][1]-b[1][1]);
 s= a[1][1]*(b[1][0]-b[0][0]);
 t= (a[0][0]+a[0][1])*b[1][1];
 u= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
 v= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
 c[0][0]=p+s-t+v;
 c[0][1]=r+t;
 c[1][0]=q+s;
 c[1][1]=p-q+r+u;
 cout<<"\nProduct of both is:\n";
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
   cout<<c[i][j]<<" ";
  }
  cout<<"\n";
 }
 return 0;
}
