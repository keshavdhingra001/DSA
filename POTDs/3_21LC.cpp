class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        //set for fast lookup of initial supplies
        unordered_set<string> avail(supplies.begin(), supplies.end());
        
        // Build dependency graph: maps each ingredient to the list of recipes that need it
        unordered_map<string, vector<int>> graph;
        // inDegree[i] cnts how many ingredients (dependencies) recipe i still needs
        vector<int> inDegree(n, 0);
        
        // Build graph and inDegree for each recipe
        for (int i = 0; i < n; i++) {
            // For each recipe, set inDegree as number of required ingredients
            inDegree[i] = ingredients[i].size();
            for (string& ing : ingredients[i]) {
                // If the ingredient is already available, reduce the dependency count
                if (avail.count(ing)) {
                    inDegree[i]--;
                } else {
                    // Otherwise, add an edge: ingredient -> recipe index
                    graph[ing].push_back(i);
                }
            }
        }
        
        // Queue for BFS: add recipes with no remaining dependencies (inDegree == 0)
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                que.push(i);
        }
        
        vector<string> result;
        // Process the graph using BFS (Kahn's Algorithm)
        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            result.push_back(recipes[idx]);
            // For each recipe that depends on the current recipe (treated as an ingredient now)
            if (graph.find(recipes[idx]) != graph.end()) {
                for (int dep : graph[recipes[idx]]) {
                    inDegree[dep]--;
                    if (inDegree[dep] == 0)
                        que.push(dep);
                }
            }
        }
        
        return result;
    }
};
/* App - using BFS (Kahn's Algorithm)
         build a dependency graph and inDegree array for recipes
         (to process available supplies and unlock recipes whose ingredients are all available)
*/
// TC - O(R + I + E), where R = number of recipes, I = total number of ingredient entries, 
//      E = total dependency edges; approximately O(n) given constraints.
// SC - O(R + I), for storing the graph, inDegree array, and queue.
