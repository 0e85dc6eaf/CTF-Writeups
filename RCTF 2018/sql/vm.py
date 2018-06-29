#!/usr/bin/env python3
with open("dump.txt") as f:
	instructions = [i.split('|') for i in f.read().splitlines()]
	f.close()
class VM:
	def __init__(self,instructions):
		self.ins = instructions
		self.ni = 0
		self.running = True
		self.registers = [0 for i in range(128)]
		self.result = ['' for i in range(29)] 
		self.nextindex = 0
		self.opcodes = {
			'Trace':self.ignore,
			'Goto':self.goto,
			'Transaction':self.ignore,
			'VerifyCookie':self.ignore,
			'TableLock':self.ignore,
			'Integer':self.setRegister,
			'String8':self.setStrRegister,
			'OpenRead':self.ignore,
			'Rewind':self.ignore,
			'Column':self.ignore,
			'Function':self.function,
			'Ne':self.ne,
			'ResultRow':self.ignore,
			'Next':self.ignore,
			'Close':self.ignore,
			'Halt':self.kill
		}

	def ignore(self,*args):
		pass

	def goto(self,*args):
		self.ni = int(args[1])
		
	def setRegister(self,*args):
		self.registers[int(args[1])] = int(args[0])
	
	def setStrRegister(self,*args):
		self.registers[int(args[1])] = args[3]
		
	def kill(self,*args):
		self.running = False
		
	def function(self,*args):
		if args[3] == "substr(3)":
			self.nextindex = self.registers[int(args[1])+1]-1
		else:
			print("Unrecognized function")
	
	def ne(self,*args):
		self.result[self.nextindex] = self.registers[int(args[0])]
	
	def run(self):
		while self.running:
			i = self.ins[self.ni]
			self.ni += 1
			print("[%d] - %s"%(int(i[0]),i[1]))
			if i[1] not in self.opcodes:
				print("Unsupported instruction")
				break
			else:
				self.opcodes[i[1]](i[2],i[3],i[4],i[5])
		print("".join(self.result))

vm = VM(instructions)
vm.run()