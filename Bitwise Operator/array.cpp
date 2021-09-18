#include <iostream> 
#include<climits>
using namespace std;

int main(){

 /* int a[6]={3,5,4,6,8,7};

int min=INT_MAX;
int max=INT_MIN;

for (int i = 0; i < 6; i++)
{
    if(a[i]<min){
        min=a[i];
    }
    if(a[i]>max){
        max=a[i];
    }
}
cout<<"min="<<min<<endl<<"max="<<max;
*/

/*int a[6]={2,5,3,7,11,9};

int key=12;
int ans=0;
int i;

for( i=0;i<6;i++){
    if(a[i]==key){
       ans=i;
       break;
    }
}
if(i==6)
cout<<"not found";

else 
cout<<"ans="<<ans;
*/

/*int a[6]={2,3,5,7,11,19};

int key=3;
int s=0;
int e=6;
int ans;

while(s<=e){
    int mid=(s+e)/2;
    
    if(a[mid]<key){
        s=mid+1;
    }
    else if(a[mid]>key){
        e=mid-1;
    }
    else {
    ans=mid;
    break;
    }
}
if(s<=e)
cout<<"ans="<<ans;

else 
cout<<"ghanta";
*/

/*int a[6]={6,4,3,27,8,1};

for(int i=0;i<5;i++){
int min=INT_MAX;

    for(int j=i;j<6;j++){
     if(a[j]<min){
         min=a[j];
     int temp=a[i];
     a[i]=a[j];
     a[j]=temp;
     }
    }
}
for (int i = 0; i < 6; i++)
{
    cout<<a[i]<<" ";
}*/

/*int a[6]={6,4,3,27,8,1};

int counter=0;

for(int i=0;i<5;i++){
    for(int j=0;j<6-counter;j++){
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    counter++;
}
for (int i = 0; i < 6; i++)
{
    cout<<a[i]<<" ";
}*/

/*int a[12]={6,4,3,27,8,1,66,23,44,55,17,9};

for(int i=0;i<11;i++){
    int j=i+1;

        while(a[j]<a[j-1]&&j>0){
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
    }
for (int i = 0; i < 12; i++)
{
    cout<<a[i]<<" ";
}*/

/*int a[6]={4,6,3,2,8,7};

int max=INT_MIN;
for(int i=0;i<6;i++){
    if(a[i]>max){
        max=a[i];
    }
    cout<<max<<" ";
}*/

 /*int a[4]={1,2,3,4};

 for(int i=0;i<4;i++){
     for(int j=i;j<4;j++){
     int sum=0;
         for(int k=i;k<=j;k++){
             sum=sum+a[k];
         }
     cout<<sum<<" ";
     }
 }*/

 /*int a[7]={10,7,4,6,8,10,11};

 int d=a[1]-a[0];
 int ans=2;
 int mx=INT_MIN;

 for(int i=1;i<7;i++){
      if(a[i+1]-a[i]==d){
          ans++;
          mx=max(mx,ans);
      }
      else {
      ans=2;
      d=a[i+1]-a[i];
      }
 }
 cout<<"ans="<<mx;
*/

/*int a[8]={1,2,0,7,2,0,2,2};
a[8]=-1;

int mx=INT_MIN;
int ans=0;

for(int i=0;i<8;i++){
    if(a[i]>mx&&a[i]>a[i+1]){
        ans++;
    }
    mx=max(mx,a[i]);
}
cout<<"ans="<<ans;
*/

/*int a[7]={1,5,3,4,3,5,6};

int a1[100];
for(int i=0;i<100;i++){
a1[i]=-1;
}

int ans=INT_MAX;
for(int i=0;i<7;i++){
    if(a1[a[i]]==-1){
       a1[a[i]]=i; 
    }
    else {
        ans=min(ans,a1[a[i]]);
    }
}
cout<<"ans="<<ans;
if(ans=INT_MAX)
cout<<"ghanta";
*/

/*int a[6]={2,1,4,-9,5,0};

bool a1[100];
for(int i=0;i<100;i++){
    a1[i]=false;
}

for(int i=0;i<6;i++){
    if(a1[a[i]]==false){
        a1[a[i]]=true;
    }
}
int i;
for( i=0;i<100;i++){
    if(a1[i]==false){
        cout<<"ans="<<i;
        break;
    }
}
if(i==100)
cout<<"ghanta";
*/

/*int a[4]={-1,4,7,2};

int mx=INT_MIN;
for(int i=0;i<4;i++){
    for(int j=i;j<4;j++){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum=sum+a[k];
            mx=max(sum,mx);
        }
    }
}
cout<<"max sum="<<mx;
*/

/*int a[4]={-1,4,7,2};

for(int i=1;i<4;i++){
    a[i]=a[i]+a[i-1];
}

int mx=INT_MIN;
for(int i=0;i<4;i++){
    for(int j=0;j<i;j++){
        a[i]=a[i]-a[j];
        mx=max(a[i],mx);
    }
}
cout<<"max sum="<<mx;
*/

/*int a[5]={-1,4,-6,7,-4};
int sum=0;

int mx=INT_MIN;
for(int i=0;i<5;i++){
    sum=a[i]+sum;
    if(sum<0){
        sum=0;
    }
    mx=max(mx,sum);
}
cout<<"max sum="<<mx;
*/

/*int a[7]={4,-4,6,-6,10,-11,12};
int sum1=0;

int mx1=INT_MIN;
for(int i=0;i<7;i++){
    sum1=a[i]+sum1;
    if(sum1<0){
        sum1=0;
    }
    mx1=max(mx1,sum1);
}
//cout<<"max sum="<<mx1;

int total=0;
for(int i=0;i<7;i++){
    total=a[i]+total;
}
//cout<<"total="<<total;

for(int i=0;i<7;i++){
    a[i]=-a[i];
}
int sum2=0;

int mx2=INT_MIN;
for(int i=0;i<7;i++){
    sum2=a[i]+sum2;
    if(sum2<0){
        sum2=0;
    }
    mx2=max(mx2,sum2);
}
//cout<<"max sum="<<mx2;

int circular=total+mx2;
cout<<max(mx1,circular);
*/

/*int a[8]={2,4,7,11,14,16,20,21};

int key=31;
int i;
int j;

for( i=0;i<8;i++){
    for( j=i;j<7;j++){
        int sum=0;
        sum=a[i]+a[j];
        if(sum==key){
            cout<<i<<" "<<j;
            break;
        }
    }
}*/

/*int a[3][3]={1,2,3,4,5,6,7,8,9};

int r=0;
int re=2;
int c=0;
int ce=2;

while(r<=re&&c<=ce){
for(int i=c;i<=ce;i++){
    cout<<a[r][i]<<" ";
}
    r++;
for(int i=r;i<=re;i++){
    cout<<a[i][ce]<<" ";
    }
    ce--;
    for(int i=ce;i>=c;i--){
        cout<<a[re][i]<<" ";
    }
        re--;
    for(int i=re;i>=r;i--){
        cout<<a[i][c]<<" ";
    }
        c++;
}*/

/*int a[3][3]={1,2,3,4,5,6,7,8,9};

for(int i=0;i<3;i++){
    for(int j=i;j<3;j++){
        int temp=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=temp;
    }
}

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}*/

/*int a[4][4]={1,4,7,11,2,5,8,12,3,6,9,16,10,13,14,17};

int key=23;

int r=0;
int c=3;

while(r<=3&&c>=0){
    if(a[r][c]==key){
        cout<<r<<" "<<c;
        break;
    }
    if(a[r][c]<key){
        r++;
    }
    if(a[r][c]>key){
        c--;
    }
}
if(r>3||c<0){
cout<<"not found";
}*/

/*int a[2][2]={1,2,3,4};
int b[2][3]={1,3,5,2,4,6};

int c[2][3];
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        c[i][j]=0;
        for(int k=0;k<2;k++){
            c[i][j]+=a[i][k]+b[j][k];
        }
    }
}
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}*/








    return 0;
}