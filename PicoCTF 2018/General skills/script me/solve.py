#!/usr/bin/env python2
from pwn import *
from sys import exit
MODE_OUT = 0
MODE_IN = 1
class ComponentError(Exception):
	pass
class ImplicitComponent:
	def __init__(self,value=""):
		self.components = []
		self.range = 0
		self.length = 0
		self.parse(value)
	def parse(self,value):
		ctr = 0
		while ctr<len(value):
			if value[ctr] not in "()":
				raise ComponentError("Unexpected character in data")	
			if value[ctr]==")":
				raise ComponentError("Unexpected closing bracket")
			elif value[ctr]=="(":
				tmp = Component(value[ctr:])
				self.components.append(tmp)
				ctr += tmp.length
				if tmp.range >= self.range:
					self.range = tmp.range+1
		if ctr != len(value):
			raise ComponentError("Data length is invalid")
		self.length = ctr
	def dump(self):
		text = ""
		for c in self.components:
			text+="(%s)"%(c.dump())
		if len(text)!=self.length:
			raise ComponentError("It seems data was not correctly dumped")
		return text
	def add(self,c):
		if not isinstance(c,ImplicitComponent):
			raise TypeError("Expected ImplicitComponent in Component::add")
		if len(self.components)==0:
			return c
		if self.range==c.range:
			self.components += c.components
			self.length += c.length
		elif self.range>c.range:
			self.components[-1].components += c.components
			self.components[-1].length += c.length
			self.length += c.length
		else:
			c.components[0].components = self.components + c.components[0].components
			c.components[0].length += self.length
			c.length += self.length
			return c
		return self
	
class Component:
	def __init__(self,value):
		self.components = []
		self.range = 0
		self.length = 0
		self.parse(value)
	def parse(self,value):
		ctr = 0
		mode = MODE_OUT
		while ctr<len(value):
			if MODE_OUT == mode:	
				if value[ctr]!="(":
					raise ComponentError("Unexpected char")
				elif value[ctr]=="(":
					mode = MODE_IN
					ctr += 1
			elif MODE_IN == mode:
				if value[ctr]==")":
					mode = MODE_OUT
					ctr += 1
					break
				elif value[ctr]=="(":
					tmp = Component(value[ctr:])
					self.components.append(tmp)
					ctr += tmp.length
					if tmp.range >= self.range:
						self.range = tmp.range+1
		self.length = ctr
	def append(self,c):
		if not isinstance(c,Component):
			raise TypeError("Expected Component in Component::append")
		self.components.append(c)
	def dump(self):
		text = ""
		for c in self.components:
			text+="(%s)"%(c.dump())
		return text

def solve(challenge):
	components = [x.strip() for x in challenge.split("=")[0].split("+")]
	result = ImplicitComponent()
	try:
		for c in components:
			result = result.add(ImplicitComponent(c))
		print(result.dump())
		return result.dump()
	except ComponentError as e:
		print("ComponentError: %s"%e)
		exit(1)
	except TypeError as e:
		print("TypeError: %s"%e)
		exit(1)
		
r = remote("2018shell1.picoctf.com", 8672)
r.recvuntil("Let's start with a warmup.")
r.recvline()
r.sendline(solve(r.recvline()))
r.recvuntil("Okay, now we're cookin!")
r.recvline()
r.sendline(solve(r.recvline()))
r.recvuntil("Alright see if you can get this one.")
r.recvline()
r.sendline(solve(r.recvline()))
r.recvuntil("This one's a little bigger!")
r.recvline()
r.sendline(solve(r.recvline()))
r.recvuntil("Ha. No more messin around. Final Round.")
r.recvline()
r.sendline(solve(r.recvline()))
print(r.recvall())
r.close()
"""
Rules:
() + () = ()()                                      => [combine]
((())) + () = ((())())                              => [absorb-right]
() + ((())) = (()(()))                              => [absorb-left]
(())(()) + () = (())(()())                          => [combined-absorb-right]
() + (())(()) = (()())(())                          => [combined-absorb-left]
(())(()) + ((())) = ((())(())(()))                  => [absorb-combined-right]
((())) + (())(()) = ((())(())(()))                  => [absorb-combined-left]
() + (()) + ((())) = (()()) + ((())) = ((()())(())) => [left-associative]
"""