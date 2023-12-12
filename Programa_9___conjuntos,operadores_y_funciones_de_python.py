#Garcia Junquera Luis Eduardo
#15/septiembre/2021


even_nums = {2, 4, 6, 8, 10}  #conjunto de numeros pares
                             #{even es par, emp es impar}
emp = {1, 'Steve',10.5, True }

#Conjunto de elementos distintos
nums = {1, 2, 2, 3, 4, 4, 5, 5}
print (nums)

#Establecer elementos del conjunto
s = set('Hello') #convierte string en tupla
print (s)

s = set ((1,2,3,4,5))  #convierte tuple a set
print (s)

d ={1:'One' , 2: 'Two'}
s = set(d)  #convierte dict a set
print (s)

s.add(100)    #crea un ampty set
print (s)
s1={1,2,3,4,5}
s2={4,5,6,7,8}
su = s1|s2
print (su)

si = s1&s2
print(si)
sr = s2-s1
print (sr)
ss = s1^s2 
print (ss)     



#diccionario
capitals = {"USA":"Washington D.C.", "France":"Paris", "India":"New Delhi"}
print (capitals)
  # Objetos de diccionario
d = {} # empty dictionary

numNames={1:"One", 2: "Two", 3:"Three"} # int key, string value

decNames={1.5:"One and Half", 2.5: "Two and Half", 3.5:"Three and Half"} # float key, string value

items={("Parker","Reynolds","Camlin"):"pen", ("LG","Whirlpool","Samsung"): "Refrigerator"} # tuple key, string value

romanNums = {'I':1, 'II':2, 'III':3, 'IV':4, 'V':5} # string key, int value


print (romanNums)
print(romanNums["I"])
print(capitals.get("India"))
print(capitals.get("india"))



 #Diccionario de acceso mediante For Loop

for k in capitals:
    print("Key = " + k + ", Value = " + capitals[k])
capitals["México"] = "CDMX"     #para agragar en la lista de capitales
print (capitals)
del capitals ["México"]     #borrara elementos de capítals
print(capitals)
del capitals   #borra todo de capitals

print(romanNums.keys())
print (romanNums.values())
print ("I" in romanNums)
print ("X" in romanNums)
print ("XX" in romanNums)    #imprime los numeros romanos








