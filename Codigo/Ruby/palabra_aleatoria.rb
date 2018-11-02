# -*- coding: utf-8 -*-

def palabra_aleatoria
    letters = { ?v => 'aeiou',
                ?c => 'bcdfghjklmnprstvwyz' }
    word = ''
    'cvcvcvcvc'.each_byte do |x|
     source = letters[x]
     word << source[rand(source.length)].chr
    end
    return word
end
