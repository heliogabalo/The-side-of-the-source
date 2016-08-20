# -*- coding: utf-8 -*-

strings = ["uno", "dos", "tres"]

symbols = []
strings.each do |x|
   symbols.push(x.to_sym)
end
puts symbols
