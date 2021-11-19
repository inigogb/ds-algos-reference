from abc import ABC, abstractmethod



class BaseNode:

    @abstractmethod
    def value():
        ...

    @abstractmethod
    def next():
        ...

class NullNode(BaseNode):

    def value(self):
        return None
    
    def next(self):
        return None

class Node(BaseNode):

    def __init__(self, value):

        self._value = value
        self._next = None

    def value(self):
        return self._value

    def next(self):
        return self._next

class Stack():

    def __init__(self):
        self.head = None

    def push(self, node):
        if self.head == None:
            self.head = node
        else:
            tmp = self.head
            node.next = tmp
            head = node

    def peek(self):
        if self.head == None:
            return NullNode()
        else:
            return self.head
    
    def pop(self):
        if self.head == None:
            return NullNode()
        else:
            tmp = self.head
            self.head = tmp.next()
            return tmp



myStack = Stack()

print(f'CASE 1: {myStack.peek().value()}')
myStack.push(Node(5))
print(f"CASE 2: {myStack.peek().value()}")
print(f"CASE 3: {myStack.pop().value()}")
print(f"CASE 4: {myStack.pop().value()}")






