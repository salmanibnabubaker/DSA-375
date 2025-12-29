vector<vector<pair<int,int>>> adjacencyList(int V,vector<vector<int>>&edges){
    vector<vector<pair<int,int>>>adj;
    for(int i=0;i<V;i++){
        vector<pair<int,int>>empty;
        adj.push_back(empty);
    }
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0],v=edges[i][1],w=edges[i][2];
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    return adj;
}
void pushMinheap(vector<pair<int,int>>&minheap,int node,int weight){
    minheap.push_back({weight,node});
    int ch=minheap.size()-1;
    int p;
    ch%2==0?p=(ch-2)/2:p=(ch-1)/2;
    while(p>=0&&minheap[ch].first<=minheap[p].first){
        if(minheap[ch].first<minheap[p].first){
            int temp=minheap[ch].first;
            minheap[ch].first=minheap[p].first;
            minheap[p].first=temp;

            temp=minheap[ch].second;
            minheap[ch].second=minheap[p].second;
            minheap[p].second=temp;
        }
        else{
            if(minheap[ch].second<minheap[p].second){
                int temp=minheap[ch].first;
                minheap[ch].first=minheap[p].first;
                minheap[p].first=temp;

                temp=minheap[ch].second;
                minheap[ch].second=minheap[p].second;
                minheap[p].second=temp;
            }
            else{
                break;
            }
        }
        ch=p;
        ch%2==0?p=(ch-2)/2:p=(ch-1)/2;
    }
}
pair<int,int> popMinheap(vector<pair<int,int>>&minheap){
    int weight=minheap[0].first,node=minheap[0].second;
    int n=minheap.size();
    minheap[0].first=minheap[n-1].first;
    minheap[0].second=minheap[n-1].second;
    minheap.pop_back();
    int p=0,ch;
    if(2*p+1>minheap.size()-1){
        return {weight,node};
    }
    else if(2*p+2>minheap.size()-1){
        ch=2*p+1;
    }
    else{
        if(minheap[2*p+1].first<minheap[2*p+2].first){
            ch=2*p+1;
        }
        else if(minheap[2*p+1].first>minheap[2*p+2].first){
            ch=2*p+2;
        }
        else{
            if(minheap[2*p+1].second<minheap[2*p+2].second){
                ch=2*p+1;
            }
            else{
                ch=2*p+2;
            }
        }
    }
    while(minheap[p].first>=minheap[ch].first){
        if(minheap[ch].first<minheap[p].first){
            int temp=minheap[ch].first;
            minheap[ch].first=minheap[p].first;
            minheap[p].first=temp;

            temp=minheap[ch].second;
            minheap[ch].second=minheap[p].second;
            minheap[p].second=temp;
        }
        else{
            if(minheap[ch].second<minheap[p].second){
                int temp=minheap[ch].first;
                minheap[ch].first=minheap[p].first;
                minheap[p].first=temp;

                temp=minheap[ch].second;
                minheap[ch].second=minheap[p].second;
                minheap[p].second=temp;
            }
            else{
                break;
            }
        }
        p=ch;
        if(2*p+1>minheap.size()-1){
            break;
        }
        else if(2*p+2>minheap.size()-1){
            ch=2*p+1;
        }
        else{
            if(minheap[2*p+1].first<minheap[2*p+2].first){
                ch=2*p+1;
            }
            else if(minheap[2*p+1].first>minheap[2*p+2].first){
                ch=2*p+2;
            }
            else{
                if(minheap[2*p+1].second<minheap[2*p+2].second){
                    ch=2*p+1;
                }
                else{
                    ch=2*p+2;
                }
            }
        }
    }
    return {weight,node};
}
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    // Code here
    vector<int>shortDist(V,INT_MAX);
    vector<vector<pair<int,int>>>adj=adjacencyList(V,edges);
    vector<pair<int,int>>minheap;
    pushMinheap(minheap,src,0);
    shortDist[src]=0;
    while(minheap.size()!=0){
        pair<int,int>temp=popMinheap(minheap);
        int node=temp.second;
        int dist=temp.first;

        if(dist>shortDist[node]){
            continue;
        }

        for(int i=0;i<adj[node].size();i++){
            int adjNode=adj[node][i].second;
            int adjWeight=adj[node][i].first;
            if(shortDist[adjNode]>dist+adjWeight){
                shortDist[adjNode]=dist+adjWeight;
                pushMinheap(minheap,adjNode,shortDist[adjNode]);
            }
        }
    }
    return shortDist;
}