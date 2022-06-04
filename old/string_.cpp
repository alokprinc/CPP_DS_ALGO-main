#include <bits/stdc++.h>
using namespace std;

int main() {
   string A = "baadbbbccedddee";
   int B = 3;
   int n = A.length();

    int i = 0, j = 0;
    string s;
    while(i < n){
        if(A[i] == A[i+1]){
            while(A[j] == A[j+1]){
                j++;
            }
            string temp = A.substr(i,j+1);
            int len = temp.length();

            if(len != B){
                s+=temp;
            }
            else{
                i=j+1;
                j=i;
            }
        }else{
            s+=A[i];
            i++;
            j=i;
        }
    }
    cout<<A<<endl<<s;
	return 0;
}