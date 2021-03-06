#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xbasic_types.h"
#include "xparameters.h"
#include "xil_io.h"
Xuint32 *baseaddr_p = (Xuint32 *)XPAR_CALCULATOR_IP_0_S00_AXI_BASEADDR;
int main()
{
 init_platform();
 xil_printf("Calculator Test\n\r");
 // CLEAR = 0x00000001 ; LOAD = 0x0000002 ; ADD = 0x00000004

 xil_printf("Signal : Clear \n\r");

 Xil_Out32(*(baseaddr_p+0) ,0x00000001);  // register 0
 Xil_Out32(*(baseaddr_p+1) ,0x00000000);
 //Xil_Out32(*(baseaddr_p+4) ,0x00000006);  // register 1 -> dIn
 xil_printf("Reading Input => 0x%08x \n\r", Xil_In32(*(baseaddr_p+2))); // register 2

 xil_printf("Data Input : 2 \n\rSignal : Load \n\r");
 Xil_Out32(*(baseaddr_p+0) ,0x00000002);  // register 0
 Xil_Out32(*(baseaddr_p+1) ,0x00000002);
 //Xil_Out32(*(baseaddr_p+4) ,0x00000006);  // register 1 -> dIn
 xil_printf("Reading Input => 0x%08x \n\r", Xil_In32(*(baseaddr_p+2))); // register 2


 xil_printf("Data Input : 2 \n\rSignal: Add \n\r");

 Xil_Out32(*(baseaddr_p+1), 0x00000002);  // Data Input is 5
 Xil_Out32(*(baseaddr_p+0), 0x00000004); // register 0
 xil_printf("Output => 0x%08x \n\r", Xil_In32(*(baseaddr_p+2))); // register 2

 xil_printf("Signal: Clear \n\r");
 Xil_Out32(*(baseaddr_p+0) ,0x00000000);  // register 0
 xil_printf("Output => 0x%08x \n\r", Xil_In32(*(baseaddr_p+8))); // register 2




// // Write calculator signal inputs to register 0
//  *(baseaddr_p+0) = 0x00000010;
//  xil_printf("Add => HIGH \n\r");
//  // Write calculator data inputs to register 1
//  *(baseaddr_p+1) = 0x000000003;
//  xil_printf("Writing Input =>  0x%08x \n\r", *(baseaddr_p+1));
//  // Read calculator output from register 2
//  xil_printf("Reading Output => 0x%08x \n\r", *(baseaddr_p+2));
//
// //clearing
// *(baseaddr_p+0) = 0x00000001;
// xil_printf("Clear => HIGH \n\r");
// xil_printf("Reading Output => 0x%08x \n\r", *(baseaddr_p+2));
//
//
// // Write calculator signal inputs to register 0
// *(baseaddr_p+0) = 0x00000002;
// xil_printf("Load => HIGH \n\r");
// // Write calculator data inputs to register 1
// *(baseaddr_p+1) = 0x0000003;
// xil_printf("Writing Input => 0x%08x \n\r", *(baseaddr_p+1));
// // Read calculator output from register 2
// xil_printf("Reading Output => 0x%08x \n\r", *(baseaddr_p+2));
//
// //clearing
// *(baseaddr_p+0) = 0x00000001;
// xil_printf("Clear => HIGH \n\r");
// xil_printf("Reading Output => 0x%08x \n\r", *(baseaddr_p+2));




 xil_printf("End of test\n\n\r");
 cleanup_platform();
 return 0;
}

