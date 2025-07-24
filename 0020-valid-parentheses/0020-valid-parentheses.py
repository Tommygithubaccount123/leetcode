class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mapper = {"(":")", "{":"}", "[":"]"}
        queue = []
        for c in s:
            if c in mapper:
                queue.append(c)
            else:
                if not queue:
                    return False
                top = queue.pop()
                if mapper[top] != c:
                    return False
        if queue:
            return False
        return True


        