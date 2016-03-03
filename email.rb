# -*- coding: utf-8 -*-

class Computer
        @@users = {}
        def initialize(username, password)
           @username = username
           @password = password
           @@users[username] = password
           @files = {}
        end
        
        def create(filename)
            time = Time.now
            @files[filename] = time
            puts "#{filename} fue creado por #{username} en #{time}"
            def Computer.get_users
               @@users
            end                    
      end

my_computer = Computer.new("helio", 12345)
	
