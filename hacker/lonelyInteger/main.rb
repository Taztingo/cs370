#!/usr/bin/ruby

gets

numbers = gets.strip.split(" ").map { |i| i.to_i }

numbers.uniq.each do |i|
	if(numbers.count(i) == 1)
		puts i
	end
end