# -*- coding: utf-8 -*-


puts "dime argo pallo"
text = gets.chomp

words = text.split(" ")
frequencies = Hash.new(0)
words.each do |x|
   frequencies[x] += 1
end
frequencies = frequencies.sort_by {|a, b| b}
frequencies.reverse!
frequencies.each do |x, a|
   puts x + " " + a.to_s
end
