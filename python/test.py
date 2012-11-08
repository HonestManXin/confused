#-*- coding="utf-8" -*-

class parent(object):
    def get(self):
        print "parent get called"


class son(parent):
    def get(self):
        print "son get called"

if __name__ == "__main__":
    s = son()
    s.get()

