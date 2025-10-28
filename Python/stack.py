stack = []      # Create an empty stack

stack.append("C++")     # push
stack.append("java")
stack.append("Python")

print(stack.pop())      # pop -> 'Python'
print(stack[-1])        # peek -> 'Java'
print(len(stack))       # size -> 2
print(not stack)        # is_empty -> false