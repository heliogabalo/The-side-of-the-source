from Tkinter import *

class Interface:
    def __init__(self, contenedor):
        self.e1 = Label(contenedor, text = "my-etiqueta", fg = "black", bg = "white")
        self.e1.place(x = 20, y = 30, width = 120, height = 25)

ventana = Tk()
miInterface = Interface(ventana) 
ventana.mainloop()

