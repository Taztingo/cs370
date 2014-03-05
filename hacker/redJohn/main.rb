#!/usr/bin/ruby -w

def sieve_primes(n)
  num_iter = Integer(Math.sqrt(n)) #Number of times primes array will be sieved
  primes = (2..n).to_a #Array that will contain primes

  while num_iter > 1
    primes = primes.select do |e| 
      (((e % num_iter) != 0) or (e == num_iter))
    end
    num_iter -= 1
  end

  return primes
end

bricks = Array.new(41, 1)

(4..41).each do |i|
  bricks[i] = bricks[i - 1] + bricks[i - 4]
end

n = Integer(gets.chomp)

i = 0
while i < n
  puts sieve_primes(bricks[Integer(gets.chomp)]).length
  i += 1
end