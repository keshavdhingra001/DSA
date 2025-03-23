class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        //build undir graph
        vector<vector<pair<int, int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }
        
        //Init dist vector with INF and ways vector with 0
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);
        //Str node (0): dist = 0, ways = 1
        dist[0] = 0;
        ways[0] = 1;
        
        // Min-heap priority queue: (current distance, current node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        
        //using Dijkstra's algo
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            //Skip, if we have already found a better path to u
            if (d > dist[u])
                continue;
            
            for (auto &[t, v] : adj[u]) {
                //If a new shorter path is found, update distance and ways for v
                if (d + t < dist[v]) {
                    dist[v] = d + t;
                    //Inherit ways from u
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                //If another path with the same shortest dist found, add no. of ways
                else if (d + t == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        //Return no. of ways to reach node n-1 modulo MOD
        return ways[n - 1] % MOD;
    }
};
/* App - Using Dijkstra's algorithm with a min-heap to compute the shortest path cost 
         from node 0 to node n-1 while counting the number of shortest paths.
*/
// TC - O((n + m) log n), where n is the number of nodes and m is the number of roads
// SC - O(n + m), for storing the graph, distance array, and ways array
