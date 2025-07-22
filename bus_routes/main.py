from collections import deque

def numBusesToDestination(graph, start, target):
    if start == target:
        return 0

    # construir grafo a partir da matriz
    # quais paradas preciso pegar a partir desse onibus
    stop_route = {}
    for bus, route in enumerate(graph):
        for stop in route:
            if stop not in stop_route:
                stop_route[stop] = []
            stop_route[stop].append(bus)

    # stop_route = {1: [0], 2: [0], 7: [0, 1], 3: [1], 6: [1]}

    if start not in stop_route or target not in stop_route:
        return -1

    queue = deque()
    visited_stops = set()
    visited_bus = set()


    queue.append((start, 0))  # (no inicial, onibus zero)
    visited_stops.add(start)

    while queue:
        stop, steps = queue.popleft()

        for bus in stop_route.get(stop): # aqui eh feito a verificacao entre os dois onibus, ou seja para o caso 7 (for bus in [0,1])
            if bus in visited_bus:
                continue
            visited_bus.add(bus)

            for next_stop in graph[bus]:
                if next_stop == target:
                    return steps + 1

                if next_stop not in visited_stops:
                    visited_stops.add(next_stop)
                    queue.append((next_stop, steps + 1))

    return -1


routes = [[1,2,7],[3,6,7]]
source = 8
target = 6


print(numBusesToDestination(routes, source, target))

