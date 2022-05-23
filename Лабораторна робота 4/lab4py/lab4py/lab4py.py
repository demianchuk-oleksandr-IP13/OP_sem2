from func import*

m = int(input("enter size: "))
n = int(input("enter size: "))
arrR = RatList(m);
arrC = CompList(n);
print(m, "rational numbers: ")
displayRat(arrR);
print(n, "complex numbers: ")
displayComp(arrC);
print("rational divided by 2:")
changeRat(arrR)
displayRat(arrR)
print("complex multiplied by 3: ")
changeComp(arrC)
displayComp(arrC)
print("the sum of abs equals", findSum(arrR, arrC))