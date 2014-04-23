# SPOJ 1699 - Numeral System
# Problem code: NSYSTEM

# Define a custom String function to determine if its a number
class String
  def is_number?
    true if Float(self) rescue false
  end
end

class Fixnum
  def is_number?
    true
  end
end

# Translates MCXI base letters into their values, and values into letters
def translate_base(mcxi_base)
  if(!mcxi_base.is_number?)
    case mcxi_base
    when 'm'
      1000
    when 'c'
      100
    when 'x'
      10
    when 'i'
      1
    else
      warn 'Invalid character'
      nil
    end
  else
    case mcxi_base
    when 1000
      'm'
    when 100
      'c'
    when 10
      'x'
    when 1
      'i'
    else
      warn 'Invalid character'
      nil
    end
  end
end

# Translate integer to mcxi
def i_to_mcxi(i)
  number = i

  result_string = ''

  # Initial base
  base = 1000

  while(base > number)
    base /= 10
  end

  # Will count down by factors of 10 checking every base
  while(base != 0)
    # Start accumulator
    accumulator = 0

    # Store prefix to come before base
    prefix = 0

    # accumulator is incremented as it approached the target number
    # When accumulator >= number then that is the biggest number that
    # can be represented by that base
    while(accumulator + base <= number)
      prefix = prefix + 1
      accumulator = accumulator + base
    end

    # No prefixes of 0 or 1
    if(prefix > 1)
      result_string << (prefix).to_s
    end

    # If accumulator is 0, there was no digit in that place in the original number
    # Therefore
    if(accumulator != 0)
      result_string << translate_base(base)
    end

    number -= accumulator
    base = base / 10
  end

  result_string

end

# Translate mcxi to integer
def mcxi_to_i(mcxi)

  word = mcxi

  prefix = 1
  result = 0

  # Go through the word one by one and determine what value each digit has
  (0..word.length-1).each do |i|

    digit = word[i]

    # Checks for number
    if(digit.is_number?)
      digit = digit.to_i
    end

    case digit
    # Letter Checking
    when 'a'..'z'
      # Increment result by the value of the letter found multiplied by prefix
      result += translate_base(digit) * prefix
      # Reset prefix
      prefix = 1
    when 2..9
      prefix = digit
    else
      puts "What the fuck is this: #{digit}"
    end
  end

  result

end

# Tests
# puts mcxi_to_i('6m2c4i')
# puts mcxi_to_i('6mi')
# puts mcxi_to_i('i')
# puts mcxi_to_i('2mci')
# puts mcxi_to_i('9xi')
# puts
# puts i_to_mcxi(6204)
# puts i_to_mcxi(624)
# puts i_to_mcxi(4)
# puts i_to_mcxi(3104)
# puts i_to_mcxi(104)
# puts i_to_mcxi(194)
# puts i_to_mcxi(30)

num_inputs = gets.to_i

(0..num_inputs - 1).each do
  inputs = gets.split(' ')
  results = mcxi_to_i(inputs[0]).to_i + mcxi_to_i(inputs[1]).to_i
  puts i_to_mcxi(results)
end
