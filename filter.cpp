#include "filter.hpp"

void grey_filter(AXI_STREAM &inStream, AXI_STREAM &outStream, int rows, int cols){
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE s_axilite port=rows bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=cols bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS

	RGB_IMAGE  img_0(rows, cols);
	GRAY_IMAGE img_1(rows, cols);
	RGB_IMAGE  img_2(rows, cols);

	#pragma HLS dataflow

	hls::AXIvideo2Mat(inStream, img_0);
	hls::CvtColor<HLS_BGR2GRAY>(img_0, img_1);
	hls::CvtColor<HLS_GRAY2RGB>(img_1, img_2);
	hls::Mat2AXIvideo(img_1, outStream);
}
