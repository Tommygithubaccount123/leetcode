class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        storage = {}
        for prereq in prerequisites:
            a, b = prereq[0], prereq[1] 
            if a not in storage:
                storage[a] = [b]
            else:
                storage[a].append(b)
        
        visited = set()
        for course in range(numCourses):
            if not self.dfs(course, visited, storage):
                return False
        return True

    def dfs(self, start, visited, storage):
        if start not in storage or not storage[start]:
            return True
        if start in visited:
            return False
        visited.add(start)
        for b in storage[start]:
            if not self.dfs(b, visited, storage):
                return False
        storage[start] = []
        return True
        
        

