#include<bits/stdc++.h>
using namespace std;
int minimum_verticalsum(vector<vector<int>>vec)
{
   int size = 0,sum =10000000,p=0;
   for (int i = 0; i < vec.size(); i++)
   {
      if(size<vec[i].size())
      {
         size = vec[i].size();
      }
   }
   
   for(int i=0;i<vec.size();i++){
       while(vec[i].size()!=size){
           vec[i].push_back(0);
       }
   }
   for(int i=0;i<size;i++){
       int temp=0;
       for(int j=0;j<vec.size();j++){
           temp+=vec[j][i];
       }
       sum=min(sum,temp);
   }
   
   return sum;
}
int main()
{
int n;
cin>>n;
vector<int>v;
int a[n];
vector<vector<int>>vec;
for (int i = 0; i < n; i++)
{
   cout<<"ENTER THE SIZE OF VECTOR"<<" "<<i<<"  ";
   cin>>a[i];
   cout<<"ENTER THE ELEMENTS OF VECTOR"<<"  ";
   for (int j = 0; j < a[i]; j++)
   {
      int x;
      cin>>x;
      v.push_back(x);
   }
   vec.push_back(v);
   v.clear();
}
cout<<"Value of minimum vertical sum is "<<"  "<<minimum_verticalsum(vec)<<endl;
return 0;
}