#Garcia Junquera Luis Eduardo
#13/sep/21


miprimeralista = []
print(miprimeralista)

#Segunda lista donde tambiens se puede agregar pasabras, funciones y números
miprimeralista = ["Javier", 1.34,"Bosco","Angel","Abigail", True]
print(miprimeralista)
nums = list#(range(1,61))#Sirve para hacer una lista sin necisidad de escribir todos
for i in nums:
    print(i)    #hacer la lista de forma vertical
nums.append(61)    #sirve para poner el numero hasta el final
print(nums)
nums.remove(61)    #para remover algun numero de la lista 
del nums   #borrar todo el arreglo(lista)

#Nueva lista 
L1 = [1,2,3]
L2 = [4,5,6]    #Sirve para añadir una lista a la otra
print(L1+L2)


#Ejercicio con las listas
potencial = []
for i in range (0,10000):
    potencial.append(float(i))    
print(potencial[100])   #para imprimir solo hasta el 100
potencia = tuple(potencial)
print(potencia[100])








