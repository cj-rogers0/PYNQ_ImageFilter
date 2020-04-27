#include <hls_stream.h>
#include <hls_video.h>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>

typedef ap_axiu<32,1,1,1> image;
typedef hls::stream<image> AXI_STREAM;

#define MAX_WIDTH  2000
#define MAX_HEIGHT 2000

typedef hls::Mat<MAX_HEIGHT,   MAX_WIDTH,   HLS_8UC3> RGB_IMAGE;
typedef hls::Mat<MAX_HEIGHT,   MAX_WIDTH,   HLS_8UC1> GRAY_IMAGE;

void grey_filter(AXI_STREAM &inStream, AXI_STREAM &outStream, int width, int height);
