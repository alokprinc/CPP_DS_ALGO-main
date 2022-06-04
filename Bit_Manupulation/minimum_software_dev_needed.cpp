#include<bits/stdc++.h>
using namespace std;

vector<int>sol;

void soultion(vector<int>& people,int nskils,int cp,vector<int>& onesol,int smask){
   if(cp == people.size()){
       if(smask == ((1 << nskils)-1)){
          if(sol.size() == 0 or onesol.size() < sol.size()){
              sol = onesol;
          }
       }
       return;
   }
   soultion(people,nskils,cp+1,onesol,smask);

   onesol.push_back(cp);
   soultion(people,nskils,cp+1,onesol,(smask | people[cp]));
   onesol.pop_back();
}


int main(){
    int n;
    cin>>n;

    unordered_map<string ,int>smap;
    for(int i=0;i<n;i++){
        string x;cin>>x;
        smap[x]=i;
    }
    int np;
    cin>>np;

    vector<int>people(np);

    for(int i=0;i<np;i++){
        int personskills;
        cin>>personskills;

        for(int j=0;j<personskills;j++){
            string skill;
            cin>>skill;

            int snum=smap[skill];
            people[i]=people[i]|(1<<snum);
        }
    }

    vector<int>soln;
    soultion(people,n,0,soln,0);
    cout<<"[";
    for(int i=0;i<sol.size();i++){
        if(i==sol.size()-1){
            cout<<sol[i];
        }else{
            cout<<sol[i]<<", ";
        }
    }
    cout<<"]";

}