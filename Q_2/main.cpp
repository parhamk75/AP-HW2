// Warning: This app will work for text with the length of up to 2^32-1 characters!


#include <iostream>
#include <string>
#include <fstream>


int main(){

  //// Variable Define{ ////
  std::ifstream in_txt {"Error_find.txt"};       //the text to be checked
  std::string str_txt, tmp_str;                  //I'll use these two strings to...
                                                 //...import the text into program
  unsigned int* txt_2_nmbr {};                   //This will point to the array which contains...
                                                 //...the non vowels' position in the text  
  std::string non_vowels {"bcdfghjklmnpqrstvwxyz"};   //non vowels except CAPITALS!

  unsigned int i {};                             //Iteration variable that will be used a lot!
  unsigned int offset {};                        //This will be useful in find_first_of() func.

  unsigned int mstk_l {};                        //This will count the length of mistakes...
                                                 //...(mistake_length) in detection block
  bool s_d_f {false};                            //Sequence detected flag (used in detecton block)
  //// }Variable Define ////
  
  //// Importing the text to str_txt{ ////
  while(in_txt){
    in_txt >> tmp_str;
    if( in_txt.eof() ){break;}
    str_txt += ( tmp_str + ' ' );
  }
  in_txt.close();
  //// }Importing the text to str_txt //// 

  //// Extracting non vowel letters' position{ ////
  txt_2_nmbr = new unsigned int[str_txt.length()] {}; //It is so important to initialize all cells
                                                      //with 0 (This fact is used later in program
                                                      //in "Detecting..." part!)
  offset = 0;
  i = 0;
  
  while(true){      
    offset = str_txt.find_first_of (non_vowels, offset);

    if (offset >= (str_txt.length()-1)) {break;}
    
    *(txt_2_nmbr + i) = offset;
    i++;
    offset++;
  }
  //// }Extracting non vowel letters' position ////
  
  //// Detect and show the mistakes{ //// 
  i = 0;
  mstk_l = 1;
  s_d_f = false;
  
  while( i < (str_txt.length() - 1) && !( (*(txt_2_nmbr + i) == 0) && i>0 ) ){
    
    if( s_d_f == false && (*(txt_2_nmbr + i))+1 == *(txt_2_nmbr + i+1) ){
      s_d_f = true;
      mstk_l++;
    }
    else if (s_d_f == true && (*(txt_2_nmbr + i))+1 == *(txt_2_nmbr + i+1)){
      mstk_l++;
    }
    else if (s_d_f == true && !( (*(txt_2_nmbr + i))+1 == *(txt_2_nmbr + i+1) ) ){
            
      if( mstk_l >= 5 ){

	// Show the result!{ //
	unsigned int j {i - mstk_l + 1};
	while (j <= i) {
	  std::cout << str_txt[*(txt_2_nmbr + j)];
	  j++;
	}
	std::cout << "\t" ;
	// }Show the result! //
	
	mstk_l = 1;
	s_d_f = false;
      }
      else {
	mstk_l = 1;
	s_d_f = false;
      }
    }
    else if (s_d_f == false && !( (*(txt_2_nmbr + i))+1 == *(txt_2_nmbr + i+1) ) ){
      //Nothing!
    }

    i++;

  }
  std::cout << std::endl;
  //// }Detect and show the mistakes //// 



  //// Delete Dynamic Variables{ ////
   delete [] txt_2_nmbr;
  //// }Delete Dynamic Variables ////
  return 0;
  }
