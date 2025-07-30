/*
Question 1: Message Propagation (Graph + Dijkstra/BFS)
Difficulty: Easy-Medium

You are given a network of n servers labeled from 0 to n-1. Each server can communicate with others through direct connections given as:
connections[i] = [from, to, time] 
This means a message takes time seconds to travel from from to to.
You are given an integer k, the starting server.
Your task is to return the minimum time it takes to send a message from server k to all other servers. If it's impossible to reach all servers, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()

int main() {
    int n, m;
    cin >> n >> m; // n = number of servers, m = number of connections

    vector<vector<pair<int, int>>> adj(n); // directed graph

    for (int i = 0; i < m; i++) {
        int from, to, t;
        cin >> from >> to >> t;
        adj[from].pb({to, t}); // directed edge
    }

    int k;
    cin >> k; // starting node

    vector<int> dist(n, INT_MAX);
    dist[k] = 0;

    // Min-heap: {time, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [curr_time, node] = pq.top(); pq.pop();

        if (curr_time > dist[node]) continue; // skip if outdated entry

        for (auto [nbr, t] : adj[node]) {
            if (curr_time + t < dist[nbr]) {
                dist[nbr] = curr_time + t;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    int max_time = *max_element(all(dist));
    cout << (max_time == INT_MAX ? -1 : max_time) << endl;
}
