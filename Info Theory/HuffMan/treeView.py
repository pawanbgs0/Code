from graphviz import Digraph

# Example level order traversal of a tree
# level_order = [1, 2, 3, None, 4, 5, 6, None, None, 7, None, None, None, None, None]

# Open the file in read mode
with open('levelOrder.txt', 'r') as file:
    # Read the entire contents of the file
    contents = file.read()
    print(contents)

nodes = contents.split(",")
tree = []
for node in nodes:
    if node == "":
        continue
    elif node == "#":
        tree.append(None)
    else:
        tree.append(int(node))

level_order = tree

# Create a new Digraph object
dot = Digraph()

# Add the nodes to the graph
for i, val in enumerate(level_order):
    if val is not None:
        dot.node(str(i), str(val))

# Add the edges to the graph
i = 0
while i < len(level_order):
    if level_order[i] is not None:
        left_child = i * 2 + 1
        right_child = i * 2 + 2
        if left_child < len(level_order) and level_order[left_child] is not None:
            dot.edge(str(i), str(left_child))
        if right_child < len(level_order) and level_order[right_child] is not None:
            dot.edge(str(i), str(right_child))
    i += 1

# Render the graph
dot.render('tree', view=True)
