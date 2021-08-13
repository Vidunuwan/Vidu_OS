  
    #include "frame_buffer.h"
    #include "serial_port.h"
    #include "memory_segments.h"


    
    int main(){

           char ptr2[] = "Starting Vidu OS";
   
    
    serial_write(0x3F8, ptr2, 16);
    fb_write(ptr2, 16);
    segments_install_gdt();
    }	
