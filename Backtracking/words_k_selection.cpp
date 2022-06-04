#include <bits/stdc++.h>
using namespace std;

void combination(int i, string uq, int ssf, int ts, string ans )
{
  if (i == uq.length())
    {
       if (ssf == ts)
        {  
                cout << ans << endl; 
        }
        return;
    }
    
    combination(i+1,uq,ssf+1,ts,ans + uq[i]);
    combination(i+1,uq,ssf+0,ts,ans);
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    set<char> unique;
    string ustr="";
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(unique.find(ch)==unique.end())
        {
            unique.insert(ch);
            ustr+=ch;
        }
    }
    combination(0, ustr, 0, k, "");
    return 0;
}