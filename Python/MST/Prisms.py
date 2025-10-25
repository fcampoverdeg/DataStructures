''' Prim's Algorithm

- Prim's Algorithm: The goal is to find the collection of edges in a graph that connects all vertices,
  with a minimum sum of edge weights.
  
  Find the MST (Minimum Spanning Tree) by first including a randome vertex to the MST. The algorithm
  then finds the vertex with the lowest edge weight from the current MST, and includes that to the MST.
  Prim's algorithm keeps doing this until all nodes are included in the MST.
  
  Prim's algorithm is greedy, and has a straightforward way to create a MST.
  
  For it to work, all the nodes must be connected. For an unconnected graph use Kruskal's algorithm.
  '''

import heapq

def prims(graph, start_node):
    """
    Prim's Minimum Spanning Tree (lazy version, using a min-heap).
    
    Args:
        graph (dict): A dictionary representing the graph, where keys are nodes
        and values are dictionaries of neighbors and their edge weights.
        Example: {'A': {'B': 1, 'C': 4}, 'B': {'A': 1, 'D': 2}, ...}

        start_node: The starting node for finding MST.

    Returns:
        tuple: A tuple containing:
            - list: A list of edges in the MST, represented as tuples (u, v, weight).
            - int: The total weight of the MST.
        """
    if not graph:
        return [], 0
    
    mst_edges = []
    total_weight = 0
    visited = {start_node}

    # Priority Queue to store edges (weight, u, v)
    # The smallest weight edge will always be at the top
    pq = []

    # Add all edges connected to start_node to the priority queue
    for neighbor, weight in graph[start_node]:
        heapq.heappush(pq, (weight, start_node, neighbor))

    # Keep growing until all vertices are in the tree
    while pq:
        weight, u, v = heapq.heappop(pq)

        if v not in visited:
            visited.add(v)
            mst_edges.append((u, v, weight))
            total_weight += weight

            # Add all edges connected to the newly added vertex 'v'
            # to the priority queue, if the neighbor is not yet visited
            for next_neighbor, next_weight in graph[v]:
                if next_neighbor not in visited:
                    heapq.heappush(pq, (next_weight, v, next_neighbor))

    return mst_edges, total_weight

# Example Usage:
if __name__ == "__main__":
    # Represent the graph using an adjacency list
    graph = {
        'A': [('B', 4), ('C', 2)],
        'B': [('A', 4), ('D', 5)],
        'C': [('A', 2), ('D', 8), ('E', 10)],
        'D': [('B', 5), ('C', 8), ('E', 2)],
        'E': [('C', 10), ('D', 2)]
    }


    start_node = 'A'
    mst_edges, total_weight = prims(graph, start_node)
    print("Edges in MST: ", mst_edges)
    print("Total weight of MST: ", total_weight)