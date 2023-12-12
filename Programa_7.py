#Garcia Junquera Luis Eduardo
#10/septiembre/2021


#Inpu permite obtener datos del usuario en prompter
nombre = input("Dame tu nombre:        ")
print("Hola cómo estás",nombre)

#Los enteros son de precisión ilimitada
y = 50000000000000000000000000
print (y)

#La función int()cambia strings y floats a enteros
numero = int(input("Dame tu edad:  "))
type(numero)

#la notación cientifica de flotantes utiliza  e o E
#1.2 * 10^(-9)
y = 1.2E-09
print(y)


#la función float()convierte strings y enteros a floats
y = float("14.3")
print(y)

#los complejos se escriben con la raiz de menos 1 con un numero como prefijo
z = 1+1j
#suma +
#resta -
#multiplicacion *
#division /
#modulos %
#exponente ""
#  // funcion piso 
#funciones para transformar numeros int(), float() complax()
#operaciones abs() round() bow()


#Strings de varias lineas
parrafo =""" En el bosque de la china 
la chinita se perdio"""
print(parrafo)

#la función len() obtiene el tamaño del string
n=len(parrafo)
print(n)


#|Las letras en un string ocupan lugares como en un arreglo (tambien de atras
#para adelante comenzando en -1(el ultimo))
palabra = "hola"
print(palabra[0])
print(palabra[-4])


