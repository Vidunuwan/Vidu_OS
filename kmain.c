  
    #include "frame_buffer.h"
    #include "serial_port.h"


    
    int main(){

           char ptr2[] = "Starting Vidu OS";
   
    
    serial_write(0x3F8, ptr2, 16);
    fb_write(ptr2, 16);
    
    }	
