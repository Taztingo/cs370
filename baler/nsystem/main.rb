# SPOJ 1699 - Numeral System
# Problem code: NSYSTEM

# Define a custom String function to determine if its a number
class String
  def is_number?
    true if Float(self) rescue false
  end
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
        end
    when 2..9
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
