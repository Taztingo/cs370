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

  # Will count down by factors of 10 checking every base
  while(base / 10 != 0)
    accumulator = base

    # Store prefix to come before base
    prefix = 1

    while(accumulator + base < number)
      prefix += 1
      accumulator += base
    end

    if prefix == 1
      prefix = nil
    end

    result_string.prepend(prefix.to_s + translate_base(base))

    base /= 10
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
      # If a prefix was expected, stop
      if(want_prefix == true)
        result = -1
        break
      else
        want_prefix = true
      end

      case digit
      when 'm'
        result = result + 1000 * prefix
      when 'c'
        result = result + 100 * prefix
      when 'x'
        result = result + 10 * prefix
      when 'i'
        result = result + 1 * prefix
      else
        warn 'Invalid character'
        result = -1
        break
      end
    when 2..9
      # If a prefix wasn't expected, stop
      if(want_prefix == false)
        result = -1
        break
      else
        want_prefix = false
        prefix = digit
      end
    else
      puts "What the fuck is this: #{digit}"
    end
  end

  return result

end

puts mcxi_to_i('6m2c4i')
puts mcxi_to_i('6mm2c4i')

puts i_to_mcxi(6204)
