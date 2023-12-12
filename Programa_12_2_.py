#------------------
#Una clase para un objeto vacio 
#--------------------
class ObjetoVacio:
    pass
nada = ObjetoVacio()

#------------------------
print(nada)     #darle lo que sera el objeto
#-------------------------

class Llanta:
    cuenta = 0
    #metodo constructor de identidad
    def __init__(self,radio=50,ancho=30,presion=1.5):   #se necisita un constructor (de mi mismo)
      Llanta.cuenta+= 1      #ENVES DE SELF ESCRIBIMOS MI(puede ser cualquiera) Y FUNCIONA YA que no es una palabra clave
      self.radio = radio #= 50 #cm
      self.ancho = ancho#= 30 #cm       variables propias para cada objeto
      self.presion =presion #= 1.5 #atm

class Coche:
    pass
llanta1 = Llanta(50,30,1.5)
llanta2 = Llanta(50,30,1.5)
llanta3 = Llanta()
llanta4 = Llanta(50,30,1.6)
print(Llanta.cuenta)  #Variable global de la clase
print(llanta4.presion)  #presion de la llanta 4
#se tiene que saber primero los objetos para poder llamarlos
print(llanta4.radio)
print(llanta3.radio)


#EJEMPLO DE ESTUDIANTE
#Uso de la funcion python PROPERTY para poner y obtener atributos
class Student:
    def __int__(self):
        self.__name=''
    def setname(self, name):
        print('setname() fue llamada')
        self.__name=name
    def getname(self):
        print('getname() fue llamada')
        return self.__name
    name=property(getname,setname)

std =Student()
std.name = "Diego"
print(std.name)


#HERENCIA
class Cuadrilatero:
    def __init__(self, a, b, c, d):
        self.side1=a
        self.side2=b
        self.side3=c
        self.side4=d

    def perimetro(self):
        p=self.side1 + self.side2 + self.side3 + self.side4
        print("perimetro=",p)
        return p

class Rectangulo(Cuadrilatero):
    def __init__(self, a,b):
        super().__init__(a, b, a, b)
    

class Cuadrado(Rectangulo):
    def __int__(self, a):
        super().__init__(a,a)

    def area(self):
      area = pow(self.side1,2)
      return area

cuadrado1 = Cuadrado(5)
perimetro1 = cuadrado1.perimetro()
area1 = cuadrado1.area()

print(perimetro1)
print(area)







