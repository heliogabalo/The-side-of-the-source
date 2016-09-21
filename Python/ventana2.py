from Tkinter import *

class Interface:
    def __init__(self, contenedor):
        self.e1 = Label(contenedor, text = "my-etiqueta", fg = "black", bg = "white")
        self.e2 = Label(contenedor, text = "my-etiqueta2", fg = "black", bg = "gray")
        self.e3 = Label(contenedor, text = "my-etiqueta3", fg = "black", bg = "green")
        self.e4 = Label(contenedor, text = "my-etiqueta3", fg = "black", bg = "blue")
        self.e5 = Label(contenedor, text = "my-etiqueta3", fg = "black", bg = "yellow")
        self.e6 = Label(contenedor, text = "my-etiqueta3", fg = "black", bg = "red")

        self.e1.grid(column=0,row=0)
        self.e2.grid(column=0,row=1)
        self.e3.grid(column=0,row=2)
        self.e4.grid(column=1,row=0)
        self.e5.grid(column=1,row=1)
        self.e6.grid(column=1,row=2)

ventana = Tk()
miInterface = Interface(ventana) 
ventana.mainloop()

