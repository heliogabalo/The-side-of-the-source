import sqlite3

def insertar():

    db1=sqlite3.connect('tabla.db')
    print("Estas en la funcion insertar")

    nombre1=raw_input("Escribe el titulo de la novela: ")
    autor1=raw_input("Escribe el autor de la novela: ")
    year1=str(input("Digita el any de la novela: "))

    consulta=db1.cursor()

    strConsulta = "insert into tabla(nombre, autor, year) values\
    ('"+nombre1+"','"+autor1+"','"+year1+"')"
    print(strConsulta)

    consulta.execute(strConsulta)
    consulta.close()
    db1.commit()
    db1.close()

def consultar():
    db2 = sqlite3.connect("tabla.db")
    print("Estas en la funcion insertar")
    db2.row_factory = sqlite3.Row
    consulta = db2.cursor()
    consulta.execute("select * from tabla")
    filas = consulta.fetchall()
    lista = []
    for fila in filas:
        s = {}
        s['nombre'] = fila['nombre']
        s['autor'] = fila['autor']
        s['year'] = str(fila['year'])
        lista.append(s)

    consulta.close()
    db2.close()
    return(lista)


#consultar()

def menu():
    Opcion= input("\nIngresa la opcion deseada\n1.Inserta un valor en la tabla\n2.Consultar los valores de la tabla\n")
    if Opcion==1:
        insertar()
        menu()
    elif Opcion==2:
        ListaNovelas = consultar()
        for novela in ListaNovelas:
            print(novela['nombre'],novela['autor'],novela['year'])
        menu()

menu()

