class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """
        if n == 0:
            return -1

        adj_list = dict()
        for source, dest, price in flights:
            if source in adj_list:
                adj_list[source].append((dest, price))
            else:
                adj_list[source] = [(dest,price)]
        cost = [float("inf") for i in range(n)]
        cost[src] = 0

        queue = [(src,0)]
        count = 0
        while (queue and count <= k):
            length = len(queue)
            for i in range(length):
                flight, cur_cost = queue.pop(0)
                if flight in adj_list:
                    for elem in adj_list[flight]:
                        dest, price = elem
                        new_price = price + cur_cost
                        if new_price < cost[dest]:
                            cost[dest] = new_price
                            queue.append((dest, new_price))
            count += 1
        if cost[dst] == float("inf"):
            return -1
        return cost[dst]



