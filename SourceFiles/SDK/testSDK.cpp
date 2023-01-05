#include "xparameters.h"
#include "xforward.h"
#include "InputImages.h"

XForward* SingletonXf()
{
	static XForward forward;
	return &forward;
}

void process_image(int img[])
{
	XForward* forward = SingletonXf();

	XForward_Initialize(&*forward, 0);

	XForward_Write_input_array_Words(&*forward, 0, img, 784);

	XForward_Start(&*forward);
}

int get_return()
{
	XForward* forward = SingletonXf();

	while (XForward_IsDone(&*forward) == 0) {}

	return XForward_Get_return(&*forward);
}


int main(void) {

	process_image(test_array0);
	xil_printf("0 = %d\n", get_return());
	process_image(test_array1);
	xil_printf("1 = %d\n", get_return());
	process_image(test_array2);
	xil_printf("2 = %d\n", get_return());
	process_image(test_array3);
	xil_printf("3 = %d\n", get_return());
	process_image(test_array4);
	xil_printf("4 = %d\n", get_return());
	process_image(test_array5);
	xil_printf("5 = %d\n", get_return());
	process_image(test_array6);
	xil_printf("6 = %d\n", get_return());
	process_image(test_array7);
	xil_printf("7 = %d\n", get_return());
	process_image(test_array8);
	xil_printf("8 = %d\n", get_return());
	process_image(test_array9);
	xil_printf("9 = %d\n", get_return());
	process_image(test_arrayplus);
	xil_printf("+ = 10 = %d\n", get_return());
	process_image(test_arrayminus);
	xil_printf("- = 11 = %d\n", get_return());
	process_image(test_arrayslash);
	xil_printf("/ = 12 = %d\n", get_return());
	process_image(test_arraydot);
	xil_printf("* = 13 = %d\n", get_return());
	process_image(test_arrayw);
	xil_printf("w = 14 = %d\n", get_return());
	process_image(test_arrayx);
	xil_printf("x = 15 = %d\n", get_return());
	process_image(test_arrayy);
	xil_printf("y = 16 = %d\n", get_return());
	process_image(test_arrayz);
	xil_printf("z = 17 = %d\n", get_return());
}
