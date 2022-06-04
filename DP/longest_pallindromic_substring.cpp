#include<bits/stc++.h>
using namespace std;

int main() {
	string A = "abbcccbbbcaaccbababcbcabca";
	int n = A.size();
	  int x=-1,y=-1;
	  int c=0;
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int g = 0 ; g < n ;g++){
        for(int i = 0, j = g;j <n;i++,j++){
            if(g == 0){
                dp[i][j] = c++;
            }
            else if(g == 1){
                if(A[i] == A[j]) dp[i][j] = c++;
                else dp[i][j] = 0;
            }
            else{
                if(A[i] == A[j] and dp[i+1][j-1] >0 ){
                    dp[i][j] = c++;
                }
                else{
                    dp[i][j] = 0;
                }
            }
			if(dp[i][j]){
				x=i;
				y=j;
			}
        }
    }

	for(int i = 0 ; i < n ;i++){
        for(int j = 0;j <n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
  cout<<c<<endl;
//     for(int g = n-1 ; g >= 0 ;g--){
//         for(int i = 0, j = g;j <n;i++,j++){
//             if(dp[i][j] == 1){ x=i; y =j;
// 				cout<<x<<" "<<y<<endl;
// 				break;
// 			}
//         }
// 		if(x>=0 and y >= 0) break;
//     }
     cout<<x<<"-^-"<<y<<endl;
}