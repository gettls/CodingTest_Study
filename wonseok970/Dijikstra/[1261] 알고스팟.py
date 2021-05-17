import heapq
from collections import deque

m, n = map(int, input().split())
graph = []

for i in range(n):
    graph.append(list(map(int, input())))

# (n,m) 으로 이동하기 위해서?
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
wall = [[-1] * m for _ in range(n)]
wall[0][0] = 0


def bfs(x, y):
    q = deque()
    q.append((x, y))

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx <= -1 or nx >= n or ny <= -1 or ny >= m:
                continue
            # 벽을 만났을 때
            if wall[nx][ny] == -1:
                if graph[nx][ny] == 0:
                    wall[nx][ny] = wall[x][y]
                    q.appendleft((nx, ny))
                elif graph[nx][ny] == 1:
                    wall[nx][ny] = wall[x][y] + 1
                    q.append((nx, ny))
    return wall[n - 1][m - 1]


print(bfs(0, 0))