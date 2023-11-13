n = int(input("Enter the number of nodes: "))
graph = {}
for i in range(n):
  adj = list(map(int, input("Enter the adjacency list of node " + str(i) + ": ").split()))
  graph[i] = adj

start = int(input("Enter the starting node: "))
end = int(input("Enter the ending node: "))

# Start bfs
visited = [False] * n
queue = [start]
visited[start] = True
while len(queue) > 0:
  node = queue.pop(0)
  if node == end:
    print("Path exists")
    exit(0)
  for adj in graph[node]:
    if not visited[adj]:
      queue.append(adj)
      visited[adj] = True

print("Path does not exist")
