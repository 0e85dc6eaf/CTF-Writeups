import math
import gmpy2
from gmpy2 import mpfr
def find_nearest_power(number):
	gmpy2.get_context().precision=10000
	smallest_r = number
	nearest_xy = 0
	for i in range(2,int(math.log(number,2))):
		floor = int(gmpy2.root(mpfr(number),i))**i
		if number - floor < smallest_r:
			if floor > number:
				print("error at %d"%i)
			smallest_r = number - floor
			nearest_xy = floor
	return smallest_r