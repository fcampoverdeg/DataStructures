''' Dijkstra's Algorithm

- Dijkstra's Algorithm, the goal is to find the shortest distance from a given source node to all
  other nodes in the graph. As the source node is the starting point, its distance is initialized
  to zero. From there, we iteratively pick the unprocessed node with the minimum distance from the
  source this is where a min-heap (priority queue) or a set is typically used for efficienty. For
  each picked node u, we update the distance to its neighbors v using the formula:

        dist[v] = dist[u] + weight[u][v]
  
  but only if this new path offers a shorter distance than the current known one.
  The process continues until all nodes have been processed.
  '''

import heapq

def dijkstra(graph, start_node):
    """
    Finds the shortest path from a start_node to all other nodes in a graph.
    
    Args:
        graph (dict): A dictionary representing the graph, where keys are nodes
                      and values are dictionaries of neighbors and their edge weights.
                      Example: {'A': {'B': 1, 'C': 4}, 'B': {'A': 1, 'D': 2}, ...}
                      
        start_node: The starting node for finding shortest paths.
        
    Returns:
        dict: A dictionary containing the shortest distances from the start_node to all
              other reachable nodes. 
    """

    # Step 1: Initialize distances - start node = 0, others = infinity
    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0

    # Step 2: Create a priority queue (min-heap) storing pairs (distance, node)
    pq = [(0, start_node)]   # (distance so far, node)

    # Step 3: While we still have nodes to process
    while pq:
        # 3a Get the node with the smallest current distance
        current_distance, current_node = heapq.heappop(pq)

        # 3b If this distance is already larger than the recorded one, skip (stale entry)
        if current_distance > distances[current_node]:
            continue

        # 3c Explore each neighbor of the current node
        for neighbor, weight in graph[current_node].items():
            # Distance through current node
            new_distance = current_distance + weight

            # 3d If we found a shorter path to the neighbor, update it
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                
                # 3e Push the updated distance into the priority queue
                heapq.heappush(pq, (new_distance, neighbor))

    # Step 4: When queue is empty, we have found all shortest distances
    return distances

# Example Usage:
if __name__ == "__main__":
    # Represent the graph using an adjacency list
    graph = {
        'A': {'B': 4, 'C': 2},
        'B': {'C': 5, 'D': 10},
        'C': {'E': 3},
        'D': {'F': 11},
        'E': {'D': 4, 'F': 2},
        'F': {}
    }
        
    start_node = 'A'
    shortest_path = dijkstra(graph, start_node)
    print(shortest_path)