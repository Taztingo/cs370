#!/usr/bin/ruby

# Head ends here
def move_x dist
    if dist > 0 then
        return "LEFT"
    else
        return "RIGHT"
    end
end

def move_y dist
    if dist > 0 then
        return "UP"
    else
        return "DOWN"
    end
end

def next_move posr, posc, board
    closestY= board.length - 1
    closestX= board[0].length - 1
    
    (0...board.length).each do |i|
        (0...board[0].length).each do |j|
            #puts "#{i}, #{j}"
            puts board[i][j]
            if board[i][j].eql? 100 then
                ydist = posr - i
                xdist = posc - j

                puts "YDIST:#{ydist}, XDIST:#{xdist}"
                
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
    if closestY == 0 && closestX ==0
        return "CLEAN"
    elsif closestY == 0
        return move_x(closestX)
    elsif closestX == 0
        return move_y(closestY)
    else
        if closestX.abs < closestY.abs
            return move_x(closestX)
        elsif closestY.abs < closestX.abs
            return move_y(closestY)
        else
            return move_y(closestY)
        end
    end                           
end

# Tail starts here
pos = gets.split.map {|i| i.to_i}
board = Array.new(5)

(0...5).each do |i|
    board[i] = gets.strip
end

puts board

puts next_move pos[0], pos[1], board