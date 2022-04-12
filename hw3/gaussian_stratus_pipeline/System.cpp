#include "System.h"
System::System( sc_module_name n, string input_bmp, string output_bmp ): sc_module( n ), 
	tb("tb"), Gaussian_blur("Gaussian_blur"), clk("clk", CLOCK_PERIOD, SC_NS), rst("rst"), _output_bmp(output_bmp)
{
	tb.i_clk(clk);
	tb.o_rst(rst);
	Gaussian_blur.i_clk(clk);
	Gaussian_blur.i_rst(rst);
	tb.o_rgb(rgb);
	tb.i_result(result);
	Gaussian_blur.i_rgb(rgb);
	Gaussian_blur.o_result(result);

  tb.read_bmp(input_bmp);
}

System::~System() {
  tb.write_bmp(_output_bmp);
}
