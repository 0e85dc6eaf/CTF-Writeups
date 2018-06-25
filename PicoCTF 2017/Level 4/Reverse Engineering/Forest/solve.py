#!/usr/bin/env python2
str = "yuoteavpxqgrlsdhwfjkzi_cmbn"
class Node:
	def __init__(self,letter):
		self.letter=letter
		self.left=None
		self.right=None
	def add(self,letter):
		if ord(letter) > ord(self.letter):
			if self.right == None:
				self.right = Node(letter)
			else:
				self.right.add(letter)
		else:
			if self.left == None:
				self.left = Node(letter)
			else:
				self.left.add(letter)
	def get(self,node):
		if node == "":
			return self.letter
		elif node[0] == 'L':
			return self.left.get(node[1:])
		elif node[0] == 'R':
			return self.right.get(node[1:])
		else:
			print "Oops! Something went wrong!"
			return None
class Tree:
	def __init__(self):
		self.root = None
	def add(self,letter):
		if self.root == None:
			self.root = Node(letter)
		else:
			self.root.add(letter)
	def get(self,node):
		return self.root.get(node)
tree = Tree()
for c in str:
	tree.add(c)
	
nodes = open("string.txt").read().strip().split('D')
password = "".join(tree.get(node) for node in nodes)
print password