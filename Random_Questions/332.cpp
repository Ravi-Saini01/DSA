// 332. Reconstruct Itinerary

// You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

// All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

// Example 1:

// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK","MUC","LHR","SFO","SJC"]
// Example 2:

// Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

// Constraints:

// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi

class Solution
{
public:
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        adj;
    vector<string> result;
    void dfs(string u)
    {
        auto &edges = adj[u];

        while (!edges.empty())
        {
            string v = edges.top();
            edges.pop();
            dfs(v);
        }
        result.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto e : tickets)
            adj[e[0]].push(e[1]);

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
// TC-->O(E log E) where E is the number of edges in the graph, which is equal to the number of tickets. This is because we are using a priority queue to store the edges,
// and each edge is inserted into the priority queue once. The time complexity of inserting an edge into a priority queue is O(log E).
// SC-->O(V + E) where V is the number of vertices (airports) and E is the number of edges (tickets). This is because we are using an adjacency list to represent the graph, which requires O(V + E) space.
//  Additionally, we are using a result vector to store the itinerary, which also requires O(V) space in the worst case.