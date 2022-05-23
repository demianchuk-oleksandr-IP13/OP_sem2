import random
import math

class Number:
    def multiply(self, times):
        pass
    def divide(self, times):
        pass
    def findAbs(self):
        pass

class Rational(Number):
    def __init__(self, Re):
        self.real = Re
    def multiply(self, times):
        self.real *= times
    def divide(self, times):
        self.real /= times
    def findAbs(self):
        return math.sqrt(math.pow(self.real, 2))


class Complex(Number):
    def __init__(self, Re, Im):
        self.real = Re
        self.imaginary = Im
    def multiply(self, times):
        self.real *= times
        self.imaginary *= times
    def divide(self, times):
        self.real /= times
        self.imaginary /= times
    def findAbs(self):
        return math.sqrt(math.pow(self.real, 2) + math.pow(self.imaginary, 2))

def RatList(size):
    return [Rational(round(random.uniform(-100, 100), 3)) for i in range(size)]

def displayRat(Rat):
    for i in range(len(Rat)):
        x = round(Rat[i].real, 3)
        print(f"{i+1}) {x}")

def CompList(size):
    return [Complex(round(random.uniform(-100, 100), 3), round(random.uniform(-100, 100), 3)) for i in range(size)]

def displayComp(Comp):
    for i in range(len(Comp)):
        x = round(Comp[i].real, 3)
        y = round(Comp[i].imaginary, 3)
        print(f"{i+1}) {x} + {y}*i")

def changeRat(Rat):
    for i in range(len(Rat)):
        Rat[i].divide(2)

def changeComp(Comp):
    for i in range(len(Comp)):
        Comp[i].multiply(3)

def findSum(Rat, Comp):
    sum = 0
    for i in range(len(Rat)):
        sum += Rat[i].findAbs()
    for i in range(len(Comp)):
        sum += Comp[i].findAbs()
    return sum