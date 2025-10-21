#include <iostream>
#include "functions.h"

// returns the boolean value true if and only if 1,000 <= a <= b < 1,000,000,000,000
bool is_valid_range(long long a, long long b) {
	// TODO(student): return true if and only if 1,000 <= a <= b < 1,000,000,000,000
	if ( a >= 1000 && a <= b && b < 1000000000000) { 
		return true;
	}
	else {return false;}
}

// returns the 'p' if number is a plateau, 'b' if number is a basin, and 'n' if number is neither
char classify_geo_type(long long number) {            // 1221 (for testing)
	// TODO(student): Initialize local variables
	long long num = number;
	int remainder {};
	int prevRemainder {};
	int count = 1;
	char type {};
	bool up = false;
	// TODO(student): Determine whether number is a plateau: this is the key loop
	while (num !=0){
		remainder = num % 10;
		num /= 10;
		if (count != 1){ // 2nd iteration onwards
			if (prevRemainder > remainder){
				type = 'n';
				return type;
			}
			if (count > 2){ // 3rd iteration onwards
				if (prevRemainder == remainder){
					up = true;
				}
				if (up){
					if (prevRemainder < remainder){ // if NOT increasing after 
						type = 'n';
						return type;
					}
				}
			}

		}
		prevRemainder = remainder;
		count++;
	}
	type = 'p';
	return type;
	// TODO(student): Determine whether number is a basin
	//                If you get the logic for plateau right, minor tweaks can create the code for basins.

	// TODO(student): return the appropriate char, p for plateau, b for basin, n for neither

	if (number / 1000 < 1){ // has less than 4 digits
		return 'n';
	}

}

// returns how many numbers in the range [a, b] are plateaus and basins
plateaus_and_basins count_pb_numbers(long long a, long long b) {
	int number_of_plateaus = 0;
	int number_of_basins = 0;

	// TODO(student): count plateaus and basins in the range [a,b]

	return {number_of_plateaus, number_of_basins};
}