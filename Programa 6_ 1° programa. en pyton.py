#Garcia Junquera Luis Eduardo
#08/septiembre/2021



#operaciones basicas
print (2+3)
print (2*3)
print(2/3)
#para saber el tipo de objeto usa type
t=0
type(t)  #entero
t=3.6
type(t)  #real (flotante)
t=True
type(t)   #booleano

#mensaje de pantalla
print("Este es un comando de python", "Este es otro enunciado", t)
print ('id:', 1)
print('First Name:', 'Steve')
print('Last name', 'Jobs')

#Continuar una instruccion en varios renglones
if 100 > 99 and \
    200<=300 and \
    True != False:
        print('Hello Word')

#Comandos diferentes en la misma linea
print("Hola "); print("tu")

#Usando parentesis redondos, cuadrados o llaves se puede escribir en varios -----
list = [1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12]
print(list)

#Identacion escrita para procesos dependientes de:
if 10>5:
  print ("diez es mayor que cinco")
  print("otra identación")
for i in list:
    print (i)
    print("ok")
if 10>5:
     print("verdadero")
     if 10<20:
       print("verdadero")
elif 5>3: #comienza segunda condición
    print("esto no se imprimira")

#Funciones
def say_hello(name):
    print("Hello",name)
    print("Welcome to python Tutorials")

say_hello("Luis")      #funciona de la misma manera
SayHello(1.3)


print(_36)




    

        





        
