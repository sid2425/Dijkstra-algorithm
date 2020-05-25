# Dijkstra-algorithm
Dijkstra algorithm is a greedy algorithm, which is used to find shortest path from one vertex to all the other vertices. This algorithm works until all the vertices in the graph have been visited.
The abstracted rules are as follows:
Every time that we set out to visit a new node, we will choose the node with the smallest known distance/cost to visit first.
Once we’ve moved to the node we’re going to visit, we will check each of its neighboring nodes.
For each neighboring node, we’ll calculate the distance/cost for the neighboring nodes by summing the cost of the edges that lead to the node we’re checking from the starting vertex.
Finally, if the distance/cost to a node is less than a known distance, we’ll update the shortest distance that we have on file for that vertex.
Time Complexity: O(n^2)->Worst case 
Limitations: 
1)If there are any negative edge weights, then this algorithm fails to process those vertices. 
Applications:
Google Maps 
Satellite Routing 
