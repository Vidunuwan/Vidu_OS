  
    #include "frame_buffer.h"
    #include "serial_port.h"
    #include "io.h"
    #include "memory_segments.h"
    #include "interrupts.h"
    #include "keyboard.h"
    #include "pic.h"
    

    void kmain()
    {

       //char arr[] = "Startin Vidu OS";
       //fb_move_cursor(6*80);
       //fb_write(arr, 20);
       //serial_write(arr, 20);
       segments_install_gdt();
       interrupts_install_idt();

    }
