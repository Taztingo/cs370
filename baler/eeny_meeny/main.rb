candidates = gets.chomp.to_i
remove_pos = gets.chomp.to_i

# Fill array with Xs denoting people
positions = Array.new(candidates) { |x| x = 'X'}

# Increment at which people are removed
pos = remove_pos

# The closest position to the big guy
min_pos = candidates

# While the chief hasn't been chosen
while positions.count('X') != 1 do

  #If the position is one to be chosen
  if(pos % remove_pos == 0)

    # If the position is empty move on until you find a person
    while positions[pos] == '_'
      pos = pos + 1
    end

    puts pos
    # Remove person found
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
end

puts min_pos