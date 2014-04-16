gets

input = gets.split(" ").map { |x| x.to_i}

def swap(array, x, y)
	temp = array[x]
	array[x] = array[y]
	array[y] = temp

	return array
end


# This is the recursive function for silly sort. It's goal is to sort an array
# into ascending order while also minimizing the cost needed to do so. Each swap's
# cost is equal to the sum of the swapped integers. This method utilizes a "temporary"
# swap which then evaluates the cost of... See my personal blog for more details.
def silly_sort(array, size)
	min_sum = 0 #The minimum sum that has been found during all of the various recursive function calls
	first_swap = true #A variable that determines whether or not the swap being conducted is the first swap

	#A for loop that is initialized at 0 and loops until the temporary variable, i, hits the size of the array
	for i in 0..size
		#A for loop that is initialized at the value of the temporary variable, i, then loops until it hits the size of the array
		for j in i..size
			#Conditional that checks if the ith element in the array is greater than the jth element, if so a potential swap is here
			if array[i] > array[j]
				#Declares sum as the cost of the swap that is going to be initiated
				sum = array[i] + array[j]

				#Swaps the desired elements and returns the new array
				array = swap(array, x, y)

				#min_silly is an interesting variable. It's given name, min, is indicative of the general purpose of the variable, while its surname, silly
				#is more of a specific identifier. When combined the names clearly describe the purpose of this all important variable. The minimum costing
				#sily_sort
				min_silly - silly_sort(array, size)

				#If a new min_silly is found then mark old min_silly as the new min_silly
				if((min_silly + sum) < min_sum)
					first_swap = false
					min_sum = min_silly + sum
				end

				#Reswap the array back to its original way it was before anything silly could ever touch it
				array = swap(array, x, y)				
			end
		end
	end

	#Returns the minimum sum found and is conclusively the solution
	return min_sum
end