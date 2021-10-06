#include <bits/stdc++.h >

using namespace std;

bool is_Prime(int n){

  if(n == 2)
    return true;
    
  if(n % 2 == 0)
    return false;

  for(int i = 3; i*i <= n; i += 2){
    if(n % i == 0)
      return false;
  }

  return true;
}

int main(){

  int t, n;
  cin >> t;

  while(t--){

    cin >> n;

    if(is_Prime(n)){
      cout << n << " is Prime no";
    }
    else{
      cout << n << " is not a Prime no";
    }
}




  return 0;
}
