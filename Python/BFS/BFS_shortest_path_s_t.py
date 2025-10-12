from collections import deque

def bfs_shortest_path(graph, s, t):
    """
    Returns the shortest path (as a list of nodes) from s to t in an unweighted graph,
    or None if t is unreachable from s.
    """
    if s == t:
        return [s]

    visited = {s}
    parent = {s: None}
    q = deque([s])

    while q:
        u = q.popleft()
        for v in graph.get(u, []):
            if v not in visited:
                visited.add(v)
                parent[v] = u
                if v == t:
                    # Reconstruct path s -> ... -> t
                    path = [t]
                    cur = t
                    while parent[cur] is not None:
                        cur = parent[cur]
                        path.append(cur)
                    path.reverse()
                    return path
                q.append(v)

    return None  # no path


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

    path = bfs_shortest_path(graph, 'A', 'F')
    print(path)
