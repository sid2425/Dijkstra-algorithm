#include<iostream>
#include<limits.h>
#include<string>
#include<map>
#include<list>
using namespace std;
class Graph 
{
    private:
    map<string,list<pair<string,int>> > l;
    public:
    void addEdge(string x,string y,bool bid,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bid)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }
    string minDistance(map<string,int> dist,map<string,bool> visited)
    {
        int minVertex=INT_MAX;
        string index="";
        for(auto p:l)
        {
            string i=p.first;
            if(dist[i]<minVertex && !visited[i])
            {
                minVertex=dist[i];
                index=i;
            }
        }
        return index;
    }
    void print(map<string,int> dist)
    {
        cout<<"Vertex\tDistance\n";
        for(auto p:l)
        {
            string firstVertex=p.first;
            cout<<firstVertex<<"\t"<<dist[firstVertex]<<"\n";
        }
    }
    void printList()
    {
        cout<<"Vertices:\n";
        for(auto p:l)
        {
            cout<<p.first<<"->";
            list<pair<string,int>> p1=p.second;
            for(auto p2:p1)
            {
                cout<<"["<<p2.first<<","<<p2.second<<"]-";
            }
            cout<<endl;
        }
        cout<<"\n";
    }
    void shortestPath(string source)
    {
        map<string,bool> visited;
        map<string,int> dist;
        for(auto p:l)
        {
            string v=p.first;
            dist[v]=INT_MAX;
            visited[v]=false;
        }
        dist[source]=0;
        for(auto p:l)
        {
            string u=minDistance(dist,visited);
            visited[u]=true;
            for(auto nbr:l[u])
            {
                pair<string,int> p1=nbr;
                string v2=p1.first;
                int wt=p1.second;
                if(!visited[v2])
                {
                    if(dist[v2]>dist[u]+wt)
                    {
                        dist[v2]=dist[u]+wt;
                    }
                }
            }
        }
        print(dist);
    }
};
int main()
{
    Graph g;
    g.addEdge("A","B",true,7);
    g.addEdge("A","C",true,3);
    g.addEdge("B","C",true,1);
    g.addEdge("B","E",true,6);
    g.addEdge("B","D",true,2);
    g.addEdge("C","D",true,2);
    g.addEdge("D","E",true,4);
    g.printList();
    g.shortestPath("A");
}
