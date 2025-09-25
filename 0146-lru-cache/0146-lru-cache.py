class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

# head <-> tail
# prev      next
class LRUCache:
    def __init__(self, capacity: int):
        self.storage = {}
        self.head = Node("dummyhead", "dummy")
        self.tail = Node("dummytail", "dummy")
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
    
    def insert(self, key, value):
        node = Node(key, value)
        head_next = self.head.next
        self.head.next = node
        head_next.prev = node
        node.next = head_next
        node.prev = self.head
        self.storage[key] = node
        self.capacity -= 1
    
    def delete(self, key):
        node = self.storage[key]
        node_next = node.next
        node_prev = node.prev
        node_next.prev = node_prev
        node_prev.next = node_next
    
        value = node.val
        del self.storage[key]
        del node
        self.capacity += 1
        return value
        
    def get(self, key: int) -> int:
        if key in self.storage:
            val = self.delete(key)
            self.insert(key, val)
            return self.storage[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.storage:
            self.delete(key)
        if self.capacity <= 0:
            self.delete(self.tail.prev.key)
        self.insert(key, value)
        
        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)