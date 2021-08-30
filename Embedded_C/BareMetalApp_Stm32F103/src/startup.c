/*****************************************
*  Author: Mohamed Hosny
*  Date: 5/7/2021
*  Description: Startup code for STM32F103
*               
******************************************/

void Default_Handler();
void Reset_Handler();
void NMI_Handler()          __attribute__((weak, alias ("Default_Handler")));
void H_Fault_Handler()      __attribute__((weak, alias ("Default_Handler")));
void MM_Fault_Handler()     __attribute__((weak, alias ("Default_Handler")));
void Bus_Fault_Handler()    __attribute__((weak, alias ("Default_Handler")));
void Usage_Fault_Handler()  __attribute__((weak, alias ("Default_Handler")));
int main();

extern unsigned long int _data_LMA_start;
extern unsigned long int _data_VMA_start;
extern unsigned long int _data_VMA_end;
extern unsigned long int _bss_start;
extern unsigned long int _bss_end;

unsigned long int Vectors[] __attribute__((section(".vectors")))= 
{
    &_stack_top, 
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler,
    &MM_Fault_Handler,
    &Bus_Fault_Handler,
    &Usage_Fault_Handler
};

void Default_Handler()
{
    for(;;);
}

void Reset_Handler()
{
   int i;
   
   unsigned long int _data_size = (unsigned long int)_data_VMA_end - (unsigned long int)_data_VMA_start;
   unsigned long int _bss_size =  (unsigned long int)_bss_end - (unsigned long int)_bss_start;
   unsigned char* _src =  (unsigned char*)_data_LMA_start;
   unsigned char* _dest = (unsigned char*)_data_VMA_start;
   
   for(i = 0; i < _data_size; i++)
   {
     *_dest++ = *_src++; 
   }
   
   _src = (unsigned char*)_bss_start;
   
   for(i = 0; i < _bss_size; i++)
   {
       *_src++ = 0;	   
   }
   
   main();
   for(;;);
}