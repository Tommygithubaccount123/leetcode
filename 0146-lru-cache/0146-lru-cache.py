class Node():
    def __init__(self, val, left, right, key):
        self.val = val
        self.left = left
        self.right = right
        self.key = key

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cur_capacity = 0
        self.storage = {}

        self.tail = Node(None, None, None, None)
        self.head = Node(None, None, None, None)
        self.tail.right = self.head
        self.head.left = self.tail

    def insert(self, node):
        left = self.head.left
        right = self.head
        left.right = node
        right.left = node
        node.left = left
        node.right = right
        self.cur_capacity += 1
        self.storage[node.key] = node
    
    def remove(self, node):
        left = node.left
        right = node.right
        right.left = left
        left.right = right
        self.cur_capacity -= 1
        del self.storage[node.key]

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.storage:
            return -1
        node = self.storage[key]
        self.remove(node)
        self.insert(node)
        return node.val
        
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        new_node = Node(value, None, None, key)
        if key not in self.storage:
            self.insert(new_node)
            if self.cur_capacity > self.capacity:
                self.remove(self.tail.right)
            return
        node = self.storage[key]
        self.remove(node)
        self.insert(new_node)
        self.storage[key] = new_node
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)