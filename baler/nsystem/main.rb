# SPOJ 1699 - Numeral System
# Problem code: NSYSTEM

class String
  def is_number?
    true if Float(self) rescue false
  end
end

# Translate mcxi to integer
def mcxi_to_i(mcxi)

  word = mcxi

  (0..word.length-1).each do |i|

    digit = word[i]

    if(digit.is_number?)
      digit = digit.to_i
    end

    case digit
    when 'm'
      puts 'm'
    when 'c'
      puts 'c'
    when 'x'
      puts 'x'
    when 'i'
      puts 'i'
    when 2..9
      puts digit
    else
      puts "What the fuck is this: #{digit}"
    end
  end

end

mcxi_to_i('m2c4i')
