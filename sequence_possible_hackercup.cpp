#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt","r",stdin);
	freopen("outp.txt","w",stdout);
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
       int n,k;
	   cin>>n>>k;
	   vector<int>vec(n),vec1(n);
	   for(int i=0;i<n;i++)
	   cin>>vec[i];
	   for(int i=0;i<n;i++)
	   cin>>vec1[i];
	   int p=0,q=0;
	   int a=0;
	   for(int i=0;i<n;i++){
		if(vec[0]==vec1[i])

		    { q=i;
			 a=i;
			break;
			
			}
	   }
	   bool b=true;
	   while(p<n){
		  if(vec[p]==vec1[q])
		  {   p++;
		     q=(q+1)%n;
             
		  }
		  else
		  {
			b=false;
			break;
		  }
	   }
	   if((a && k == 0)|| !b)
	   cout<<"Case #"<<j+1<<": NO\n";
	   else
	   cout<<"Case #"<<j+1<<": YES\n";


	}
	return 0;
}
