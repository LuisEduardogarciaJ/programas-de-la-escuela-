#Garcia Junquera Luis Eduardo
#20/septiembre/2021

def saludo ():
    """Esta función saluda """
    print('Quiubole!, ¿cómo estas?')

saludo()
salida = saludo()
print(salida)
help(saludo)


def salu2(nombre):
    """Esta funcion te saluda por tu nombre"""
    print("que onda ese,", nombre,"!")
salu2("Julian")
salu2("Luis")


def saludos (nombre:str):
    """ Esta funcion te saluda por tu nombre estrictamente"""
    print("Que onda ese", nombre, "!")
saludos("Julian")
a=123
saludos(a)
print(type(a))


def saludos_multiples(nombre_1,nombre_2,nombre_3):
    """Esta funcion saluda a 3 personas al mismo timpo"""
    print ("Hola",nombre_1,",",nombre_2,"y",nombre_3)
saludos_multiples("Hugo","Paco","Luis")


def muchos_saludos(*nombres):
    """Esta funcion saluda a todos los que quieras """
    i = 0
    print ("Hola ", end="")
    while len(nombres) > i:
      if (i==len(nombres)-1):
        print(nombres[i])
      else:
        print(nombres[i], end=", ")
      i+=1



muchos_saludos("Bosco", "Angel", "David", "Tamara", "Mili", "Edwin", "Lev", "Luis ", "Abigail")

def greet(firstname, lastname):
    print ('Hello', firstname, lastname)

greet(lastname='Jobs', firstname='Steve')#se puede especificar las variablos en desorden

    
def greet(**person):
    	  print('Hello ', person['firstname'],  person['lastname'])

greet(firstname='Steve', lastname='Jobs')
greet(lastname='Jobs', firstname='Steve')   #se puede pasar mas parametros de los necesarios
greet(firstname='Bill', lastname='Gates', age=55) 
# greet(firstname='Bill') # raises KeyError     #1.07

def greet(name = 'Guest'):
    print ('Hello', name)

greet()   #utiliza el valor dado de antemano
greet ('Steve')


#
def suma(a, b):
    return a + b
total=suma(5, suma(10, 20))
print(total)


#
x_al_cuadrado = lambda x : x * x
a = x_al_cuadrado(5)
print(a)


#
suma = lambda x1, x2, x3: x1+x2+x3
print(suma(99,98,97))

sumas = lambda *x: x[0]+x[1]+x[2]+x[3]

print(sumas(100,200,300,400))

print((lambda x: x*x)(6))  #función anonima

name = 'Steve'
def greet ():
  global name  #para utilizar una variable global (que viene de fuera del bloque)
  name = 'Bill'
  print('Hello', name)

greet()  










