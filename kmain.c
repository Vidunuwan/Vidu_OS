  
    #include "frame_buffer.h"
    #include "serial_port.h"
    #include "io.h"
    #include "memory_segments.h"
    #include "interrupts.h"
    #include "keyboard.h"
    #include "pic.h"
    #include "multiboot.h"
    #include "paging.h"
    
   void init(){
   segments_install_gdt();
   interrupts_install_idt();
   init_paging();
}
    
    
    void kmain(unsigned int ebx)
    {
    

       //char arr[] = "Startin Vidu OS";
       //fb_move_cursor(6*80);
       //fb_write(arr, 20);
       //serial_write(arr, 20);
       //segments_install_gdt();
       //interrupts_install_idt();
       
       
       init();
       
        multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
  	multiboot_module_t* modules = (multiboot_module_t*) mbinfo->mods_addr; 
  	unsigned int address_of_module = modules->mod_start;
  	
  	if((mbinfo->mods_count) == 1){
  		char message[] = "ONE module loaded successfully!";
  		serial_write(message,sizeof(message));
  		
  		typedef void (*call_module_t)(void);
        	/* ... */
        	call_module_t start_program = (call_module_t) address_of_module;
        	start_program();
        	/* we'll never get here, unless the module code returns */

  	}else{
  		char message[] = "Error: More than ONE module loaded";
  		serial_write(message,sizeof(message));
  	}

    }
    
