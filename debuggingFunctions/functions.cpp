#include <stdexcept>
#include <limits>
#include <cstdint>

int largest(int a, int b, int c) {
  int d = a;
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;
}

bool sum_is_even(int a, int b) {
  long long sum = (long long)a + (long long)b;
  if (sum % 2 == 0){
    return true;
  }
  return false;
}



int boxes_needed(int apples) {
  if (apples <= 0){
    return 0;
  }
  return ((long long)apples + 19) / 20;
}

bool smarter_section(int A_correct, int A_total, int B_correct, int B_total) { 
  // if parameters are negative or students are larger than total, throw exception
  if ( (A_correct > A_total || B_correct > B_total) || (A_correct < 0 || A_total < 0 || B_correct < 0 || B_total < 0) ){
      throw std::invalid_argument("an invalid argument error just occured");
  }
  return (A_correct/double(A_total)) > (B_correct/double(B_total));
}


bool good_dinner(int pizzas, bool is_weekend) {
  if (pizzas < 0){
    return false;
  }
  if (is_weekend) {
    if (pizzas >= 10){
      return true;
    }
  }
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  return false;
}

int32_t sum_between(int low, int high) {

  if (high < low){
    throw std::invalid_argument("low and high are out of order");
  }
  long value = 0;
  for (int n = low; n < high; n++) { // needs to be inclusive BUT last element needs to be added seperately
    value += n;
  }
  value += high;

  if (value > std::numeric_limits<int32_t>::max() || value < std::numeric_limits<int32_t>::min()){
    throw std::overflow_error("the value exceeds the min/max limit");
  }
  return int32_t(value);
}

int64_t product(long a, long b) {
  // need to check if multiplying results in overflow (6 cases total)

  // edge case when flipping sign causes overflow
  if ((a == std::numeric_limits<int64_t>::min() && b == -1) || (b == std::numeric_limits<int64_t>::min() && a == -1)) {
    throw std::overflow_error("the product exceeds the min limit for a signed 64-bit integer");
  }
  // when both a & b are positive
  if ( (a > 0) && (b > 0) && a > (std::numeric_limits<int64_t>::max() / b)) {
    throw std::overflow_error("the product exceeds the max limit for a signed 64-bit integer");
  }
  // when both a & b are negative
  if ( (a < 0) && (b < 0) && a < (std::numeric_limits<int64_t>::max() / b)) { // in class prof example (multiplication as sneaky division)
    throw std::overflow_error("the product exceeds the max limit for a signed 64-bit integer");
  }
  // when a & b have different signs and not -1
  if ( ( (a > 0) && (b < 0) && (b < std::numeric_limits<int64_t>::min() / a) ) || ( (a < 0) && (b > 0) && (a < std::numeric_limits<int64_t>::min() / b) )){
    throw std::overflow_error("the product exceeds the min limit for a signed 64-bit integer");
  }
  return a * b;
}
