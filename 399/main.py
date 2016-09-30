class Solution(object):

    def traverse(self, graph, a, b):
        if a not in graph or b not in graph:
            return -1.
        seen = set()
        queue = [(a, 1.)]
        while queue:
            x, c = queue.pop()
            if x in seen:
                continue
            seen.add(x)
            if x == b:
                return c
            for y, cost in graph[x]:
                queue.append((y, c * cost))
        return -1.

    def calcEquation(self, equations, values, queries):
        from collections import defaultdict
        graph = defaultdict(lambda: [])
        for (a, b), v in zip(equations, values):
            graph[a].append((b, v))
            graph[b].append((a, 1 / v))
        results = []
        for a, b in queries:
            results.append(self.traverse(graph, a, b))
        return results

