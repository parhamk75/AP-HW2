#include <string>

class Queue {
 public:
  Queue (const std::string& file_add);       //Constructor for Queue

  void displayQueue () const;                //Shows current elements(cells) of the Queue

  float deQueue ();                          //Returns the value of the cell in the queue...
                                             //...that was inserted before the other cells

  void enQueue (float in_num = 0);           //Put a number in the Queue (if nothing is...
                                             //...entered, the default value '0' will be used
  
  ~Queue ();                                 //Destructor for Queue
  
 private:
  
  unsigned int size {};                      //Contains the size of the queue
  float* content {};                         //Elements of the queue will be stored...
                                             //...here (In fact this is the pointer to...
                                             //...that place!)
  size_t wrt_pstn {};                        //Write_position
  size_t rd_pstn {};                         //Read_position
  bool e_f_flg {true};                       //Empty(true) or Full(false) Flag


};
