
#include "IntCtrl.h"
#include "SCB.h"


int main(void)
{
	Init_voidSCB_Clock();
	 SCB_voidEnable_Clock_Run_Mode( UART, MODULE_1 );


    while (1)
    {
        /* code */
    }
    
		return 0;


}