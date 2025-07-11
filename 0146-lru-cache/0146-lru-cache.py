class Node():
    def __init__(self, key, val, prev=None, next=None,):
        self.prev = prev
        self.next = next
        self.val = val
        self.key = key

class LRUCache(object):

    def __init__(self, capacity):
        self.storage = dict()
        self.capacity = capacity
        self.head = None
        self.tail = None
        
    def printList(self):
        node = self.tail
        while(node):
            print(node.key)
            node = node.next
        node = self.head

    def get(self, key):
        if key not in self.storage:
            return -1
        node = self.storage[key]
        self.update(node)
        print("AFTER GET " + str(key))
        # self.printList()
        return node.val

    # Make node most recently used
    def update(self, node):
        # if head was updated, do nothing
        if node == self.head:
            return

        # if node was tail
        if node == self.tail:
            if node.next:
                self.tail = node.next

        # connect neighbors
        if node.prev:
            left = node.prev
            if node.next:
                right = node.next
                left.next = right
                right.prev = left
            else:
                left.next = None
        else:
            if node.next:
                right = node.next
                right.prev = None

        # set node to head
        if self.head:
            old_head = self.head
            old_head.next = node
            node.prev = old_head
            self.head = node
            node.next = None
        else:
            self.head = node
        # print("AFTER UPDATE " + str(node.key))
        # self.printList()

    def put(self, key, value):
        node = None
        if key in self.storage:
            node = self.storage[key]
            node.val = value
            self.update(node)
            return

        node = Node(key=key,val=value)
        self.storage[key] = node
        self.update(node)
        # if first node inserted
        if len(self.storage) == 1:
            self.tail = node
            # self.head = node
                    
        if len(self.storage) > self.capacity:
            # delete tail
            old_tail = self.tail
            if old_tail.next:
                right = old_tail.next
                right.prev = None
                del self.storage[old_tail.key]
                print("DELETED", old_tail.key)
                del old_tail
                self.tail = right
        print("AFTER PUT " + str(key))
        # self.printList()
        
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)