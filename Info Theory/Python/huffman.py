import heapq #minHeap

class Node:
    def __init__(self, symbol, freq):
        self.freq = freq
        self.symbol = symbol
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


class Huffman:
    def __init__(self, inputText):
        self.inputText = inputText
        self.freqMap = {}
        self.codeMap = {}
        self.root = None
        
    def setInput(self, inputText):
        self.inputText = inputText

    def takeInput(self):
        self.inputText = input("Enter the text: ")
        # print(self.inputText) #debug

    def calcCharFreq(self):
        for character in self.inputText:
            if character not in self.freqMap:
                self.freqMap[character] = 1
            else:
                self.freqMap[character] += 1

        # print(self.freqMap) #debug

    def buildTree(self):
        heap = []
        for symbol, freq in self.freqMap.items():
            node = Node(symbol, freq)
            heapq.heappush(heap, node)

        # print(heap[0].symbol)  # Debugging line
        while (len(heap) > 1):
            node1 = heapq.heappop(heap)
            node2 = heapq.heappop(heap)

            parent = Node('$', node1.freq + node2.freq)
            parent.left = node1
            parent.right = node2

            heapq.heappush(heap, parent)

        self.root = heap[0]

    def generateCodeHelper(self, TreeRoot, code):
        if TreeRoot is None:
            return
        
        if TreeRoot.left is None and TreeRoot.right is None:
            print("{} -> {}".format(TreeRoot.symbol, code))
            self.codeMap[TreeRoot.symbol] = code

        self.generateCodeHelper(TreeRoot.left, code + '0')
        self.generateCodeHelper(TreeRoot.right, code + '1')

    def huff(self):
        self.takeInput()
        self.calcCharFreq()
        self.buildTree()
        self.generateCodeHelper(self.root, "")
        res = ""
        for i in self.inputText:
            res += self.codeMap[i]

        return res
    
    def deHuff(self, huffed):
        res = ""
        curr = self.root

        for i in huffed:
            if curr.left is None and curr.right is None:
                res += curr.symbol
                curr = self.root

            if i == '0':
                curr = curr.left

            elif i == '1':
                curr = curr.right

            else:
                print("Invalid Huffed")
                return ""
            
        # Add the last character in the tree
        if curr.left is None and curr.right is None:
            res += curr.symbol
            
        return res

# h = Huffman()
# huffed = h.huff()
# print(huffed)
# dehuffed = h.deHuff(huffed)
# print(dehuffed)
