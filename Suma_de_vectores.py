#Suma de vectores en python

#Garcia Junquera Luis Eduardo 2AV1

# 01/Octubre/2021

import numpy as np 
       
# Vectores
arr = [[14, 17, 12, 33, 44],   
       [15, 6, 27, 8, 19],        #Se puede cambiar los vectores por cualesquiera.
       [23, 2, 54, 1, 4,]]  

 #Suma de los vectores  
print("\nSum of arr : ", np.sum(arr)) 
print("Sum of arr(axis = 0) : ", np.sum(arr, axis = 0)) 
print("Sum of arr(axis = 1) : ", np.sum(arr, axis = 1))
  
 #Salida de los vectores 
print("\nSum of arr (keepdimension is True): \n",
      np.sum(arr, axis = 1, keepdims = True))

#-------------------------------------------------
#Programa 2
#Suma de vectores en python

#Garcia Junquera Luis Eduardo 2AV1

# 01/Octubre/2021

import random

n=int(input("Ingresa el valor de n:  "))

vect1 = [None] * n
vect2 = [None] * n
vect3 = [None] * n

for i in range(0,n):
  vect1[i] = (int)(random.randint(1,1001))
  vect2[i] = (int)(random.randint(1,1001))

for i in range(0,n):
  vect3[i] = vect1[i] + vect2[i]

print("Vector 1")
print(vect1)

print("Vector 2")
print(vect2)

print("Vector suma")
print(vect3)




