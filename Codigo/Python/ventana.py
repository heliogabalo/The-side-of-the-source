from Tkinter import *

class Interface:
    def __init__(self, contenedor):
        self.e1 = Label(contenedor, text = "my-etiqueta", fg = "black", bg = "white")
        self.e1.pack()

ventana = Tk()
miInterface = Interface(ventana) 
ventana.mainloop()

