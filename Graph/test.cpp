// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    class Pair{
  public:
   int v;
   int wsf;
   string psf;
   Pair(int v,int wsf,string psf){
       this->v = v;
       this->wsf = wsf;
       this->psf = psf;
   }
   
   
};
struct myComp
{
    bool operator()(
        Pair &a,
        Pair &b)
    {
        return a.wsf > b.wsf;
    }
};
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
    priority_queue<Pair, vector<Pair>, myComp> q;
      q.push({src,0, to_string(src)});
        vector<int> ans;
      vector<int> vis(V, 0);

      while (!q.empty())
      {
        Pair rem = q.top();
        q.pop();
        if (vis[rem.v]==1)
        {
          continue;
        }
        vis[rem.v] = 1;

        ans.push_back(rem.wsf);

        for (auto e : adj[rem.v])
        { 
          int nbr = e[0];
          int wt  = e[1];
          if (!vis[nbr])
          {
            q.push({nbr, rem.wsf + wt,rem.psf + to_string(nbr)});
          }
        }
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends