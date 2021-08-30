ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000 , LENGTH = 128k
	SRAM(rwx) : ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
    .text :
	{
	    *(.vectors*)
	    *(.text*)
		*(.rodata)
		. = ALIGN(4);
		 _data_LMA_start = .;
		 
	} > FLASH
	
	.data :
	{
	    _data_VMA_start = .;
	     *(.data*)
		 . = ALIGN(4);
		 _data_VMA_end = .;
		 
	} > SRAM AT > FLASH
	
	.bss :
	{
	    _bss_start = .;
	    *(.bss*)
		. = ALIGN(4);
		_bss_end = .;
		. = . + 1000;
		_stack_top = .;
		
	} > SRAM 
}