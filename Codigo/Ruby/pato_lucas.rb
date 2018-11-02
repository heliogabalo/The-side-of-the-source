# -*- coding: utf-8 -*-

print "¡Ztring, por favor!: "
datos_usuario = (gets.chomp)
datos_usuario.downcase!

if datos_usuario.include? "s"
   datos_usuario.gsub!(/s/, "z")

else
   puts puts "¡No hay nada que hacer aquí!"
end

puts "Tu estring es: #{datos_usuario}"
