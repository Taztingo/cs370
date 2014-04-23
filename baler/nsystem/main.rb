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
      return 1000
    when 'c'
      return 100
    when 'x'
      return 10
    when 'i'
      return 1
    else
      warn 'Invalid character'
      return nil
    end
  else
    case mcxi_base
    when 1000
      return 'm'
    when 100
      return 'c'
    when 10
      return 'x'
    when 1
      return 'i'
    else
      warn 'Invalid character'
      return nil
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
    accumulator = 0

    # Store prefix to come before base
    prefix = 0


    while(accumulator + base <= number)
      prefix = prefix + 1
      accumulator = accumulator + base
    end

    if(prefix > 1)
      result_string << (prefix).to_s
    end

    if(accumulator != 0)
      result_string << translate_base(base)
    end

    number -= accumulator
    base = base / 10
  end

  return result_string

end

# Translate mcxi to integer
def mcxi_to_i(mcxi)

  word = mcxi

  prefix = 1
  result = 0
  want_prefix = 0

  (0..word.length-1).each do |i|

    digit = word[i]

    if(digit.is_number?)
      digit = digit.to_i
    end

    case digit
    # Letter Checking
    when 'a'..'z'
      case digit
      when 'm'
        result = result + 1000 * prefix
        prefix = 1
      when 'c'
        result = result + 100 * prefix
        prefix = 1
      when 'x'
        result = result + 10 * prefix
        prefix = 1
      when 'i'
        result = result + 1 * prefix
        prefix = 1
      else
        warn 'Invalid character'
        result = -1
        break
      end
    when 2..9
      prefix = digit
    else
      puts "What the fuck is this: #{digit}"
    end
  end

  return result

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

  # puts "#{inputs[0]} = #{mcxi_to_i(inputs[0])}"
  # puts "#{inputs[1]} = #{mcxi_to_i(inputs[1])}"
  results = mcxi_to_i(inputs[0]).to_i + mcxi_to_i(inputs[1]).to_i
  # puts "Results: #{results}"

  puts i_to_mcxi(results)
end
