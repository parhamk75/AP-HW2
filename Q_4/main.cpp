#include <iostream>
#include <vector>


int main () {
  //// Definition of variables{ ////
  std::vector<float> numbers;       //This vector will contain the numbers to be processed
  float in_num_tmp {};              //This will help in "Getting numbers" block!
  float min_tmp {};                 //This will help in "Sorting ..." block!
  size_t min_tmp_num {};            //This will help in "Sorting ..." block!
  //// }Definition of variables ////
  
  //// Getting numbers{ ////
  std::cout << "please enter numbers (It will end by entering '0'): "
	    << std::endl;
  while (true) {
  std::cin >> in_num_tmp;
  if ( in_num_tmp == 0 ) { break;};
  numbers.push_back (in_num_tmp);
  }
  //// }Getting numbers ////

  //// Show the scrambled numbers that user had entered!{ ////
  std::cout << "Entered numbers are:" << std::endl;
  for ( size_t i{}; i < numbers.size(); i++) {
    std::cout << numbers[i] << std::endl;
  }
  //// }Show the scrambled numbers that user had entered! ////
  
  //// Sorting the numbers with "Selection Sort" method{ ////
  for ( size_t i{}; i < (numbers.size() - 1); i++) {
    min_tmp = numbers[i];
    min_tmp_num = i;
    for (size_t j{i+1}; j < numbers.size(); j++) {
      if ( numbers[j] < min_tmp ) {
	min_tmp = numbers[j];
	min_tmp_num = j;
      }
    }
	if ( !(min_tmp_num == i) ) {
    numbers[min_tmp_num] = numbers[i];
    numbers[i] = min_tmp;
	}
  }
  //// }Sort the numbers with "Selection Sort" method ////  

  //// Show the sorted numbers{ ////
  std::cout << "Sorted numbers are:" << std::endl;
  for ( size_t i{}; i < numbers.size(); i++) {
    std::cout << numbers[i] << std::endl;
  }
  //// }Show the sorted numbers ////
  
    return 0;
}
