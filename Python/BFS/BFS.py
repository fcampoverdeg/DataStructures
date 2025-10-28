''' BFS

- Breadth First Search is used to calculate the shortests path in a graph with unweighted edges.
    Traversal is usually implemented using a queue due to the FIFO behaviour.
    
    Intuition: Explore outward from s in all possible directions, adding nodes one "layer" at a time

    BFS algorithm: 
            L0 = { s }
            L1 = all neighbors of L0
            L2 = all nodes that do not belong to L0 or L1, and that have an edge to a node in L1
            L i + 1 = all nodes that do not belong to an earlier layer, and that have an edge to a node in Li

    Theorem:
            For each i, Li consists of all nodes at disatance exactly i from s.
            There is a path from s to t iff t appears in some layer. 
'''


from collections import deque

def bfs(graph, start_node):
    """
    Performs a Breadth-First Seach traversal on a graph.
    
    Args:
        graph (dict): An adjacency list representation of the graph.
                      Keys are nodes, values are lists of their neighbors
        start_node: The node from which to start the BFS. 
        
    Returns:
        list: A list of nodes in the order they were visited during the BFS.


    Visited                 When node is enqueued           Avoid duplicates and infinite loops
    queue                   While nodes are pending         Maintain exploration order
    traversal order         When node is dequeued           Record final traversal order
    
    """

    visited = set() # To keep track of visited nodes
    queue = deque() # Initialize the queue

    # Add the starting node to the queue, and mark it as visited
    queue.append(start_node)
    visited.add(start_node)

    traversal_order = []    # An array to keep track of the order in which the nodes are visited

    while queue:
        # Dequeu a node from the front of the queue
        current_node = queue.popleft()
        traversal_order.append(current_node)

        # Explore neighbors of the current node
        for neighbor in graph.get(current_node, []):
            # If the node is not in 'visited' add to the visited and the queue.
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return traversal_order


# Example Usage:
if __name__ == "__main__":
    # Represent the graph using an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['A', 'D', 'E'],
        'C': ['A', 'F'],
        'D': ['B'],
        'E': ['B', 'F'],
        'F': ['C', 'E']
    }

    start_node = 'A'
    result = bfs(graph, start_node)
    print(f"BFS traversal starting from '{start_node}': {result}")

    graph_disconnected = {
        '1': ['2'],
        '2': ['1', '3'],
        '3': ['2'],
        '4': ['5'],
        '5': ['4']
    }
    start_node_disconnected = '1'
    result_disconnected = bfs(graph_disconnected, start_node_disconnected)
    print(f"BFS traversal starting from '{start_node_disconnected}' (disconnected graph): {result_disconnected}")
