#!/usr/bin/ruby

# Head ends here
def next_move posr, posc, board
    closestY= board.length
    closestX= board[0].length\
    
    (0...board.length).each do |i|
        (0...board[0].length).each do |j|
            #puts "#{i}, #{j}"
            if board[i][j] == "d" then
                ydist = posr - i
                xdist = posc - j
                
                if ydist.abs < closestY then
                    closestY = ydist
                end
                
                if xdist.abs < closestX then
                    closestX = xdist
                end
                
            end
        end
    end
    
    puts "X:#{closestX}, Y:#{closestY}"
                       
    if closestX.abs < closestY.abs

        if closestX > 0 then
            puts "RIGHT"
        else
            puts "LEFT"
        end

    elseif closestY < closestX 

        if closestY > 0 then
            puts "DOWN"
        else
            puts "UP"
        end

    elseif closestY == 0 && closestX ==0
        puts "CLEAN"
    end
    
end

# Tail starts here
pos = gets.split.map {|i| i.to_i}
board = Array.new(5)

(0...5).each do |i|
    board[i] = gets.strip
end

puts next_move pos[0], pos[1], board