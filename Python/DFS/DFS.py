''' DFS

- Depth First Search is an algorithm for traversing or searching tree or graph data
    structures. It explores as far as possible along each branch before backtracking.
     
    Usage:  Used for checking path existance and cycle detection.
    '''

def dfs(graph, start_node, visited=None, traversal_order=None):
    """
    Performs a Depth-First Search traversal on a graph.
    
    Args:
        graph (dict): An adjacency list representation of the graph.
                      Keys are nodes, values are lists of their neighbors
        start_node: The node from which to start the DFS.
        
    Returns:
        list: A list of nodes in the order they were visited during DFS.
    
    """

    ''' ( RECURSIVE DFS ) *** NO STACK IMPLEMENTATION *** '''
    ''' PYTHON USES THE CALL STACK FOR RECURSIVE CALLS '''
    # if visited is None:
    #     visited = set() # Initializes visited set for the first call

    # if traversal_order is None:
    #     traversal_order = []

    # visited.add(start_node) # Mark the current node as visited
    # traversal_order.append(start_node) # Array to store traversed nodes

    # for neighbor in graph[start_node]:
    #     if neighbor not in visited:
    #         dfs(graph, neighbor, visited, traversal_order)   # Recursively call DFS for unvisited neighbors

    # return traversal_order

    ''' ( ITERATIVE DFS ) *** STACK IMPLEMENTATION ** '''
    visited = set()
    stack = [start_node]
    traversal_order = []

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            traversal_order.append(node)

            # Push neighbor's in reverse order if looking for the same order as recursive DFS
            for neighbor in reversed(graph[node]):
                if neighbor not in visited:
                    stack.append(neighbor)

    return traversal_order



# Example Usage:
if __name__ == "__main__":

    # Represent the graph using an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F'],
        'F': []
    }

    print("DFS Traversal: ", dfs(graph, 'A'))