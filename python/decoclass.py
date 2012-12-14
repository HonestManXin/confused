#coding:utf-8

handlers = []

def route(url):
	global handlers
	def _(cls):
		print cls
		handlers.append((url,cls))
		return cls
	return _

@route("/pureman")
class Man(object):
	def __init__(self):
		pass

@route("/purewoman")
class Woman(object):
	def __init__(self):
		pass

print handlers

man = Man()
print man

def add3(func):
	def _(args):
		func(args+3)
	return _

@add3
def func(num):
	print num

func(2)

class Property(object):
	def __init__(self):
		self.data = -1

	#@property
	def value(self):
		return self.data

p = Property()
print p.value





