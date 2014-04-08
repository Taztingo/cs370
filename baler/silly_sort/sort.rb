gets

input = gets.split(" ").map { |x| x.to_i}

swaps = {0 => 0}

def swap(pos1, pos2, nums)
  nums[pos1] = nums[pos1] ^ nums[pos2]
  nums[pos2] = nums[pos2] ^ nums[pos1]
  nums[pos1] = nums[pos1] ^ nums[pos2]

  return nums
   
end

input.each do |x|
  input.each do |y|
    
    if x > y and input.index(x) < input.index(y) then
      if not swaps.has_key?(x)
        swaps[input.index(x)] = input.index(y)
      end
    end
  end
end

swaps.each do |x|
  swap x, swaps[x], input
end

puts input
