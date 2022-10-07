#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, x, y;
	
	cin>>n;
	for (int i = 0; i <n;++i ){
	    cin>>x;
	    cin>>y;
	    if (y <= x + 200 && y >= x){
	        cout<<"YES";
	    }else{
	        cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
