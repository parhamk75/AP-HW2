#include "queue.h"
#include <fstream>
#include <iostream>

Queue::Queue (const std::string& file_add){
  std::string tmp_1{};
  std::ifstream init_txt { file_add };
  size_t tmp_2 {};
  size_t i{}; 
  
  getline ( init_txt, tmp_1);
  size = std::stoi ( tmp_1, &tmp_2);
  content = new float [size] {};

  i = 0;
  while(i < size){
    if ( !init_txt.eof() ) {
      getline ( init_txt, tmp_1, ',');
      *( content + i ) = std::stof (tmp_1);
    }
    i++;
    if ( init_txt.eof() ) {break;}
  }
  init_txt.close();

  if(i == size){                   //Queue is full!
    wrt_pstn = 0;
    e_f_flg = false;
  }
  else if(i < size){
    wrt_pstn = i;
  }
  
  while (i < size){
    *( content + i ) =  std::stof ("nan");
    i++;
  }
  
  rd_pstn = 0;
}

void Queue::displayQueue () const {

  if ( wrt_pstn == rd_pstn && e_f_flg == true ){         //If Queue is empty
    std::cout << "displayQueue says: The Queue is empty!" << std::endl;
  }
  else if ( wrt_pstn == rd_pstn && e_f_flg == false ){   //If Queue is full
    for ( size_t i {rd_pstn}; i < size; i++) {
    std::cout << "num: " << i << " content: " << *( content + i ) << std::endl;
    }
    for ( size_t i {0}; i < rd_pstn; i++) {
    std::cout << "num: " << i << " content: " << *( content + i ) << std::endl;      
    }
  }
  else if ( rd_pstn < wrt_pstn ){                       //If Queue is in normal mode
    for ( size_t i {rd_pstn}; i < wrt_pstn; i++) {
      std::cout << "num: " << i << " content: " << *( content + i ) << std::endl;
    } 
  }
  else if ( rd_pstn > wrt_pstn ) {                      //If Queue is in splited mode
    for ( size_t i {rd_pstn}; i < size; i++) {
      std::cout << "num: " << i << " content: " << *( content + i ) << std::endl;
    }
    for ( size_t i {0}; i < wrt_pstn; i++) {
      std::cout << "num: " << i << " content: " << *( content + i ) << std::endl;      
    }
  }
  

}

float Queue::deQueue () {
  float tmp_1 {};
  
  if ( wrt_pstn == rd_pstn && e_f_flg == true ){         //If Queue is empty
    std::cout << "deQueue says: The Queue is empty!" << std::endl;
  }
  else if ( wrt_pstn == rd_pstn && e_f_flg == false ){   //If Queue is full
    tmp_1 = *( content + rd_pstn );
    *( content + rd_pstn ) =  std::stof ("nan");         //Delete the cell
       
    if ( rd_pstn < size - 1 ){
      rd_pstn++;
    }
    else if ( rd_pstn == size - 1 ){
      rd_pstn = 0;
    }
	
	if ( rd_pstn == wrt_pstn ){ e_f_flg = true;}         //The Queue is now empty!
    
	return tmp_1;
  }
  else if ( rd_pstn < wrt_pstn ){                        //If Queue is in normal mode
    tmp_1 = *( content + rd_pstn );
    *( content + rd_pstn ) =  std::stof ("nan");         //Delete the cell

    rd_pstn++;

    if ( rd_pstn == wrt_pstn ){ e_f_flg = true;}         //The Queue is now empty!

    return tmp_1;
  }
  else if ( rd_pstn > wrt_pstn ) {                       //If Queue is in splited mode
    tmp_1 = *( content + rd_pstn );
    *( content + rd_pstn ) =  std::stof ("nan");         //Delete the cell
    
    if ( rd_pstn < size - 1 ){
      rd_pstn++;
    }
    else if ( rd_pstn == size - 1 ){
      rd_pstn = 0;
    }

    if ( rd_pstn == wrt_pstn ){ e_f_flg = true;}         //The Queue is now empty!
    
    return tmp_1;
  }
  
  return std::stof ("nan");  
}

void Queue::enQueue (float in_num) {
  
  if ( wrt_pstn == rd_pstn && e_f_flg == false ){        //If Queue is full
    std::cout << "deQueue says: The Queue is full!" << std::endl;
  }
  else {                                                 //If Queue is in empty / normal/splited mode
    *( content + wrt_pstn ) = in_num;
    
    if ( wrt_pstn < size - 1 ){
      wrt_pstn++;
    }
    else if ( wrt_pstn == size - 1 ){
      wrt_pstn = 0;
    }
    
    if ( rd_pstn == wrt_pstn ){ e_f_flg = false;}        //The Queue is now full!
  }
  
}

Queue::~Queue (){
  delete [] content;
}
