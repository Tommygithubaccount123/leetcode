class Node():
    def __init__(self, key, val):
        self.prev = None
        self.next = None
        self.val = val
        self.key = key

class LRUCache(object):
    def __init__(self, capacity):
        self.storage = dict()
        self.capacity = capacity
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.head.prev = self.tail
        self.tail.next = self.head

    def remove(self, node):
        right = node.next
        left = node.prev
        right.prev = left
        left.next = right
    
    def insert(self, node):
        right = self.head
        left = self.head.prev
        node.next = right
        node.prev = left
        left.next = node
        right.prev = node

    def get(self, key):
        if key not in self.storage:
            return -1
        node = self.storage[key]
        self.remove(node)
        self.insert(node)
        return node.val

    def put(self, key, value):
        if key in self.storage:
            self.remove(self.storage[key])
        node = Node(key=key,val=value)
        self.insert(node)
        self.storage[key] = node
        if len(self.storage) > self.capacity:
            tail = self.tail.next
            self.remove(tail)
            del self.storage[tail.key]