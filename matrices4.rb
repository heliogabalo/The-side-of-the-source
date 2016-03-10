# -*- coding: utf-8 -*-

puts "Escribe lo que quieras:"
text = gets.chomp
puts "Escribe algo más"
redact = gets.chomp

words = text.split (" ")

words.each do |x|
   if x != redact
      print x + " "
   else
      print "REDACTED "
   end
end
