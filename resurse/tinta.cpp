#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
ifstream f("tinta.in");
ofstream g("tinta.out");

 int a[1001][1001],b[1001][1001],n,i,j,x,l,c;

int main()
{
    f>>n;
    x=1;
    for(i=1;i<=n;i++)
    if (i%2==0)
     {   l=1;c=i;
         for(j=1;j<=i;j++)
         {
             a[l][c]=x;
             x=x+1;
             l++;
             c--;
         }
     }
     else
     {
          l=i;c=1;
          for(j=1;j<=i;j++)
         {
             a[l][c]=x;
             x=x+1;
             l--;
             c++;
         }
    }
    if (n%2==0)
     for (i=2;i<=n;i++)
     {
       if(i%2==0)
        {l=n;c=i;}
        else
        {
         l=i;c=n;
        }

       for(j=1;j<=n-i+1;j++)
       {
           a[l][c]=x;
           x++;
           if(i%2==0) {l--;c++;}
            else {l++;c--;}
       }
     }
     else
     for (i=2;i<=n;i++)
     {
       if (i%2==0) {l=i;c=n;}
        else {l=n;c=i;}
       for(j=1;j<=n-i+1;j++)
       {
           a[l][c]=x;
           x++;
           if (i%2==0) {l++;c--;}
            else {l--;c++;}
       }
     }
    for(i=1;i<=n;i++)
     {
         for (j=1;j<=n;j++)
          g<<a[i][j]<<" ";
         g<<'\n';
     }
     for(i=2;i<n;i++)
      for(j=2;j<n;j++)
       b[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1]+a[i][j-1]+a[i][j+1];


     g<<n-3+n-2<<'\n';
         for (j=2;j<=n-2;j++)
          g<<b[2][j]<<" ";
         for(j=2;j<=n-1;j++)
          g<<b[n-1][j]<<" ";

    return 0;
}