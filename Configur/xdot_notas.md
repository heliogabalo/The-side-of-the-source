Buscamos la aplicación asociando su pid con el id de ventana:

  ~~~  
  $ xdotool search --pid _number_  -- busca por pid  
  $ xdotool  search --class app getwindowpid %@ -- busca por window Id  
  $ xdotool search --name app -- consulta por nombre(app)  
  $ xdotool windowfocus id-ventana  
  ~~~  


 
