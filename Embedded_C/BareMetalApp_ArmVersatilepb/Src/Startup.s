/****************************************************
*
* Author: Mohamed Hosny
* Description: a Simple startup code for ARM926ej-s
*
*****************************************************/

.global reset

reset:
    ldr sp, =stack_top
    bl main

stop:
    b stop


