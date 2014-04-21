candidates = gets.chomp.to_i
candidates_max = gets.chomp.to_i

# Hard coded value of index of the 'o' in Eeny...
remove_pos = 15


mins = []
chiefs = []

# Candidate = Struct.new(:original_position, :)

#do once for every estimation
(candidates..candidates_max).each do |i|

  # Fill array with Xs denoting people
  positions = Array.new(i) { |x| x = 'X'}
  # puts "number of people #{i}"
  # print positions
  # gets

  pos = -1

  # Determine if someone is kicked out yet
  eeny = 0

  # The closest position to the big guy
  min_pos = i


  # While the chief hasn't been chosen
  while positions.count('X') != 1 do

    #If the position is one to be chosen
    if(eeny == 15)
      eeny = 0

      # If the position is empty move on until you find a person
      while positions[pos] == '_'
        # puts "Finding new pos, #{pos} was taken"
        pos = pos + 1
      end

      # puts "Current Pos: #{pos}"
      # Remove person found
      # print positions
      positions[pos] = '_'

      # If a new closest pos was found
      if(pos < min_pos && pos != 0)
        min_pos = pos
      end
    end

    # Loop around to front of circle
    if(pos + 1 >= positions.length)
        pos = 0
    else
      pos = pos + 1
    end

    eeny = eeny + 1
  end

  # puts "Min #{min_pos}"
  mins << min_pos
  # puts "Chief #{positions.index('X')}"
  chiefs << positions.index('X')

end

print mins
puts
print chiefs
puts

for x in mins
  puts "Checking #{x} in chiefs"
  if(chiefs.include?(x))
    puts x
    break
  end
end
