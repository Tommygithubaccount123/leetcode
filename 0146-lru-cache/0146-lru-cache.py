class Node():
    def __init__(self, key, val, left=None, right=None):
        self.key = key
        self.val = val
        self.left = left
        self.right = right

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.storage = dict()
        self.head = Node(None, None)
        self.tail = Node(None, None)
        self.head.left = self.tail
        self.tail.right = self.head

    def get(self, key: int) -> int:
        if key in self.storage:
            node = self.storage[key]
            self.remove(node)
            self.insert(node)
            return self.storage[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.storage:
            node = self.storage[key]
            self.remove(node)
        update_node = Node(key, value)
        self.insert(update_node)

    def remove(self, node):
        left = node.left
        right = node.right
        left.right = right
        right.left = left
        del self.storage[node.key]
    
    def insert(self, node):
        if len(self.storage) == self.capacity:
            self.remove(self.tail.right)

        left = self.head.left
        right = self.head
        node.left = left
        node.right = right
        self.head.left = node
        left.right = node
        self.storage[node.key] = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)