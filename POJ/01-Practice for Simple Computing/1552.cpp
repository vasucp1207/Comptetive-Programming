#include <iostream>
#include <vector>

using namespace std;

int main(){

	while(true){
		
		vector<int> arr;
		int x;
		for(int i = 0; i < 20; i++){
			cin >> x;
			if(x == 0) break;
			arr.push_back(x);
			if(x == -1) break;
		}
		
		if(arr[0] == -1) break;
		
		int cnt = 0;
		for(int j = 0; j < arr.size(); j++){
			for(int k = 0; k < arr.size(); k++){
				if(arr[k] == 2 * arr[j])
					cnt++;
			}
		}
		
		cout << cnt << endl;
	}


return 0;
}
