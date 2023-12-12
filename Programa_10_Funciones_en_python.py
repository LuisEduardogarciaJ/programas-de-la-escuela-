#Garcia Junquera Luis Eduardo
#17/Septiembre/2021

precio = 50
#if precio > 50:
    #print("El precio es mayor que 50")   
if precio <50:   
    print("El precio es menor que 50")    
else:                               #no pueden llevar condicional  
    print("El precio es mayor a 50 ")

#
if total > 100:
    if total > 500:
        print("Total es mayor que 500")
    else:
        if total > 500 and total > 400:
            print("Total es menor que 500 pero mayor que 400")
        elif total <500 and total > 300:
            print("Total entre 300 y 500")
        else:
            print("Total entre 200 y 500")
elif total ==100:
    print("Total es 100")
else:
    print("Total menor que 100")


#ejemplo de while loop
num =0
while num < 5:     
    num = num +1
    print ('num =', num ) 



#
num = 0
while num < 5:
    num += 1    #num += 1 is same as nume  #TRADUCELO 
    if num >3:
           continue
    print('num =', num ) 


#
for char in 'Hello':
    print (char)

#
numNames = { 1:'one', 2: 'two', 3: 'tree'}
for prirn in numNames.items():
    print(prirn)


#for loop con el diccionario
for k,v in numNames.items():
  print("key =", k , ", value =", v)


# rango menor que 5
for i in range(5):
    print (i)