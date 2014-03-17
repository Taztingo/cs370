#!/usr/bin/ruby

# Head ends here


def next_move posr, posc, board
  closest_node = Array.new(3)
  closest_node[0] = 10
  closest_node[1] = 10
  closest_node[2] = closest_node[0] + closest_node[1]

  (0...5).each do |y|
    (0...5).each do |x|
      if board[y][x].eql? "d" then
        x_dist = posc - x
        y_dist = posr - y

        #warn "#{x_dist}, #{y_dist}"

        if(closest_node[2] > (x_dist.abs + y_dist.abs)) then
          closest_node[0] = x_dist
          closest_node[1] = y_dist
          closest_node[2] = closest_node[0].abs + closest_node[1].abs
        end
      end
    end
  end

  warn "#{closest_node[0]},#{closest_node[1]},#{closest_node[2]}"

  if (closest_node[0] < 0)
    puts "RIGHT"
  elsif (closest_node[0] > 0)
    puts "LEFT"
  elsif (closest_node[1] < 0)
    puts "DOWN"
  elsif (closest_node[1] > 0)
    puts "UP"
  else
    puts"CLEAN"
  end

end

# Tail starts here
pos = gets.split.map {|i| i.to_i}
board = Array.new(5)

(0...5).each do |i|
board[i] = gets.strip
end

# puts board

puts next_move pos[0], pos[1], board
